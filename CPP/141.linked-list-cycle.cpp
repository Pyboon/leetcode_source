/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (35.22%)
 * Total Accepted:    217.4K
 * Total Submissions: 617.2K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, determine if it has a cycle in it.
 * 
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
 * 
 */
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
        if(!head) return false;
        int flag = false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && slow && slow!=fast){
            slow= slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
            else break;
        }
        if(slow==fast){
            flag = true;
        }
        return flag;
    }
};
