// EDA Graph Algorithms
// Treasures in a map (4)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs_max(int x_ini, int y_ini, int& n, int& m, vector<vector<char>>& map)
{
    int max_distance = -1;
    
    vector<vector<int>>  dis(n, vector<int> (m, -1));
    dis[y_ini][x_ini] = 0;

    queue<pair<int,int>> q;
    q.push(make_pair(x_ini,y_ini));

    while (!q.empty())
    {
        pair<int,int> current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        if (map[y][x] == 't')
        {
            if (dis[y][x] > max_distance) max_distance = dis[y][x];
        }

        // top
        if (y > 0 and dis[y-1][x] == -1 and map[y-1][x] != 'X')
        {
            dis[y-1][x] = dis[y][x] + 1;
            q.push(make_pair(x, y-1));
        }

        // bottom
        if (y < n-1 and dis[y+1][x] == -1 and map[y+1][x] != 'X')
        {
            dis[y+1][x] = dis[y][x] + 1;
            q.push(make_pair(x, y+1));
        }

        // left
        if (x > 0 and dis[y][x-1] == -1 and map[y][x-1] != 'X')
        {
            dis[y][x-1] = dis[y][x] + 1;
            q.push(make_pair(x-1, y));
        }

        // right
        if (x < m-1 and dis[y][x+1] == -1 and map[y][x+1] != 'X')
        {
            dis[y][x+1] = dis[y][x] + 1;
            q.push(make_pair(x+1, y));
        }
    }

    return max_distance;
}

int main()
{
    int n, m;
    cin >> n >> m;  

    vector<vector<char>> map(n, vector<char>(m, '\0'));

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

    int ret = bfs_max(x, y, n, m, map);

    if (ret == -1) cout << "no treasure can be reached" << endl;
    else cout << "maximum distance: " << ret << endl;
}
