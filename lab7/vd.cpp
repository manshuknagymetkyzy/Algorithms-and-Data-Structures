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
    int t;
    cin >> t;
    string a, b;
    for(int i = 0; i < t; i++){
        int cnt = 0;
        cin >> a >> b;
        vector<int> ans = prefix_function(b + '#' + a);
        for(int j = 0; j  < ans.size(); j++){
            if(ans[j] == b.size()){
                cnt++;
            }
        }
        if(cnt){
            cout << cnt << endl;
            for(int k = 0; k < ans.size(); k++){
                if(ans[k] == b.size()) cout << k - 2*b.size() + 1 << " ";
            }
        }
        else cout << "Not Found" << endl;
    }
}