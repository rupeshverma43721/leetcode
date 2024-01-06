//printrecursive
//takeinputrecurcive
//takelevewiseinput
//levelwisetraversal
//totalnumberofnodelevelwise
//totalbtnoderecursive
#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class btnode{
     public:
    T data;
    btnode<T>* left;
    btnode<T>* right;
    btnode(T data){
     this->data=data;
     left=NULL;
     right=NULL;
    }
    ~btnode(){
        delete left;
        delete right;
    }
};
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
btnode<int>* takeinputrecurcive(){
     int rootdata; cin>>rootdata;
     if(rootdata==-1){
        return NULL;
    }
     btnode<int>* root=new btnode<int>(rootdata);
     btnode<int>* leftchild=takeinputrecurcive();
     btnode<int>* rightchild=takeinputrecurcive();
     root->left=leftchild;
     root->right=rightchild;
}
btnode<int>* takelevewiseinput(){
    int rootdata; cout<<"Enter root daat:"<<endl;cin>>rootdata;
    if(rootdata==-1){ return NULL;} //edge case 
    btnode<int>* root=new btnode<int>(rootdata);
    queue<btnode<int>*>q;
    q.push(root);
    while(!q.empty()){
        btnode<int>* f=q.front();
        q.pop();
        cout<<"Enter the left child of "<< f->data<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if(leftchilddata!=-1){
            btnode<int>* leftchild=new btnode<int> (leftchilddata);
            q.push(leftchild);
            f->left=leftchild;
        }
        cout<<"Enter the right child of "<< f->data<<endl;
        int righttchilddata;
        cin>>righttchilddata;
        if(righttchilddata!=-1){
            btnode<int>* righttchild=new btnode<int> (righttchilddata);
            q.push(righttchild);
            f->right=righttchild;
        }

    }
    return root;
}
void levelwisetraversal(btnode<int>* root){
    queue<btnode<int>*>q;
    if(root==NULL){
        return;
    }  
    q.push(root);  
    q.push(NULL); 
    while(!q.empty()){
        btnode<int>* f=q.front();
        q.pop();
        if(f==NULL){
            cout<<endl;
           if(!q.empty()){
            q.push(NULL);
           }
        }
        else{
          cout<<f->data<<" ";
          if(f->left){
            q.push(f->left);
          }
          if(f->right){
            q.push(f->right);
          }
        }
    }
}
int totalnumberofnodelevelwise(btnode<int>* root){
    int ans=0;
    queue<btnode<int>*>q;
    if(root==NULL){
        return 0;
    }  
    q.push(root);  
    q.push(NULL); 
    while(!q.empty()){
        btnode<int>* f=q.front();
        q.pop();
        if(f==NULL){
            cout<<endl;
           if(!q.empty()){
            q.push(NULL);
           }
        }
        else{
         ans++;
          if(f->left){
            q.push(f->left);
          }
          if(f->right){
            q.push(f->right);
          }
        }
    }
    return ans;
}
int totalbtnoderecursive(btnode<int>* root){ 
    if(root->left==NULL){
        return 0;        
    }    // or use if(root->data==-1){ return 0;}
    if(root->right==NULL){
        return 0;
    }
   return 1+totalbtnoderecursive(root->left)+totalbtnoderecursive(root->right);
   ;
}
void inordertraversal(btnode<int>* root){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}
void preordertraversal(btnode<int>* root){
    if(root==NULL){
        return;
    }
      cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void postordertraversal(btnode<int>* root){
    if(root==NULL){
        return;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
}
  int heightofbinarytree(btnode<int>* root){
    if(root==NULL){
        return 0;
    }
  int leftheight=heightofbinarytree(root->left);
 int rightheight= heightofbinarytree(root->right);
 return max(leftheight,rightheight)+1;
}
bool findanode(btnode<int>* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
   return findanode(root->left,key)||findanode(root->right,key);
}
int minvaluenode1(btnode<int>*root){
    if(root==NULL){
        return INT8_MAX;
    }
    return min(root->data,min(minvaluenode1(root->right),minvaluenode1(root->left)));

}
void minvaluenode2(btnode<int>*root,int &ans){
    if(root==NULL){
        return;
    }
    ans=min(ans,root->data);
    minvaluenode2(root->left,ans);
    minvaluenode2(root->right,ans);
}
int maxvaluenode1(btnode<int>*root){
    if(root==NULL){
        return INT8_MIN;
    }
    int ans=root->data;
    int leftmax=maxvaluenode1(root->left);
    int rightmax=maxvaluenode1(root->right);
    return max(ans,max(leftmax,rightmax));
    //return min(root->data,min(minvaluenode1(root->right),minvaluenode1(root->left)));

}
void maxvaluenode2(btnode<int>*root,int &ans){
    if(root==NULL){
        return;
    }
    ans=max(ans,root->data);
    maxvaluenode2(root->left,ans);
    maxvaluenode2(root->right,ans);
}
void countleafnode1(btnode<int>* root,int & leafnode){
if(root==NULL){
    return;
}
if(root->left==NULL && root->right==NULL){
    cout<<root->data<<" ";
     leafnode++;
}
countleafnode1(root->left,leafnode);
countleafnode1(root->right,leafnode);
}
int countleafnode2(btnode<int>* root){
if(root==NULL){
    return 0;
}
if(root->left==NULL && root->right==NULL){
    return 1; // base case
}
return countleafnode2(root->left)+countleafnode2(root->right);

}
btnode<int>* formbtfrompreandinorder(vector<int>pre,vector<int>in,int start,int end,int &idx){
    if(start>end){  // base case 
        return NULL;
        }
    int rootdata=pre[idx];
    int i=start;
    for(i=start;i<=end;i++){
        if(in[i]==rootdata){
            break;
        }
    }
     idx++;
     btnode<int>* root=new btnode<int>(rootdata);
    root->left=formbtfrompreandinorder(pre,in,start,i-1,idx);
    root->right=formbtfrompreandinorder(pre,in,i+1,end,idx);
    return root;
}



// Binary search tree fuctions 



bool helperofcheckitisbstornot(btnode<int>* root, long long min=-10000000000,long long max=10000000000 ){
    if(root==NULL){
        return true;
    }
    bool left=helperofcheckitisbstornot(root->left,min,root->data);
    bool right=helperofcheckitisbstornot(root->right,root->data,max);
    if(left && right&&root->data>min&&root->data<max){
        return true;
    }
    else{
        return false;
    }
}
bool checkitisbstornot(btnode<int>* root){
    return helperofcheckitisbstornot(root); // argument kam diya hai because helper me maine default argument provide kiye hai
}





btnode<int>* bst_formed_from_sorted_vector_helper(vector<int>a,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    int rootdata=a[mid];
    btnode<int>* root=new btnode<int>(rootdata);
    root->left=bst_formed_from_sorted_vector_helper(a,s,mid-1);
    root->right=bst_formed_from_sorted_vector_helper(a,mid+1,e);
    return root;
}
btnode<int>* bst_formed_from_sorted_vector( vector<int>a){
    int n=a.size();
    return bst_formed_from_sorted_vector_helper(a,0,n-1);
}












