/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp{
    //重载operator<的例子：返回true时，说明左边形参的优先级低于右边形参
    bool operator()(ListNode* l1,ListNode* l2){
        return l1->val>l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp > q;//优先级队列。队首数值为优先级最高，利用了最小堆的数据结构，会自动排好序
        for(int i=0;i<lists.size();i++){
            if(lists[i])q.push(lists[i]);
        }
        ListNode *l=NULL,*cur=NULL,*pre=NULL; 
        while(!q.empty()){
            cur=q.top();
            q.pop();
            if(!pre) l=cur;
            else{
                pre->next=cur;
            }
            pre=cur;
            if(cur->next){
                q.push(cur->next);
            }
        }
        return l;
    }
    
};
