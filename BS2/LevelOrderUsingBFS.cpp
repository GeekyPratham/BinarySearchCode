#include <iostream>
#include <queue>
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

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(12);
    Node* e = new Node(5);
    Node* f = new Node(6);
    
   

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
 
    queue<Node*> q;
    q.push(a);
    while(q.size()){ //BFS
        Node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        
        // if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
        if(temp->left!=NULL)q.push(temp->left);
        
    }



}