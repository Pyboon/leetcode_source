/*
 * [389] Find the Difference
 *
 * https://leetcode.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (51.03%)
 * Total Accepted:    91.5K
 * Total Submissions: 179.2K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 *
 * Given two strings s and t which consist of only lowercase letters.
 *
 * String t is generated by random shuffling string s and then add one more
 * letter at a random position.
 *
 * Find the letter that was added in t.
 *
 * Example:
 *
 * Input:
 * s = "abcd"
 * t = "abcde"
 *
 * Output:
 * e
 *
 * Explanation:
 * 'e' is the letter that was added.
 *
 */
class Solution {
public:
    char findTheDifference(string s, string t) {
        int len = s.size();
        if(!len) return t[0];
        int chars[26] = {0};
        int chart[26] = {0};
        for(int i = 0;i<len;i++){
            chars[s[i]-'a']++;
            chart[t[i]-'a']++;
        }
        chart[t[len]-'a']++;
        for(int i = 0;i<26;i++){
            if(chars[i]!=chart[i]){
                return 'a'+i;
            }
        }
    }
};
