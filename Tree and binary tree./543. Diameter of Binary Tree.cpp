// what i learned - from line 4 to 8 is a recurssive way to reach at depest node 
class Solution {
public:
int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int option1= height(root->left)+height(root->right);
        int option2 =diameterOfBinaryTree(root->left);
         int option3 =diameterOfBinaryTree(root->right);
         return max(option1,max(option2,option3));

    }
};
