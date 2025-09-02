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
        int count = 0;

        ListNode* temp = head;
        while(temp) {
            count++;
            temp = temp->next;
        }

        int k = count - n;

        if(k==0) {
            ListNode* temp1 = head;
            head = head->next;
            delete temp1;
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(k--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;

        return head;
    }
};