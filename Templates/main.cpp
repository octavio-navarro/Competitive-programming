// This is a feature of the g++ compiler that allows us to include the entire
// standard library. Thus it is not needed to separately include libraries such
// as iostream, vector, algorithm, etc.
#include <bits/stdc++.h>

using namespace std;

// Define is handled by the preprocessor (blind text replacement), while using
// is handled by the compiler (understands types, scope, and syntax).

// --- Type Aliases ---
// Saves typing time during contests
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using sei = set<int>;
using qi = queue<int>;
using sti = stack<int>;
using mii = map<int, int>;
using msi = map<string, int>;

// --- Macros ---
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

#define pVI(data)                                                              \
  {                                                                            \
    for (int d : data)                                                         \
      cout << d << " ";                                                        \
    cout << endl;                                                              \
  }
#define sVI_a(data)                                                            \
  {                                                                            \
    sort(all(data));                                                           \
  }
#define sVI_d(data)                                                            \
  {                                                                            \
    sort(all(data), greater<int>());                                           \
  }

// --- Constants ---
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

bool is_even(int n) { return n % 2 == 0; };

void template_test() {
  int n, x;
  cin >> n >> x;

  vi v(n);

  for (int &e : v)
    cin >> e;

  auto start = chrono::high_resolution_clock::now();
  cout << n << " " << x << endl;
  pVI(v);
  sVI_a(v);
  pVI(v);
  sVI_d(v);
  pVI(v);

  vector<int>::iterator r = find(all(v), 2);

  if (r != v.end())
    cout << *r << endl;
  else
    cout << "Not found" << endl;

  auto r2 = find_if(all(v), [](int n) { return n % 2 == 0; });

  if (r2 != v.end())
    cout << *r2 << endl;
  else
    cout << "No even found" << endl;

  auto end = chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

  cout << "Time elapsed: " << duration.count() << " microseconds" << endl;
}

void solve() { template_test(); }

int main(int argc, char **argv) {
  // --- Fast I/O ---
  // This is the most important part of the template. It prevents
  // Time Limit Exceeded (TLE) errors when reading large inputs.
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;

  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
