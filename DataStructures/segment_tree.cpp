#include <bits/stdc++.h>
using namespace std;


int seg[100000];


int build_tree(int node, int l, int r, vector<int>& arr){
    if (l==r){
        return seg[node] = arr[l];
    }
    int left_child = 2*node+1;
    int right_child = 2*node+2;
    int mid = (l+r)/2;
    return seg[node] = build_tree(left_child, l, mid, arr) + build_tree(right_child, mid+1, r, arr);
}


int query(int node, int l, int r, int ql, int qr){
    if (ql <= l && qr >= r) return seg[node]; // segment lies inside query range
    if (ql > r || qr < l) return 0; // segment does not overlap with query range
    int left_child = 2*node+1;
    int right_child = 2*node+2;
    int mid = (l+r)/2;
    return query(left_child, l, mid, ql, qr) + query(right_child, mid+1, r, ql, qr);
}


void update(int node, int l, int r, int index, int incre){
    if (index >=l && index <= r)seg[node] += incre;
    else return;
    if (l==r) return;
    int left_child = 2*node+1;
    int right_child = 2*node+2;
    int mid = (l+r)/2;
    update(left_child, l, mid, index, incre);
    update(right_child, mid+1, r, index, incre);
}


int main(){
    
}