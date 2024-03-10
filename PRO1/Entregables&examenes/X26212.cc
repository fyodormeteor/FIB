/*  Happy words in a matrix
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<vector>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Matrix;

// Pre:
// Post: returns amount of " :-) " and " (-: " subwords contained in the matrix
int horizontalHappyWords(const Matrix& mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int happy_words = 0;
    char c1, c2, c3;

    for(int i = 0; i < m; ++i)
    {
        c1 = c2 = c3 = ' ';
        for(int j = 0; j < n; ++j)
        {
            c1 = c2;
            c2 = c3;
            c3 = mat[i][j];

            if (c2 == '-')
            {
                if ((c1 == ':') and (c3 == ')'))        happy_words++; 
                else if ((c1 == '(') and (c3 == ':'))   happy_words++;
            }
        }
    }
    return happy_words;
}

// Pre:
// Post: returns amount of " " " and " ^ " subwords contained in the matrix
//                           |         |    
//                           v         "
int verticalHappyWords(const Matrix& mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int happy_words = 0;
    char c1, c2, c3;
    c1 = c2 = c3 = ' ';

    for(int i = 0; i < n; ++i)
    {
        c1 = c2 = c3 = ' ';
        for(int j = 0; j < m; ++j)
        {
            c1 = c2;
            c2 = c3;
            c3 = mat[j][i];

            if (c2 == '|')
            {
                if ((c1 == '"') and (c3 == 'v'))        happy_words++;
                else if ((c1 == '^') and (c3 == '"'))   happy_words++;
            }
        }
    }

    return happy_words;
}

int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        Matrix input(m, Row(n));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cin >> input[i][j];
            }
        }

        int happy_words = horizontalHappyWords(input) + verticalHappyWords(input);
        cout << happy_words << endl;
    }
}