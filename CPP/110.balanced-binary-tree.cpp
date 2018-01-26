/*
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree
 *
 * algorithms
 * Easy (37.89%)
 * Total Accepted:    202.4K
 * Total Submissions: 533.2K
 * Testcase Example:  '[]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * 
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
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
    bool isBalanced(TreeNode* root) {
      int depth = 0;
      int diff = 0;
      getDepth(root, depth, diff);
      if(diff>1)return false;
      return true;
    }

    int getDepth(TreeNode* root, int depth, int& diff){
      if(!root) return depth;
      depth++;
      int l = getDepth(root->left,depth,diff);
      int r = getDepth(root->right,depth,diff);
      int tempdiff = l>r?l-r:r-l;
      if(diff<tempdiff)diff = tempdiff;
      return l>r?l:r;
    }
};
