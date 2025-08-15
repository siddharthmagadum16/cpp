85. Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6

Example 2:
Input: matrix = [["0"]]
Output: 0

Example3:
Input: matrix = [["1"]]
Output: 1




const int NA = 500;
struct Cell {
    int firstR = NA;
    int firstC = NA;
    int rectR =  NA;
    int rectC =  NA;
    int val = NA;
};

class Solution {


public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix.back().size();

        vector<vector<Cell>>grid(n+1, vector<Cell>(m+1));

        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= m; ++ j) {
                int value = matrix[i-1][j-1] - '0';
                grid[i][j].val = value;
                grid[i][j].rectR = value ? i : NA;
                grid[i][j].rectC = value ? j : NA;
                grid[i][j].firstR = value ? i : NA;
                grid[i][j].firstC = value ? j : NA;
            }
        }

        int maxArea = 0;
        for (int r = 1; r <= n; ++ r) {
            for (int c = 1; c <= m; ++ c) {
                grid[r][c].firstR = grid[r][c].val ? grid[r-1][c].firstR : NA;
                grid[r][c].firstC = grid[r][c].val ? grid[r][c-1].firstC : NA;

                if (grid[r][c].firstR and grid[r-1][c].firstR != NA) grid[r][c].firstR = grid[r-1][c].firstR;
                if (grid[r][c].firstC and grid[r][c-1].firstC != NA) grid[r][c].firstC = grid[r][c-1].firstC;

                if (grid[r][c].val) {
                    grid[r][c].rectR = grid[r-1][c-1].rectR == NA ? grid[r][c].rectR : max(grid[r][c].firstR, grid[r-1][c-1].rectR);
                    grid[r][c].rectC = grid[r-1][c-1].rectC == NA ? grid[r][c].rectC : max(grid[r][c].firstC, grid[r-1][c-1].rectC);
                    int area = max(0,(r - grid[r][c].rectR+1)) * max(0,(c - grid[r][c].rectC+1));
                    maxArea = max(area, maxArea);
                }

            }
        }
        return maxArea;
    }
};
