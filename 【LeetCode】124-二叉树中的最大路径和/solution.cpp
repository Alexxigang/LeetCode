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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;//全局路径最大值放在参数中，用结果res来表示。
        helper(root,res);
        return res;
    }
    
private:
    int helper(TreeNode* node,int& res){
        if(!node)return 0;
        //和0相比，取较大的那个，就是要么不加，加就要加正数
        int left=max(helper(node->left,res),0);
        int right=max(helper(node->right,res),0);
        res=max(res,left+right+node->val);
        //返回值的定义是以当前结点为终点的path之和
        return max(left,right)+node->val;
    }
};
