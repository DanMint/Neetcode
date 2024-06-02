
class Solution {
public:
    static bool isValid(string &s) {
        if (s.size() == 1) {
            return false;
        }

        stack<char> bracketsOpen;
        for (const auto el : s) {
            if (el == '(') {
                bracketsOpen.push(el);
            }
            else if (el == '{') {
                bracketsOpen.push(el);
            }
            else if (el == '[') {
                bracketsOpen.push(el);
            }
            else if (el == ')') {
                if (bracketsOpen.empty()) {
                    return false;
                }
                if (bracketsOpen.top() != '(') {
                    return false;
                }
                bracketsOpen.pop();
            }
            else if (el == '}') {
                if (bracketsOpen.empty()) {
                    return false;
                }
                if (bracketsOpen.top() != '{') {
                    return false;
                }
                bracketsOpen.pop();
            }
            else if (el == ']') {
                if (bracketsOpen.empty()) {
                    return false;
                }
                if (bracketsOpen.top() != '[') {
                    return false;
                }
                bracketsOpen.pop();
            }
        }

        if (!bracketsOpen.empty()) {
            return false;
        }

        return true;
    }
};