/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (30.83%)
 * Total Accepted:    162.4K
 * Total Submissions: 526.7K
 * Testcase Example:  'No intersection: []\n[]'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 * 
 * For example, the following two linked lists: 
 * 
 * A:          a1 → a2
 * ⁠                  ↘
 * ⁠                    c1 → c2 → c3
 * ⁠                  ↗            
 * B:     b1 → b2 → b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns. 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * 
 * 
 * 
 * Credits:Special thanks to @stellari for adding this problem and creating all
 * test cases.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *Anode = headA;
        ListNode *Bnode = headB;
        ListNode *result = NULL;
        // while(Anode){
        //     Bnode = headB;
        //     while(Bnode){
        //         if(Anode->val==Bnode->val && Anode->next== Bnode->next){
        //             result = Anode;
        //             break;
        //         }
        //         Bnode = Bnode->next;
        //     }
        //     if(result){
        //         break;
        //     }
        //     Anode = Anode->next;
        // }
        int countA = 0;
        int countB = 0;
        while(Anode){
            countA++;
            Anode = Anode->next;
        }
        while(Bnode){
            countB++;
            Bnode = Bnode->next;
        }
        ListNode *big = headA;
        ListNode *small = headA;
        int diff;
        if(countA>countB){
            big = headA;
            small = headB;
            diff = countA-countB;
        }
        else {
            big = headB;
            small = headA;
            diff = countB-countA;
        }

        while(big){
            if(diff){
                big = big->next;
                diff--;
                continue;
            }
            else{
                if(big->val==small->val && big->next==small->next){
                    result = big;
                    break;
                }
                else{
                    small = small ->next;
                    big = big->next;
                }
            }

        }
        return result;
    }
};
