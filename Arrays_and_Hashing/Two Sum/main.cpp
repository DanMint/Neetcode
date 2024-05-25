class Solution {
public:
    static std::vector<int> twoSum(std::vector<int> nums, int target) {
        std::unordered_map<int, std::pair<int, int>> values;

        for (int i = 0; i < nums.size(); i ++) {
            if (values.find(nums[i]) != values.end()) {
                if (values.find(nums[i])->second.second == INT_MIN) {
                    values.find(nums[i])->second.second = i;
                }
                continue;
            }

            values[nums[i]] = std::pair{i, INT_MIN};
        }

        for (const auto &el : values) {
            int needed = target - el.first;

            if (needed == el.first) {
                if (el.second.second != INT_MIN)
                    return {el.second.first, el.second.second};
            }

            else if (values.find(needed) != values.end())
                return {el.second.first, values.find(needed)->second.first};
        }

        return {};
    }
};