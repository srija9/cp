# 2 pointers approach and sliding window
def minSubarray(arr, n, x):
	left=0
	right=0
	summ=0
	shortest = float("inf")
	l=0
	s=[]
	
	
	while(right<n):
		summ+=arr[right]
		if(summ>x):
			while(summ>x):
				summ-=arr[left]
				left+=1
			if(shortest>(right-left+2)):
				shortest = min(shortest, right-left+2)
				l=left-1
		right+=1
	
	if(shortest != float("inf")):
		for i in range(shortest):
			s.append(arr[i+l])
	
	return s