/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii
 *
 * algorithms
 * Easy (37.46%)
 * Total Accepted:    132.6K
 * Total Submissions: 353.2K
 * Testcase Example:  '0'
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 * 
 * 
 * For example, given k = 3,
 * Return [1,3,3,1].
 * 
 * 
 * 
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> result(rowIndex+1,1);
      if(rowIndex>1){
        for (int i = 1;i<rowIndex;i++){
          for(int j = 1;j<=i;j++){
            result[0] = result[j];
            result[j] = result[j]+result[rowIndex];
            result[rowIndex] = result[0];
          }
        }
      }
      return result;
    }
 };
