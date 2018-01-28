/*
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (30.18%)
 * Total Accepted:    23.6K
 * Total Submissions: 78.2K
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * Suppose you have a long flowerbed in which some of the plots are planted and
 * some are not. However, flowers cannot be planted in adjacent plots - they
 * would compete for water and both would die.
 *
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means
 * empty and 1 means not empty), and a number n, return if n new flowers can be
 * planted in it without violating the no-adjacent-flowers rule.
 *
 * Example 1:
 *
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 *
 *
 *
 * Note:
 *
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 *
 *
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        vector<int> result(len,0);
        if(n==0)return true;
        bool left = false;
        bool right = false;
        for(int i = 0;i<len;i++){
            if(flowerbed[i]==1){
                if(i-1>=0){
                    result[i] = result[i-1];
                }
            }
            else {
                if((i-1>=0 && flowerbed[i-1]==0) || i-1<0){
                    left = true;
                }
                else {
                    left = false;
                }
                if((i+1<len && flowerbed[i+1]==0) || i+1>=len){
                    right = true;
                }
                else {
                    right = false;
                }
                if(left && right){
                    result[i] = i-1>=0?result[i-1]+1:1;
                    flowerbed[i] = 1;
                }
                else {
                    result[i] = i-1>=0?result[i-1]:0;
                }

            }
        }
        // for(int i = 0;i<len;i++){
        //     cout<<result[i]<<" ";
        // }
        return result[len-1]>=n?true:false;
    }
};
