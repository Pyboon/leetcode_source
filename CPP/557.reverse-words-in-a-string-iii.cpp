/*
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (59.88%)
 * Total Accepted:    54.7K
 * Total Submissions: 91.3K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 *
 * Example 1:
 *
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 *
 *
 *
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 *
 */
class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int pre = 0;
        int cur = 0;
        while(s[cur]==' ')cur++;
        pre = cur;
        while(cur<len){
            while(s[cur]!=' ' && cur<len)cur++;
            int post = cur-1;
            while(pre<post){
                char temp = s[pre];
                s[pre] = s[post];
                s[post] = temp;
                pre++;
                post--;
            }
            while(s[cur]==' '&& cur<len)cur++;
            pre = cur;
        }
        return s;
    }
};
