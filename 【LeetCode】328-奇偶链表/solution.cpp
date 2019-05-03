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
开奇偶节点，所有奇节点在前，偶节点在后。我们可以使用两个指针来做，pre指向奇节点，cur指向偶节点，然后把
偶节点cur后面的那个奇节点提前到pre的后面，然后pre和cur各自前进一步，此时cur又指向偶节点，pre指向当前奇节点的末尾，以此类推直至把所有的偶节点都提前了即可
*/
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode *pre=head,*cur=head->next;
        while(cur&&cur->next){
            ListNode* tmp=pre->next;
            pre->next=cur->next;
            cur->next=cur->next->next;
            pre->next->next=tmp;
            pre=pre->next;
            cur=cur->next;
        }
        return head;
    }
};
