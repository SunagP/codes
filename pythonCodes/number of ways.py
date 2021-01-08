# Python3 program to count the number
# of ways to reach n'th stair when
# user climb 1 .. m stairs at a time.

# Function to count number of ways
# to reach s'th stair
def countWays(n, m):

	temp = 0
	res = [1]

	for i in range(1, n + 1):
		s = i - m - 1
		e = i - 1
		if (s >= 0):
			temp -= res[s]
		temp += res[e]
		res.append(temp)

	return res[n]

# Driver Code
n = 4
m = 3

print('Number of ways =', countWays(n, m))

# This code is contributed by 31ajaydandge
