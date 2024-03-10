/*  Patro recursiu
    21.02.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const char c = '#';
const char s = '.';

typedef vector<bool> Row;
typedef vector<Row> Mat;

void deduce(Mat& m, int x1, int y1, int x2, int y2)
{
    //base
    if (x1 == x2 and y1 == y2)
    {
        m[x1][y1] = true;
    }
    //recursive
    else
    {
        int xm = (x1+x2)/2;
        int ym = (y1+y2)/2;
        int next_size = ((x2-x1)+1)/2;
        
        // hacer la cruz
        m[xm][y1] = true;
        m[xm][y2] = true;
        m[x1][ym] = true;
        m[x2][ym] = true;

        //top-left
        deduce(m, x1, y1, x1+next_size-1, y1+next_size-1);

        //top-right
        deduce(m, xm+1, y1, xm+next_size, y1+next_size-1);

        //bottom-left
        deduce(m, x1, ym+1, x1+next_size-1, ym+next_size);

        //bottom-right
        deduce(m, xm+1, ym+1, xm+next_size, ym+next_size);
    }
}

int main()
{
    int n;
    cin >> n;
    int size = pow(2, n)-1;
    
    Mat m(size, Row(size, false));

    deduce(m, 0, 0, size-1, size-1);

    //imprimir mat

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if(m[i][j])
            {
                cout << c;
            }
            else
            {
                cout << s;
            }
        }
        cout << endl;
    }
}