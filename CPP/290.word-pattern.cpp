/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (33.26%)
 * Total Accepted:    93.7K
 * Total Submissions: 281.5K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * ⁠Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 *
 * Examples:
 *
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 *
 *
 *
 *
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 *
 *
 * Credits:Special thanks to @minglotus6 for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> result;
        parsestr(str,result);
        if(result.size()!=pattern.size())return false;
        int len = pattern.size();
        unordered_map<char,string> pmap;
        unordered_map<string,char> smap;
        // unordered_map<char,string>:: iterator got;
        for(int i =0;i<len;i++){
            if(pmap.find(pattern[i])==pmap.end()){
                pmap.insert({{pattern[i],result[i]}});
            }
            if(smap.find(result[i])==smap.end()){
                smap.insert({{result[i],pattern[i]}});
            }
            if(pmap.find(pattern[i])->second!=result[i] || smap.find(result[i])->second!=pattern[i])return false;
        }
        return true;

    }
    void parsestr(string str, vector<string>& result){
        int len = str.size();
        if(!len) return;
        int lastpos = 0;
        for(int i=0;i<len;i++){
            if(str[i]==' '){
                string temp(str.begin()+lastpos,str.begin()+i);

                result.push_back(temp);
                lastpos = i+1;
            }
        }
        if(lastpos<len){
            string temp(str.begin()+lastpos,str.end());

            result.push_back(temp);
        }
    }
};
