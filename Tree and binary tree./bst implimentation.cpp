// implementation of binary search tree - find,insert,print,delete etc.
#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class btnode{
  public:
      T data;
       btnode* left;
       btnode* right;
      btnode( T data){
        this->data=data;
        left=NULL;
        right=NULL;
      }
      ~btnode(){
        delete left;
        delete right;
      }
};
// consider bst of int type 
class bst{
    btnode<int>* root;
   // private function of print tree  
    void printrecursive(btnode<int>*root){
    if(root==NULL){  // base case
        return;  
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
           cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL){
          cout<<"R"<< root->right->data;
    }
    cout<<endl;
    printrecursive(root->left);
    printrecursive(root->right);
}
// private function of checking data is present or not 
bool hasdata(btnode<int>* root,int data){ // this root is just pased from public section 
  if(root==NULL){
    return false;
  }
  if(root->data==data){
    return true;
  }
  if(root->data>data){
    return hasdata(root->left,data);
  }
  else{
    return hasdata(root->right,data);
  }
}
// private function for insert 
  btnode<int>* insert( btnode<int>* node,int data){
             if(node==NULL){
              btnode<int>*n=new btnode<int>(data);
              return n; 
             }
             if(data<node->data){
              node->left=insert(node->left,data);
             }
             else{
              node->right=insert(node->right,data);
             }
       return node;
  }
    public:
     bst(){
      root=NULL;
     }
     ~bst(){
      delete root;
     }
     void insert(int data){
          root = insert(root,data);
    }
    bool hasdata(int data){
      return hasdata(root,data); 
    }
    void print(){
        printrecursive(root);
    } 
     
};
int main(){
  bst b;
  b.insert(10);
  b.insert(5);
  b.insert(20);
  b.insert(7);
  b.insert(3);
  b.insert(15);
  b.print();
  cout<<b.hasdata(11)<<endl;
    return 0;
}
