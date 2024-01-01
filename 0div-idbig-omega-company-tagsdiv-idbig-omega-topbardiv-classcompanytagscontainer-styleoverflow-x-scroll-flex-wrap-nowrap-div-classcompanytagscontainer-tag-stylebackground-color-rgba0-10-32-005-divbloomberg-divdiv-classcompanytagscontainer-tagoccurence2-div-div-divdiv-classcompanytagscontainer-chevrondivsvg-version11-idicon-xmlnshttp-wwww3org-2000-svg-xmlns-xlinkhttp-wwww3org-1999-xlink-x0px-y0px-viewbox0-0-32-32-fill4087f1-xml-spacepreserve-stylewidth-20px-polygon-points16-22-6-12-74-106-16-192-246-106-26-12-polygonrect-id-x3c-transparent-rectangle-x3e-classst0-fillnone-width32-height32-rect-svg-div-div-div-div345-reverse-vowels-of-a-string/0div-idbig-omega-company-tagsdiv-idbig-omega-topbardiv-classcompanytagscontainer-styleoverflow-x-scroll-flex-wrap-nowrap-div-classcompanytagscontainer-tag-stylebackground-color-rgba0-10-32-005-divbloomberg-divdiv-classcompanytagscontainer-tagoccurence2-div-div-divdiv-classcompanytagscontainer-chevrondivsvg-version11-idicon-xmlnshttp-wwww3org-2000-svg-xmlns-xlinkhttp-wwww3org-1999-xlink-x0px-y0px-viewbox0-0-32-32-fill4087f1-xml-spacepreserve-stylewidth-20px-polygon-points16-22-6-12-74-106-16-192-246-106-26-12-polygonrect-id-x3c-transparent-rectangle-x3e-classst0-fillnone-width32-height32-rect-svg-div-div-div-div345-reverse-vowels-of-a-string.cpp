class Solution {
public:
    bool isvowel(char x){
        return x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U';
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<j && !isvowel(s[i])) i++;
            while(i<j && !isvowel(s[j])) j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};