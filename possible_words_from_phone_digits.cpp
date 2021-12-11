class Solution
{
    public:
    vector<string>keypad{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void generate(int a[],int i,int n,string out,vector<string>&v)
    {
        if(i == n)
        {
            v.push_back(out);
            return;
        }
        int digit = a[i];
        for(int k = 0; keypad[digit][k] != '\0';k++)
        {
            generate(a,i+1,n,out+keypad[digit][k],v);
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        vector<string>v;
        generate(a,0,n,"",v);
        return v;
    }
};
