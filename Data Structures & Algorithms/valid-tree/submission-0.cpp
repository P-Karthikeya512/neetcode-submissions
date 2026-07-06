class Solution {
    bool isCycle(vector<vector<int>> &adj, int u, int par, vector<bool> &vis){
        vis[u] = true;
        for(int v : adj[u]){
            if(!vis[v]) {
                if(isCycle(adj, v, u, vis)) return true;
            }
            else if(v != par) return true;
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        bool cycle = false;
        vector<vector<int>> adj(n);
        for(auto edg : edges){
            int u = edg[0], v = edg[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        int comp = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                comp++;
                if(isCycle(adj, i, -1, vis)) cycle = true;
            }
        }
        return !cycle && comp == 1;
    }
};