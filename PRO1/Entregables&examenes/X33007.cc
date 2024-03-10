/*  The height of a mountain's summit
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<vector>
using namespace std;

// Pre:  Let n be v.size(). Then n >= 3 and for all i in {0..n-1}, v[i] >= 0.
//       Also, there exists i in {1..n-2} such that v[0..i] is strictly increasing and
//                                                  v[i..n-1] is strictly decreasing.
// Post: Returns the maximum value of v.
int summitOfMountain(const vector<int> &v)
{
    int n = v.size();

    int left = 0;
    int right = n-1;
    int middle;
    bool found = false;
    while(!found)
    {
        middle = (left+right)/2;
        if (v[middle-1] < v[middle])
        {
            if (v[middle] > v[middle+1]) found = true;
            else left = middle;
        }
        else right = middle;
    }

    return v[middle];
}

int main()
{
    // para probar que funciona
    
    vector<int> vec(16);
    vec[0] =1;
    vec[1] =5;
    vec[2] =6;
    vec[3] =7;
    vec[4] =14;
    vec[5] =16;
    vec[6] =20;
    vec[7] =24;
    vec[8] =26;
    vec[9] =33;
    vec[10] =38;
    vec[11] =44;
    vec[12] =41;
    vec[13] =29;
    vec[14] =19;
    vec[15] =9;

    cout << summitOfMountain(vec) << endl;
}