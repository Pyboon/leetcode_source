/*
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (34.34%)
 * Total Accepted:    123.6K
 * Total Submissions: 359.7K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> smap;
        unordered_map<char,char> tmap;
        int len = s.size();
        for(int i = 0;i<len;i++){
            if(smap.find(s[i])==smap.end()){
                smap.insert({{s[i],t[i]}});
            }
            if(tmap.find(t[i])==tmap.end()){
                tmap.insert({{t[i],s[i]}});
            }
            if((smap.find(s[i]))->second!=t[i] || (tmap.find(t[i]))->second!=s[i])return false;
        }
        return true;
    }
};
