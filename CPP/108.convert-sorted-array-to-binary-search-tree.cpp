/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
 *
 * algorithms
 * Easy (42.73%)
 * Total Accepted:    150.9K
 * Total Submissions: 351.9K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return NULL;
        // TreeNode topNode;
        TreeNode* root ;
        array2BST(root, nums,0,nums.size()-1);
        return root;
    }

    void array2BST(TreeNode* &root, vector<int> nums, int start, int end){
      if(start<=end){
        int mid = (start+end)/2.0>(start+end)/2?(start+end)/2.0+0.5:(start+end)/2;
        root = new TreeNode(nums[mid]);
        // root = &tempNode;
        TreeNode* temp = root;
        array2BST(root->left, nums,start,mid-1);
        array2BST(temp->right, nums,mid+1,end);
      }

    }
};
