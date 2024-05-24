class Solution {
public:
    static bool isAnagram(const std::string &s, std::string &t) {
        if (s.size() != t.size())
            return false;

        std::unordered_map<char, int> stringA;
        std::unordered_map<char, int> stringB;

        for (int i = 0; i < s.size(); i ++) {
            if (stringA.find(s[i]) != stringA.end()) 
                stringA.find(s[i])->second += 1;

            if (stringB.find(t[i]) != stringB.end()) 
                stringB.find(t[i])->second += 1;
            
            stringA.insert(std::pair{s[i], 1});
            stringB.insert(std::pair{t[i], 1});
        }
        
        for (const auto &el : stringA) {
            if (stringB.find(el.first) != stringB.end()) {
                if (stringB.find(el.first)->second == el.second) {
                    continue;
                }
                return false;
            }
            return false;
        }

        return true;
    }
};