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
题目只给定了要删除的结点，并没有给定头结点，所以要先用要删除的结点的下一个结点的值覆盖掉该结点，然后用删除掉该节点的下一个结点即可
*/
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        ListNode* tmp=node->next;
        node->next=tmp->next;
        delete tmp;
    }
};
