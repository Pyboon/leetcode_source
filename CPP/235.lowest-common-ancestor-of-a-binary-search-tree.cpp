/*
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (39.52%)
 * Total Accepted:    173.4K
 * Total Submissions: 438.8K
 * Testcase Example:  '[2,1]\nnode with value 2\nnode with value 1'
 *
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 *
 *
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes v and w as the lowest node in T that has both v
 * and w as descendants (where we allow a node to be a descendant of
 * itself).”
 *
 *
 *
 * ⁠       _______6______
 * ⁠      /              \
 * ⁠   ___2__          ___8__
 * ⁠  /      \        /      \
 * ⁠  0      _4       7       9
 * ⁠        /  \
 * ⁠        3   5
 *
 *
 *
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another
 * example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of
 * itself according to the LCA definition.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = NULL;
        finddescendants(root, p, q, result);
        return result;
    }

    bool finddescendants(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result){
        if(!root)return false;
        if(result)return false;
        bool curflag = false;
        if(root==p || root==q)curflag = true;
        bool lflag = finddescendants(root->left, p, q, result);
        bool rflag = finddescendants(root->right, p, q, result);
        if(curflag+lflag+rflag>1){
            result = root;
            return true;
        }
        else return curflag+lflag+rflag;


    }
};
