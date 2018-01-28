/*
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (47.87%)
 * Total Accepted:    36.4K
 * Total Submissions: 76.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array of size n, find the minimum number of moves
 * required to make all array elements equal, where a move is incrementing n -
 * 1 elements by 1.
 *
 * Example:
 *
 * Input:
 * [1,2,3]
 *
 * Output:
 * 3
 *
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 *
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 *
 *
 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int len = nums.size();
        if(len==1) return 0;
        int count = 0;
        sort(nums.begin(),nums.end());
        count = nums[len-1]-nums[len-2];
        int diff = 0;
        for(int i = 0;i<len-1;i++){
            nums[i]+=count;
            diff +=nums[i+1]-nums[i];
        }
        while(!(this->checkeq(nums))){
            sort(nums.begin(),nums.end());
            int step = diff/(len-1);
            step = (step>0?step:1);
            count+=step;
            for(int i = 0;i<len-1;i++){
                nums[i]+=step;
                diff +=nums[i+1]-nums[i];
            }
        }
        return count;
    }
    bool checkeq(vector<int> nums){
        int len = nums.size();
        for(int i = 1;i<len;i++){
            if(nums[i]!=nums[i-1])return false;
        }
        return true;
    }
};
