void binSort(int A[], int N)
    {
        int low = 0, high = N-1;
        while(low <= high){
            if(A[low] == 0){
                low++;
            }
            else{
                swap(A[low],A[high]);
                high--;
            }
        }
    }
