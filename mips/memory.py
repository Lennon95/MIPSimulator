class Memory:

	def __init__(self, addr, value=None):
		self.__addr	= addr
		self.__value	= value

	@property
	def addr(self):
		return self.__addr

	@property
	def value(self):
		return self.__value

	@value.setter
	def value(self, v):
		self.__value = v

