/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.16%)
 * Total Accepted:    92K
 * Total Submissions: 195K
 * Testcase Example:  '"leetcode"'
 *
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 *
 *
 *
 *
 * Note: You may assume the string contain only lowercase letters.
 *
 */
class Solution {
public:
    int firstUniqChar(string s) {
        int chars[26] = {0};
        int order[26] = {0};
        int len = s.size();
        if(len<2) return len-1;
        for(int i = 0;i<len;i++){
            if(chars[s[i]-'a']==0){
                order[s[i]-'a'] = i;
            }
            chars[s[i]-'a']++;
        }
        int first = INT_MAX;
        for(int i = 0;i<26;i++){
            if(chars[i]==1){
                first = order[i]>first?first:order[i];
            }
        }
        if(first ==INT_MAX) return -1;
        return first;
    }
};
