#include <iostream>
using namespace std;
int main(){
    int s, t;
    cin >> s >> t;
    int n = s.size();
    vector<long long> p_pow(n);
    int p = 31;
    p_pow[0] = 1;
    for(int i = 1; i < n; i++){
        p_pow[i] = p_pow[i - 1] * p;
    }
    long long ht = 0;
    for(int i = 0; i < t.size(); i++){
        ht += (t[i] - 96) * p_pow[i];
    }
    vector<long long> hs(n);
    for(int i = 0; i < n; i++){
        hs[i] = (s[i] - 96) * p_pow[i];
        if(i > 0) hs[i] += hs[i - 1];
    }
    for(int i = 0; i + t.size() - 1 < n; i++){
        long long cur = hs[i + t.size() - 1];
        if(i > 0) cur -= hs[i - 1];
        if(ht * p_pow[i] == cur){
            cout << i << " ";
        }
    }
}
