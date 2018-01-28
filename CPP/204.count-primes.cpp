/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (26.65%)
 * Total Accepted:    138.2K
 * Total Submissions: 518.5K
 * Testcase Example:  '0'
 *
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i = 2;i<n;i++){
            count+=prime(i);
        }
        return count;
    }

    int prime(int n){
        if(n==2|| n==3 || n==5)return 1;
        if(n%2==0)return 0;
        if(n%3==0)return 0;
        if(n%5==0)return 0;
        int sqrtn = sqrt(n);
        int i;
        for(i = 3;i<=sqrtn;i++){
            if(n%i==0)break;
        }
        if(i>sqrtn)return 1;
        else return 0;
    }
};
