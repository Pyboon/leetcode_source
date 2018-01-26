/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists
 *
 * algorithms
 * Easy (39.30%)
 * Total Accepted:    279.3K
 * Total Submissions: 710.9K
 * Testcase Example:  '[]\n[]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

      if(l1==NULL){
        return l2;
      }
      if(l2==NULL){
        return l1;
      }
      ListNode* resl;
      ListNode head(0);
      resl = &head;// hold head pointer
      while(l1!=NULL && l2!=NULL){
        if(l1->val<l2->val){
          resl->next = l1;
          l1 = l1->next;
        }
        else {
          resl->next = l2;
          l2 = l2->next;
        }
        resl = resl->next;
      }
      resl->next = l1?l1:l2;
      return head.next;
    }
};
