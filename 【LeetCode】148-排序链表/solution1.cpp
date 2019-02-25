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
归并排序：非递归
*/
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
        pre->next=NULL;
        return Merge(sortList(head),sortList(slow));
    }
    
private:
    ListNode* Merge(ListNode* L1,ListNode*L2){
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        
        while(L1&&L2){
            if(L1->val<L2->val){
                cur->next=L1;
                L1=L1->next;
            }else{
                cur->next=L2;
                L2=L2->next;
            }
            cur=cur->next;
        }
        if(L1)cur->next=L1;
        if(L2)cur->next=L2;
        return dummy->next;
    }
};
