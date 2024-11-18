// EDA Graph Algorithms
// Treasures in a map (3)

#include <iostream>
#include <vector>

using namespace std;

int dfs(int x, int y, int& n, int& m, vector<vector<char>>& map, vector<vector<bool>>& v)
{
    if (x < 0 or y < 0) return 0;
    if (x > m-1 or y > n-1) return 0;
    if (v[y][x] or map[y][x] == 'X') return 0;

    v[y][x] = true;

    int treasures_found = 0;

    treasures_found += dfs(x-1, y, n, m, map, v);
    treasures_found += dfs(x+1, y, n, m, map, v);
    treasures_found += dfs(x, y-1, n, m, map, v);
    treasures_found += dfs(x, y+1, n, m, map, v);
    
    if (map[y][x] == 't') treasures_found++;

    return treasures_found;
}

int main()
{
    int n, m;
    cin >> n >> m;  

    vector<vector<char>> map(n, vector<char>(m, '\0'));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int x, y;
    cin >> y >> x;
    
    x--;
    y--;

    int count = dfs(x, y, n, m, map, vis);

    cout << count << endl;
}
