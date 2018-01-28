/*
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (44.39%)
 * Total Accepted:    26K
 * Total Submissions: 58.6K
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string representing an attendance record for a student. The
 * record only contains the following three characters:
 *
 *
 *
 * 'A' : Absent.
 * 'L' : Late.
 * ⁠'P' : Present.
 *
 *
 *
 *
 * A student could be rewarded if his attendance record doesn't contain more
 * than one 'A' (absent) or more than two continuous 'L' (late).
 *
 * You need to return whether the student could be rewarded according to his
 * attendance record.
 *
 * Example 1:
 *
 * Input: "PPALLP"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "PPALLL"
 * Output: False
 *
 *
 *
 *
 *
 */
class Solution {
public:
    bool checkRecord(string s) {
        int len = s.size();
        int countL = 0;
        int countA = 0;
        for(int i = 0;i<len;i++){
            if(s[i]=='L')countL++;
            else if(s[i]=='A'){
                countL=0;
                countA++;
            }
            else countL=0;
            if(countL>2 || countA>1)return false;
        }
        return true;
    }
};
