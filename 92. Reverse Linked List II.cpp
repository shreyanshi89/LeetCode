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
        ListNode* p = NULL;
        ListNode* nxt = NULL;
        ListNode* ptr = head;
        while(ptr){
            nxt = ptr->next;
            ptr->next = p;
            p = ptr;
            ptr = nxt;
        }
        return p;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* ptr1 = pre;
        int i=0;
        
        if(left == right)
            return head;
        
        while(ptr1->next && i+1 != left){
           ptr1 = ptr1->next;
           i++;
        }
        ListNode* ptr2 = ptr1;
        while(ptr2 && i != right){
            ptr2 = ptr2->next;
            i++;
        }
        ListNode* nxt = ptr2->next;
            ptr2->next = NULL;
    
        ListNode* h = reverse(ptr1->next);
        ptr1->next = h;
        while(h->next)
            h = h->next;
        h->next = nxt;
        
        return pre->next;
    }
};
