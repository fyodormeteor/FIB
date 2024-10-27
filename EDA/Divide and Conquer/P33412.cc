// EDA Divide and Conquer
// Resistant search

#include <iostream>
#include <vector>

using namespace std;

bool resistant_search_rec(double x, const vector<double> &v, int l, int r)
{
	if (r < l) return false;

	int m = (l+r)/2;

	if (v[m] == x) return true;

	if (m > 0 and v[m - 1] == x) return true;
	if (m < v.size() - 1 and v[m + 1] == x) return true;

	if (v[m] > x) return resistant_search_rec(x, v, l, m - 1);
	return resistant_search_rec(x, v, m + 1, r);
}

bool resistant_search(double x, const vector<double>& v)
{
	return resistant_search_rec(x, v, 0, int(v.size()-1));
}