class Element(object):

	def __init__(self, element=None, right=None):
		self.right = right
		self.element = element

	def get_element(self):
		return self.element

	def get_right(self):
		return self.right

	def add_element(self, element):
		self.element = element

	def add_right(self, right):
		self.right = right

class List(object):

	def __init__(self, size=0, _format=False, elements=None):
		self.size = size 
		self.format = _format
		self.elements = elements
		self.array = None
		self.initialize()

	def initialize(self):
		self.array = Element(element=None)

	def push_start(self, element):
		if self.array.get_element() == None:
			self.array.add_element(element)
			self.size += 1
		elif self.array.get_element() != None and self.array.get_right() == None:
			temp_right = self.array
			self.array = Element(element)
			self.array.add_right(temp_right)
			self.size += 1
		else:
			temp_current = self.array
			self.array = Element(element)
			current = self.array
			for i in range(self.size):
				current.add_right(Element(temp_current.get_element()))
				current = current.get_right()
				temp_current = temp_current.get_right()
			self.size += 1

	def push_back(self, element):
		if self.array.get_element() == None:
			self.array.add_element(element)
			self.size += 1
		elif self.array.get_right() == None:
			self.array.add_right(Element(element=element))
			self.size += 1
		else:
			current = self.array.get_right()
			for i in range(self.size):
				if current.get_right() == None:
					current.add_right(Element(element))
					self.size += 1
					break
				else:
					current = current.get_right()
					continue

	def change_at(self, index=0, element=None):
		current = self.array
		for i in range(self.size):
			if i == index:
				current.add_element(element)
			else:
				current = current.get_right()

	def pop(self, index=None):
		if index == None:
			self.__pop_end()
		else:
			self.__pop_at(index)

	def __pop_end(self):
		current = self.array
		for i in range(self.size):
			if i == self.size-1:
				current.add_right(None)
				self.size -= 1
			current = current.get_right()

	def __pop_at(self, index):
		current = self.array
		index_found = False
		for i in range(self.size):
			if index-1 == i:
				current.add_right(current.get_right().get_right())
				self.size -= 1
				break
			current = current.get_right()



	def show(self):
		current = self.array
		string = "["
		for i in range(self.size):
			string += str(current.get_element()) + ", "
			current = current.get_right()
		fstring = string[:-2] + "]"
		print(fstring)



arr = List()

arr.push_back(11)
arr.push_back(21)
arr.push_back(33)
arr.push_back(191)
arr.push_back(23)
arr.push_back(3)

arr.show()

arr.change_at(index=1, element=22)

arr.show()

arr.change_at(3, 1801)

arr.show()

arr.pop(1)

arr.show()

arr.pop(2)

arr.show()

arr.pop()

arr.show()

arr.push_start(88)

arr.show()

arr.push_start(77)

arr.show()

arr.push_back(15)

arr.show()

arr.push_back(65)

arr.show()

arr.push_start(1726)

arr.show()