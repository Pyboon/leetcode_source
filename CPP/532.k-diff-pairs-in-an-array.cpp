/*
 * [532] K-diff Pairs in an Array
 *
 * https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
 *
 * algorithms
 * Easy (28.23%)
 * Total Accepted:    29.8K
 * Total Submissions: 105.5K
 * Testcase Example:  '[3,1,4,1,5]\n2'
 *
 *
 * Given an array of integers and an integer k, you need to find the number of
 * unique k-diff pairs in the array. Here a k-diff pair is defined as an
 * integer pair (i, j), where i and j are both numbers in the array and their
 * absolute difference is k.
 *
 *
 *
 * Example 1:
 *
 * Input: [3, 1, 4, 1, 5], k = 2
 * Output: 2
 * Explanation: There are two 2-diff pairs in the array, (1, 3) and (3,
 * 5).Although we have two 1s in the input, we should only return the number of
 * unique pairs.
 *
 *
 *
 * Example 2:
 *
 * Input:[1, 2, 3, 4, 5], k = 1
 * Output: 4
 * Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3,
 * 4) and (4, 5).
 *
 *
 *
 * Example 3:
 *
 * Input: [1, 3, 1, 5, 4], k = 0
 * Output: 1
 * Explanation: There is one 0-diff pair in the array, (1, 1).
 *
 *
 *
 * Note:
 *
 * The pairs (i, j) and (j, i) count as the same pair.
 * The length of the array won't exceed 10,000.
 * All the integers in the given input belong to the range: [-1e7, 1e7].
 *
 *
 */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        this->qsort(nums,0,len-1);
        // for(int i = 0;i<len;i++){
        //     cout<<nums[i]<<" ";
        // }
        int count = 0;
        for(int i = 0;i<len-1;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j = i+1;j<len;j++){
                if(nums[j]-nums[i]<k) continue;
                else if (nums[j]-nums[i]==k)
                {
                    count++;
                    break;
                }
                else if(nums[j]-nums[i]>k)break;
            }
        }
        return count;
    }
    void qsort(vector<int>& nums, int left, int right){
        if(left<right){
            int pivot = (left+right)/2;
            int newpivot = this->partition(nums,left,right,pivot);
            this->qsort(nums,left,newpivot-1);
            this->qsort(nums,newpivot+1,right);
        }
    }

    int partition(vector<int>& nums, int left, int right, int pivot){
        int pivotval = nums[pivot];
        int storeidx = left;
        if(right!=pivot)this->swap(nums[pivot],nums[right]);
        for(int i = left;i<right;i++){
            if(nums[i]<pivotval){
                if(i!=storeidx)this->swap(nums[i],nums[storeidx]);
                storeidx++;
            }
        }
        if(right!=storeidx)this->swap(nums[storeidx],nums[right]);
        return storeidx;
    }
    void swap(int& a, int& b){
        a = a+b;
        b = a-b;
        a = a-b;
    }
};
