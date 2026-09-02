class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        queue<int> q;
        int count=0;
        for(auto &e:prerequisites){
            int u=e[0],v=e[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        vector<int> result;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int u=q.front();
            result.push_back(u);
            q.pop();
            for(int v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }

        if(count==n){
            return result;
        }else{
            return {};
        }
    }
};
