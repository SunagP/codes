def mirror(root):
  if root is None:
    return 0
  else:
    root.left,root.right=root.right,root.left
    mirror(root.left)
    mirror(root.right)
