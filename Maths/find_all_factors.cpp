#include <bits/stdc++.h>
using namespace std;
vector<int> all_factors(int num){
    vector<int> res;
    for(int i=1;i<=sqrt(num);i++){
        if (num%i == 0){
            if (num/i == i){
                res.push_back(i);
            }
            else {
                res.push_back(i);
                res.push_back(num/i);
            }  
        }
    }
    return res;
}

int main(){
    vector<int> factors = all_factors(100);
    for(int x : factors){
        std::cout << x << " ";
    }
    std::cout << '\n';
}