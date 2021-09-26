#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool open = false;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            open = true;
        }else if((s[i] == ')' || s[i] == ']' || s[i] == '}') && open == false){
            cout << "no";
            return 0;
        }
    }
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else if ((s[i] == ')' || s[i] == ']' || s[i] == '}') && st.empty()){
            cout << "no";
            return 0;
        }
        else if(s[i] == ')' && st.top() == '(' || s[i] == ']' && st.top() == '[' || s[i] == '}' && st.top() == '{'){
            st.pop();
        }
        else{
            cout << "no";
            return 0;
        }
    }
    if(st.empty()) cout << "yes";
    else cout << "no";
}