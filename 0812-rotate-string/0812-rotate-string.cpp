class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        goal = goal + goal;
        return goal.find(s) != string::npos;
    }
};