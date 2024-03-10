/*  Implementacion de algoritmo DFS estudiado en Matematicas 1
    03.03.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef vector<int> Vertices;
typedef vector<Vertices> AdjList;

// Pre: input consists of the order of the graph int(n) followed by n lines of adjacencies. Each line ends with a '.'
//      Vertices are named 'a'-'z' with 'a' corresponding to index 0 of the adjacency list.
//
AdjList loadAdjacencyList()
{
    int n;
    cin >> n;
    
    AdjList al(n, Vertices(n-1,-1));

    for (int i = 0; i < n; ++i)
    {
        char c;
        int j = 0;
        while(cin >> c and c != '.')
        {
            al[i][j] = c - 'a';
            j++;
        }
    }

    return al;
}

//
//
void printAdjacencyList(AdjList& al)
{
    int size = al.size();
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size-1; j++)
        {
            char c = 'a'+al[i][j];
            cout << c << ' ';
        }
        cout << endl;
    }
}

//
//
void printVertices(Vertices& v)
{
    int size = v.size();
    for(int i = 0; i < size; ++i)
    {
        char c = 'a'+v[i];
        cout << c << ' ';
    }
    cout << endl;
}

// Pre: input consists of the adjacency list followed by the starting vertex u
// Post: list w contains all vertices in the connected compontent of u. w is printed.
int main()
{
    AdjList al = loadAdjacencyList();
    char _u;
    cin >> _u;
    int u = _u-'a';

    Vertices w(0);
    stack<int> p;
    p.push(u);

    while(!p.empty())
    {
        int x = p.top();
        int y;
        int i = 0;
        bool found = false;
        bool stop = false;
        while (!found and !stop)
        {
            y = al[x][i++];

            if (y != -1)
            {
                // is y already in w?
                bool y_in_w = false;
                for(int j = 0; j < w.size(); ++j)
                {
                    if (y == w[j]) y_in_w = true;
                }

                if (!y_in_w) found = true;
            }
            else stop = true;
        }

        if (found)
        {
            p.push(y);
            w.push_back(y);
        }
        else
        {
            p.pop();
        }
    }

    printVertices(w);
}