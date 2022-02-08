static int countSetBits(int n){
        int count = 0;
        while(n > 0){
            count++;
            n = (n&(n-1));
        }
        return count;
    }
    static bool compare(pair<int,int>a,pair<int,int>b){
        int setBits_a = countSetBits(a.first);
        int setBits_b = countSetBits(b.first);
        if(setBits_a == setBits_b){
            return a.second < b.second;
        }
        return setBits_a > setBits_b;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end(),compare);
        for(int i=0;i<n;i++){
            arr[i] = v[i].first;
        }
    }
