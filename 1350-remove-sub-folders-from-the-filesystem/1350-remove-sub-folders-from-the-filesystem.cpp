class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());
        vector<string> v;
        string& prev = folder[0];
        v.push_back(prev);
        for (int i = 1; i < n; i++) {
            string& curr = folder[i];
            int prevLen = prev.size(), currLen = curr.size();
            int mini = min(prevLen, currLen);
            if (prev.substr(0, mini) != curr.substr(0, mini) ||
                (mini < currLen && curr[mini] != '/')) {
                v.push_back(curr);
                prev = curr;
            }
        }
        return v;
    }
};