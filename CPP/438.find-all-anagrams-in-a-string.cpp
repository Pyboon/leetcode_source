/*
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Easy (33.89%)
 * Total Accepted:    51.8K
 * Total Submissions: 152.8K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        vector<int> result;
        if(lens<lenp || lenp<=0) return result;
        string temp(p);
        bool flag = true;
        sort(p.begin(),p.end());
        for(int i = 0;i<=lens-lenp;i++){
            if(i>0&& s[i-1]==s[i-1+lenp]){
                if(flag)result.push_back(i);
                continue;
            }
            flag = true;
            partial_sort_copy(s.begin()+i,s.begin()+i+lenp,temp.begin(),temp.end());
            for(int j = 0;j<lenp;j++){
                if(temp[j]!=p[j]){
                    flag = false;
                    break;
                }
            }
            if(flag)result.push_back(i);
        }
        return result;
    }
};
