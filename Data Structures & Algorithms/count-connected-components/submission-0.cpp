class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visit (n, false);

        int res=0;
        for(int i=0; i<n; i++){
            if(!visit[i]){
                dfs(adj,visit,i);
                res++;
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<int>>& adj, vector<bool>& visit, int node){
        visit[node]=true;
        for(int n: adj[node]){
            if(!visit[n]){
                dfs(adj, visit, n);
            }
        }
    }

};
