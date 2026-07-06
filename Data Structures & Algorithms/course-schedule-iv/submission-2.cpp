class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& e, vector<vector<int>>& query) {
        vector<int> inDeg(n, 0);
        vector<vector<int>> adj(n);
        vector<vector<bool>> preReq(n, vector<bool>(n, false)); // tells jth node is pre-req of ith node
        // if j is pre-req of i then preReq[i][j] = true;
        // in reverse logic if i is pre-req of j then preReq[j][i] = true;
        for(auto edg : e){
            int u = edg[0], v = edg[1];
            // here u is pre-req of v
            adj[u].push_back(v);
            inDeg[v]++;
            preReq[v][u] = true;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDeg[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            topo.push_back(u);
            for(int v : adj[u]){
                inDeg[v]--;
                if(inDeg[v] == 0) {
                    q.push(v);
                    for(int i=0;i<n;i++) preReq[v][i] = preReq[u][i] | preReq[v][i];
                }
            }
        }
        vector<bool> ans;
        for(auto qry : query){
            int u = qry[0], v = qry[1];
            ans.push_back(preReq[v][u]);
        }
        return ans;
    }
};