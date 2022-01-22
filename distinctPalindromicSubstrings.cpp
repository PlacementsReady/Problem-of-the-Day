class Solution{
  public:
    int palindromeSubStrs(string s) {
        int n = s.length();
        set<string>st;
        string curr = "";
        
        //odd
        for(int i=0;i<n;i++){
            int left = i-1,right = i+1;
            while(left >= 0 and right < n){
                if(s[left] == s[right]){
                    curr = s.substr(left,right-left+1);
                    st.insert(curr);
                    left--;
                    right++;
                }
                else break;
            }
        }
        
        //even
        for(int i=0;i<n-1;i++){
            int left = i;
            int right = i + 1;
            if(s[left] == s[right]){
                while(left >= 0 and right < n){
                    if(s[left] == s[right]){
                        curr = s.substr(left,right-left+1);
                        st.insert(curr);
                        left--;
                        right++;
                    }
                    else break;
                }
            }
        }
        
        //individual characters
        for(auto x : s) {
            string curr = "";
            curr += x;
            st.insert(curr);
        }
        return st.size();
    }
};
