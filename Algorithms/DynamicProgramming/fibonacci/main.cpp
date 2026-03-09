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

int fibonacci_recursive(int n)
{
    if(n<=0) return 0;
    if(n==1) return 1;
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int fibonacci_dp(int n)
{
    ve_i v(n+1);

    v[0] = 0;
    v[1] = 1;

    for(int i=2; i<=n; i++)
        v[i] = v[i-1]+v[i-2];
    
    return v[n];
}

int fibonacci_dpM(ve_i& lookup, int n)
{
    if(lookup[n] == -1)
    {
            
        if (n <= 1)
                lookup[n] = n;
        else
            lookup[n] = fibonacci_dpM(lookup, n - 1) + fibonacci_dpM(lookup, n - 2);
    }
 
    return lookup[n];

}

void solve(int number)
{
    auto start = chrono::high_resolution_clock::now();
    
    cout << fibonacci_recursive(number) << "\n";

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Time elapsed recursive: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    cout << fibonacci_dp(number) << "\n";

    end = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Time elapsed DP: " << duration.count() << " microseconds" << endl;

    ve_i v(number+1, -1);

    start = chrono::high_resolution_clock::now();
    cout << fibonacci_dpM(v, number) << "\n";

    end = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Time elapsed DP Memoization: " << duration.count() << " microseconds" << endl;
}

int main(int argc, char** argv)
{
    solve(46);

    return 0;
}