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
//递归做法
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL)return result;
        TreeNode *node=root;
        
        preordercore(node,result);
        return result;
    }
    
private :
    void preordercore(TreeNode* head,vector<int> &result){
        result.push_back(head->val);
        if(head->left!=NULL)
            preordercore(head->left,result);
        if(head->right!=NULL)
            preordercore(head->right,result);
        return;
    }
};
