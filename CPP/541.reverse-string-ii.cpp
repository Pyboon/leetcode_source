/*
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (43.76%)
 * Total Accepted:    30.8K
 * Total Submissions: 70.4K
 * Testcase Example:  '"abcdefg"\n2'
 *
 *
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 *
 *
 * Example:
 *
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 *
 *
 *
 * Restrictions:
 *
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 *
 */
class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        int n = 0;
        while(n*k*2<len){
            if(len-(n*k*2)<k){
                int i =n*2*k;
                int j = len-1;
                while(i<j){
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    i++;
                    j--;
                }
            }
            else {
                int i =n*2*k;
                int j = n*2*k+k-1;
                while(i<j){
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    i++;
                    j--;
                }
            }
            n++;
        }
        return s;
    }
};
