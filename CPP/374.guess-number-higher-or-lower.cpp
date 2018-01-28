/*
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (36.06%)
 * Total Accepted:    62.9K
 * Total Submissions: 174K
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number is higher or
 * lower.
 *
 * You call a pre-defined API guess(int num) which returns 3 possible results
 * (-1, 1, or 0):
 *
 * -1 : My number is lower
 * ⁠1 : My number is higher
 * ⁠0 : Congrats! You got it!
 *
 *
 * Example:
 *
 * n = 10, I pick 6.
 *
 * Return 6.
 *
 *
 */
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int i = 1;
        int j = n;
        int mid = i+(j-i)/2;
        while(i<mid && mid<j){
            int res = guess(mid);
            // cout<<mid<<" ";
            if(res==1){
                i = mid+1;
            }
            else if(res==-1){
                j= mid-1;
            }
            else return mid;
            mid = i+(j-i)/2;
        }
        if(guess(i)==0) return i;
        else if(guess(j)==0) return j;

    }
};
