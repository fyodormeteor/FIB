// EDA Divide and Conquer
// Interest Rates

#include <iostream>
#include <math.h>

using namespace std;

int calc_ir_intersection(double m, double f, double r, int L, int R)
{
    if (L+1 >= R) return R;

    int d = (L+R)/2;

    if ((f*d+m - pow(1+0.01*r, d)*m) > 0) return calc_ir_intersection(m, f, r, d, R);
    else return calc_ir_intersection(m, f, r, L, d);
}

int main()
{
    double m;
    double f;
    double r;

    while (cin >> m >> f >> r)
    {
        if ((f+m - (1+0.01*r)*m) < 0) cout << "1" << endl;
        else cout << calc_ir_intersection(m,f,r,1,10000000) << endl;
    }
}