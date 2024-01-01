class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer;
        int i=0, j=0;
        int n = word1.size(), m = word2.size();
        while(i<n && j<m){
            answer+=word1[i++];
            answer+=word2[j++];
        }
        while(i<n){
            answer+=word1[i++];
        }
        while(j<m){
            answer+=word2[j++];
        }
        return answer;
    }
};