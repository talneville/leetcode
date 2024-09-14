/*

VALID PARENTHESES

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

*/

#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> s_stack;
        unordered_map<char, char> u_map;
        u_map['('] = ')';
        u_map['['] = ']';
        u_map['{'] = '}';
        u_map[')'] = '(';
        u_map[']'] = '[';
        u_map['}'] = '{';

        for (int i = 0; i < s.size(); i++) {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
                s_stack.push(s[i]);
            }
            else {
                if (s_stack.size() == 0) {
                    return false;
                }
                if (s_stack.top() != u_map[s[i]]) {
                    return false;
                }
                s_stack.pop();
            }
        }
        return !s_stack.size();
    }
};