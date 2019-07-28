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
中序遍历思想，非递归方式，利用cnt计数，栈来存储结点
*/
public:
    int kthSmallest(TreeNode* root, int k) {
        return  kthSmallestCore(root,k);
    }

private:
    int kthSmallestCore(TreeNode* head,int &k){
        TreeNode* p=head;
        stack<TreeNode*> s;
        //s.push(p);
        int cnt=0;
        while(p||!s.empty()){
            while(p){
                s.push(p);
                p=p->left;
            }
            p=s.top();s.pop();
            cnt++;if(cnt==k)return p->val;
            p=p->right;
        }
        return 0;
    }
};
