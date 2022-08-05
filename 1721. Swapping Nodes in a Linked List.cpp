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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* l = head;
        int n = 1;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        ListNode* p = head;
        
        while(l->next){
            l = l->next;
            n++;
        }
        for(int i=1;i<=n;i++){
            if(i == k)
                ptr1 = p;
            if(i == n+1-k)
                ptr2 = p;
            p = p->next;
        }
        cout<<ptr1->val<<" "<<ptr2->val;
        int temp = ptr1->val;
        ptr1->val = ptr2->val;
        ptr2->val = temp;
        return head;
    }
};
