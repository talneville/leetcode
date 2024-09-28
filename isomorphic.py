
""""
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.

Example 1:
    Input: s = "egg", t = "add"
    Output: true
    Explanation:
    The strings s and t can be made identical by:
    Mapping 'e' to 'a'.
    Mapping 'g' to 'd'.

Example 2:
    Input: s = "foo", t = "bar"
    Output: false
    Explanation:
    The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:
    Input: s = "paper", t = "title"
    Output: true
    

Constraints:
    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.

"""



class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        map_s = {}
        map_t = {}

        for c1, c2 in zip(s, t):
            if map_s.get(c1) == None:
                map_s[c1] = c2
            elif map_s.get(c1) != c2:
                return False

        for c1, c2 in zip(s, t):
            if map_t.get(c2) == None:
                map_t[c2] = c1
            elif map_t.get(c2) != c1:
                return False
        
        return True
    


# _______________________CHAT_GPT_IMPROVEMENT_______________________

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        # Create two mappings to keep track of character correspondences
        map_s_to_t = {}
        map_t_to_s = {}

        # Iterate over both strings simultaneously
        for c1, c2 in zip(s, t):
            # Check if there's a conflict in s -> t mapping
            if c1 in map_s_to_t and map_s_to_t[c1] != c2:
                return False
            # Check if there's a conflict in t -> s mapping
            if c2 in map_t_to_s and map_t_to_s[c2] != c1:
                return False

            # Create the mapping if not present
            map_s_to_t[c1] = c2
            map_t_to_s[c2] = c1

        return True
