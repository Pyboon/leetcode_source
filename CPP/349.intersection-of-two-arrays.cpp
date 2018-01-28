/*
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (47.68%)
 * Total Accepted:    114.3K
 * Total Submissions: 239.4K
 * Testcase Example:  '[]\n[]'
 *
 *
 * Given two arrays, write a function to compute their intersection.
 *
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 *
 * Note:
 *
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 *
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> result;
        if(len1==0 || len2==0)return result;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i = 0;
        int j = 0;
        int count = 0;
        while(i<len1 && j<len2){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else {
                if(count==0 || result[count-1]!=nums1[i]){
                    result.push_back(nums1[i]);
                    count++;
                }
                i++;j++;
            }
        }
        return result;
    }
};
