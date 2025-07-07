class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int count = 0, lastday = 0, n = events.size();
        sort(events.begin(), events.end());
        for (auto& event : events)
            lastday = max(lastday, event[1]);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0, n = events.size(), day = 1; day <= lastday; day++) {
            // Add all events starting today
            while (i < n && events[i][0] == day)
                pq.push(events[i++][1]);
            // Remove all expired events
            while (!pq.empty() && pq.top() < day)
                pq.pop();
            // Attent one event with earilest end
            if (!pq.empty())
                pq.pop(), count++;
        }
        return count;
    }
};