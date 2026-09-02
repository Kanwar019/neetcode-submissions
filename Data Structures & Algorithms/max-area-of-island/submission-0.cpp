class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int row, int col){
        int area=0;
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]!=1){
            return 0;
        }
        area=1;
        grid[i][j]=0;

        area+= dfs(grid,i-1,j,row,col);
        area+= dfs(grid,i+1,j,row,col);
        area+= dfs(grid,i,j-1,row,col);
        area+= dfs(grid,i,j+1,row,col);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int islands=0;
        int row=grid.size();
        int col=grid[0].size();
        int maxarea=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    maxarea=max(maxarea,dfs(grid,i,j,row,col));
                }
            }
        }
        return maxarea;
    }
};
