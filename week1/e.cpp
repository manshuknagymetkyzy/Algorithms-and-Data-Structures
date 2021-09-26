#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> first(5);
    deque<int> second(5);
    for (int i = 0; i < 5; i++){
        cin >> first[i];
    }
    for (int i = 0; i < 5; i++){
        cin >> second[i];
    }
    int cnt = 1;
    while (cnt < 1e6){
        if (first.front() == 0 && second.front() == 9){
            first.push_back(first.front());
            first.push_back(second.front());
            first.pop_front();
            second.pop_front();
        }
        else if (first.front() == 9 && second.front() == 0){
            second.push_back(first.front());
            second.push_back(second.front());
            first.pop_front();
            second.pop_front();
        }
        else if (first.front() > second.front()){
            first.push_back(first.front());
            first.push_back(second.front());
            first.pop_front();
            second.pop_front();
        }
        else if (first.front() < second.front()){
            second.push_back(first.front());
            second.push_back(second.front());
            first.pop_front();
            second.pop_front();
        }
        if(first.size() == 0){
            cout << "second " << cnt;
            return 0;
        }
        else if(second.size() == 0){
            cout << "first " << cnt;
            return 0;
        }
        cnt++;
    }
    cout << "botva";

    return 0;
}