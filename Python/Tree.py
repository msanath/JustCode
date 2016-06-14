

class Node:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None



class Tree:
	def __init__(self):
		self.root = None

	def insertNode(self, node, root):
		if node.data <= root.data:
			if root.left is None:
				root.left = node
			else:
				self.insertNode(node, root.left)

		else:
			if root.right is None:
				root.right = node

			else:
				self.insertNode(node, root.right)

	def insert(self, data):
		node = Node(data)

		if self.root is None:
			self.root = node
		else:
			self.insertNode(node, self.root)

	def inOrderTraverse(self, root):
		if root is not None:
			self.inOrderTraverse(root.left)
			print root.data
			self.inOrderTraverse(root.right)


tree = Tree()

tree.insert(5)
tree.insert(3)
tree.insert(6)
tree.insert(7)
tree.insert(4)
tree.inOrderTraverse(tree.root)
