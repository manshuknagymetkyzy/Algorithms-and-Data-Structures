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
    string s;
    cin >> s;
    vector<int> ans = prefix_function(s);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}