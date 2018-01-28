/*
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (32.68%)
 * Total Accepted:    129.7K
 * Total Submissions: 396.8K
 * Testcase Example:  '[]\n0'
 *
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 *
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len<2) return false;
        vector<int > index;
        for(int i = 0;i<len;i++){
            index.push_back(i);
        }
        this->quicksort(nums,index,0,len-1);

        for(int i = 0;i<len-1;i++){
            if(nums[i]==nums[i+1]){
                if(abs(index[i]-index[i+1])<=k){
                    return true;
                }
            }
        }

        return false;

    }

    void swap(int& a , int& b){
        a = a+b;
        b = a-b;
        a = a-b;
    }
    int partition(vector<int>& nums, vector<int>& index, int left, int right, int pivot){
        int pivotval = nums[pivot];
        int storeidx = left;
        this->swap(nums[pivot],nums[right]);
        if(nums[pivot]!=nums[right])this->swap(index[pivot],index[right]);
        for(int i =left;i<right;i++){
            if(nums[i]<pivotval){
                if(i!=storeidx){
                    this->swap(nums[i],nums[storeidx]);
                    if(nums[i]!=nums[storeidx])this->swap(index[i],index[storeidx]);
                }
                storeidx++;
            }
        }
        this->swap(nums[storeidx],nums[right]);
        if(nums[right]!=nums[storeidx])this->swap(index[right],index[storeidx]);
        return storeidx;
    }

    void quicksort(vector<int>& nums, vector<int>& index, int left, int right){
        if(right>left){
            int pivot = (left+right)/2;
            int newpivot = this->partition(nums, index, left, right, pivot);
            this->quicksort(nums,index, left,newpivot-1);
            this->quicksort(nums,index, newpivot+1,right);
        }
    }
};
