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
        ListNode* tortoise = head;
        ListNode* rabit = head;

        while(rabit != nullptr && rabit->next != nullptr){
            tortoise = tortoise->next;
            rabit = rabit->next->next;

            if(rabit == tortoise){
                return true;
            } 
        }
        return false;
    }
};