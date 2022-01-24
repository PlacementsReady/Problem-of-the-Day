class Solution {
  public:
    bool possible(int arr[],int n,int mid,int D){
        int days = 1;
        int weight = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > mid) return false;
            if(weight + arr[i] > mid){
                days++;
                weight = arr[i];
            }else{
                weight += arr[i];
            }
        }
        return days <= D;
    }
    int leastWeightCapacity(int arr[], int N, int D) {
        int ans = 0;
        int s = 0, e = accumulate(arr,arr+N,0);
        while(s <= e){
            int mid = (s+e)/2;
            if(possible(arr,N,mid,D)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};
