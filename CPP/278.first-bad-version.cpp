/*
 * [278] First Bad Version
 *
 * https://leetcode.com/problems/first-bad-version/description/
 *
 * algorithms
 * Easy (25.89%)
 * Total Accepted:    126.9K
 * Total Submissions: 489.7K
 * Testcase Example:  '1 version\n1 is the first bad version.'
 *
 *
 * You are a product manager and currently leading a team to develop a new
 * product. Unfortunately, the latest version of your product fails the quality
 * check. Since each version is developed based on the previous version, all
 * the versions after a bad version are also bad.
 *
 *
 *
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the
 * first bad one, which causes all the following ones to be bad.
 *
 *
 *
 * You are given an API bool isBadVersion(version) which will return whether
 * version is bad. Implement a function to find the first bad version. You
 * should minimize the number of calls to the API.
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int mid = start+(-start+end)/2;
        
        while(start<mid && mid<end){
            if(isBadVersion(mid)){
                end = mid-1;
                if(!isBadVersion(end))return mid;
            }
            else {
                start = mid+1;
                if(isBadVersion(start))return start;
            }
            mid = start+(-start+end)/2;
        }
        if(start==mid && !isBadVersion(start) && isBadVersion(mid+1))return mid+1;
        else if(end==mid && !isBadVersion(mid-1) && isBadVersion(end))return mid;
        else return mid;
    }
};
