/*
 * [476] Number Complement
 *
 * https://leetcode.com/problems/number-complement/description/
 *
 * algorithms
 * Easy (60.94%)
 * Total Accepted:    67.2K
 * Total Submissions: 110.1K
 * Testcase Example:  '5'
 *
 * Given a positive integer, output its complement number. The complement
 * strategy is to flip the bits of its binary representation.
 *
 * Note:
 *
 * The given integer is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You could assume no leading zero bit in the integer’s binary
 * representation.
 *
 *
 *
 * Example 1:
 *
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits),
 * and its complement is 010. So you need to output 2.
 *
 *
 *
 * Example 2:
 *
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and
 * its complement is 0. So you need to output 0.
 *
 *
 */
class Solution {
public:
    int findComplement(int num) {
        bitset<32> bits(num);
        bool flag = false;
        for(int i = 31;i>=0;i--){
            if(bits[i]==1){
                bits[i] = 0;
                flag = true;
            }
            else if((bits[i]==0) && flag){
                bits[i] = 1;
            }
        }
        return bits.to_ulong();
    }
};
