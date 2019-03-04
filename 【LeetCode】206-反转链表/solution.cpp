/*
方法：在原链表之前建立一个空的newHead，因为首节点会变，然后从head开始，将之后的一个节点移到newHead之后，重复此操作直到head成为末节点为止
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while (head) {
            ListNode *t = head->next;
            head->next = newHead;
            newHead = head;
            head = t;
        }
        return newHead;
    }
};
