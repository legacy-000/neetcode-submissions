class Solution {
public:
    void bfs(int i,int j,int n,int m, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        int nr[]={-1,0,1,0};
        int nc[]={0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int newr=r+nr[k];
                int newc=c+nc[k];
                if(newr>=0 && newc>=0 &&newr<n &&newc<m){
                    if(!visited[newr][newc] && grid[newr][newc]=='1'){
                        visited[newr][newc]=true;
                        q.push({newr,newc});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,n,m,grid,visited);
                }
            }
        }
        return count;
    }
};
