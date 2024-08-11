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

int height(Node* root){
    if(root== NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}
void nthLevel(Node* a,int curr,int value){

    if(a == NULL) return; // base case
    if(curr == value){
        cout<<a->val<<" "; 
        return;
    }
    nthLevel(a->left,curr+1,value); // call1
    nthLevel(a->right,curr+1,value); //call2
}
void nthLevelRev(Node* a,int curr,int value){

    if(a == NULL) return; // base case
    if(curr == value){
        cout<<a->val<<" "; 
        return;
    }
    nthLevelRev(a->right,curr+1,value); //call2
    nthLevelRev(a->left,curr+1,value); // call1
    
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
   
    int level = height(a);

    for(int i=1;i<= level;i++){
        nthLevel(a,1,i);
        cout<<endl;
    }
    for(int i=1;i<= level;i++){
        nthLevelRev(a,1,i);
        cout<<endl;
    }
    
    

}