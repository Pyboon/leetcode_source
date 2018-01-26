/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array
 *
 * algorithms
 * Easy (32.13%)
 * Total Accepted:    197.5K
 * Total Submissions: 614.8K
 * Testcase Example:  '[1]\n1\n[]\n0'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * 
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2. The number of elements
 * initialized in nums1 and nums2 are m and n respectively.
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

       //  vector<int>::iterator it1 = nums1.begin();
       //  vector<int>::iterator it2 = nums2.begin();
       // while(it2!=nums2.end()){
       //   if((*it1)>(*it2)){
       //     nums1.insert(it1, *it2);
       //     ++it2;
       //   }
       //   else{
       //     ++it1;
       //   }
       // }'
       int i = m-1;
       int j = n-1;
       int k = m+n-1;
       while(j>=0 && i>=0){
         if(nums1[i]>nums2[j]){
           nums1[k] = nums1[i];
           k--;i--;
         }
         else {
           nums1[k] = nums2[j];
           k--;j--;
         }
       }
       if(j>=0){
         while(j>=0){
           nums1[k] = nums2[j];
           k--;j--;
         }
       }
    }
};
