class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto p : prerequisites){
            int a = p[0], b = p[1];
            graph[b].push_back(a);   // b → a
            indegree[a]++;           // a depends on b
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(int nei : graph[node]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }

        return count == numCourses;
    }
};