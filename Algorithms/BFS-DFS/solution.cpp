#include <bits/stdc++.h>

using namespace std;

// --- Type Aliases ---
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;

// --- Macros ---
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

// Helper macros for vectors
#define pVI(data) { for(int d : data) cout << d << " "; cout << "\n"; }
#define sVI_a(data) sort(all(data))
#define sVI_d(data) sort(all(data), greater<int>())

// --- Constants ---
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ====================================================================
// APPROACH 1: Depth-First Search (DFS)
// Uses the Call Stack (Recursion) to go as deep as possible first.
// ====================================================================
bool dfs(int current, int target, const vector<vi>& adj, vector<bool>& visited) {
    if (current == target) return true;
    
    visited[current] = true;

    for (int neighbor : adj[current]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, target, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}

// ====================================================================
// APPROACH 2: Breadth-First Search (BFS)
// Uses a Queue to explore the graph layer by layer.
// ====================================================================
bool bfs(int start, int target, const vector<vi>& adj, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == target) return true;

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    // 1-indexed adjacency list
    vector<vi> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int start, target;
    cin >> start >> target;

#ifndef ONLINE_JUDGE
    auto t_start = chrono::high_resolution_clock::now();
#endif

    // --- Choose which algorithm to run here ---
    
    // Using BFS:
    bool possible = bfs(start, target, adj, n);

    // Using DFS (Uncomment to use instead):
    // vector<bool> visited(n + 1, false);
    // bool possible = dfs(start, target, adj, visited);

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

#ifndef ONLINE_JUDGE
    auto t_end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t_end - t_start);
    cerr << "Time elapsed: " << duration.count() << " microseconds\n"; 
#endif
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t; // Only one test case per file for this problem
    
    while(t--) {
        solve();
    }

    return 0;
}
