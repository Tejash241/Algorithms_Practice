#PROBLEM DESCRIPTION: https://leetcode.com/problems/3sum/#/description

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return []
        global_dict = {}
        triplet_list = []
        n = len(nums)
        nums = sorted(nums)
        for x in nums:
            if x in global_dict:
                global_dict[x] += 1
            else:
                global_dict[x] = 1
        
        for i in range(n):
            curr_dict = global_dict
            for j in range(i+1, n):
                val = -(nums[i]+nums[j])
                if val in curr_dict and curr_dict[val] > 0:
                    if val != nums[i] or curr_dict[nums[i]] > 1:
                        if (val != nums[j] or curr_dict[nums[j]] > 1) and curr_dict[nums[j]] > 0:
                            triplet_list.append([val, nums[i], nums[j]])
                            curr_dict[val] -= 1
                            curr_dict[nums[j]] -= 1
        return triplet_list