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
先判断根节点是否为空或者为p,q两者中任意一个，如果是则直接返回该节点，然后递归左子树，如果左子树中发现和p或者q相等的结点，则返回该值给left，right同理，
如果left和right都有值，说明p和q在当前root结点的两侧，直接返回该root，如果只有left有值，说明p和q在root结点的左子树，同时left是p和q中深度最浅的，所以
返回该left，right同理
*/
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||p==root||q==root)return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left&&right)return root;
        return left?left:right;
    }
};

优化法二：当p和q同时为于左子树或右子树中，而且返回的结点并不是p或q，那么就是p和q的最小父结点了，已经求出来了，就不用再对右结点调用递归函数了

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||p==root||q==root)return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        if(left&&left!=p&&left!=q)return left;
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left&&right)return root;
        return left?left:right;
    }
};
