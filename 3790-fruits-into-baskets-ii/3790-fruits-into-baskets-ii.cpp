class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0, n = baskets.size();
        for (int fruit : fruits) {
            bool fruitUnplaced = true;
            for (int i = 0; i < n; i++) {
                if (fruit <= baskets[i]) {
                    baskets[i] = 0;
                    fruitUnplaced = false;
                    break;
                }
            }
            unplaced += fruitUnplaced;
        }
        return unplaced;
    }
};