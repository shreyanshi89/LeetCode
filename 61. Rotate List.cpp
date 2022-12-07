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
        ListNode* nxt = NULL;
        ListNode* ptr = head;
        ListNode* tail = NULL;

        while(ptr){
            nxt = ptr->next;
            ptr->next = tail;
            tail = ptr;
            ptr = nxt;
        }
        return tail;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;

        ListNode* h = reverse(head);
        ListNode* tail = h;

        int size = 0;
        while(tail->next) {
            size++;
            tail = tail->next;
        }

        ListNode* curr = h;
        ListNode* nxt = NULL;

        if(k > size+1)
            k = k % (size+1);
        
        for(int i=0;i<k;i++){
            nxt = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = tail->next;
            curr = nxt;
        }
        return reverse(curr);
    }
};
