// EDA Divide and Conquer
// First occurence

#include <vector>
#include <iostream>

using namespace std;

int first_occ_rec(int l, int r, double x, const vector<double>& v)
{
    if (r < l) return -1;
    if (r == l)
    {
        if (v[r] == x) return r;
        return -1;
    }

    int m = (l+r)/2;

    if (x <= v[m]) return first_occ_rec(l, m, x, v);
    return first_occ_rec(m+1, r, x, v);
}

int first_occurrence(double x, const vector<double>& v)
{
    return first_occ_rec(0, v.size()-1, x, v);
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}