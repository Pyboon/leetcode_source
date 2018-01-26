/*
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (29.78%)
 * Total Accepted:    125K
 * Total Submissions: 419.6K
 * Testcase Example:  '[]'
 *
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
        if(!head) return head;
        ListNode* pre = head;
        ListNode* cur = head;
        bool flag = false;
        while(cur){
            if(cur && cur->next){
                if(cur->val == cur->next->val){
                    if(cur==head){
                        head = cur->next;
                        pre = head;
                    }
                    else{
                        pre->next = cur->next;
                    }

                    flag = true;
                }
                else {
                    if(flag){
                        if(cur==head){
                            head = cur->next;
                            pre = head;
                        }
                        else {
                            pre->next = cur->next;
                        }
                        flag = false;
                    }
                    else {
                        pre = cur;
                    }
                }
            }
            else {
                if(flag){
                    if(cur==head){
                        head = cur->next;
                        pre = head;
                    }
                    else {
                        pre->next = cur->next;
                    }
                    flag = false;
                }
                else {
                    pre = cur;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};
