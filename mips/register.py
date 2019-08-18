class Register:
	
	def __init__(self, name, number, value):
		self.__name 	= name
		self.__number	= number
		self.__value	= value

	@property
	def name(self):
		return self.__name

	@property
	def number(self):
		return self.__number

	@property
	def value(self):
		return self.__value

	@value.setter
	def value(self, v):
		self.__value = v
