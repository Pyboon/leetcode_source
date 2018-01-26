/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list
 *
 * algorithms
 * Easy (40.02%)
 * Total Accepted:    208.6K
 * Total Submissions: 521.1K
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* result = head;
        while(head){
          if(head->next){
            ListNode* temp = head->next;
            if(head->val == temp->val){
              head->next = temp->next;
            }
            else{
              head = head->next;
            }
          }
          else{
            break;
          }
        }
        return result;
    }
};
