# PROBLEM DESCRIPTION: https://leetcode.com/problems/container-with-most-water/#/description
def calc_area(x1, x2, y1, y2):
    return (x2-x1)*min(y1, y2)

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        max_area = 0
        start = 0
        end = n-1
        while start<end:
            h1 = height[start]
            h2 = height[end]
            curr_area = calc_area(start, end, h1, h2)
            max_area = max(max_area, curr_area)
            if h2<h1:
                end -= 1
            else:
                start += 1
        
        return max_area