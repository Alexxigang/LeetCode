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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* p=l1;
        ListNode* q=l2;
        ListNode* L;
        if(p==NULL){
            L=l2;
            return L;
        }
        if(q==NULL){
            L=l1;
            return L;
        }
        if(p->val<=q->val){
            L=new ListNode(p->val);
            p=p->next;
        }else{
            L=new ListNode(q->val);
            q=q->next;
        }
        ListNode* r=L;
        while(p!=NULL&&q!=NULL){
            if(p->val<=q->val){
                r->next=p;
                p=p->next;
            }else{
                r->next=q;
                q=q->next;
            }
            r=r->next;
        }
        if(p!=NULL){
             r->next=p;
        }
        if(q!=NULL){
             r->next=q;
        }
        return L;
    }
};
