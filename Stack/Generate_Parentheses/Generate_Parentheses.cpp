class Solution {
public:
    void createParenthesis(vector<string> &combinations, int open, int closed, const int &n, string combination) {
        if (combination.size() == n * 2) {
            combinations.push_back(combination);
            return;
        }

        if (open < n) {
            createParenthesis(combinations, open + 1, closed, n, combination + '(');
        }

        if (closed < open) {
            createParenthesis(combinations, open, closed + 1, n, combination + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        createParenthesis(answer, 0, 0, n, "");
        return answer;
    }
};
