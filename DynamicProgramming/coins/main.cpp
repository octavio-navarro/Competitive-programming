// This is a feature of the g++ compiler that allows us to include the entire standard library. Thus it is not needed to separately include libraries such as iostream, vector, algorithm, etc.
#include <bits/stdc++.h>

using namespace std;

using ve_i = vector<int>;
using se_i = set<int>;
using pa_i = pair<int, int>;
using ma_i = map<int, int>;

#define pVI(data){ for(int d : data) cout << d << " "; cout << endl; }
// void pVI(ve_i data){ for(int d : data) cout << d << " "; cout << endl; }

// Memoization
int coinsDpM(ve_i coinValues, int target, ma_i &values)
{
    if(target < 0) return INT8_MAX;
    if(target == 0) return 0;
    if(values.find(target) != values.end()) return values[target];

    int best = INT8_MAX;

    for(int coinValue : coinValues)
        best = min(best, coinsDpM(coinValues, target-coinValue, values) + 1);

    values[target] = best;
    return best;
}

int coinsDP(ve_i coinValues, int target)
{
    if(target < 0) return INT8_MAX;
    if(target == 0) return 0;
    
    int best = INT8_MAX;

    for(int coinValue : coinValues)
        best = min(best, coinsDP(coinValues, target-coinValue) + 1);

    return best;
}

void solve()
{
    int target, n;
    cin >> target >> n;

    ve_i v(n);

    for(int &e : v) cin >> e;

    ma_i values;

    cout << target << " " << n << " " << endl;
    pVI(v);
    auto start = chrono::high_resolution_clock::now();
    cout << "Optimum coins DP: " << coinsDP(v, target) << endl;
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Time elapsed: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    cout << "Optimum coins DP M: " << coinsDpM(v, target, values) << endl;
    end = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(end-start);
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