/*
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (33.22%)
 * Total Accepted:    115.5K
 * Total Submissions: 347.6K
 * Testcase Example:  '[]\n0'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 *
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
       ListNode* cur = head;
       ListNode tempnode(0);
       ListNode* base = &tempnode;
       base->next = head;
       ListNode* precur = base;
       ListNode* prebase = base;
       while(cur){
           if(cur->val>=x){
               precur = cur;
               cur = cur->next;
           }
           else{
               precur->next = cur->next;
               cur->next = prebase->next;
               prebase->next= cur;
               prebase = cur;
               cur = precur->next;
           }
       }
       return base->next;
    }
};
