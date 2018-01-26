/*
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum
 *
 * algorithms
 * Easy (34.35%)
 * Total Accepted:    189K
 * Total Submissions: 550K
 * Testcase Example:  '[]\n1'
 *
 * 
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        bool result  = false;
        pathSum(root, 0, sum, result);
        return result;
    }
    void pathSum(TreeNode* root, int pathsum, int sum, bool& result){
      if(!root)return;
      if(!result){
        pathsum+= root->val;
        if(!root->left && !root->right){
          if(pathsum==sum){
            result = true;
          }
          return;
        }
        pathSum(root->left, pathsum, sum, result);
        pathSum(root->right, pathsum, sum, result);
      }
    }
};
