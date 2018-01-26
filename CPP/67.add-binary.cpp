/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary
 *
 * algorithms
 * Easy (33.20%)
 * Total Accepted:    172K
 * Total Submissions: 517.9K
 * Testcase Example:  '"0"\n"0"'
 *
 * 
 * Given two binary strings, return their sum (also a binary string).
 * 
 * 
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        if(alen==0 || blen==0){
          return a+b;
        }
        else {
          int len = alen>blen?alen:blen;
          string s = alen>blen?a:b;
          int carry = 0;
          int temp = 0;
          while(len){
            if(alen<=0){
              temp = b[blen-1]-'0'+carry;
            }
            else if(blen<=0){
              temp = a[alen-1]-'0'+carry;
            }
            else {
              temp = a[alen-1]-'0'+b[blen-1]-'0'+carry;
            }
            s[len-1] = (temp)%2+'0';
            carry = (temp)/2;
            len--;alen--;blen--;
          }
          if(carry){
            return "1"+s;
          }
          else {
            return s;
          }
        }
    }
};
