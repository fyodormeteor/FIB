/*  Count submatrices of sizes 1x9 and 9x1 which contain all digits 1, 2, ..., 9.
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Mat;

bool checkSubrow(Row row)
{
    sort(row.begin(), row.end());

    bool valid = true;
    for(int i = 0; i < 9; ++i)
    {
        if (i+1 != row[i]) valid = false;
    }

    return valid;
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        Mat mat(n, Row(m));
        int subrows = 0;
        int subcolumns = 0;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                char in;
                cin >> in;
                mat[i][j] = in - '0';
            }
        }

        //Check rows
        for(int i = 0; i < n; ++i)
        {
            Row last9(9, -1);
            for(int j = 0; j < m; ++j)
            {
                last9[j%9] = mat[i][j];
                if (checkSubrow(last9)) subrows++;
            }
        }
        
        //Check columns
        for(int j = 0; j < m; ++j)
        {
            Row last9(9, -1);
            for(int i = 0; i < n; ++i)
            {
                last9[i%9] = mat[i][j];
                if (checkSubrow(last9)) subcolumns++;
            }
        }

        cout << subrows << ' ' << subcolumns << endl;
    }
}