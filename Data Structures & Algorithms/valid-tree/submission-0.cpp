class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()> n-1){
            return false;
        }

        /*
        vector<int> v = {1,2,3,4}
        vector<vector<int>> v = {{0,1},{0,2},{0,3},{1,4}}
        */
        vector<vector<int>> adj(n);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int>visit;

        if(!dfs(0,-1, visit,adj)){
            return false;
        }

        return visit.size() == n;

    }

private:
    bool dfs(int node, int parent, unordered_set<int>& visit, vector<vector<int>>& adj){
        if(visit.count(node)){
            return false;
        }

        visit.insert(node);
        for(int n : adj[node]){
            if(n == parent)
            continue;

            if(!dfs(n,node,visit,adj)){
                return false;
            }
        }
        return true;
        
    }
};
