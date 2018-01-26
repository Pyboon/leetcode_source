/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word
 *
 * algorithms
 * Easy (31.99%)
 * Total Accepted:    167.8K
 * Total Submissions: 524.6K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
      int len = s.size();
      int result = 0;
      bool flag = true;
      if(len==0) return 0;
      else {
        for (int i =len-1;i>=0;i--){
          if(s[i]==' ' && flag) continue;
          else if(s[i]!=' '){
            result++;
            flag = false;//has character
          }
          else if(s[i]==' ' && !flag){
            return result;
          }
        }
        return result;
      }
    }
};
