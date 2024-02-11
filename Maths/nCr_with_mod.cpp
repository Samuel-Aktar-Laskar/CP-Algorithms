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

const int N = 2000001;
int fact[N];

void init(){
    fact[0] = 1;
    for(long long i=1;i<N;i++){
        fact[i] = (i*fact[i-1])%mod;
    }
}

long long nCr(long long n, long long r){
    long long res = (fact[n]*mod_inverse(fact[r]))%mod;
    res = (res*mod_inverse(fact[n-r]))%mod;
    return res;
}

int main(){
    init();
    std::cout << nCr(600000,3) << '\n';
    return 0;
}