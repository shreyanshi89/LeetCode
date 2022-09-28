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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int i = 0;
        while(ptr){
            ptr = ptr->next;
            i++;
        }
        
        if(i == n){
            head = head->next;
            return head;
        }
        
        i -= n;
        ptr = head;
        while(ptr && i > 1){
            ptr = ptr->next;
            i--;
        }
        ptr->next = ptr->next->next;
        return head;
    }
};
