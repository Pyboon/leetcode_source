/*
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (26.80%)
 * Total Accepted:    122.3K
 * Total Submissions: 456.2K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    string convertToTitle(int n) {
        if(!n) return "";
        if(n>INT_MAX) return "";
        int ipart = (n-1)/26;

        string result = "";
        while(ipart){
            char temp = 'A'+((ipart-1)%26);
            result = temp + result;
            ipart = (ipart-1)/26;
        }
        result += 'A'+(n-1)%26;


        return result;
    }
};
