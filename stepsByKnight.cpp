class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	  int dx[8] = {1, -1, -1, 1, 2, -2, -2, 2};
    int dy[8] = {2, 2, -2, -2, 1, 1, -1, -1};
  
    bool isSafe(int x, int y, int n, vector<vector<int>>&visited) {
    	return (x >= 1 and x <= n and y >= 1 and y <= n and visited[x][y] == 0);
    }
  
    int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
    {
    	int s_x, s_y, e_x, e_y;
    	s_x = KnightPos[0];
    	s_y = KnightPos[1];
    	e_x = TargetPos[0];
    	e_y = TargetPos[1];
    	queue<vector<int>>q;
    	vector<vector<int>>visited(N + 1, vector<int>(N+1, 0));
    	q.push({s_x, s_y, 0});
    	visited[s_x][s_y] = 1;
    	while (!q.empty()) {
    		vector<int>curr = q.front();
    		q.pop();
    		int x = curr[0];
    		int y = curr[1];
    		int depth = curr[2];
    		if (x == e_x and y == e_y) {
    			return depth;
    		}
    		for (int k = 0; k < 8; k++) {
    			int new_x = x + dx[k];
    			int new_y = y + dy[k];
    
    			if (isSafe(new_x, new_y, N, visited)) {
    				q.push({new_x, new_y, depth + 1});
    				visited[new_x][new_y] = 1;
    			}
    		}
    	}
    
    	return -1;
    }
};
