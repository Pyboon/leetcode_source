/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say
 *
 * algorithms
 * Easy (35.68%)
 * Total Accepted:    163.3K
 * Total Submissions: 457.6K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * 
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * Example 1:
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
      if(!n) return "";
      vector<string> result(n,"");
      result[0] = "1";
      for (int i = 1;i<n;i++){
        int count = 1;
        string temp = result[i-1];
        int j = 1;
        for (;j<temp.size();j++){
          if(temp[j]-temp[j-1]==0){
            count++;

          }
          else {
            char chartemp = count+'0';
            result[i] += chartemp;
            result[i] += temp[j-1];
            count = 1;

          }
        }
        char chartemp = count+'0';
        result[i] += chartemp;
        result[i] += temp[j-1];
        // cout<<result[i]<<endl;
      }
      return result[n-1];

    }
};
