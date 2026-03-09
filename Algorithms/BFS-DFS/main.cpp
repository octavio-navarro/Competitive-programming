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

void solve() {
    // 1. Read N (nodes) and M (edges)
    
    // 2. Build your adjacency list to represent the graph
    // Hint: vector<vector<int>> adj(N + 1); is a good start for 1-indexed nodes.

    // 3. Read the edges and populate the adjacency list

    // 4. Read S (Start node) and T (Target node)

    // Local timing start
#ifndef ONLINE_JUDGE
    auto t_start = chrono::high_resolution_clock::now();
#endif

    // --- YOUR BFS/DFS LOGIC GOES HERE ---
    // Hint: Don't forget a 'visited' array or set to avoid infinite loops!
    
    // Print "YES\n" if you can reach T from S, otherwise "NO\n"
    

    // --- END LOGIC ---

    // Local timing end
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
