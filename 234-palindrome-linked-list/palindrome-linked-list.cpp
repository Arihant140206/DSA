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
/*class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        count/=2;
        ListNode* curr=head,* prev=NULL;
        while(count--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        //REVERSE SECOIND LINKED LIOST

        ListNode* front;
        prev=NULL;
        while(count--){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        //check palindrome
        ListNode*head1=head,*head2=prev;
        while(head1){
            if(head1->val!=head2->val)
            return 0;
            head1=head1->next;
            head2=head2->next;
        }
        return 1;

    }
};*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 1️⃣ Find middle using slow & fast pointers
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2️⃣ Reverse second half
        ListNode *prev = nullptr, *curr = slow, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3️⃣ Compare first & second half
        ListNode *head1 = head;
        ListNode *head2 = prev;
        while (head2) {
            if (head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};
