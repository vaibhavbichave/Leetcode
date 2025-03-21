class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        int lastSize = 0;
        queue<int> recipeQueue;
        unordered_set<string> available(supplies.begin(), supplies.end());
        for (int idx = 0; idx < recipes.size(); ++idx)
            recipeQueue.push(idx);
        vector<string> createdRecipes;
        while (lastSize < available.size()) {
            lastSize = available.size();
            int queueSize = recipeQueue.size();
            for (int i = 0; i < queueSize; i++) {
                int recipeIdx = recipeQueue.front();
                recipeQueue.pop();
                bool canCreate = true;
                for (string& ingredient : ingredients[recipeIdx]) {
                    if (available.find(ingredient) == available.end()) {
                        canCreate = false;
                        break;
                    }
                }
                if (canCreate) {
                    available.insert(recipes[recipeIdx]);
                    createdRecipes.push_back(recipes[recipeIdx]);
                } else {
                    recipeQueue.push(recipeIdx);
                }
            }
        }
        return createdRecipes;
    }
};