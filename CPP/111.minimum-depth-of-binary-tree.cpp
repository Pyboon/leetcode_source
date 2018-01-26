/*
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree
 *
 * algorithms
 * Easy (33.35%)
 * Total Accepted:    193K
 * Total Submissions: 578.2K
 * Testcase Example:  '[]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
      if(!root) return 0;
        int depth = 0;
        int result = INT_MAX;
        getDepth(root,depth,result);
        return result;
    }
    int getDepth(TreeNode* root, int depth, int& result){
      if(!root)return depth;
      depth++;
      int ldepth = getDepth(root->left,depth,result);
      int rdepth = getDepth(root->right,depth,result);
      int less = 0;
      if(ldepth==depth){
        less = rdepth;
      }
      else if(rdepth==depth){
        less = ldepth;
      }
      else less = (ldepth<rdepth?ldepth:rdepth);
      result = (result>less?less:result);
      return less;
    }
};
