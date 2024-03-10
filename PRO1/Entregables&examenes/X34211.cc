/*  Sum or subtract numbers from an input list
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> list(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> list[i];
    }

    string s;
    while(cin >> s)
    {
        int result = 0;
        for(int i = 0; i < n; ++i)
        {
            if (s[i] == '-')    result -= list[i];
            else                result += list[i];
        }
        cout << result << endl;
    }
}