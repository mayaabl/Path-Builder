#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

const int N = 100;

vector<int> adj[N];  // adjacency list representation of the graph
bool visited[N];
int d[N];  // d[u] is the discovery time of vertex u
int f[N];  // f[u] is the finish time of vertex u
int p[N];  // p[u] is the predecessor of vertex u in the DFS tree
int t;  // t is the time counter (discovery and finish times are based on t)

// DFS using iterative deepening
void dfs(int u) {
    stack<tuple<int, int>> s;
    s.emplace(u, 0);

    while (!s.empty()) {
        int u, i;
        tie(u, i) = s.top();
        s.pop();

        if (!visited[u]) {
            t++;
            d[u] = t;
            visited[u] = true;
            cout << "Discovering vertex " << u << " at time " << t << endl;
        }

        if (i < adj[u].size()) {
            int v = adj[u][i];
            if (!visited[v]) {
                p[v] = u;
                s.emplace(u, i + 1);
                s.emplace(v, 0);
            }
        }
        else {
            t++;
            f[u] = t;
            cout << "Finishing vertex " << u << " at time " << t << endl;
        }
    }
}

int main() {
    // assume that the graph has been constructed and stored in the adjacency list adj

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    return 0;
}
