class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n -1){
            return false;
        }

        vector<vector<int>>adj(n);
        for (const auto& edge : edges){
           adj[edge[0]].push_back(edge[1]);
           adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int>visit;
        queue<pair<int, int>>q;
        q.push({0,-1});
        visit.insert(0);

        while(!q.empty()){
            auto [node, parent] = q.front();
            q.pop();
            for(int neighbour : adj[node]){
                if(neighbour == parent){
                    continue;
                }
                if(visit.count(neighbour)){
                    return false;
                }
                visit.insert(neighbour);
                q.push({neighbour,node});

            }
        }
        return visit.size() == n;

    }


};
