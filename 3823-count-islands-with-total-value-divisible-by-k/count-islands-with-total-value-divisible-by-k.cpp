class Solution {
public:
      int m, n;
    vector<vector<int>> grid;
    vector<vector<bool>> visited;

    long long dfs(int r, int c) {
        // Out of bounds
        if (r < 0 || r >= m || c < 0 || c >= n)
            return 0;

        // Water or already visited
        if (grid[r][c] == 0 || visited[r][c])
            return 0;

        // Mark this cell as visited
        visited[r][c] = true;

        // Include the current cell's value
        long long sum = grid[r][c];

        // Explore all four directions
        sum += dfs(r - 1, c);
        sum += dfs(r + 1, c);
        sum += dfs(r, c - 1);
        sum += dfs(r, c + 1);

        return sum;
    }

public:
    int countIslands(vector<vector<int>>& gridInput, int k) {
        grid = gridInput;
        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<bool>(n, false));

        int count = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] > 0 && !visited[r][c]) {
                    long long sum = dfs(r, c);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};