/*
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (41.01%)
 * Total Accepted:    30.7K
 * Total Submissions: 74.7K
 * Testcase Example:  '26'
 *
 *
 * Given an integer, write an algorithm to convert it to hexadecimal. For
 * negative integer, two’s complement method is used.
 *
 *
 * Note:
 *
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is
 * zero, it is represented by a single zero character '0'; otherwise, the first
 * character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You must not use any method provided by the library which converts/formats
 * the number to hex directly.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * 26
 *
 * Output:
 * "1a"
 *
 *
 *
 * Example 2:
 *
 * Input:
 * -1
 *
 * Output:
 * "ffffffff"
 *
 *
 */
class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        bitset<32> bits(num);
        string result = "";
        for(int i = 7;i>=0;i--){
            int sum = 0;
            int multi = 1;
            for(int j = 0;j<4;j++){
                sum+=multi*bits[i*4+j];
                multi*=2;
            }
            if(sum==0 && result.size()>0){
                result +="0";
            }
            else if(sum>0 && sum<10){
                result+= '0'+sum;
            }
            else if(sum>9){
                result+='a'+sum-10;
            }
        }
        return result;
    }
};
