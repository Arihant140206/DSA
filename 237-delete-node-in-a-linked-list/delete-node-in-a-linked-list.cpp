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
        ListNode* temp = node->next;  // your idea

        node->val = temp->val;        // copy next node value into this node
        node->next = temp->next;      // unlink the next node

        delete temp;  
    }
};