queue<int> modifyQueue(queue<int> q, int k) {
    deque<int>Q;
    int x = k;
    int n = q.size();
    for(int i=0;i<k;i++){
        Q.push_back(q.front());
        q.pop();
    }
    x = (n-k);
    while(x--){
        Q.push_front(q.front());
        q.pop();
    }
    while(!Q.empty()){
        q.push(Q.back());
        Q.pop_back();
    }
    return q;
}
