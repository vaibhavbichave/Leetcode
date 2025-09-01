class Solution {
public:
    double average(double data, int size) { return data / size; }
    double gain(int data, int size) {
        return average(data + 1, size + 1) - average(data, size);
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
            pq.push({gain(classes[i][0], classes[i][1]),
                     {classes[i][0], classes[i][1]}});
        for (int i = 0; i < extraStudents; i++) {
            auto [data, size] = pq.top().second;
            pq.pop();
            pq.push({gain(data + 1, size + 1), {data + 1, size + 1}});
        }
        double avg = 0;
        while (!pq.empty()) {
            auto [data, size] = pq.top().second;
            pq.pop();
            avg += average(data, size);
        }
        return average(avg, n);
    }
};