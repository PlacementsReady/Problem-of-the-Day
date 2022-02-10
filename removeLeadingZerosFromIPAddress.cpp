string newIPAdd (string s)
    {
        string ans = "";
        s += '.';
        int n = s.length();
        int i = 0;
        while(i<n){
            int j = i;
            while(s[j] != '.'){
                j++;
            }
            
            string temp = s.substr(i,j-i);
            
            int k = 0;
            while(temp[k] == '0'){
                k++;
            }
            if(k == temp.length()){
                ans += '0';
            }
            else{
                ans += temp.substr(k);
            }
            
            ans += '.';
            i = j+1;
        }
        ans.pop_back();
        return ans;
    }
