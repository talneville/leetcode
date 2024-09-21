/*

___________________________________LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS___________________________________

Given a string s, find the length of the longest substring without repeating characters.


Example 1:
	Input: s = "abcabcbb"
	Output: 3
	Explanation: The answer is "abc", with the length of 3.

Example 2:
	Input: s = "bbbbb"
	Output: 1
	Explanation: The answer is "b", with the length of 1.

Example 3:
	Input: s = "pwwkew"
	Output: 3
	Explanation: The answer is "wke", with the length of 3.

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:
	0 <= s.length <= 5 * 104
	s consists of English letters, digits, symbols and spaces.


*/


#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int left = 0;
		int right = 0;
		int max_length = 0;
		int temp_length = 0;
		unordered_map<char, int> s_map;

		while (right < s.size()) {
			if (s_map.find(s[right]) == s_map.end()) {
				s_map[s[right]] = right;
				temp_length++;
				max_length = max(max_length, temp_length);
				right++;
			}
			else {
				int	temp_i = s_map[s[right]];
				while (left <= temp_i) {
					s_map.erase(s[left]);
					left++;
					temp_length--;
				}
			}		
		}

		return max_length;
	}
};




/*___________________________________CHAT_GPT_IMPROVEMENT___________________________________*/



class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int left = 0;
		int right = 0;
		int max_length = 0;
		unordered_map<char, int> s_map;  // Map to store the last index of each character

		while (right < s.size()) {
			// If the character is found in the map and is within the current window
			if (s_map.find(s[right]) != s_map.end() && s_map[s[right]] >= left) {
				// Move the left pointer to the right of the previous occurrence
				left = s_map[s[right]] + 1;
			}

			// Update the last seen index of the current character
			s_map[s[right]] = right;

			// Calculate the length of the current substring and update max_length
			max_length = max(max_length, right - left + 1);

			// Move the right pointer to expand the window
			right++;
		}

		return max_length;
	}
};


