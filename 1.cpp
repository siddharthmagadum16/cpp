#include <bits/stdc++.h>
using namespace std;


// O(n)
bool checkIfLiesInRange(int row, int col, int n, int m) {
    return 0 <= row and row < n and 0 <= col and col < m;
}


int solve(vector<string>&grid) {

    int n = grid.size();
    int m = grid[0].size(); // assuming n >0

    vector<int>ex({0,0,1,-1});
    vector<int>ey({1,-1,0,0});

    vector<int>dx({0,0,1,-1,1,-1,1,-1});
    vector<int>dy({1,-1,0,0,1,-1,-1,1});
    vector<vector<bool>>vis(n, vector<bool>(m, false));
    queue<pair<int,int>>spoil;
    int freshCounter = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            if (grid[i][j] == 'B') {
                spoil.push({i,j});
                vis[i][j] = true;
            }
            if (grid[i][j] == 'F') {
                freshCounter++; // = true;
            }
        }
    }

    if (freshCounter == 0) {
        return 0;
    }

    int days = 0;

    while (!spoil.empty() and freshCounter > 0) {
        int numSpoiled = spoil.size();
        while (numSpoiled--) {

            pair<int,int>spot = spoil.front();
            spoil.pop();
    
            int row = spot.first;
            int col = spot.second;
    
            if (grid[row][col] == 'B') {
                
                for (int p = 0; p < dx.size(); ++ p) {
                    int newRow = row + dx[p];
                    int newCol = col + dy[p];
                    bool isInBoundary = checkIfLiesInRange(newRow,newCol, n, m);
                    if (!isInBoundary) continue;
    
                    if (!vis[newRow][newCol] and grid[newRow][newCol] != '#') {
                        vis[newRow][newCol] = true;
                        if (grid[newRow][newCol] == 'F') {
                            -- freshCounter;
                            grid[newRow][newCol] = 'B';
                        }
                        spoil.push({newRow, newCol});
                    }
                }
            }
            else if (grid[row][col] == '.') {
                for (int p = 0; p < ex.size(); ++ p) {
                    int newRow = row + ex[p];
                    int newCol = col + ey[p];
                    bool isInBoundary = checkIfLiesInRange(newRow,newCol, n, m);
                    if (!isInBoundary) continue;
        
                    if (!vis[newRow][newCol] and grid[newRow][newCol] != '#') {
                        vis[newRow][newCol] = true;
                        if (grid[newRow][newCol] == 'F') {
                            -- freshCounter;
                            grid[newRow][newCol] = 'B';
                        }
                        spoil.push({newRow, newCol});
                    }
                }
            }
        }
        days++;        
    }

    if (freshCounter > 0) {
        return -1;
    }

    return days;
}


int main () {

    vector<string>grid({"F.F#.", ".BFF.", ".F#..", "F..B."});

    int ans = solve(grid);
    cout << ans;
    cout << endl;


    return 0;
}

/*
n = 8, k = 3
 A = [ 5, -2,  4,  4,  1,  7,  1,  6]
 Q = [ 0,  1,  0,  0,  1,  0,  0,  1]
 Windows (size 3):
 minVal = [4, 4, 4, 4, 1, 1]
*/