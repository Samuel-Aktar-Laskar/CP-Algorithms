#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vl vector<ll>
#define forn(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
const ll N=1e5+5;


vl tree[5*N];
ll arr[N];

/**
 * Given array arr and several queries of type l,r,k where you have to find the number of elements smaller or equal to
 * k in range l to r.
 * 
 * It is same as segment tree with the difference that each node in the tree contains vector instead of number. 
 * That vector is sorted array of corresponding segment subarray. 
 * 
 * The tree formed is very similar to tree formed in merge sort, therefore called merge sort tree. 
*/

void build(ll node, ll l, ll r){
    if (l == r){
        tree[node] = {arr[l]};
        return;
    }
    ll mid = (l+r)/2;
    ll left = 2*node+1;
    ll right = 2*node+2;
    build(left, l, mid);
    build(right,mid+1,r);
    tree[node].resize(tree[left].size() + tree[right].size());
    merge(all(tree[left]), all(tree[right]), tree[node].begin());
}

ll query(ll node, ll l, ll r, ll ql, ll qr, ll k){
    if (qr < l || ql > r){
        return 0;
    }
    if (ql <= l && r <= qr){
        return upper_bound(all(tree[node]),k) - tree[node].begin();
    }
    ll mid = (l+r)/2;
    return query(2*node+1,l,mid,ql,qr,k) + query(2*node+2,mid+1,r,ql,qr,k);
}


int main(){
    vl tmp = {2,3,4,5,7,8,2,5};
    forn(i,tmp.size()) arr[i+1] = tmp[i];
    build(0,1,tmp.size());
    for(auto x : tree[0]){
        cout << x <<  " ";
    }
    cout << endl;
    ll n = tmp.size();
    cout << query(0,1,n,1,3,3) << endl;
    cout << query(0,1,n,1,5,8) << endl;
    cout << query(0,1,n,3,7,5) << endl;
}
