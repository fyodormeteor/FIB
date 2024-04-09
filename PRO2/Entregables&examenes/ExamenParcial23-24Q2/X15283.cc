/*  Cortxets ben tancats i parèntesis parcialment tancats.
    09.04.2024

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <list>
#include <string>
#include <stack>

using namespace std;

// Uses an auxiliary stack to reverse the original stack, and uses the auxiliary stack to output the contents of the original stack in reversed order.
void reverseAndPrintStack(stack<char>& s)
{
    stack<char> s_aux;

    while (!s.empty())
    {
        char content = s.top();
        s_aux.push(content);
        s.pop();
    }

    while (!s_aux.empty())
    {
        cout << s_aux.top();
        s_aux.pop();
    }
    
    cout << endl;
}

int main()
{
    string input_line;
    while(getline(cin, input_line))
    {
        list<char> input; 
        for(int i = 0; i < input_line.size(); ++i) // Convert the read string into a list of characters
        {
            input.push_back(input_line[i]);
        }

        stack<char> s;
        char c;
        auto it = input.begin();
        while(it != input.end()) // Iterate on the list of characters
        {
            c = *it;
            
            if (c == '(' or c == '[')
            {
                s.push(c);
            }

            if (c == ')')
            {
                if (!s.empty() and s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    s.push(c);
                }
            }

            if (c == ']')
            {
                if (!s.empty() and s.top() == '[')
                {
                    s.pop();
                }
                else if (!s.empty() and s.top() == '(') // delete the element from the stack and add ']' to the next position of the list
                                                        // this way, the newly added ']' will be treated in the next iteration.
                {
                    s.pop();
                    auto it_aux = it;
                    it_aux++;
                    input.insert(it_aux, ']');
                }
                else
                {
                    s.push(c);
                }
            }

            it++;
        }

        // Any elements that could not be reduce will be left in the stack, thus we print the stack (in reverse order)
        reverseAndPrintStack(s);
    }
}