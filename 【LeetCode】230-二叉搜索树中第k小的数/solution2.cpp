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
递归方法，利用中序遍历
*/
public:
    int kthSmallest(TreeNode* root, int k) {
        return  kthSmallestCore(root,k);
    }

private:
    int kthSmallestCore(TreeNode* head,int &k){
        if(!head)return -1;
        int val=kthSmallestCore(head->left,k);
        if(k==0)return val;
        if(--k==0)return head->val;//判断句中执行k--操作
        return kthSmallestCore(head->right,k);
    }
};
