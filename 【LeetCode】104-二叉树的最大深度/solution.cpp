/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return findMaxDepth(root);
    }
private:
    int findMaxDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }else{
            int Ldepth=findMaxDepth(root->left);
            int Rdepth=findMaxDepth(root->right);
            return Ldepth>Rdepth?(Ldepth+1):(Rdepth+1);
        }
        
    }
};
