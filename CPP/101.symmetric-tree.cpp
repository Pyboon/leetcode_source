/*
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree
 *
 * algorithms
 * Easy (39.47%)
 * Total Accepted:    212.9K
 * Total Submissions: 537.7K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
      if(root!=NULL){
        return judgeSymmetric(root->left, root->right);
      }
      else return true;
    }
    bool judgeSymmetric(TreeNode* left, TreeNode* right){
      if(left!=NULL && right!=NULL && left->val==right->val){
          if(judgeSymmetric(left->left, right->right) && judgeSymmetric(left->right, right->left)){
            return true;
          }
          else return false;
      }
      else if(left==NULL && right==NULL){
        return true;
      }
      else return false;
    }
};
