class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count =  0;
        for(int i=low;i<=high;i++){
            string s = to_string(i);
            int sum=0, n = s.size();
            if((n & 1) == 0){
                for(int i=0,j=n-1;i<j;i++,j--){
                    sum+=(s[i]-'0');
                    sum-=(s[j]-'0');
                }
                if(sum==0) count++;
            }
        } 
        return count;
    }
};