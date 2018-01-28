/*
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (25.08%)
 * Total Accepted:    153.9K
 * Total Submissions: 613.6K
 * Testcase Example:  '[1]\n0'
 *
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
 * [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 *
 *
 * [show hint]
 * Hint:
 * Could you do it in-place with O(1) extra space?
 *
 *
 * Related problem: Reverse Words in a String II
 *
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        // vector<int> temparr(nums.begin()+len-k,nums.end());
        // for(int i = len-k-1;i>=0;i--){
        //     nums[i+k] = nums[i];
        // }
        // for (int i = 0;i<k;i++){
        //     nums[i] = temparr[i];
        // }

        //another method
        this->invert(nums,0,len-k);
        this->invert(nums,len-k,k);
        this->invert(nums,0,len);
    }
    void invert(vector<int>& nums, int start, int n){
        if(n<=0)return;
        if(start<0)return;
        int end = start +n-1;
        while(start<end){
            nums[start] = nums[start]+nums[end];
            nums[end] = nums[start]-nums[end];
            nums[start] = nums[start]-nums[end];
            start++;
            end--;
        }
    }
};
