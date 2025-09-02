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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextPtr = nullptr;

        while(curr) {
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);

        ListNode* temp = head;
        ListNode* temp1 = newHead;

        while(temp1) {
            if(temp1->val != temp->val) return false;
            temp = temp->next;
            temp1 = temp1->next;
        }

        head = reverse(newHead);
        return true;
    }
};