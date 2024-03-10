/*  Minimo comun divisor
    27.11.2024

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> Vec;

bool sortcmp(int x, int y)
{
    return x > y;
}

//pre: a > b (although sort function in main takes care of that)
int mcd(int a,int b)
{
    int r = a%b;
    if (r == 0) return b;
    else        return mcd(b, r);
}

//pre: data vector with all numbers, size of the vector, and index initially set at 0;
int calculate_mcd_from_vector(const Vec& data, const int size, int index)
{
    if  (index == size-1) return data[index];
    else
    {
        int x = calculate_mcd_from_vector(data, size, index+1);
        return mcd(data[index], x);
    }
}

// pre: input is size, n0, n1, ..., n_(size-1)
// post: mcd of the size n's
int main()
{
    int size;
    cin >> size;

    if (size > 0)
    {
        Vec data(size);
        for(int i = 0; i < size; ++i)
        {
            cin >> data[i];
            if (data[i] < 0) data[i]*=-1;
        }
        sort(data.begin(), data.end(), sortcmp);

        cout << "mcd = " << calculate_mcd_from_vector(data, size, 0) << endl;
    }
    else cout << "No numbers" << endl;
}