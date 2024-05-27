class Solution {
public:
    static vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> categorized;

        for (const auto &el : nums) {
            if (categorized.find(el) != categorized.end()) {
                categorized.find(el)->second += 1;
            }
            else {
                categorized[el] = 1;
            }
        }

        vector<int> answer;
        vector<int> used;

        for (int i = 0; i < k; i ++) {
            int maxHappened = 0;
            int val = 0;
            for (const auto &el : categorized) {
                auto finder = std::find(used.begin(), used.end(), el.first);
                if (maxHappened < el.second && (finder == used.end())) {
                    maxHappened = el.second;
                    val = el.first;
                }
            }
            used.push_back(val);
            answer.push_back(val);
        }

        return answer;
    }
};