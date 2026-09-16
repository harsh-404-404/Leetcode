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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        ListNode* pt1 = head;
        ListNode* pt2 = (head->next)->next;

        while(pt1 != nullptr && pt2 != nullptr && pt2->next != nullptr && pt1 != pt2){
            pt1 = pt1->next;
            pt2 = pt2->next->next;
        }
        if(pt1 != nullptr && pt2 != nullptr && pt1 == pt2){
            return true;
        }
        return false;
    }
};