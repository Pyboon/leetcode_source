/*
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (47.57%)
 * Total Accepted:    69.8K
 * Total Submissions: 146.7K
 * Testcase Example:  '"a"\n"b"'
 *
 *
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom
 * note can be constructed from the magazines ; otherwise, it will return
 * false.
 *
 *
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 *
 *
 * Note:
 * You may assume that both strings contain only lowercase letters.
 *
 *
 *
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 *
 *
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int lenr = ransomNote.size();
        int lenm = magazine.size();
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int i = 0;
        int j = 0;
        while(j<lenm){
            if(i==lenr)return true;
            if(ransomNote[i]==magazine[j]){
                i++;j++;
            }
            else j++;
        }
        if(i<lenr)return false;
        else return true;
    }
};
