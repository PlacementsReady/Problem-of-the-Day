string reverseWords(string S) 
    { 
        vector<string>v;
        int i = 0;
        S += '.';
        int n = S.length();
        while(i < n){
            int j = i;
            while(S[j] != '.'){
                j++;
            }
            // cout<<i<<" "<<j<<endl;
            string curr = S.substr(i,j-i);
            v.push_back(curr);
            i = j+1;
        }
        string ans = "";
        for(int i=v.size()-1;i>=1;i--){
            ans += v[i];
            ans += '.';
        }
        ans += v.front();
        return ans;
    } 
