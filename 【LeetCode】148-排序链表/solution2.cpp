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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode *fast=head,*pre=head,*slow=head;
        while(fast&&fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        //通过pre结点将原链表分成两半
        pre->next=NULL;
        return Merge(sortList(head),sortList(slow));
    }
    
private:
    ListNode* Merge(ListNode* L1,ListNode*L2){
    //递归合并
        if(!L1)return L2;
        if(!L2)return L1;
            if(L1->val<L2->val){
                L1->next=Merge(L1->next,L2);
                return L1;
            }
            else{
                L2->next=Merge(L1,L2->next);
                return L2;
            }
    }
};
