class Solution {
public:
    static vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> days;
        vector<int> ans(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i ++) {
            if (days.empty()) {
                days.push(i);
                continue;
            }

            while (!days.empty() && temperatures[i] > temperatures[days.top()]) {
                ans[days.top()] = i - days.top();
                days.pop();
            }

            days.push(i);
        }

        return ans;
    }
};