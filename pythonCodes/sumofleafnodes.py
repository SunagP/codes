# Python3 Program to find the
#sum of leaf nodes of a binary tree


# Class for node creation
class Node:

	# Constructor
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

# Utility function to calculate
# the sum of all leaf nodes
def leafSum(root):
	global total
	if root is None:
		return
	if (root.left is None and root.right is None):
		total += root.data
	leafSum(root.left)
	leafSum(root.right)

# Binary tree Fromation
if __name__=='__main__':
	root = Node(1)
	root.left = Node(2)
	root.left.left = Node(4)
	root.left.right = Node(5)
	root.right = Node(3)
	root.right.right = Node(7)
	root.right.left = Node(6)
	root.right.left.right = Node(8)
# Variable to store the sum of leaf nodes
	total = 0
	leafSum(root)
# Printing the calculated sum
	print(total)

# This code is contributed by Naren Sai Krishna
