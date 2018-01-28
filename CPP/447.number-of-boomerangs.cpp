/*
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (46.00%)
 * Total Accepted:    31.3K
 * Total Submissions: 68.1K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 *
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 *
 * Example:
 *
 * Input:
 * [[0,0],[1,0],[2,0]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 *
 *
 */
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int len = points.size();
        if(!len) return 0;
        vector<vector<double> > result(len, vector<double>(len,0));
        for(int i = 0;i<len-1;i++){
            for(int j = i+1;j<len;j++){
                double dis = this->calcDis(points[i],points[j]);
                result[i][j] = result[j][i] = dis;
            }
        }
        
        int sum = 0;
        int count = 1;
        for(int i = 0;i<len;i++){
            sort(result[i].begin(),result[i].end());
            count = 1;
            for(int j = 1;j<len;j++){
                if(result[i][j]==result[i][j-1])count++;
                else{
                    if(count>1)sum+= count*(count-1);
                    count = 1;
                }
            }
            if(count>1)sum+= count*(count-1);
        }
        return sum;
    }
    double calcDis(pair<int,int> p1, pair<int, int> p2){
        return sqrt((double)((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second)));
    }
};
