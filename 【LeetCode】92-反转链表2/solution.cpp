/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
/*
按如下的交换顺序：

1 -> 2 -> 3 -> 4 -> 5 -> NULL

1 -> 3 -> 2 -> 4 -> 5 -> NULL

1 -> 4 -> 3 -> 2 -> 5 -> NULL

我们可以看出来，总共需要n-m步即可，第一步是将结点3放到结点1的后面，第二步将结点4放到结点1的后面。这是很有规律的操作，那么我们就说一个就行了，比如刚开始，
pre指向结点1，cur指向结点2，然后我们建立一个临时的结点t，指向结点3（注意我们用临时变量保存某个结点就是为了首先断开该结点和前面结点之间的联系，这可以
当作一个规律记下来），然后我们断开结点2和结点3，将结点2的next连到结点4上，也就是 cur->next = t->next，再把结点3连到结点1的后面结点（即结点2）的前面
，即 t->next = pre->next，最后再将原来的结点1和结点2的连接断开，将结点1连到结点3，即 pre->next = t。这样我们就完成了将结点3取出，加入结点1的后方。
第二步将结点4取出，加入结点1的后方，也是同样的操作
*/
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy=new ListNode(-1),*pre=dummy;
        dummy->next=head;
        for(int i=1;i<=m-1;i++){
            pre=pre->next;
        }
        ListNode* cur=pre->next;
        for(int i=m;i<n;i++){
            ListNode *t=cur->next;
            cur->next=t->next;
            t->next=pre->next;
            pre->next=t;
        }
        return dummy->next;
    }
};
