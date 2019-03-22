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
/*
非递归方法：用个while循环来代替递归调用即可，然后不停的更新当前的根节点
*/
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        
        while(root){
            if(root->val>max(p->val,q->val)){
                root=root->left;
            }else if(root->val<min(p->val,q->val)){
                root=root->right;
            }else return root;
        }
        return root;
    }
};
