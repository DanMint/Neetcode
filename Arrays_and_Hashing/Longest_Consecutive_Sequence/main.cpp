class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> numMap;

        for (const auto &el : nums) {
            numMap[el] = true;
        }

        int longestChain = 0;

        for (const auto &el : nums) {
            if (numMap.find(el - 1) == numMap.end()) {
                int chain = 1;
                int target = el + 1;
                while (numMap.find(target) != numMap.end()) {
                    chain++;
                    target++;
                }
                longestChain = std::max(longestChain, chain);
            }
        }

        return longestChain;
    }
};