// This is a feature of the g++ compiler that allows us to include the entire standard library. Thus it is not needed to separately include libraries such as iostream, vector, algorithm, etc.
#include <bits/stdc++.h>

using namespace std;

// Given a sorted array A (sorted in ascending order), having N integers, find if there exists any pair of elements (A[i], A[j]) such that their sum is equal to X.

using ve_i = vector<int>;
using se_i = set<int>;
using pa_i = pair<int, int>;

bool pairIsNumNaive(ve_i data, int sum)
{
    for(int i = 0; i<data.size(); i++)
    {
        for(int j = data.size(); j > 0; j--)
        {
            if(i==j)
                continue;
            if(data[i]+data[j]==sum)
                return 1;   
        }
    }
    return 0;
}

bool pairIsNumTwoPointers(ve_i data, int sum)
{
    int i = 0, j = data.size()-1;

    while(i < j)
    {
        if(data[i]+data[j]==sum)
            return 1;   
        else if(data[i]+data[j] < sum)
            i++;
        else
            j--;
    }

    return 0;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    ve_i v(n);

    for(int &e : v) cin >> e;
    
    // cout << n << " " << x << endl;
    // for(int &e : v) cout << e << endl;

    auto start = chrono::high_resolution_clock::now();
    cout << pairIsNumNaive(v, x) << endl;
    // cout << pairIsNumTwoPointers(v, x) << endl;
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