/*
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (40.09%)
 * Total Accepted:    46.2K
 * Total Submissions: 115K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 *
 * Find the number of paths that sum to a given value.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 *
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 *
 * Example:
 *
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 *
 * Return 3. The paths that sum to 8 are:
 *
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
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
    int pathSum(TreeNode* root, int sum) {
        vector<int> result;
        int count = 0;
        traverse(root,result,count,sum);
        return count;
    }
    void traverse(TreeNode *root, vector<int> result, int &count,int sum){
        if(!root) return;
        result.push_back(0);
        int len = result.size();
        for(int i = 0;i<len;i++){
            result[i]+= root->val;
            if(result[i]==sum)count++;
        }
        if(root->left)traverse(root->left,result,count,sum);
        if(root->right)traverse(root->right,result,count,sum);
    }
};
