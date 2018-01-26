/*
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (24.39%)
 * Total Accepted:    126.5K
 * Total Submissions: 518.4K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a list, rotate the list to the right by k places, where k is
 * non-negative.
 *
 *
 *
 * Example:
 *
 * Given 1->2->3->4->5->NULL and k = 2,
 *
 * return 4->5->1->2->3->NULL.
 *
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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while(cur){
            len++;
            if(cur->next)cur = cur->next;
            else break;
        }
        if(len==0) return head;
        k = len-k%len;
        ListNode* pos = head;
        cur->next = head;//cycle
        while(k){
            cur = pos;
            pos = pos->next;
            k--;
        }
        cur->next = NULL;
        return pos;

    }
};
