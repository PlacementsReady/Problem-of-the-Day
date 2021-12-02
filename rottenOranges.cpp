class Solution{
public:
    typedef pair<int,pair<int,int>> node;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    
    bool isSafe(int x,int y,int n,int m,vector<vector<bool>>&visited,vector<vector<int>>&grid){
        return (x >= 0 and y >=0 and x < n and y < m and visited[x][y] == 0 and grid[x][y] == 1);
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        priority_queue<node,vector<node>,greater<node>>pq;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0)); 
        
        //push all the rotten oranges into pq and make them visited
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2){
                    pq.push({0,{i,j}});
                    visited[i][j] = 1;
                }
            }
        }
        
        int ans = 0;
        while(!pq.empty()){
            node curr = pq.top();
            pq.pop();
            int x = curr.second.first;
            int y = curr.second.second;
            int t = curr.first;
            // cout<<x<<" "<<y<<" "<<t<<endl;
            ans = max(ans,t);
            for(int k=0;k<4;k++){
                int new_x = x + dx[k];
                int new_y = y + dy[k];
                if(isSafe(new_x,new_y,n,m,visited,grid)){
                    pq.push({t+1,{new_x,new_y}});
                    visited[new_x][new_y] = 1;
                    grid[new_x][new_y] = 2;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
         return ans;
      }
    };
