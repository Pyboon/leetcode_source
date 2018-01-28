/*
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (46.58%)
 * Total Accepted:    11.4K
 * Total Submissions: 24.3K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 *
 * Example 1:
 *
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation:
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 *
 *
 *
 *
 * Example 2:
 *
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 *
 *
 *
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 *
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> temp(nums);
        sort(temp.begin(),temp.end());

        vector<int> result;
        int count = 1;
        int maxcount = 1;
        for(int i = 1;i<len;i++){
            if(temp[i]==temp[i-1]){
                count++;
                if(maxcount<count){
                    maxcount = count;
                }
            }
            else{
                count=1;
            }
        }
        if(maxcount==1)return 1;
        count = 1;

        for(int i = 1;i<len;i++){
            if(temp[i]==temp[i-1]){
                count++;
                if(count==maxcount){
                    result.push_back(temp[i-1]);
                }
            }
            else{
                count = 1;
            }
        }

        int rlen = result.size();

        int minlen = 50000;
        int minpos = INT_MAX;
        int maxpos = INT_MIN;
        for(int i =0;i<rlen;i++){
             minpos = INT_MAX;
             maxpos = INT_MIN;
            for(int j = 0;j<len;j++){
                if(nums[j]==result[i]){
                    if(j<minpos)minpos = j;
                    else if(j>maxpos)maxpos = j;
                }
            }
            minlen = maxpos-minpos<minlen?maxpos-minpos:minlen;
        }
        return minlen+1;
    }
};
