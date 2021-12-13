#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    public:
    Node *root;
    BST(){
        root = NULL;
    }

    Node *insert(Node *node, int data){
        if(node == NULL){
            node = new Node(data);
            return node;
        }
        if(data <= node->data){
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right, data);
        }
        return node;
    }

    Node *search(Node *node, int data){
        if(node == NULL || node->data == data)
            return node;
        if(node->data < data)
            search(node->right, data);
        else 
            search(node->left, data);
    }
    void inOrder(Node *node){
        if(node == NULL)
            return;
        inOrder(node->left);
        cout << node->data;
        inOrder(node->right);
    }

    Node *findMin(Node *node){
        while(node->left != NULL)
            node = node->left;
        return node;
    }

    Node *findMax(Node *node){
        while(node->right != NULL)
            node = node->right;
        return node;
    }

    Node *deleteNode(Node *node, int data) {
        if(node == NULL)
            return NULL;
        if(data < node->data)
            node->left = deleteNode(node->left, data);
        else if(data > node->data)
            node->right = deleteNode(node->right, data)
        else{
            if(node->left == NULL && node->right == NULL) 
                return NULL;
            else if(root->left == NULL) {
                node = node->right;
                return node;
            }
        }
    }
}

int main() {
    return 0;
}
