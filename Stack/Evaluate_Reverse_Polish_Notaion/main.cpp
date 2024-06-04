class Solution {
public:
    static int evalRPN(vector<string> tokens) {
        stack<int> numbers;
        for (const auto &el : tokens) {
            int first = 0;
            int second = 0;
            int value = INT_MIN;
            if (el == "+") {
                first = numbers.top();
                numbers.pop();
                second = numbers.top();
                numbers.pop();
                value = second + first;
                numbers.push(value);
            }
            else if (el == "-") {
                first = numbers.top();
                numbers.pop();
                second = numbers.top();
                numbers.pop();
                value = second - first;
                numbers.push(value);
            }
            else if (el == "*") {
                first = numbers.top();
                numbers.pop();
                second = numbers.top();
                numbers.pop();
                value = second * first;
                numbers.push(value);
            }
            else if (el == "/") {
                first = numbers.top();
                numbers.pop();
                second = numbers.top();
                numbers.pop();
                value = second / first;
                numbers.push(value);
            }
            else {
                numbers.push(stoi(el));
            }
        }

        return numbers.top();
    }
};