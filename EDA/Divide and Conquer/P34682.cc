// EDA Divide and Conquer
// Fixed Points

#include <vector>
#include <iostream>

// S[i]+a = i

using namespace std;

int fixed_point(const vector<int>& S, int a, int l, int r)
{
    if (l>r) return -1;
    if (l==r)
    {
        if(S[r]+a == r) return r;
        return -1;
    }

    int m = (l+r)/2;
    if (S[m] + a < m) return fixed_point(S, a, m+1, r);
    return fixed_point(S, a, l, m);
}

int main()
{
    int n;
    int seqnum = 1;

    while(cin >> n)
    {
        vector<int> S = vector<int>(n+1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> S[i];
        }

        int m;
        cin >> m;
        vector<int> a = vector<int>(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> a[i];
        }
        
        cout << "Sequence #" << seqnum << endl;
        for (int i = 0; i < m; ++i)
        {
            int fp = fixed_point(S, a[i], 1, n);
            if (fp >= 0) cout << "fixed point for " << a[i] << ": " << fp << endl;
            else cout << "no fixed point for " << a[i] << endl;
        }

        cout << endl;
        seqnum++;
    }
}