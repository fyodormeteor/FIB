/*  Palindroms amb piles
    28.02.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;

    int n;
    cin >> n;

    int i = 0;
    while(i < n/2)
    {
        int x;
        cin >> x;
        s.push(x);

        ++i;
    }

    if (n%2 == 1)
    {
        int x;
        cin >> x;
        ++i;
    }

    bool is_palindrome = true;
    while(i < n)
    {
        int x;
        cin >> x;
        
        int y = s.top();
        s.pop();

        if (x != y) is_palindrome = false;

        ++i;
    }

    switch(is_palindrome)
    {
        case true:  cout << "SI" << endl; break;
        case false: cout << "NO" << endl; break;
    }
}