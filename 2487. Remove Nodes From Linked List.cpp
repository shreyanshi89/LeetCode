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

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* nxt = NULL;
        ListNode* ptr = NULL;

        while(curr){
            ptr = curr->next;
            curr->next = nxt;
            nxt = curr;
            curr = ptr;
        }
        return nxt;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* h = reverse(head);
        ListNode* prev = NULL;
        ListNode* curr = h;
        int maxi = INT_MIN;

        while(curr){
            if(curr->val >= maxi){
                maxi = curr->val;
                if(prev)
                    prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        prev->next = curr;
        return reverse(h);
    }
};
