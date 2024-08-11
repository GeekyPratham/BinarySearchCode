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

void displayTree(Node* a){

    if(a == NULL) return; // base case
    cout<<a->val<<" ";
    displayTree(a->left);
    displayTree(a->right);
}


int prodOfTreeNode(Node* a){
    
    if(a==NULL) return 1;
    // int sum = a->val + sumOfTreeNode(a->left) +sumOfTreeNode(a->right);
    // return ans;
    return  a->val * prodOfTreeNode(a->left) * prodOfTreeNode(a->right);
}

int size(Node* a){
    if(a==NULL) return 0;
    int length = 1 + size(a->left)+size(a->right);
    return length;
}

int minimum(Node* a){
    if(a == NULL) return INT_MAX;
    int mn = min(a->val,min(minimum(a->left),minimum(a->right)));
    return mn;
}
int level(Node* a){
    if(a == NULL) return 0;
    return 1 + max(level(a->left),level(a->right));
}
int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    Node* h = new Node(17);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    g->left = h;

    displayTree(a);
    cout<<endl;
    cout<<prodOfTreeNode(a);
    cout<<endl;
    cout<<size(a);
    cout<<endl;
    cout<<minimum(a);
    cout<<endl;
    cout<<level(a);



}