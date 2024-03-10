/*  Indexar sequencies ben parentitzades
    28.02.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string w;
    while (cin >> w)
    {
        stack<int> s;
        int n = w.size();
        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            if (w[i] == '(')
            {
                ++count;
                s.push(count);
                cout << '(' << count;
            }
            else
            {
                cout << ')' << s.top();
                s.pop();
            }
        }

        cout << endl;
    }
}