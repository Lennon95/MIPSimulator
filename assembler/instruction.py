import abc

class Opcode:
	
	def __init__(self, name, code, syntax):
		self.__name	= name
		self.__code	= code
		self.__syntax	= syntax

	@property
	def name(self):
		return self.__name
	
	@property
	def code(self):
		return self.__code
	
	@property
	def syntax(self):
		return self.__syntax

class Instruction(ABC):
	@property
	@abstractmethod
	def fields(self):
		pass

	@abstractmethod
	def execute(self)

	@classmethod
	def getInstance(cls, data):
		pass
	
class InstructionTypeR(Instruction):
	
	fields = {
		'rs'	: 5,
		'rt'	: 5,
		'rd'	: 5,
		'shamt'	: 5,
		'funct'	: 6
	}
	
	def __init__(self, src_register_s, src_register_t, dest_register_d, shamt, funct):
		self.__rs	= src_register_s
		self.__rt	= src_register_t
		self.__rd	= dest_register_d
		self.__shamt	= shamt
		self.__funct	= funct

	@property
	def rs(self):
		return self.__rs
	
	@property
	def rt(self):
		return self.__rt

	@property
	def rd(self):
		return self.__rd

	@property
	def shamt(self):
		return self.__shamt

	@property
	def funct(self):
		return self.__funct
