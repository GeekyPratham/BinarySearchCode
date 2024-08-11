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
void nthLevel(Node* a,int value){

    if(a == NULL) return; // base case
    if(value==2)cout<<a->val<<" "; // work
    nthLevel(a->left,value+1); // call1
    nthLevel(a->right,value+1); //call2
}
void nthLevelRev(Node* a,int value){

    if(a == NULL) return; // base case
    if(value==2)cout<<a->val<<" "; // work
    nthLevelRev(a->right,value+1); //call2
    nthLevelRev(a->left,value+1); // call1
    
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
   

    nthLevel(a,1);
    cout<<endl;

    nthLevelRev(a,1);
    

}