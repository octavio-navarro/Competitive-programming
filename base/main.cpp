// This is a feature of the g++ compiler that allows us to include the entire standard library. Thus it is not needed to separately include libraries such as iostream, vector, algorithm, etc.
#include <bits/stdc++.h>

using namespace std;

using ve_i = vector<int>;
using se_i = set<int>;
using q_i = queue<int>;
using st_i = stack<int>;
using pa_i = pair<int, int>;
using ma_ii = map<int, int>;
using ma_si = map<string, int>;

#define pVI(data){ for(int d : data) cout << d << " "; cout << endl; }
#define sVI_a(data){ sort(data.begin(), data.end()); }
#define sVI_d(data){ sort(data.begin(), data.end(), greater<int>()); }

inline bool is_even(int n) { return n%2==0;};

void solve()
{
    int n, x;
    cin >> n >> x;

    ve_i v(n);

    for(int &e : v) cin >> e;

    auto start = chrono::high_resolution_clock::now();
    cout << n << " " << x << endl;
    pVI(v);
    sVI_a(v);
    pVI(v);
    sVI_d(v);
    pVI(v);

    vector<int>::iterator r = find(v.begin(), v.end(), 2);

    if(r != v.end())
        cout << *r << endl;
    else
        cout << "Not found" << endl;

    auto r2 = find_if(v.begin(), v.end(), [](int n) { return n%2==0;});

    if(r2 != v.end())
        cout << *r2 << endl;
    else
        cout << "No even found" << endl;

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