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
    
    ListNode*  reverse(ListNode* head){
        ListNode* ptr = head;
        ListNode* nxt = NULL;
        ListNode* curr = NULL;
        
        while(ptr != NULL){ 
            curr = ptr->next;
            ptr->next = nxt;
            nxt = ptr;
            ptr = curr;
        }
        return nxt;
    }
    
    int pairSum(ListNode* head) {
        ListNode* p = head;
        int n = 0;
        int maxSum = 0;
        
        while(p != NULL){
            p = p->next;
            n++;
        }
        
        p = head;
        int i=0;
        while(i != n/2){
            p = p->next;
            i++;
        }
        
        ListNode* ptr = head;
        i=0;
        while(i != n/2-1){
            ptr = ptr->next;
            i++;
        }
        ptr->next = NULL;
        
        ptr = reverse(head);
        
        while(ptr && p){
            int sum = ptr->val + p->val;
            ptr = ptr->next;
            p = p->next;
            maxSum = max(maxSum,sum);
        }
        
        return maxSum;
    }
};
