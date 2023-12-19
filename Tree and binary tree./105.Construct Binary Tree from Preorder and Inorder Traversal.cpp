// what i learned- sometime  we should learn or rember some fudatmental algorithm  of dsa 
// if want to reach each node then use recursion with by refrence passed value in argument for example in this question with the help of idx i have created 
// all the node of tree it is refrenced passed value 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* formbtfrompreandinorder(vector<int>&pre,vector<int>&in,int start,int end,int &idx){
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
     TreeNode* root=new TreeNode(rootdata);
    root->left=formbtfrompreandinorder(pre,in,start,i-1,idx);
    root->right=formbtfrompreandinorder(pre,in,i+1,end,idx);
    return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int idx=0;
  int n=inorder.size();
    return formbtfrompreandinorder(preorder,inorder,0,n-1,idx);
    }
};
