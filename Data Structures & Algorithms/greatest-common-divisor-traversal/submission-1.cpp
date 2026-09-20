class Dsu{
public:
    vector<int> par, size;
    Dsu(int n){
        par.resize(n + 1);
        size.assign(n + 1, 1);
        for(int i = 0; i <= n; i++) par[i] = i;
    }

    int findUPar(int x){
        if(x == par[x]) return x;
        return par[x] = findUPar(par[x]);
    }

    void unite(int u, int v){
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
    vector<int> sieve(int n){
        vector<int> spf(n + 1, 0);
        for(int i = 0; i <= n; i++) spf[i] = i;
        for(int i = 2; i*i <= n; i++){
            if(spf[i] == i){
                for(int j = i*i; j <= n; j += i){
                    if(spf[j] == j) spf[j] = i;
                }
            }
        }
        return spf;
    }

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size() > 1) {
            for (int x : nums) {
                if (x == 1) return false;
            }
        }
        Dsu ds(1e5);
        vector<int> spf = sieve(1e5);
        for(int i : nums){
            int x = i;
            while(x > 1){
                int q = spf[x];
                ds.unite(i, q);
                x = x / spf[x];
            }
        }
        set<int> comp;
        for(int x : nums) comp.insert(ds.findUPar(x));
        return comp.size() == 1;
    }
};