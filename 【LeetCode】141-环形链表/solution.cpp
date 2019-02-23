/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
//利用快慢指针
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        if(!head)return false;
        fast=fast->next;
        while(fast!=slow&&fast!=NULL&&fast->next!=NULL&&fast->next!=NULL){
            fast=fast->next;
            fast=fast->next;
            slow=slow->next;
        }
        if(fast==slow)return true;
        return false;
    }
};
