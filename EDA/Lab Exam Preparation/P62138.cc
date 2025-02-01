#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef vector<int> Node;
typedef vector<Node> Graph;

void print_sol(const list<int>& l) {
    auto it = l.begin();
    while (it != l.end()) {
        cout << *it;
        it++;
        if (it != l.end()) cout << ' ';
        else cout << endl;
    }
}

void topo(const Graph& G, list<int>& sol, vector<int>& dg, vector<bool>& used, int k, int n) {
    if (k == n) {
        print_sol(sol);
        return;
    }

    for(int i = 0; i < n; i++) {
        if (dg[i] == 0 and !used[i]) {
            used[i] = true;
            sol.push_back(i);
            for (int e: G[i]) {
                dg[e]--;
            }

            topo(G, sol, dg, used, k+1, n);

            used[i] = false;
            sol.pop_back();
            for (int e: G[i]) {
                dg[e]++;
            }
        }
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

        vector<int> dg(n, 0);
        for (Node n : g) {
            for (int e : n) {
                dg[e]++;
            }
        }

        vector<bool> used(n, false);
        list<int> sol;
        topo(g, sol, dg, used, 0, n);
    }
}