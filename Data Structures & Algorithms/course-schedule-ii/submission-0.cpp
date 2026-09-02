class Solution {
public:
    bool dfs(vector<vector<int>> &adj, int u, stack<int> &st, vector<bool> &visited,vector<bool> &inrecursion){
        visited[u]=true;
        inrecursion[u]=true;
        for(int v:adj[u]){
            if(!visited[v]){
                if(dfs(adj,v,st,visited,inrecursion)){
                    return true;
                }
            }else if(inrecursion[v]==true){
                return true;
            }
        }

        st.push(u);
        inrecursion[u]=false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<bool> visited(n,false);
        vector<bool> inrecursion(n,false);
        vector<vector<int>> adj(n);
        for(auto &e:prerequisites){
            int u=e[0],v=e[1];
            adj[v].push_back(u);
        }

        vector<int> result;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(adj,i,st,visited,inrecursion)){
                    return {};
                }
            }
        }

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
