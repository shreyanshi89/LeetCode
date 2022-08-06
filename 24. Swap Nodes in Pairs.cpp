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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next))
           return head;
        
        ListNode* prev = NULL;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        head = head->next;
        
        while(ptr1 && ptr2){
            if(prev)
                prev->next = ptr2;
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            prev = ptr1;
            ptr1 = prev->next;
            if(ptr1)
                ptr2 = ptr1->next;
        }
        return head;
    }
};
