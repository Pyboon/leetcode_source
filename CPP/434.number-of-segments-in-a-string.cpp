/*
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (36.70%)
 * Total Accepted:    32.9K
 * Total Submissions: 89.5K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 *
 * Please note that the string does not contain any non-printable characters.
 *
 * Example:
 *
 * Input: "Hello, my name is John"
 * Output: 5
 *
 *
 */
class Solution {
public:
    int countSegments(string s) {
        int len = s.size();
        if(!len) return 0;
        int count  =0;
        int result = 0;
        for(int i = 0;i<len;i++){
            if(s[i]==' '){
                if(count){
                    result++;
                    count = 0;
                }
                else count = 0;
            }
            else count++;
        }
        if(count)result++;
        return result;
    }
};
