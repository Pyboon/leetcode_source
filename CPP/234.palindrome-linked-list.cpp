/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (33.21%)
 * Total Accepted:    136.1K
 * Total Submissions: 409.4K
 * Testcase Example:  '[]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        vector<int> result;

        ListNode* cur = head;
        while(cur){
            result.push_back(cur->val);
            cur = cur->next;
        }
        int len = result.size();
        if(!len)return true;
        int i = 0;
        int j = len-1;
        while(i<j){
            if(result[i]!=result[j]){
                return false;
            }
            else {
                i++;j--;
            }
        }
        return true;
    }
};
