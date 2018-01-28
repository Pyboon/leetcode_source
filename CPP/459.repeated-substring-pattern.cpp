/*
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (38.22%)
 * Total Accepted:    45K
 * Total Submissions: 117.9K
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together.
 * You may assume the given string consists of lowercase English letters only
 * and its length  will not exceed 10000.
 *
 * Example 1:
 *
 * Input: "abab"
 *
 * Output: True
 *
 * Explanation: It's the substring "ab" twice.
 *
 *
 *
 * Example 2:
 *
 * Input: "aba"
 *
 * Output: False
 *
 *
 *
 * Example 3:
 *
 * Input: "abcabcabcabc"
 *
 * Output: True
 *
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 *
 *
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        if(len<2) return false;
        int chars[26] = {0};
        for(int i = 0;i<len;i++){
            chars[s[i]-'a']++;
        }
        return false;
    }
};
