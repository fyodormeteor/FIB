/*  Consecutive number at distance less or equal to 2,
    only two consecutives at distance 1.
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <vector>
using namespace std;

// Pre: Let n be v.size(). Then, for each i in {0..n-2}, |v[i]-v[i+1]|<=2 holds.
//      In addition, there is exactly one i in {0..n-2} satisfying |v[i]-v[i+1]|=1.
// Post: The function returns this particular i in {0..n-2} satisfying |v[i]-v[i+1]|=1.
int positionDistance1(const vector<int> &v)
{
    int n = v.size();
    int l = 0;
    int r = n-1;

    while (l+1 < r)
    {
        int m = (l+r)/2;
        if (v[m]%2 == v[0]%2) l = m;
        else r = m;
    }
    return l;
}

int main()
{

}