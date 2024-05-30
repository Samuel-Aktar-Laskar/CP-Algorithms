#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define mp make_pair

const ll N = 1001;
const ll inf = 1e18;


#ifdef LOCAL_RUN
#define Error(x...) {cout << "(" << #x << ")" << " = ( " ; printIt(x); }
#else
#define Error(x...) 42
#endif
template <typename T1> void printIt(T1  t1){cout << t1 << ")" << endl;}
template <typename T1, typename... T2> void printIt(T1 t1, T2... t2){cout << t1 << " , "; printIt(t2...);}

    




/**
 * Maximum flow: Ford Fulkersen and Edmords Karp
 * Reference :https://cp-algorithms.com/graph/edmonds_karp.html
*/

/**
 * Network: It's a directed graph G with vertices V and edges E combined with function c, which assigns each 
 * edge e \in E a non-negative integer value, the capacity of e. 
 * 
 * Flow Network: In a network, if we additionally label two vertices, one as source and one as sink, it becomes flow network.
 * 
 * Flow: A flow in a network is a function f which assigns each edge a non negative interger value, namely the 
 * flow. 
 * The flow can not exceed the capacity f(e) <= c(e)
 * The sum of incoming flow should be equal to sum of outgoing flow except for source and sink. 
*/

vll adj[N];
ll capacity[N][N],n,e, s,t, parent[N]; // capacity, no of vertices, no of edges, source and sink

ll bfs(){
    memset(parent,-1,sizeof(parent));
    parent[s] = -2;
    queue<pll> q;
    q.push({s,inf});

    while(!q.empty()){
        auto item = q.front();
        q.pop();
        ll cur = item.first;
        ll flow = item.second;
        for(ll child: adj[cur]){
            if (capacity[cur][child] == 0 || parent[child] != -1) continue;
            parent[child] = cur;
            ll new_flow = min(flow, capacity[cur][child]);
            if (child == t){
                return new_flow;
            }
            q.push({child, new_flow});
        }
    }
    return 0;
}

ll maxFlow(){
    ll flow = 0;

    ll new_flow;
    while(new_flow = bfs()){
        Error(new_flow);
        flow += new_flow;

        ll node = t;
        while(node != s){
            ll prev = parent[node];
            Error(prev);
            capacity[prev][node] -= new_flow;
            capacity[node][prev] += new_flow;
            node = prev;
        }
    }
    return flow;
}



int main(){
    ios::sync_with_stdio(false);
    freopen("flow_inp.txt", "r", stdin);
    memset(adj,0,sizeof(adj));
    memset(capacity,0,sizeof(capacity));
    cin >> n >> e >> s >> t;

    for(ll i=1;i<=e;i++){
        ll u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] = c;
    }

    ll mx_flow = maxFlow();

    cout <<"Printing capacity" << endl;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cout << capacity[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << mx_flow << endl;

}