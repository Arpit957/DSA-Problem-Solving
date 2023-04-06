class Solution {
 bool isClosed(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())return false;
        
        // Return true if it's water or a visited cell
        if (grid[i][j] == 1 || grid[i][j] == 2) return true;

        // Mark current land as visited
        grid[i][j] = 2;

        // Check if all 4 directions are closed recursively.
        bool isLeftClosed = isClosed(grid, i, j - 1);
        bool isRightClosed = isClosed(grid, i, j + 1);
        bool isTopClosed = isClosed(grid, i + 1, j);
        bool isBottomClosed = isClosed(grid, i - 1, j);

        return isLeftClosed && isRightClosed && isTopClosed && isBottomClosed;
    }

public:
    // T:O(n*m), S:O(n*m)
    int closedIsland(vector<vector<int>>& grid) {
        int islands = 0;

        // Go through all cells in a grid
        for(int i = 0; i < grid.size(); i++) { // O(n)
            for(int j = 0; j < grid[i].size(); j++) { // O(m)
                if(grid[i][j] == 0 && isClosed(grid, i, j)) {
                    islands++;
                }
            }
        }
        return islands;
    }
};
