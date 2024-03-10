/*  Number of happy and sad subsequences
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<vector>
using namespace std;

// Pre: c1,c2,c3 are pairwise different characters.
// Post: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size() and
//       s[i1]=c1, s[i2]=c2, s[i3]=c3.
int numberSubsequences(const string &s, char c1, char c2, char c3)
{
    int n = s.size();
    int n1, n2, n3;
    n1 = n2 = n3 = 0;

    for(int i = 0; i < n; ++i)
    {
        if (s[i] == c1)         n1 += 1;
        else if (s[i] == c2)    n2 += n1;
        else if (s[i] == c3)    n3 += n2;
    }
    
    return n3;
}

// Pre:
// Post: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size() and
//       either s[i1]=':', s[i2]='-', s[i3]=')' or s[i1]='(', s[i2]='-', s[i3]=':'.
int numberHappySubsequences(const string &s)
{
    int count = 0;
    count += numberSubsequences(s, '(', '-', ':');
    count += numberSubsequences(s, ':', '-', ')');
    return count;
}

// Pre:
// Post: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size() and
//       either s[i1]=':', s[i2]='-', s[i3]='(' or s[i1]=')', s[i2]='-', s[i3]=':'.
int numberSadSubsequences(const string &s)
{
    int count = 0;
    count += numberSubsequences(s, ')', '-', ':');
    count += numberSubsequences(s, ':', '-', '(');
    return count;
}

int main()
{
    string s;
    while (cin >> s)
    {
        cout << numberHappySubsequences(s) << ' ' << numberSadSubsequences(s) << endl;
    }
}
