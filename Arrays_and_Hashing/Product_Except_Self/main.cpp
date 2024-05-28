class Solution {
public:
    static vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeros = 0;
        bool flush = false;

        for (const auto &el : nums) {
            if (el == 0) {
                zeros += 1;
                if (zeros > 1 && !flush) {
                    flush = true;
                }
                continue;
            }
            product *= el;
        }


        vector<int> ans;
        for (const auto &el : nums) {
            if (flush) {
                ans.push_back(0);
            }
            else if (el != 0 && zeros == 1) {
                ans.push_back(0);
            }
            else if (el == 0 && zeros == 1){
                ans.push_back(product);
            }
            else {
                ans.push_back(product / el);
            }
        }

        return ans;
    }
};