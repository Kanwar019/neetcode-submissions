class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(auto& e:prerequisites){
            int u=e[0], v=e[1];
            adj[v].push_back(u);
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(int &v:adj[i]){
                indegree[v]++;
            }
        }
        int count=0;
        queue<int> q;
        for(int u=0;u<n;u++){
            if(indegree[u]==0){
                q.push(u);
                count++;
            }
        }
        while(!q.empty()){
            int u=q.front();
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
            return true;
        }else{
            return false;
        }
    }
};
