class Solution{
    public:
    static bool compare(pair<int,int>a,pair<int,int>b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
    vector<int> TopK(vector<int>& arr, int k)
    {
        vector<pair<int,int>>v;
        map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(auto p : m){
            v.push_back(p);
        }
        sort(v.begin(),v.end(),compare);
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
