/*
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (47.33%)
 * Total Accepted:    74.8K
 * Total Submissions: 157.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 *
 * Example:
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        bool left=false;
        traverse(root,left,result);
        return result;
    }

    void traverse(TreeNode *root, bool left, int &result){
        if(!root)return;
        if(!(root->left) && !(root->right) && left){
            result += root->val;
        }
        if(root->left){
            traverse(root->left,true,result);
        }
        if(root->right){
            traverse(root->right,false,result);
        }
    }
};
