/*
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (41.63%)
 * Total Accepted:    48.9K
 * Total Submissions: 117.2K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int len1 = num1.size()-1;
        int len2 = num2.size()-1;
        int carry = 0;
        int sum = 0;
        int i = 0;
        while(len1>=0 && len2>=0){
            if((num1[len1]-'0' + num2[len2]-'0'+carry)>9){
                sum = (num1[len1]-'0' + num2[len2]-'0'+carry)-10;
                carry = 1;
            }
            else {
                sum = (num1[len1]-'0' + num2[len2]-'0'+carry);
                carry = 0;
            }
            char temp = sum+'0';
            result = temp+result;
            len1--;len2--;
        }
        while(len1>=0){
            if((num1[len1]-'0'+carry)>9){
                sum = (num1[len1]-'0' +carry)-10;
                carry = 1;
            }
            else {
                sum = (num1[len1]-'0' +carry);
                carry = 0;
            }
            char temp = sum+'0';
            result = temp+result;
            len1--;
        }
        while(len2>=0){
            if((num2[len2]-'0'+carry)>9){
                sum = (num2[len2]-'0' +carry)-10;
                carry = 1;
            }
            else {
                sum = (num2[len2]-'0' +carry);
                carry = 0;
            }
            char temp = sum+'0';
            result = temp+result;
            len2--;
        }
        if(carry) result = "1"+result;
        return result;

    }
};
