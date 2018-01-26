/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (38.81%)
 * Total Accepted:    195.2K
 * Total Submissions: 502.7K
 * Testcase Example:  '[]'
 *
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 *
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 *
 *
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = head;
        ListNode* cur = head;
        ListNode* nex = head;
        while(cur && cur->next){
          nex = cur->next;
          if(cur!=head){
              pre->next = nex;
              cur->next = nex->next;
              nex->next = cur;

          }
          else{
              cur->next = nex->next;
              nex->next = cur;
              head = nex;
          }
          pre = cur;
          cur = cur->next;

        }
        return head;
    }
};
