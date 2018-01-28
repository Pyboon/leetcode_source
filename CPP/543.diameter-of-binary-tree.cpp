/*
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (44.94%)
 * Total Accepted:    44K
 * Total Submissions: 97.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 *
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 *
 *
 *
 * Example:
 * Given a binary tree
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \
 * ⁠     4   5
 *
 *
 *
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxd = 0;
        int level = 0;
        traverse(root,level,maxd);
        return maxd;
    }
    int traverse(TreeNode* root, int level, int &maxd){
        if(!root) return level;
        level ++;
        int leftl = traverse(root->left,level,maxd);
        int rightl = traverse(root->right,level,maxd);
        if(maxd<(leftl+rightl-2*level)){
            maxd = leftl+rightl-2*level;
        }
        return leftl>rightl?leftl:rightl;
    }
};
