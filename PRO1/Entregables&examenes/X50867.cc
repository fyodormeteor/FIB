/*  simpleAlternatedSum
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int simpleAlternatedSum(int n)
{
    if (n == 1) return 1;
    else
    {
        int z = n;
        if (n%2 == 0) z = -z;                   // Substract if current n is even.
        return z + simpleAlternatedSum(n-1);
    }
}

int main()
{

}
