#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<string> deq9;
    deque<string> deq10;
    deque<string> deq11;
    string s;
    int n;
    while (cin >> n){
        cin >> s;
        if (n == 9){
            deq9.push_back(s);
        }
        else if (n == 10){
            deq10.push_back(s);
        }
        else{
            deq11.push_back(s);
        }
    }

    for (int i = 0; i < deq9.size(); i++){
        cout << 9 << " " << deq9[i] << endl;
    }
    for (int i = 0; i < deq10.size(); i++){
        cout << 10 << " " << deq10[i] << endl;
    }
    for (int i = 0; i < deq11.size(); i++){
        cout << 11 << " " << deq11[i] << endl;
    }
    return 0;
}