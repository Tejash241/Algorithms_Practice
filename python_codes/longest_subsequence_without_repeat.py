# PROBLEM DESCRIPTION: https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
class Solution(object):
    def check_and_remove_lists(self, all_xors, d, n):
        is_removed = False
        if n == 1:
            return all_xors, n, n
        else:
            for i in range(n-1, 0, -1):
                if all_xors[i] == all_xors[i-1]:
                    all_xors = all_xors[i:]
                    is_removed = True
                    break
                else:
                    all_xors[i-1] = all_xors[i-1]^d
            if is_removed:
                return all_xors, len(all_xors), n-1
            else:
                return all_xors, n, n

    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_len = 0
        all_xors = []
        list_counter = 0
        num_lists = 0
        for i in xrange(len(s)):
            curr_char = s[i]
            # append new xor
            all_xors.append(ord(curr_char))
            list_counter += 1
            num_lists += 1
            all_xors, num_lists, max_till_now = self.check_and_remove_lists(all_xors, ord(curr_char), num_lists)
            max_len = max(max_len, max_till_now)

        return max_len