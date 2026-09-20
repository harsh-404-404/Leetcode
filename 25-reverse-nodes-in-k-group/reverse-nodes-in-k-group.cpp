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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head == nullptr) return head;

        ListNode dummy_head {0, head};
        ListNode* start_node = &dummy_head;
        ListNode* ptr = start_node->next;

        int node_count = 0;
        while(node_count == k ||ptr){
            if(node_count == k){
                ListNode* front { start_node->next->next };
                ListNode* back { start_node->next };
                node_count--;

                while(node_count){
                    ListNode* temp =  front->next;

                    front->next = start_node->next;
                    start_node->next = front;
                    back->next = temp;
        
                    node_count--;

                    front = temp;
                }
                start_node = back;

            }else{
                node_count++;
                ptr = ptr->next;
            }
        }
        return dummy_head.next;

    }
};