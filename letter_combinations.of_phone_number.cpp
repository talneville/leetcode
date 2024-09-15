/*

_______________LETTER_COMBINATIONS_OF_PHONE_NUMBER_______________


Given a string containing digits from 2-9 inclusive, return all possible letter combinations 
that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].


*/

#include <vector>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, vector<char>> digit_to_letter = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}
    };

    vector<string> Combinations_AUX(string digits, int start) {
        vector<string> result;
        if (start == digits.size() - 1) {         
            for (int i = 0; i < digit_to_letter[digits[start]].size(); i++) {
                string str(1, digit_to_letter[digits[start]][i]);
                result.push_back(str);
            }
            return result;
        }
               
        vector<string> combinations = Combinations_AUX(digits, start + 1);
        for (int j = 0; j < digit_to_letter[digits[start]].size(); j++) {
            for (int k = 0; k < combinations.size(); k++) {
                result.push_back(digit_to_letter[digits[start]][j] + combinations[k]);
            }
        }
        return result;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty() == true) {
            return vector<string>();
        }
        return Combinations_AUX(digits, 0);
    }
};



/*

_______CHAT_GPT_IMPROVMENT_______

*/


#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // Map of digit to corresponding letters
    unordered_map<char, vector<char>> digit_to_letter = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    vector<string> Combinations_AUX(const string& digits, int start) {
        vector<string> result;

        // Base case: If we've processed all digits
        if (start == digits.size()) {
            result.push_back("");  // Start with an empty string for the combination
            return result;
        }

        // Get the current digit's corresponding letters
        const vector<char>& letters = digit_to_letter[digits[start]];
        // Recur for the rest of the digits
        vector<string> combinations = Combinations_AUX(digits, start + 1);

        // Combine current letters with the rest of the combinations
        for (char letter : letters) {
            for (const string& combination : combinations) {
                result.push_back(letter + combination);
            }
        }

        return result;
    }

public:
    vector<string> letterCombinations(const string& digits) {
        if (digits.empty()) {
            return {};  // Return an empty vector if input is empty
        }
        return Combinations_AUX(digits, 0);
    }
};
