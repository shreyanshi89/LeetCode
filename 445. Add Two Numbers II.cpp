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
        ListNode* ptr = head;
        ListNode* next = NULL;
        
        while(ptr){
            next = ptr->next;
            ptr->next = p;
            p = ptr;
            ptr = next;
        }
        return p;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return NULL;
        if(!l1 || !l2)
            return l1? l1:l2;
        ListNode* list1 = reverse(l1);
        ListNode* list2 = reverse(l2);
        
        ListNode* list = new ListNode();
        ListNode* l = list;
        int carry = 0;
        int value = 0;
        while(list1 || list2 || carry){
            int sum = (list1? list1->val:0) + (list2? list2->val:0) + carry;
            value = sum%10;
            carry = sum/10;
            list->next = new ListNode(value);
            list1 = list1? list1->next:NULL;
            list2 = list2? list2->next:NULL;
            list = list->next;
        }
        return reverse(l->next);
    }
};
