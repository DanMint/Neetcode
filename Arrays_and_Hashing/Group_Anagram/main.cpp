class Solution {
public:

    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> ordered = strs;
        vector<vector<int>> orderedPos;

        for (auto &el : ordered) {
            std::sort(el.begin(), el.end());
        }

        for (int i = 0; i < ordered.size(); i ++) {
            if (ordered[i] == "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm") {
                continue;
            }
            vector<int> pos = {i};
           for (int j = i + 1; j < ordered.size(); j ++) {
               if (ordered[i] == ordered[j]) {
                   pos.push_back(j);
                   ordered[j] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
               }
           }
           ordered[i] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
           orderedPos.push_back(pos);
        }

        vector<vector<string>> answer;

        for (const auto &el : orderedPos) {
            vector<string> ans;
            for (const auto &elo : el) {
                ans.push_back(strs[elo]);
            }
            answer.push_back(ans);
        }

        return answer;
    }
};