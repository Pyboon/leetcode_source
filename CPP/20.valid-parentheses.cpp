/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses
 *
 * algorithms
 * Easy (33.66%)
 * Total Accepted:    264.1K
 * Total Submissions: 784.5K
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> strstack;
        for(int i = 0;i<s.length();i++){
          if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            strstack.push(s[i]);
          }
          else if(s[i]==')' || s[i]==']' || s[i]=='}'){
            if(strstack.empty()){
              return false;
            }
            if((strstack.top()=='(' && s[i]==')') || (strstack.top()=='[' && s[i]==']') || (strstack.top()=='{' && s[i]=='}')){
              strstack.pop();
            }
            else {
              return false;
            }
          }
        }
        if(strstack.empty()){
          return true;
        }
        else {
          return false;
        }
    }
};
