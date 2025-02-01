#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

typedef vector<int> Node;
typedef vector<Node> Graph;

void topo(const Graph& G, list<int>& sol, int n) {
    vector<int> dg(n, 0);
    for (Node n : G) {
        for (int e : n) {
            dg[e]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        if (dg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int top = q.top();
        q.pop();
        sol.push_back(top);

        for (int e : G[top]) {
            if (--dg[e] == 0) q.push(e);
        }
    }
}

void print_sol(const list<int>& l) {
    auto it = l.begin();
    while (it != l.end()) {
        cout << *it;
        it++;
        if (it != l.end()) cout << ' ';
        else cout << endl;
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph g(n, Node());
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
        }

        list<int> sol;
        topo(g, sol, n);
        print_sol(sol);
    }
}