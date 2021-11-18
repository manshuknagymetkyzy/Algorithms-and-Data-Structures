#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s){
    vector<int> pi(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int main(){
    string s, t;
    cin >> s >> t;
    vector<int> ans = prefix_function(s + '#' + t + t);
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == s.size()){
            cout << i - 2*s.size();
            return 0;
        }
    }
    cout << -1;
}
