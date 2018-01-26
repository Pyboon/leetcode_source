/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr
 *
 * algorithms
 * Easy (28.56%)
 * Total Accepted:    223.9K
 * Total Submissions: 783.9K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 
 * Implement strStr().
 * 
 * 
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * 
 * Example 1:
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = -1;
        int slen = haystack.size();
        int plen = needle.size();

        if(plen==0) return 0;

        //init next
        int next[plen];
        next[0] = -1;
        int k = -1; //longest common prefix and subfix
        int j = 0; //pattern postion
        while(j<plen-1){
          if(k==-1 || needle[j] == needle[k] ){
            j++;
            k++;
            next[j] = k;
          }
          else{
              k = next[k];
          }
        }
        int i = 0; // search postion
        j = 0; // pattern postion
        while(i<slen && j<plen){
          if(j==-1 || haystack[i]==needle[j]){
            ++i;
            ++j;
          }
          else {
            j = next[j];
          }
        }
        if(j==plen){
          return i-plen;
        }
        else return -1;


    }
};
