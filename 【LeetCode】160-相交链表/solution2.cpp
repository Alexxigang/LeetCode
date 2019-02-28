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
方法：这里用了比较灵巧的方法，同时遍历两个链表，如果有一个到了尾结点，则转至两一个链表的头部继续遍历，直至两个节点指针相同为止，类似于环，两个指针最终会
相等，而且只有两种情况，一种情况是在交点处相遇，另一种情况是在各自的末尾的空节点处相等。为什么一定会相等呢，因为两个指针走过的路程相同，是两个链表的长度
之和，所以一定会相等
*/
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p=headA,*q=headB;
        while(p!=q){
            p=p?p->next:headB;
            q=q?q->next:headA;
        }
        return p;
    }
};
