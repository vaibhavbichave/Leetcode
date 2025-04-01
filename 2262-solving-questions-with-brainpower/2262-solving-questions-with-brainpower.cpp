class Solution {
public:
    
    long long dp[100002];
    long long solve(vector<vector<int>>& questions,long long ind,long long result){
        if(ind>=questions.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=max(solve(questions,ind+1,result),solve(questions,ind+questions[ind][1]+1,result)+questions[ind][0]);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return solve(questions,0,0);
    }
};