/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii
 *
 * algorithms
 * Easy (41.01%)
 * Total Accepted:    147.4K
 * Total Submissions: 358.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> result;
      levelTraverse(root, &result, 1);
      return result;
    }

    void levelTraverse(TreeNode* root, vector<vector<int>>* lvec, int depth){
      if(root!=NULL){
        if((*lvec).size()<depth){
          vector<int> curLev;
          vector<vector<int>>::iterator it = (*lvec).begin();
          (*lvec).insert(it,curLev);
        }
         (*lvec)[(*lvec).size()-depth].push_back(root->val);

        levelTraverse(root->left, lvec, depth+1);
        levelTraverse(root->right, lvec, depth+1);

      }
    }
};
