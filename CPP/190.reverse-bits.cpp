/*
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (29.45%)
 * Total Accepted:    121K
 * Total Submissions: 410.8K
 * Testcase Example:  '           0 (00000000000000000000000000000000)'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as
 * 00000010100101000001111010011100), return 964176192 (represented in binary
 * as 00111001011110000010100101000000).
 *
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 *
 * Related problem: Reverse Integer
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bits(n);

        int i = 0;
        int j = 31;
        while(i<j){
            if(bits[i]==1 && bits[j]==0){
                bits[i] = 0;
                bits[j] = 1;
            }
            else if(bits[i]==0&& bits[j]==1){
                bits[i] = 1;
                bits[j] = 0;
            }
            i++;
            j--;
        }
        return bits.to_ulong();
    }
};
