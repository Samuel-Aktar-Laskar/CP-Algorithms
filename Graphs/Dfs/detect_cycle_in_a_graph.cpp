#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5+1;
ll clr[N];
vector<vector<ll>> adj;

bool dfs(int node){
    clr[node] = 1;
    for(ll child : adj[node]){
        if (clr[child] == 0){
            if (dfs(child)) 
                return true;
        }
        else if (clr[child] == 1){
            return true;
        }
    }
    clr[node] = 2;
    return false;
}


int main(){
    
}
