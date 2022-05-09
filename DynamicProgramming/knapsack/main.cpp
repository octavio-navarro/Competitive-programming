// This is a feature of the g++ compiler that allows us to include the entire standard library. Thus it is not needed to separately include libraries such as iostream, vector, algorithm, etc.
#include <bits/stdc++.h>

using namespace std;

using ve_i = vector<int>;
using se_i = set<int>;
using pa_i = pair<int, int>;
#define pVI(data){ for(int d : data) cout << d << " "; cout << endl; }

int knapSackM(int W, ve_i w, ve_i v, int n, vector<vector<int>> &weightTable)
{
    if(n == 0 || W == 0) return 0; // Si no hay más espacio o si no hay más objetos
    if(weightTable[n-1][W] != 0) return weightTable[n-1][W];
    
    // si me paso del peso, checo los otros objetos
    if(w[n-1] > W) 
    {
        weightTable[n-1][W] = knapSackM(W, w, v, n-1, weightTable); 
        return weightTable[n-1][W];
    }
    // Revisar cuál de las dos opciones de más valor
    else
    {
        weightTable[n-1][W] = max(
            v[n-1] + knapSackM(W - w[n-1], w, v, n-1, weightTable),
            knapSackM(W, w, v, n-1, weightTable));
        return weightTable[n-1][W];
    }
}

int knapSack(int W, ve_i w, ve_i v, int n)
{
    if(n == 0 || W == 0) 
        return 0; // Si no hay más espacio o si no hay más objetos
    
    // si me paso del peso, checo los otros objetos
    if(w[n-1] > W) 
        return knapSack(W, w, v, n-1); 
    // Revisar cuál de las dos opciones de más valor
    else
        return max(
            // Agregar el objeto n
            v[n-1] + knapSack(W - w[n-1], w, v, n-1),
            // No agregar el objeto n
            knapSack(W, w, v, n-1)
        );
}

void solve()
{
    int W, n;
    cin >> W >> n;

    ve_i v(n);
    ve_i w(n);

    vector<vector<int>> weightTable(n+1, vector<int>(W+1));

    for(int &e : w) cin >> e;
    for(int &e : v) cin >> e;

    cout << W << " " << n << endl;
    pVI(v);
    pVI(w);

    cout << "Max value: " << knapSack(W, w, v, n) << endl;
    cout << "Max value M: " << knapSackM(W, w, v, n, weightTable) << endl;
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