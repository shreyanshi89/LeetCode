/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;

        queue<ListNode*> q1;
        queue<ListNode*> q2;

        ListNode* ptr = head;
        while(ptr){
            if(ptr->val < x)
                q1.push(ptr);
            else 
                q2.push(ptr);
            ptr = ptr->next;
        }

        ListNode* num;
        ListNode* h;
        if(!q1.size())
            h = q2.front();
        else 
            h = q1.front();

        while(!q1.empty()){
            num = q1.front();
            q1.pop();
            if(!q1.empty())
                num->next = q1.front();
        }
        if(num && q2.size())
            num->next = q2.front();

        while(!q2.empty()){
            num = q2.front();
            q2.pop();
            if(!q2.empty())
                num->next = q2.front();
        }
        if(num)
            num->next = NULL;
        return h;
    }
};
