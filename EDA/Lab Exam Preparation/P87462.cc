#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<char>    Row;
typedef vector<Row>     Grid;
typedef pair<int,int>   Pos;

char get_grid(const Grid& g, Pos& p) {
    return g[p.first][p.second];
}

int get_dis(const vector<vector<int>>& dis, Pos& p) {
    return dis[p.first][p.second];
}

void visit(vector<vector<int>>& dis, Pos& p, int set) {
    dis[p.first][p.second] = set;
}

bool is_visited(vector<vector<int>>& dis, Pos& p) {
    return (dis[p.first][p.second] != -1);
}

bool is_valid_grid_pos(Pos p, int r, int c) {
    return (p.first > 0 and p.first < r and p.second > 0 and p.second < c);
}

bool is_close_to_ghost(const Grid& g, Pos p, int r, int c) {
    for (Pos d : {Pos(-1,0), Pos(-1,1), Pos(0,1), Pos(1,1), Pos(1,0), Pos(1,-1), Pos(0,-1), Pos(-1,-1)}) {
        Pos i = Pos(p.first+d.first, p.second+d.second);
        if (is_valid_grid_pos(i, r, c) and get_grid(g, i) == 'F') return true;
    }
    return false;
}

bool bfs_pellet(const Grid& g, Pos ini, int r, int c) {
    vector<vector<int>> dis(r, vector<int>(c, -1));
    queue<Pos> q;
    
    visit(dis, ini, 0);
    q.push(ini);

    while (!q.empty()) {
        Pos current = q.front();
        int current_dis = get_dis(dis, current);
        q.pop();

        // Bad cases
        if (!is_valid_grid_pos(current, r, c)) continue;
        if (get_grid(g, current) == 'X') continue;
        if (is_close_to_ghost(g, current, r, c)) continue;

        // Good case
        if (get_grid(g, current) == 'B') return true;

        for (Pos d: {Pos(-1, 0), Pos(1, 0), Pos(0, -1), Pos(0, 1)}) {
            Pos next = Pos(current.first+d.first, current.second+d.second);
            if (is_visited(dis, next)) continue;
            visit(dis, next, current_dis+1);
            q.push(next);
        }
    }
    return false;
}

int main() {
    int r, c;
    while (cin >> r >> c) {
        Grid g(r, Row(c, '.'));
        Pos ini(0, 0);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                char c;
                cin >> c;
                g[i][j] = c;
                if (c == 'P') ini = Pos(i, j);
            }
            
        if (bfs_pellet(g, ini, r, c)) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}