# PROBLEM DESCRIPTION: https://leetcode.com/problems/median-of-two-sorted-arrays/#/description

def binary_search_one_less(arr, elem, lo, hi):
	if hi-lo <= 1:
		return lo
	else:
		mid = (lo+hi)/2
		if arr[mid] > elem:
			arr = arr[:mid]
			hi = mid
		else:
			arr = arr[mid:]
			lo = mid+1
		return binary_search_one_less(arr, elem, lo, hi)

def find_index(elem, arr, len_arr):
	lo = 0
	hi = len_arr-1
	return binary_search_one_less(arr, elem, lo, hi)

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        len1 = len(nums1)
        len2 = len(nums2)
        if len1==1 and len2==1:
        	return float((nums1[0]+nums2[0])/2)
        elif len1==1: #cannot reduce nums1 further
        	ins_idx = find_index(nums1[0], nums2, len2)
        	_len = len2+1
        	med_idx = (_len/2)-1 if _len%2==0 else (_len/2)
    		if med_idx < ins_idx:
    			return (nums2[med_idx]+nums2[med_idx+1])/2 if _len%2==0 else nums2[med_idx]
    		elif med_idx == ins_idx:
    			return (nums1[0]+nums2[med_idx+1])/2 if _len%2==0 else nums1[0]
    		else:
    			return (nums2[med_idx+1]+nums2[med_idx+2])/2 if _len%2==0 else nums2[med_idx+1]
    	elif len2==1: # cannot reduce nums2 further
        	ins_idx = find_index(nums2[0], nums1, len1)
        	_len = len1+1
        	med_idx = (_len/2)-1 if _len%2==0 else (_len/2)
    		if med_idx < ins_idx:
    			return (nums1[med_idx]+nums1[med_idx+1])/2 if _len%2==0 else nums1[med_idx]
    		elif med_idx == ins_idx:
    			return (nums2[0]+nums1[med_idx+1])/2 if _len%2==0 else nums2[0]
    		else:
    			return (nums1[med_idx+1]+nums1[med_idx+2])/2 if _len%2==0 else nums1[med_idx+1]

        idx1 = (len1/2)-1 if len1%2==0 else (len1/2)
        print idx1, len1, len(nums1)
        med1 = nums1[max(idx1, 0)]
        idx2 = (len2/2)-1 if len2%2==0 else (len2/2)
        med2 = nums2[max(idx2, 0)]
        if med1==med2:
        	return med1
        elif med1>med2: #cut left of med1 and right of med2
        	n_cut = min(idx1, len2-idx2)
        	nums1 = nums1[n_cut:]
        	nums2 = nums2[:-n_cut]
        else: #cut right of med1 and left of med2
        	n_cut = min(idx2, len1-idx1)
        	nums1 = nums1[:-n_cut]
        	nums2 = nums2[n_cut:]
        
        return self.findMedianSortedArrays(nums1, nums2)