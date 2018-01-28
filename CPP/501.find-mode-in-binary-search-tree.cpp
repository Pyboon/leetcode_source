/*
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (37.81%)
 * Total Accepted:    28K
 * Total Submissions: 74.1K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 *
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 *
 * For example:
 * Given BST [1,null,2,2],
 *
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 *
 *
 *
 * return [2].
 *
 *
 * Note:
 * If a tree has more than one mode, you can return them in any order.
 *
 *
 * Follow up:
 * Could you do that without using any extra space? (Assume that the implicit
 * stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        int freq = INT_MIN;
        inorder(root,result);
        int len = result.size();
        int count = 1;

        for(int i = 1;i<len;i++){
            
            if(result[i]==result[i-1])count++;
            else {
                if(freq<count)freq = count;
                count = 1;
            }
        }
        if(count>freq) freq = count;

        count = 1;
        vector<int> res;
        for(int i = 1;i<len;i++){
            if(result[i]==result[i-1])count++;
            else {
                if(freq==count)res.push_back(result[i-1]);
                count = 1;
            }
        }
        if(freq==count)res.push_back(result[len-1]);
        return res;

    }
    void inorder(TreeNode* root, vector<int> &result){
        if(!root) return;
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
};
