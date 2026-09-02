class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // Get number of rows
    int m = grid.size();
    // If grid is empty, return
    if (m == 0) return;
    // Get number of columns
    int n = grid[0].size();

    // Create a queue for BFS
    queue<pair<int,int>> q;

    // Directions for moving up, down, left, right
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    // Push all treasure cells into the queue
    for (int i = 0; i < m; i++) {
        // Loop through each column
        for (int j = 0; j < n; j++) {
            // If current cell is treasure
            if (grid[i][j] == 0) {
                // Add it to BFS queue
                q.push({i, j});
            }
        }
    }

    // Process BFS until queue becomes empty
    while (!q.empty()) {
        // Get current cell from front of queue
        auto [x, y] = q.front();
        // Remove it from queue
        q.pop();

        // Try all 4 directions
        for (auto [dx, dy] : dirs) {
            // Compute next row
            int nx = x + dx;
            // Compute next column
            int ny = y + dy;

            // Check bounds and make sure cell is an empty land cell
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == INT_MAX) {
                // Set distance as current distance + 1
                grid[nx][ny] = grid[x][y] + 1;
                // Push new cell into queue
                q.push({nx, ny});
            }
        }
    }
    }
};
