def partition(arr, lo, hi):
	if lo < hi:
		pivot = hi
		pivot_val = arr[pivot]
		i = lo-1
		j = lo
		for x in range(lo, hi):
			if arr[j] <= pivot_val:
				i +=1
				tmp = arr[i]
				arr[i] = arr[j]
				arr[j] = tmp
			j += 1

		i += 1
		tmp = arr[i]
		arr[i] = pivot_val
		arr[pivot] = tmp
		return i

	elif lo == hi:
		return lo


def quick_sort(arr, start, end):
	if start < end:
		part = partition(arr, start, end)
		quick_sort(arr, start, part-1)
		quick_sort(arr, part+1, end)

if __name__=='__main__':
	n_elem = int(raw_input('Enter number of elements\n'))
	arr = map(int, raw_input('Enter the space-separated array\n').split(' '))
	print 'Sorting ....'
	quick_sort(arr, 0, n_elem-1)
	for x in arr:
		print x,
