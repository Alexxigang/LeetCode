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
方法：求出两个链表的长度的差值，然后将较长的链表的头指针后移该差值的数量，然后两个链表同时后移，若遇到结点指向相同，则找到要求结点
*/
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)return NULL;
        ListNode *L1=headA,*L2=headB;
        ListNode *L3=headA,*L4=headB;
        int lenB=1,lenA=1;
        while(L2->next!=NULL){
            lenB++;
            L2=L2->next;
        }
        while(L1->next!=NULL){
            lenA++;
            L1=L1->next;
        }
        if(lenB<lenA){
            int diff=lenA-lenB;
            ListNode* p=headA;
            for(int i=0;i<diff;i++){
                p=p->next;
            }
            while(L4!=p&&L4->next!=NULL&&p->next!=NULL){
                L4=L4->next;
                p=p->next;
            }
            if(L4==p){
                return p;
            }
        }else{
            int diff=lenB-lenA;
            ListNode* p=headB;
            for(int i=0;i<diff;i++){
                p=p->next;
            }
            while(L3!=p&&L3->next!=NULL&&p->next!=NULL){
                L3=L3->next;
                p=p->next;
            }
            if(L3==p){
                return p;
            }
        }
        return NULL;
    }
};
