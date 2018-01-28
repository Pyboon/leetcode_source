/*
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (50.33%)
 * Total Accepted:    26.9K
 * Total Submissions: 53.4K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 *
 * Example 1:
 *
 * Input:
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 *
 * Target = 9
 *
 * Output: True
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 *
 * Target = 28
 *
 * Output: False
 *
 *
 *
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        vector<int> lists;
        inorder(root, lists);
        int len = lists.size();
        if(len<2) return false;
        int i = 0,j=len-1;
        while(i<j){
            if(lists[i]+lists[j]==k)return true;
            else if(lists[i]+lists[j]<k)i++;
            else j--;
        }
        return false;
    }
    void inorder(TreeNode* root, vector<int> &lists){
        if(!root) return;
        inorder(root->left,lists);
        lists.push_back(root->val);
        inorder(root->right,lists);
    }

};
