class Element(object):

	def __init__(self, element=None, right=None):
		self.right = right
		self.element = element

	def get_element(self):
		return self.element

	def get_right(self):
		return self.right

	def add_element(self, element=None):
		self.element = element

	def add_right(self, right=None):
		self.right = right

class List(object):

	def __init__(self, size=0, _format=False, elements=None):
		self.size = size 
		self.format = _format
		self.elements = elements
		self.array = None
		self.initialize()

	def __str__(self):
		return self.show()

	def initialize(self):
		self.array = Element(element=None)

	def get(self, index=0):
		if index > self.size or index < 0:
			return "Index out of range"
		current = self.array
		for i in range(self.size):
			if i == index:
				return current.get_element()
				break
			else:
				current = current.get_right()

	def push_start(self, element=None):
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

	def push_back(self, element=None):
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
		if index > self.size or index < 0:
			return "Index out of range"
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

	def __pop_at(self, index=0):
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
		return fstring

arr = List()

arr.push_back(11)
arr.push_back(21)
arr.push_back(33)
arr.push_back(191)
arr.push_back(23)
arr.push_back(3)

print(arr)

arr.change_at(index=1, element=22)

print(arr)

arr.change_at(3, 1801)

print(arr)

arr.pop(1)

print(arr)

arr.pop(2)

print(arr)

arr.pop()

print(arr)

arr.push_start(88)

print(arr)

arr.push_start(77)

print(arr)

arr.push_back(15)

print(arr)

arr.push_back(65)

print(arr)

arr.push_start(1726)

print(arr)

print(arr.get(2))