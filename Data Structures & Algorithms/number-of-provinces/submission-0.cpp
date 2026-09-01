class Solution {
public:
    void dfs(vector<vector<int>> &adj, int u, vector<bool> &visited){
        visited[u]=true;

        for(int &v:adj[u]){
            if(!visited[v]){
                dfs(adj,v,visited);
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
                dfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};