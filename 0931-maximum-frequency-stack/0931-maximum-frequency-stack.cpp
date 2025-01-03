class FreqStack {
private:
    int maxfreq = 0;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> mp;

public:
    FreqStack() {}

    void push(int x) {
        maxfreq = max(maxfreq, ++freq[x]);
        mp[freq[x]].push(x);
    }

    int pop() {
        int x = mp[maxfreq].top();
        mp[maxfreq].pop();
        if (mp[freq[x]--].empty()) maxfreq--;
        return x;
    }
};
