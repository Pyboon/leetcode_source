/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (39.99%)
 * Total Accepted:    139.3K
 * Total Submissions: 347.4K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 *
 * For example, given the following binary tree:
 *
 *
 *
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 *
 *
 *
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root) return result;
        int level = 1;
        vector<int> nodes;
        traverse(root,nodes,result);
        return result;
    }
    void traverse(TreeNode* root, vector<int> nodes, vector<string>& result){
        if(!root)return;
        if(!root->left && !root->right){
            nodes.push_back(root->val);
            int len = nodes.size();
            string s = "";
            for(int i = 0;i<len;i++){
                if(i==0){
                    s+= to_string(nodes[i]);
                }
                else{
                    s= s+ "->"+to_string(nodes[i]);
                }
            }
            result.push_back(s);
        }
        else {
            nodes.push_back(root->val);
            if(root->left)traverse(root->left,nodes,result);
            if(root->right)traverse(root->right,nodes,result);
        }
    }
};
