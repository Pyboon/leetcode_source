/*
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (57.63%)
 * Total Accepted:    68K
 * Total Submissions: 117.9K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water. Grid cells are connected
 * horizontally/vertically (not diagonally). The grid is completely surrounded
 * by water, and there is exactly one island (i.e., one or more connected land
 * cells). The island doesn't have "lakes" (water inside that isn't connected
 * to the water around the island). One cell is a square with side length 1.
 * The grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 *
 * Example:
 *
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 *
 * Answer: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 *
 *
 *
 */
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int row = grid.size();
        if(row==0) return 0;
        int col = grid[0].size();
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j]){
                    dfs(grid, i, j, row, col, perimeter);
                    return perimeter;
                }
            }
        }
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int r, int c, int& perimeter){
        if(outbodary(i,j,r,c))return;
        if(grid[i][j]!=1) return;
        // i-1,j  i+1,j  i,j-1   i,j+1
        if(outbodary(i-1,j,r,c)|| grid[i-1][j]==0) ++perimeter;
        if(outbodary(i+1,j,r,c)|| grid[i+1][j]==0) ++perimeter;
        if(outbodary(i,j-1,r,c)|| grid[i][j-1]==0) ++perimeter;
        if(outbodary(i,j+1,r,c)|| grid[i][j+1]==0) ++perimeter;
        grid[i][j] = 2;
        dfs(grid,i-1,j,r,c,perimeter);
        dfs(grid,i+1,j,r,c,perimeter);
        dfs(grid,i,j-1,r,c,perimeter);
        dfs(grid,i,j+1,r,c,perimeter);
    }
    bool outbodary(int i, int j, int r, int c){
        if(i<0 || i>=r || j<0 || j>=c) return true;
        else return false;
    }
};
