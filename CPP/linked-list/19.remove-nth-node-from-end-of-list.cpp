/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.06%)
 * Total Accepted:    216.8K
 * Total Submissions: 636.2K
 * Testcase Example:  '[1]\n1'
 *
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 *
 *
 * For example,
 *
 *
 * ⁠  Given linked list: 1->2->3->4->5, and n = 2.
 *
 * ⁠  After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 *
 *
 *
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* cur = head;
      int len = 0;
      while(cur){
        len++;
        cur = cur->next;
      }
      if(len==n){
        head = head->next;
        return head;
      }
      cur = head;
      ListNode* pre = head;
      while(len>n){
        pre = cur;
        cur  = cur->next;
        len--;
      }
      //delete node
      pre->next = cur->next;
      return head;

    }
};
