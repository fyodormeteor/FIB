/*  Happy subsequences at increasing positions in a matrix
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<vector>
using namespace std;

typedef vector<char> RowChar;
typedef vector<RowChar> MatrixChar;
typedef vector<int> RowInt;
typedef vector<RowInt> MatrixInt;

//Pre:
//Post: return value of matrix on coordinate i,j, or 0 if position invalid
int readMatInt(const MatrixInt& mat, int i, int j)
{
    if (i < 0 or j < 0) return 0;
    return mat[i][j];
}

//Pre:
//Post: returns number of happy subsequences such as at the triple of positions
//      (i1,j1),(i2,j2),(i3,j3) such that M[i1][j1]=’:’, M[i2][j2]=’-’, M[i3][j3]=’)’ and 0≤i1<i2<i3<n and 0≤j1<j2<j3<m.
int happySubsequences(const MatrixChar& mat)
{
    int m = mat.size();
    int n = mat[0].size();
    if ((m < 3) or (n < 3)) return 0;

    MatrixInt dots(m, RowInt(n)); // Auxiliary matrix for ':'
    MatrixInt dash(m, RowInt(n)); // Auxiliary Matrix for '-'
    MatrixInt pars(m, RowInt(n)); // Auxiliary Matrix for ')'

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            dots[i][j] = readMatInt(dots, i-1, j) + readMatInt(dots, i, j-1) - readMatInt(dots, i-1, j-1);
            if (mat[i][j] == ':') dots[i][j] += 1;

            dash[i][j] = readMatInt(dash, i-1, j) + readMatInt(dash, i, j-1) - readMatInt(dash, i-1, j-1);
            if (mat[i][j] == '-') dash[i][j] += readMatInt(dots, i-1, j-1);

            pars[i][j] = readMatInt(pars, i-1, j) + readMatInt(pars, i, j-1) - readMatInt(pars, i-1, j-1);
            if (mat[i][j] == ')') pars[i][j] += readMatInt(dash, i-1, j-1);
        }
    }

    return readMatInt(pars, m-1, n-1);
}

int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        MatrixChar input(m, RowChar(n));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cin >> input[i][j];
            }
        }

        cout << happySubsequences(input) << endl;
    }
}