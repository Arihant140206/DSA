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
    // comparator for min heap
    class compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   // min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {//leetcode me alag hota hai ye

        // priority queue (min heap)
        priority_queue<ListNode*, vector<ListNode*>, compare> p;

        // push head of each list, leetcode me ye bhi alag hota hai compared to book ka code
        
        for (auto node : lists) {
            if (node)
                p.push(node);
        }

        // dummy node
        ListNode* root = new ListNode(0);
        ListNode* tail = root;

        ListNode* temp;

        while (!p.empty()) {
            temp = p.top();
            p.pop();

            tail->next = temp;
            tail = tail->next;

            if (temp->next)
                p.push(temp->next);
        }

        return root->next;   // skip dummy node
    }
};
