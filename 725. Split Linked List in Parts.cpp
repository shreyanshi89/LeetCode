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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, NULL);
        ListNode* ptr = head;
        int size = 0;
        while(ptr){
            ptr = ptr->next;
            size++;    
        }

        int iter = size / k;
        int r = size % k; 
        ptr = head;
        for(int i=0;i<k && ptr;i++){
            int n = iter;
            if(r){
                n++;
                r--;
            }
            
            ListNode* prev = NULL;
            ans[i] = ptr;
            for(int j=0;j<n && ptr;j++){
                prev = ptr;
                ptr = ptr->next;    
            }
            prev->next = NULL;
        }
        return ans;
    }
};
