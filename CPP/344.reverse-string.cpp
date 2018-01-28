/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (59.73%)
 * Total Accepted:    202.4K
 * Total Submissions: 338.8K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 *
 *
 * Example:
 * Given s = "hello", return "olleh".
 *
 */
class Solution {
public:
    string reverseString(string s) {
        int len = s.size();
        int i = 0;
        int j = len-1;
        char temp;
        while(i<j){

            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s;
    }
};
