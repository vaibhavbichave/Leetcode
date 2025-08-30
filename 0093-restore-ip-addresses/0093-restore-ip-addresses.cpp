class Solution {
public:
    bool valid(string temp) {
        int n = temp.size();
        if (n == 1) return true;
        if (temp[0] == '0') return false;
        if (stoi(temp) > 255) return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        for (int i = 1; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                for (int k = 1; k < 4; k++) {
                    int sz = n - (i + j + k);
                    if (0 < sz && sz < 4) {
                        string a = s.substr(0, i);
                        string b = s.substr(i, j);
                        string c = s.substr(i + j, k);
                        string d = s.substr(i + j + k);
                        if (valid(a) && valid(b) && valid(c) && valid(d)) {
                            ans.push_back(a + '.' + b + '.' + c + '.' + d);
                        }
                    }
                }
            }
        }
        return ans;
    }
};