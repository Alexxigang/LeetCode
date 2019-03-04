/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 递归解法，代码量更少，递归解法的思路是，不断的进入递归函数，直到head指向倒数第二个节点，因为head指向空或者是最后一个结点都直接返回了，newHead则指向对
 head的下一个结点调用递归函数返回的头结点，此时newHead指向最后一个结点，然后head的下一个结点的next指向head本身，这个相当于把head结点移动到末尾的操作，
 因为是回溯的操作，所以head的下一个结点总是在上一轮被移动到末尾了，但head之后的next还没有断开，所以可以顺势将head移动到末尾，再把next断开，
 最后返回newHead即可
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* newHead=  reverseList(head->next);
        head->next->next=  head;
        head->next=  NULL;
        return newHead;
    }
};
