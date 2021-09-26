#include <iostream>

using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    public:
    Node *top;
    int sz;

    Stack(){
        top = NULL;
        sz = 0;
    }
    
    void push(int data){
        Node *node = new Node(data);
        node->next = top;
        top = node;
        sz++;
    }

    void pop(){
        top = top->next;
        sz--;
    }
};

int main(){
    Stack *st = new Stack();
    string str;
    int n;
    while(cin >> str){
        if(str == "push"){
            cin >> n;
            st->push(n);
            cout << "ok\n";
        } 

        else if (str == "pop"){
            if (st->sz != 0){ 
                cout << st->top->data << endl;
                st->pop();
            }
            else cout << "error\n"; 
        }

        else if (str == "back"){
            if (st->sz != 0) cout << st->top->data << endl;
            else cout << "error\n";
        }

        else if (str == "size") cout << st->sz << endl;

        else if (str == "clear"){
            while (st->sz != 0){
                st->pop();
            }
            cout << "ok" << endl;
        }

        else if (str == "exit") {
            cout << "bye\n";
            return 0;
        }
    }
    return 0;
}