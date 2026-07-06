class Solution {
    void bfs(vector<vector<int>> &grid, int &n, int i, int j){
        queue<pair<int, int>> q;
        vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
        q.push({i, j});
        grid[i][j] = 2;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
        return;
    }

    int shortestDistance(vector<vector<int>> &grid, int &n, int i, int j){
        vector<vector<int>> dist(n, vector<int>(n, -1));
        dist[i][j] = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(grid[x][y] == 2) return dist[x][y] - 1;
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 1){
                    if(dist[nx][ny] == -1){
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }

public:    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool found = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    bfs(grid, n, i, j);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int curr_distance = shortestDistance(grid, n, i, j);
                    if(curr_distance != -1) ans = min(ans, curr_distance);
                }
            }
        }
        return ans;
    }
};