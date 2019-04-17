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
//迭代方法一：先将根节点保存在栈中，然后在while循环中取出栈顶点，保存该节点的值到res中，然后将右结点保存到栈中，最后保存左节点到栈中
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL)return result;
        TreeNode *node=root;
        stack<TreeNode*> s{{root}};
        while(!s.empty()){
            TreeNode* p=s.top();s.pop();
            result.push_back(p->val);
            if(p->right!=NULL)
                s.push(p->right);
            if(p->left!=NULL)
                s.push(p->left);
            
        }
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
