#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vvl vector<vector<ll>>
#define vvc vector<vector<char>>
#define vvpll vector<vector<pair<ll,ll>>>
#define vc vector<char>
#define vl vector<ll>
#define vvb vector<vector<bool>> 
#define vb vector<bool>
#define pb push_back
#define umap unordered_map
#define pll pair<ll,ll>
#define INF 1e9
#define forn(i,n) for(ll i=0;i<n;i++)
#define input(arr) for(auto& x : arr) cin >> x;
#define rep(n) for(int i_99=n;i_99>0;i_99--)
#define all(v) v.begin(), v.end()
#ifdef LOCAL_RUN
#define Error(x...) {cout << "(" << #x << ")" << " = ( " ; printIt(x); }
#else
#define Error(x...) 42
#endif
const ld pi=3.14159265359;
const ll e5=1e5;
const ll e6=1e6;
const ll e9=1e9;
const ll inf=1e18;
const ll mod=1e9+7;
const ll mod2=998244353;
const ll N=1e5+5;
template <typename T1> void printIt(T1  t1){cout << t1 << ")" << endl;}
template <typename T1, typename... T2> void printIt(T1 t1, T2... t2){cout << t1 << " , "; printIt(t2...);}

    


vector<pll> adj[N];
ll D[N], P[N];
bool U[N];

void dijkstra(ll s, ll n){
    for(ll i=1;i<=n;i++){
        D[i] = inf;
        U[i] = false;
    }

    D[s] = 0;
    for(ll i=1;i<=n;i++){
        ll v = -1;
        for(ll j=1;j<=n;j++){
            if (v == -1 || D[j] < D[v]){
                v = j;
            }
        }
        if (D[v] == inf) 
            break;
        U[v] = true;
        for(auto edge : adj[v]){
            ll to = edge.first;
            ll w = edge.second;

            if (D[v] + w < D[to]){
                D[to] = D[v] + w;
                P[to] = v;
            }
        }
    }
}



int main(){
    //TODO testing
}


