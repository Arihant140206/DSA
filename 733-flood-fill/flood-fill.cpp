class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    void dfs(vector<vector<int>>& image, int i, int j,
             int oldColor, int newColor, int n, int m) {

        // Base Case
        if (!valid(i, j, n, m) || image[i][j] != oldColor)
            return;

        // Paint current cell
        image[i][j] = newColor;

        // Visit all 4 directions
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            dfs(image, ni, nj, oldColor, newColor, n, m);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int newColor) {

        int n = image.size();
        int m = image[0].size();

        int oldColor = image[sr][sc];

        // Edge Case
        if (oldColor == newColor)
            return image;

        dfs(image, sr, sc, oldColor, newColor, n, m);

        return image;
    }
};