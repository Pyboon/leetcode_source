/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (38.81%)
 * Total Accepted:    95.5K
 * Total Submissions: 246K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 *
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 *
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 *
 *
 *
 * Note:
 * The vowels does not include the letter "y".
 *
 */
class Solution {
public:
    string reverseVowels(string s) {
        int len = s.size();
        int i = 0;
        int j = len-1;
        while(i<j){
            if(isvowel(s[i]) && isvowel(s[j])){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;j--;
            }
            else if(!isvowel(s[i])){
                i++;
            }
            else if(!isvowel(s[j])){
                j--;
            }
        }
        return s;
    }
    bool isvowel(char c){
        if(c=='a' || c=='e'|| c=='i'|| c=='o'|| c=='u'||
        c=='A'|| c=='E'|| c=='I'|| c=='O'|| c=='U')return true;
        else return false;
    }
};
