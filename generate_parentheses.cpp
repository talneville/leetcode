/*

____________________GENERATE_PARENTHESES____________________

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8

*/


#include <vector>
#include <string>
#include <stack>

using namespace std;

//class Solution {
//private:
//    stack<string> parentheses;
//
//public:
//    vector<string> generateParenthesis(int n) {
//        if (n <= 0) {
//            return vector<string>();
//        }
//        vector<string> result;
//        string current;
//        generateParenthesis_AUX(n, current, result);
//        return result;
//    }
//
//    void generateParenthesis_AUX(int n, string current, vector<string>& result) {
//        if (n == 0) {
//            for (int i = 0; i < parentheses.size(); i++) {
//                current += ")";
//            }
//            result.push_back(current);
//            return;
//        }
//
//        current += "(";
//        parentheses.push("(");
//        generateParenthesis_AUX(n - 1, current, result);
//        parentheses.pop();
//        current.pop_back();
//        if (!parentheses.empty()) {
//            parentheses.pop();
//            current += "()";
//            generateParenthesis_AUX(n - 1, current, result);
//        }
//    }
//};


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generateParenthesis_AUX(n, 0, 0, current, result);
        return result;
    }

    void generateParenthesis_AUX(int n, int open, int close, string current, vector<string>& result) {
        if (n <= 0) {
            return;
        }
        if ((open == n) && (close == n)) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            current += "(";
            open++;
            generateParenthesis_AUX(n, open, close, current, result);
            current.pop_back();
            open--;
            if (close < open) {
                close++;
                current += ")";
                generateParenthesis_AUX(n, open, close, current, result);
                close--;
                current.pop_back();
            }
        }
        else {
            close++;
            current += ")";
            generateParenthesis_AUX(n, open, close, current, result);
            close--;
            current.pop_back();
        }
  
    }
};

int main() {
    Solution sol;
    sol.generateParenthesis(3);
    return 0;
}