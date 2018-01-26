/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome
 *
 * algorithms
 * Easy (26.58%)
 * Total Accepted:    193.6K
 * Total Submissions: 727K
 * Testcase Example:  '""'
 *
 * 
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * 
 * 
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * 
 * 
 * 
 * Note:
 * Have you consider that the string might be empty? This is a good question to
 * ask during an interview.
 * 
 * For the purpose of this problem, we define empty string as valid palindrome.
 * 
 */
class Solution {
public:
    bool isPalindrome(string s) {
      int len = s.size();
      if(len==0)return true;
      int i = 0;
      int j = len-1;
      bool flag = false;
      int count = 0;
      while(i<j){
        if(!((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')|| (s[i]>='0'&&s[i]<='9'))){
          i++;
          count++;
          continue;
        }
        else if(!((s[j]>='a'&&s[j]<='z') || (s[j]>='A'&&s[j]<='Z')||(s[j]>='0'&&s[j]<='9'))){
          j--;
          count++;
          continue;
        }
        else {
          if(s[i]-'9'>0 && s[j]-'9'>0){
            int pre = s[i]-'Z'>0?(s[i]-'a'):(s[i]-'A');
            int post = s[j]-'Z'>0?(s[j]-'a'):(s[j]-'A');
            if(pre==post){
              i++;
              j--;
              flag = true;
              continue;
            }
            else {
              flag = false;
              break;
            }
          }
          else if(s[i]-'9'<=0 && s[j]-'9'<=0){
            int pre = s[i]-'0';
            int post = s[j]-'0';
            if(pre==post){
              i++;
              j--;
              flag = true;
              continue;
            }
            else {
              flag = false;
              break;
            }
          }
          else {
            flag = false;
            break;
          }

        }

      }
      if(len-count<=1)flag  = true;
      return flag;
    }
};
