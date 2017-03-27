# PROBLEM DESCRIPTION: https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description

def dfs(char, digits, keypad_dict):
    if len(digits) == 1:
        return list(keypad_dict[int(digits)])
    elif len(digits) == 0:
        return []

    return_list = []
    curr_int = int(digits[0])
    curr_level = keypad_dict[curr_int]
    dfs_list = dfs(char, digits[1:], keypad_dict)
    #print dfs_list, curr_level, 'fghh'
    for char in curr_level:
        #print char
        for dfs_char in dfs_list:
            #print char, dfs_char
            return_list.append(char+dfs_char)	

    return return_list

class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        keypad_dict = {1:'*', 2:'abc', 3:'def', 4:'ghi', 5:'jkl', 6:'mno', 7:'pqrs', 8:'tuv', 9:'wxyz', 0:' '}
        return dfs('', digits, keypad_dict)

