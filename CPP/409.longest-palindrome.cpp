/*
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (45.58%)
 * Total Accepted:    55.8K
 * Total Submissions: 122.2K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 *
 *
 * Example:
 *
 * Input:
 * "abccccdd"
 *
 * Output:
 * 7
 *
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 *
 *
 */
class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();
        if(len<2) return len;
        int lcase[26] = {0};
        int ucase[26] = {0};
        for(int i = 0;i<len;i++){
            if(s[i]<='Z'){
                ucase[s[i]-'A']++;
            }
            else {
                lcase[s[i]-'a']++;
            }
        }
        int sum = 0;
        bool oddflag = false;
        for(int i = 0;i<26;i++){
            sum+=lcase[i]/2 *2;
            sum+=ucase[i]/2 *2;
            if(!oddflag){
                if(lcase[i]%2)oddflag = true;
                else if(ucase[i]%2)oddflag = true;
            }
        }
        return sum+oddflag;
    }
};
