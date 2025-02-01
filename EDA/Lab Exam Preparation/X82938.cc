#include <iostream>
#include <vector>

using namespace std;

bool binary_search(int x, const vector<int>& v, bool inc, int l, int r) {
    if (l >= r) return (x == v[l]);
    int m = (l+r)/2;
    if (inc) {
        if (x <= v[m])  return binary_search(x, v, inc, l, m);
        else            return binary_search(x, v, inc, m+1, r);
    }
    else {
        if (x >= v[m])  return binary_search(x, v, inc, l, m);
        else            return binary_search(x, v, inc, m+1, r);
    }
}

bool resistant_search(int x, const vector<int>& v, int l, int r) {
    if (l >= r) return (x == v[l]);
    int m = (l+r)/2;
    bool inc = (v[m] < v[m+1]);
    if (inc) {
        return binary_search(x, v, inc, l, m) or resistant_search(x, v, m+1, r);
    } else {
        return resistant_search(x, v, l, m) or binary_search(x, v, inc, m+1, r);
    }
}

bool search(int x, const vector<int>& v) {
    return resistant_search(x, v, 0, v.size()-1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}