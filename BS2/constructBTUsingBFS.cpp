

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
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9,INT_MIN};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root = new Node(arr[0]);
    
    queue<Node* > q;
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT_MIN) l=new Node(arr[i]);
        else l=NULL;
        if(j!=n && arr[j]!=INT_MIN) r=new Node(arr[j]);
        else r=NULL;
        temp->left=l;
        temp->right=r;
        if(l!=NULL)q.push(l);
        if(r!=NULL)q.push(r);
        i+=2;
        j+=2;
    }
    int level = height(root);

    for(int i=1;i<= level;i++){
        nthLevel(root,1,i);
        // cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<= level;i++){
        nthLevelRev(root,1,i);
        // cout<<endl;
    }
    
    

}