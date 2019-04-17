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
/*迭代方法二：辅助结点p初始化为根结点，while循环的条件是栈不为空或者辅助结点p不为空，在循环中首先判断如果辅助结点p存在，
那么先将p加入栈中，然后将p的结点值加入结果res中，此时p指向其左子结点。否则如果p不存在的话，表明没有左子结点，我们取出栈顶结点，将p指向栈顶结点的右子结点
*/
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL)return result;
        stack<TreeNode*> s;
        TreeNode *p=root;
        
        while(!s.empty()||p){
            if(p){
                result.push_back(p->val);
                s.push(p);
                p=p->left;
            }else{
                TreeNode *t=s.top();s.pop();
                p=t->right;
            }
        }
        return result;
    }
    

};
