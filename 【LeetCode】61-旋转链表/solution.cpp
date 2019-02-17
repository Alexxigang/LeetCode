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
总体思路是：利用快慢指针，将从尾部向前数k个结点的结点放在前面，主要注意细节是注意k是否大于n,所以要将K对n取模
*/
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        int n=0;
        ListNode* cur=head;
        while(cur){
            n++;
            cur=cur->next;
        }
        k%=n;
        ListNode *fast=head,*slow=head;
        for(int i=0;i<k;i++){
            if(fast)fast=fast->next;
        }
        if(!fast)return head;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        //将从尾部向前数k个结点的结点放在前面
        fast->next=head;
        fast=slow->next;
        slow->next=NULL;
        return fast;
    }
};
