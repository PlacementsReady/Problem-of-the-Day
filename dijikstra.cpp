vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        dist[S] = 0;
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            int node = p.second;
            int curr_dis = p.first;
            for(auto it : adj[node]){
                if(it[1] + curr_dis < dist[it[0]]){
                    dist[it[0]] = it[1] + curr_dis;
                    pq.push({dist[it[0]],it[0]});
                }
            }
        }
        return dist;
    }
