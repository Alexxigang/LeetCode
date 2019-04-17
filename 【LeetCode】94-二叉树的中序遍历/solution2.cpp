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
/*方法二：好前序遍历的那段代码类似，可作为前序中序遍历后序遍历的模板，这里和前序不同的是把结点值加入结果res的步骤从if中移动到了else中，
因为中序遍历的顺序是左-根-右*/
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        stack<TreeNode*> s;
        TreeNode* p=root;
        while(!s.empty()||p){
            if(p){
                s.push(p);
                p=p->left;
            }else{
                p=s.top();s.pop();
                res.push_back(p->val);
                p=p->right;
            }
            
        }
        return res;
    }
};
