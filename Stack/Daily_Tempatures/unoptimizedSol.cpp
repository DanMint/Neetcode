class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        
        for (int i = 0; i < temperatures.size(); i ++) {
            int daysToWait = 0;
            bool found = false;
            for (int j = i + 1; j < temperatures.size(); j ++) {
                if (temperatures[j] > temperatures[i]) {
                    daysToWait += 1;
                    found = true;
                    break;
                }
                daysToWait += 1;
            }
            if (found) {
                ans.push_back(daysToWait);
            }
            else {
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};