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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        int n=lists.size();
        while(n>1){
            int k=(n+1)/2;
            for(int i=0;i<n/2;i++){
                lists[i]=MergeTwo(lists[i],lists[i+k]);
            }
            n=k;
        }
        return lists[0];
    }
private:
    ListNode* MergeTwo(ListNode* l1,ListNode* l2){
        ListNode* l=new ListNode(-1);
        ListNode* r=l,*p=l1,*q=l2;
        while(l1&&l2){
            if(l1->val<=l2->val){
                r->next=l1;
                l1=l1->next;
            }else{
                r->next=l2;
                l2=l2->next;
            }
            r=r->next;
        }
        r->next=l1?l1:l2;
        return l->next;
    }
};
