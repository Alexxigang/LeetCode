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
解法二：直接将链表收尾相连，在往后走n - k % n个节点就到达新链表的头结点前一个点，这时断开链表即可
*/
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        int n=1;
        ListNode* cur=head;
        while(cur->next){
            n++;
            cur=cur->next;
        }
        cur->next=head;
        int m=n-k%n;
        for(int i=0;i<m;i++){
            cur=cur->next;
        }
        ListNode* newhead=cur->next;
        cur->next=NULL;
        return newhead;
    }
};
