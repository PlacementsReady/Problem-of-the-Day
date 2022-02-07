class Solution {
  public:
    bool isPrime(int n){
        if(n <= 1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> primeRange(int M, int N) {
        vector<int>ans;
        for(int i=M;i<=N;i++){
            if(isPrime(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
