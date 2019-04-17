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
//方法一：不断进栈根节点的左子节点，如果到末尾，则将当前节点保存到res中，然后将当前节点指向当前节点的右子节点
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        stack<TreeNode*> s;
        TreeNode* p=root;
        while(!s.empty()||p){
            while(p){
                s.push(p);
                p=p->left;
            }
            p=s.top();s.pop();
            res.push_back(p->val);
            p=p->right;
        }
        return res;
    }
};
