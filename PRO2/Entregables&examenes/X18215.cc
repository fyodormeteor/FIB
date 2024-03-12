/*  Reduccio de programes 
    12.03.2024

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef string Stack; // This solution uses a string as a stack

bool stringAtEnd(Stack& s, string str)
{
    int amt = str.size();
    int size = s.size();

    if (amt > size) return false;

    for(int i = 0; i < amt; ++i)
    {
        if(s[size-1-i] != str[amt-1-i]) return false;
    }

    return true;
}

bool charAtPos(Stack& s, int pos, char c)
{
    if (pos < 0 or s[pos] != c) return false;
    return true;
}

// Post: Pops amt elements from Stack, pushes c at the end, and updates size variable by reference
void replaceAtEnd(Stack& s, int& size, int amt, char c)
{
    for(int i = 0; i < amt; ++i)
    {
        s.pop_back();
    }
    s.push_back(c);
    size = s.size(); // Updates size
}

// Post: Applies rules collapsing the stack until there is no rule satisfied.
void collapse(Stack& s, char& next)
{
    int size = s.size();
    bool try_next = true;

    if (stringAtEnd(s, "n"))
    {
        replaceAtEnd(s, size, 1, 'E');
        try_next = false;
    }

    if (stringAtEnd(s, "v") and next != '=' and try_next)
    {
        replaceAtEnd(s, size, 1, 'E');
        try_next = false;
    }

    if (stringAtEnd(s, "E*E") and try_next)
    {
        replaceAtEnd(s, size, 3, 'E');
        try_next = false;
    }

    if (stringAtEnd(s, "E+E") and next != '*' and try_next)
    {
        replaceAtEnd(s, size, 3, 'E');
        try_next = false;
    }

    if (stringAtEnd(s, "E<E") and next != '*' and next != '+' and try_next)
    {
        replaceAtEnd(s, size, 3, 'E');
        try_next = false;
    }

    if (stringAtEnd(s, "v=E;") and try_next)
    {
        replaceAtEnd(s, size, 4, 'I');
        try_next = false;
    }

    if (stringAtEnd(s, "(E)") and !charAtPos(s, size-4, 'i') and !charAtPos(s, size-4, 'w') and try_next)
    {
        replaceAtEnd(s, size, 3, 'E');
        try_next = false;
    }

    if (stringAtEnd(s, "i(E)I") and next != 'e' and try_next)
    {
        replaceAtEnd(s, size, 5, 'I');
        try_next = false;
    }

    if (stringAtEnd(s, "i(E)IeI") and try_next)
    {
        replaceAtEnd(s, size, 7, 'I');
        try_next = false;
    }

    if (stringAtEnd(s, "w(E)I") and try_next)
    {
        replaceAtEnd(s, size, 5, 'I');
        try_next = false;
    }

    if (stringAtEnd(s, "LI") and try_next)
    {
        replaceAtEnd(s, size, 2, 'L');
        try_next = false;
    }

    if (stringAtEnd(s, "I") and !charAtPos(s, size-2, ')') and !charAtPos(s, size-2, 'L') and try_next)
    {
        replaceAtEnd(s, size, 1, 'L');
        try_next = false;
    }

    if (stringAtEnd(s, "{L}") and try_next)
    {
        replaceAtEnd(s, size, 3, 'I');
        try_next = false;
    }

    if (!try_next) collapse(s, next);
}

void printStack(Stack& s)
{
    cout << s << endl;
}

int main()
{
    string input;
    while(getline(cin, input))
    {
        stringstream sstream(input);
        Stack s;
        
        char c;
        while (sstream >> c)
        {
            s.push_back(c);
            char next = sstream.peek();
            collapse(s, next);
        }

        if (s.size() == 1 and s[0] == 'L')  // Last rule
        {
            s[0] = 'P';
        }

        printStack(s);
    }
}