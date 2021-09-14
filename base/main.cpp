// This is a feature of the g++ compiler that allows us to include the entire standard library. Thus it is not needed to separately include libraries such as iostream, vector, algorithm, etc.
#include <bits/stdc++.h>

using namespace std;

using ve_i = vector<int>;
using se_i = set<int>;
using pa_i = pair<int, int>;

void solve()
{
    int n, x;
    cin >> n >> x;

    ve_i v(n);

    for(int &e : v) cin >> e;

    auto start = chrono::high_resolution_clock::now();
    cout << n << " " << x << endl;
    for(int &e : v) cout << e << endl;
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);

    cout << "Time elapsed: " << duration.count() << " microseconds" << endl;
}

int main(int argc, char** argv)
{
    int t;

    cin >> t;
    
    while(t--)
    {
        solve();
    }

    return 0;
}