class Solution{
public:
    int xorCal(int k){
        for(int i=1;i<=100;i++){
            if((i^(i+1)) == k){
                return i;
            }
        }
        return -1;
    }
};
