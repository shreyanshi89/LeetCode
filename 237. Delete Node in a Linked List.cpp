/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};

//  OR

/*
class Solution {
public:
    void deleteNode(ListNode* node) {
        int temp = node->val;
        node->val = node->next->val;
        node->next->val = temp;
        node->next = node->next->next;
    }
};
*/
