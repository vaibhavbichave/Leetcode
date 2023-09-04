class Solution {
public:
    string intToRoman(int n) {
        string answer;
        int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        for(int i=12;i>=0;i--){
            int div = n / num[i];
            n = n % num[i];
            while(div--) answer += sym[i];
        }
        return answer;
    }
};