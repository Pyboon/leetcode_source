/*
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (47.02%)
 * Total Accepted:    188.2K
 * Total Submissions: 400K
 * Testcase Example:  '""\n""'
 *
 * Given two strings s and t, write a function to determine if t is an anagram
 * of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        if(slen!=tlen) return false;
        vector<int> chars(26,0);
        vector<int> chart(26,0);

        for(int i = 0;i<slen;i++){
            chars[s[i]-'a']++;
            chart[t[i]-'a']++;
        }
        for(int i = 0;i<26;i++){
            if(chars[i]!=chart[i])return false;
        }
        return true;

    }
};
