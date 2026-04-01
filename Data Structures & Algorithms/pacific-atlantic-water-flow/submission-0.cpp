class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int Rows = heights.size(), Cols = heights[0].size();
        vector<vector<bool>> pac(Rows, vector<bool>(Cols,false));
        vector<vector<bool>> atl(Rows, vector<bool>(Cols,false));

        for (int c = 0; c < Cols; ++c) {
            dfs(0, c, pac, heights);
            dfs(Rows - 1, c, atl, heights);
        }
        for (int r = 0; r < Rows; ++r) {
            dfs(r, 0, pac, heights);
            dfs(r, Cols - 1, atl, heights);
        }
        vector<vector<int>> res;
        for (int r = 0; r < Rows; ++r) {
            for (int c = 0; c < Cols; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
    private:
        void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;
        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < heights.size() &&
                nc >= 0 && nc < heights[0].size() &&
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
};
