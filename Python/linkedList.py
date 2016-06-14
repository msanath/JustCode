

class Node:
	def __init__(self, data):
		self.data = data
		self.next = None


class LinkedList:
	listCount = 0
	
	def __init__(self):
		self.firstNode = None


	def add(self, data):
		node = Node(data)
		if self.firstNode is None:
			self.firstNode = node
		else:
			tmp = self.firstNode
			while tmp.next is not None:
				tmp = tmp.next
			tmp.next = node

		self.listCount += 1


	def delPosition(self, pos):
		if self.listCount < pos:
			print "Not enough elements"
			return

		if pos == 1:
			tmp = self.firstNode
			self.firstNode = self.firstNode.next
			del tmp
			self.listCount -= 1
			return

		cur = self.firstNode
		prev = None

		while pos is not 1:
			prev = cur
			cur = cur.next
			pos -= 1

		prev.next = cur.next
		del cur
		self.listCount -= 1

	def printAll(self):
		tmp = self.firstNode
		while tmp is not None:
			print tmp.data
			tmp = tmp.next


ll = LinkedList()
for x in range(150):
	ll.add(x)

k = 145

prev = ll.firstNode
cur = ll.firstNode



while k != 0:
	cur = cur.next
	k -=1


while cur is not None:
	cur = cur.next
	prev = prev.next


print prev.data





