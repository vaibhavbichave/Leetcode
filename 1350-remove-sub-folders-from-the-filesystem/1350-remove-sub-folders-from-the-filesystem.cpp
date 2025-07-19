class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> v;
        int n = folder.size();
        unordered_set<string> st(folder.begin(), folder.end());
        sort(folder.begin(), folder.end());
        for (string& subfolder : folder) {
            string curr;
            int m = subfolder.size();
            v.push_back(subfolder);
            for (int i = 0; i < m; i++) {
                curr += subfolder[i];
                if (i + 1 < m && subfolder[i + 1] == '/' && st.contains(curr)) {
                    v.pop_back();
                    break;
                }
            }
        }
        return v;
    }
};