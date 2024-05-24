class Solution {
public:
    static bool containsDuplicate(const std::vector<int>& nums) {
        std::map<int, int> values;

        for (const auto &el : nums) {
            if (values.find(el) != values.end()) {
                return true;
            }

            values.insert(std::make_pair(el , 1));
        }

        return false;
    }
};