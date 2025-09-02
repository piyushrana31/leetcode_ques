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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0;
        int countB = 0;

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA) {
            countA++;
            tempA = tempA->next;
        }
        tempA = headA;

        while(tempB) {
            countB++;
            tempB = tempB->next;
        }
        tempB = headB;

        int count = abs(countA - countB);

        while(countA != countB) {
            if(countA > countB) {
                countA--;
                tempA = tempA->next;
            }else {
                countB--;
                tempB = tempB->next;
            }
        }

        while(tempA && tempB) {
            if(tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;
    }
};