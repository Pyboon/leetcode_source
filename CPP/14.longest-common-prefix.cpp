/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.56%)
 * Total Accepted:    227.5K
 * Total Submissions: 721K
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(!len) return "";
        string temp = strs[0];
        int i = 0;
        bool flag = true;
        string result="";
        while(temp[i]!='\0'){
            for (int j = 0;j<len;j++){
                if(strs[j][i]!=temp[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                result += temp[i];
                i++;
            }
            else {
                break;
            }
        }
        return result;
    }
};
