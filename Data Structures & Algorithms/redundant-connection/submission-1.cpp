class Dsu{
public:
    vector<int> par, size;
    Dsu(int n){
        par.resize(n + 1);
        for(int i=0;i<=n;i++) par[i] = i;
        size.assign(n + 1, 1);
    }
    int findUPar(int u){
        if(par[u] == u) return u;
        return par[u] = findUPar(par[u]);
    }
    bool merge(int u, int v){
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return false;
        if(size[ulp_u] < size[ulp_v]){
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Dsu ds(n);
        vector<int> ans;
        for(auto e : edges){
            int u = e[0], v = e[1];
            if(!ds.merge(u, v)) ans = {u, v};
        }
        return ans;
    }
};
