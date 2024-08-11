#include <iostream>

#include <climits>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;

    // constructor
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void preOrder(Node* a){

    if(a == NULL) return; // base case
    cout<<a->val<<" "; // work
    preOrder(a->left); // call1
    preOrder(a->right); //call2
}

void inOrder(Node* a){

    if(a == NULL) return; // base case
    
    inOrder(a->left);
    cout<<a->val<<" ";
    inOrder(a->right);
}
void postOrder(Node* a){

    if(a == NULL) return; // base case
    
    postOrder(a->left);
    postOrder(a->right);
    cout<<a->val<<" ";
}
int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
   

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
   

    preOrder(a);
    cout<<endl;
    inOrder(a);
    cout<<endl;
    postOrder(a);
    cout<<endl;

}