// revise traversal or this question good question you have to learn or practice some technique 
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
    TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int instart,int inend,int poststart,int postend){
        if(instart>inend||poststart>postend){  // base case 
            return NULL;
        }
      // work on one node 
           int rootval=postorder[postend];
            int i=instart;
        for(i=0;i<inend;i++){
            if(rootval==inorder[i]){
                break;
            }
        }
        int leftsize=i-instart;
        int rightsize=inend-i;
            TreeNode* root=new TreeNode(rootval);
      // after work on one node go for left and righ node with changed parameters 
            root->left=solve(inorder,postorder,instart,i-1,poststart,poststart+leftsize-1);
            root->right=solve(inorder,postorder,i+1,inend,postend-rightsize,postend-1);
      // finally return the main root address 
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int instart=0,inend=n-1,poststart=0,postend=n-1;
        return solve(inorder,postorder,instart,inend,poststart,postend);
    }
};
