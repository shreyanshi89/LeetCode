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
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* p = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = p;
            p = curr;
            curr = next;
        }
        return p;
    }
    
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        
        if(!head->next)
            return true;
        
        while(p != NULL){
            n++;
            p = p->next;
        }
        
        p = head;
        for(int i=1;i<n/2;i++){
            p = p->next;
        }
            
        ListNode* ptr;
        if(n%2 == 0)
            ptr = p->next;
        else 
            ptr = p->next->next;
        
        p->next = NULL;
        p = reverse(head);
        
        while(p != NULL){
            if(p->val != ptr->val)   
                return false;
            p = p->next;
            ptr = ptr->next;
        }
    return true;
    }
};
