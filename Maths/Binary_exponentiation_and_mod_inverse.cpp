#include <bits/stdc++.h>

const int mod = 1e9+7;

long long binpow(long long a, long long b){
    long long res = 1;
    while(b>0){
        if (b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b = (b>>1);
    }
    return res;
}

long long mod_inverse(long long a){
    return binpow(a,mod-2);
}

int main(){
}
