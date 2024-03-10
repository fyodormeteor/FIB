/*  Count occurrences of each digit in its row and column
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Mat;

void printMat(const Mat& mat)
{
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << mat[i][j];
        cout << endl;
    }
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        Mat aux_row(n, Row(10, 0));
        Mat aux_col(m, Row(10, 0));

        Mat u(n, Row(m, 0));

        for(int i = 0; i < n; ++i)
        {
            string readrow;
            cin >> readrow;

            for(int j = 0; j < m; ++j)
            {
                int read = int(readrow[j]) - int('0');

                aux_row[i][read] += 1;
                aux_col[j][read] += 1;
                u[i][j] = read;
            }
        }

        Mat v(n, Row(m, 0));

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int num = u[i][j];
                v[i][j] = (aux_row[i][num] + aux_col[j][num])%10;
            } 
        }
            
        printMat(v);
        cout << endl;
    }
}