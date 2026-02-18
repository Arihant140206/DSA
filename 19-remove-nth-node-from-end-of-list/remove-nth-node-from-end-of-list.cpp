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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode*temp= head;
        while(temp){
            count++;
            temp=temp->next;
        };
        count-=n;
        /*So we are asked to remove the 1st node from the start
(which is also the Nth node from the end).

In simple words:

We need to delete the head node.*/
        if(count==0){
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode*curr= head,*prev= NULL;
        while(count--){
            prev=curr;
            curr=curr->next;
        };
        prev->next=curr->next;
        delete curr;
        return head;
        
    }
};