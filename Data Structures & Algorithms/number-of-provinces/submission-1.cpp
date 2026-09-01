class Solution {
public:
    void bfs(vector<vector<int>> &adj, int u, vector<bool> &visited){
        visited[u]=true;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        int count=0;
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(isConnected[u][v]==1){
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};