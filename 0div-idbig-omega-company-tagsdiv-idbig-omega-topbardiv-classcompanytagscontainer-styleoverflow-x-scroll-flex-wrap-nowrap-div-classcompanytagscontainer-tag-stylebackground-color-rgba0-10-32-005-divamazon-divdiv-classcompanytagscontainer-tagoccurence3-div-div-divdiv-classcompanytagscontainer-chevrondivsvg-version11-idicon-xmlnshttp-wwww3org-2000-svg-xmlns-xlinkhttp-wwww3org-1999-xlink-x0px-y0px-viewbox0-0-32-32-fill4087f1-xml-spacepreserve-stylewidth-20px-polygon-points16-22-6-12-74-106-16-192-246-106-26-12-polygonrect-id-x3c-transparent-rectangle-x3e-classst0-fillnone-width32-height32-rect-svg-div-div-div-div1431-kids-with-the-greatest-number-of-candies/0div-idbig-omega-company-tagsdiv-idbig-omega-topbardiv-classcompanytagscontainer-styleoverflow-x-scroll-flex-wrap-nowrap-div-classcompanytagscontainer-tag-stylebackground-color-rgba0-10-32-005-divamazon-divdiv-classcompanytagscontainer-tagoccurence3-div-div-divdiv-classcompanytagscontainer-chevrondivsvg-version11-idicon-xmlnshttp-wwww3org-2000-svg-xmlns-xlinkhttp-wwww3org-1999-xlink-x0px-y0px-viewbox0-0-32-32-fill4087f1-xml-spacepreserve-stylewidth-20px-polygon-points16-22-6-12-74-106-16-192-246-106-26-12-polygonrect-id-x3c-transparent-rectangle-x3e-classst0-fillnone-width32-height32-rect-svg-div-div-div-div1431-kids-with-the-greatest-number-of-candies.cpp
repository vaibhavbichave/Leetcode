class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        vector<bool> answer;
        for(int x:candies) maxi = max(x, maxi);
        for(int x:candies){
            if(x + extraCandies >= maxi) answer.push_back(true);
            else answer.push_back(false);
        }
        return answer;
    }
};