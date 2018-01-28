/*
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (55.85%)
 * Total Accepted:    31.5K
 * Total Submissions: 56.3K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 *
 * Example 1:
 *
 * Input:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 *
 *
 *
 * Note:
 *
 * The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> lists;
        vector<double> result;
        if(!root) return result;
        traverse(root,lists,1);
        int row = lists.size();

        for(int i = 0;i<row;i++){
            long sum = 0;
            int col = lists[i].size();
            for(int j = 0;j<col;j++){
                sum+=lists[i][j];
            }
            result.push_back(((double)sum)/col);
        }
        return result;
    }
    void traverse(TreeNode* root, vector<vector<int>> &lists, int level){
        if(!root) return;
        if(level>lists.size()){
            lists.push_back(vector<int>(1,root->val));
        }
        else {
            lists[level-1].push_back(root->val);
        }
        if(root->left) traverse(root->left,lists,level+1);
        if(root->right) traverse(root->right,lists,level+1);
    }
};
