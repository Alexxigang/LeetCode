/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)return NULL;
        if(!head->next)return head;
        //先把头结点两个交换，因为头结点没有前驱结点，所以要特殊对待
        ListNode* p=head;
        ListNode *q=p->next;
        p->next=q->next;
        q->next=p;
        head=q;
        while(p->next&&p->next->next){
            ListNode *q=p->next;
            ListNode* t=q->next->next;
            q->next->next=q;
            p->next=q->next;
            q->next=t;
            p=p->next->next;
        }
        return head;
    }
};
