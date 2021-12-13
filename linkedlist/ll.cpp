#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class LinkedList{
    Node *head;
    public:
    LinkedList(){
        head = NULL;
    }

    void push_front(int val){
        Node *node = new Node(val);
        node->next = head;
        head = node;
    }

    void push_back(int val){
        Node *node = new Node(val);
        if(head == NULL){
            head = node;
            return;
        }
        Node *last = head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = node;
        return;
    }

    void print(){
        Node *cur = head;
        while(cur != NULL){
            cout << cur->data << " ";
            cur = cur->next;
        }
    }

    void pop_back(){
        if(head == NULL) 
            return;
        else if(head->next == NULL){
            head = NULL;
            return;
        }
        Node *last = head;
        while(last->next->next != NULL){
            last = last->next;
        }
        last->next = NULL;
        return;
    }

    void pop_front(){
        if(head == NULL)
            return;
        head = head->next;
        return;
    }
};

int main(){
    LinkedList list;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        list.push_back(x);
    }
    list.print();
    list.pop_back();
    cout << endl;
    list.print();
    list.pop_front();
    list.print();
}