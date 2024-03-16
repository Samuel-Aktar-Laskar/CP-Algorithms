#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll peakMountain(vector<ll>& arr){
    ll left = 0, right = arr.size()-1,mid;
    while(left < right){
        mid = (left+right)/2;
        if (arr[mid] < arr[mid+1]){
            left = mid+1;
        }
        else right = mid;
    }
    return left;
}

