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

void pI(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i=0; i<count; i++) cout << va_arg(args, int) << " ";
    va_end(args);
    cout << endl;
}

void closestSum(ve_i f, ve_i s, int sum)
{
    int i = 0, j = f.size()-1;
    int diff = 2147483647;
    int r1 = 0, r2 = 0;

    while(i < f.size() && j >= 0)
    {
        int ts = (f[i]+s[j]);
        int t = abs(sum - ts);
        
        if(t < diff)
        {
            diff = t;
            r1 = i; 
            r2 = j;
        }
        
        if(ts > sum)
            j--;
        else if(ts < sum)
            i++;
    }

    pI(2, f[r1], s[r2]);
    // pVI(ve_i({f[r1], s[r2]}));
}

void solve()
{
    int n, s;
    cin >> n;

    ve_i v1(n);
    ve_i v2(n);

    for(int &e : v1) cin >> e;
    for(int &e : v2) cin >> e;

    cin >> s;

    closestSum(v1, v2, s);
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