/*
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree
 *
 * algorithms
 * Easy (53.37%)
 * Total Accepted:    286.1K
 * Total Submissions: 534.9K
 * Testcase Example:  '[]'
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
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
    int maxDepth(TreeNode* root) {
      if(root==NULL) return 0;
      else{
        int ldepth = maxDepth(root->left)+1;
        int rdepth = maxDepth(root->right)+1;
        return ldepth>rdepth?ldepth:rdepth;
      }
    }
    // void traverse(TreeNode* root ){
    //   if(root!=NULL){
    //
    //   }
    // }
};
