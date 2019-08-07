### 经典题目
  求二叉树的后序遍历的非递归方法，跟前序，中序，层序一样都需要用到栈，后续的顺序是左-右-根，所以当一个节点值被取出来时，它的左右子节点要么不
存在，要么已经被访问过了。我们先将根结点压入栈，然后定义一个辅助结点head，while循环的条件是栈不为空，在循环中，首先将栈顶结点t取出来，如果栈顶结点没有左
右子结点，或者其左子结点是head，或者其右子结点是head的情况下。我们将栈顶结点值加入结果res中，并将栈顶元素移出栈，然后将head指向栈顶元素；否则的话就看如
果右子结点不为空，将其加入栈，再看左子结点不为空的话，就加入栈，注意这里先右后左的顺序是因为栈的后入先出的特点，可以使得左子结点先被处理。下面来看为什么
是这三个条件呢，首先如果栈顶元素如果没有左右子结点的话，说明其是叶结点，而且我们的入栈顺序保证了左子结点先被处理，所以此时的结点值就可以直接加入结果res了
，然后移出栈，将head指向这个叶结点，这样的话head每次就是指向前一个处理过并且加入结果res的结点，那么如果栈顶结点的左子结点或者右子结点是head的话，说明其
子结点已经加入结果res了，那么就可以处理当前结点
了。

看到这里，大家可能对head的作用，以及为何要初始化为root，还不是很清楚，这里再解释一下。head是指向上一个被遍历完成的结点，由于后序遍历的顺序是左-右-根，所
以一定会一直将结点压入栈，一直到把最左子结点（或是最左子结点的最右子结点）压入栈后，开始进行处理。一旦开始处理了，head就会被重新赋值。所以head初始化值并
没有太大的影响，唯一要注意的是不能初始化为空，因为我们在判断是否打印出当前结点时除了判断是否是叶结点，还要看head是否指向其左右子结点，如果head指向左子结
点，那么右子结点一定为空，因为我们的入栈顺序是根-右-左，不存在右子结点还没处理，就直接去处理根结点了的情况。若head指向右子结点，则是正常的左-右-根的处理
顺序。那么回过头来在看，若head初始化为空，且此时正好左子结点不存在，那么在压入根结点时，head和左子结点相等就成立了，此时就直接打印根结点了，明显是错的。
所以head只要不初始化为空，一切都好说，甚至可以新建一个结点也没问题。将head初始化为root，也可以，就算只有一个root结点，那么在判定叶结点时就将root打印了，
然后就跳出while循环了，也不会出错。代码如下：
```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s{{root}};
        TreeNode *head = root;
        while (!s.empty()) {
            TreeNode *t = s.top();
            if ((!t->left && !t->right) || t->left == head || t->right == head) {
                res.push_back(t->val);
                s.pop();
                head = t;
            } else {
                if (t->right) s.push(t->right);
                if (t->left) s.push(t->left);
            }
        }
        return res;
    }
};
```

由于后序遍历的顺序是左-右-根，而先序遍历的顺序是根-左-右，二者其实还是很相近的，我们可以先在先序遍历的方法上做些小改动，使其遍历顺序变为**根-右-左**，然后
翻转一下，就是左-右-根啦，翻转的方法我们使用反向Q，哦不，是反向加入结果res，每
次都在结果res的开头加入结点值，而改变先序遍历的顺序就只要该遍历一下入栈顺序，先左后右，这样出栈处理的时候就是先右后左啦，参见代码如下：
```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s{{root}};
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            res.insert(res.begin(), t->val);
            if (t->left) s.push(t->left);
            if (t->right) s.push(t->right);
        }
        return res;
    }
};
```
