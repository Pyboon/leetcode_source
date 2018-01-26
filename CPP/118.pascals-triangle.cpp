/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle
 *
 * algorithms
 * Easy (39.23%)
 * Total Accepted:    152.6K
 * Total Submissions: 387.8K
 * Testcase Example:  '0'
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * 
 * For example, given numRows = 5,
 * Return
 * 
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int> > result;
      if(numRows==1){
        result.push_back(vector<int>(1,1));
      }
      if(numRows>=2){
        vector<int> temp(1,1);
        result.push_back(temp);
        temp.push_back(1);
        result.push_back(temp);
        for (int i = 2;i<numRows;i++){
          vector<int> temp;
          for (int j = 0;j<i+1;j++){
            if(j ==0 || j==i){
              temp.push_back(1);
            }
            else{
              temp.push_back(result[i-1][j-1]+result[i-1][j]);
            }
          }
          result.push_back(temp);
        }
      }
      return result;
    }
};
