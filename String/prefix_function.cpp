#include <bits/stdc++.h>
using namespace std;

/** 
 * link :https://cp-algorithms.com/string/prefix-function.html
 * p[i] gives length of longest proper prefix which is also suffix.
 * proper prefix means prefix which is not the string itself.
 * pi is called prefix function
 * */

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j>0 && s[j] != s[i]){
            j = pi[j-1];
        }
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

//Knuth Morris Pratt algorithm
