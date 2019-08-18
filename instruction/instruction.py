from abc import ABC, abstractmethod

class Opcode:
	
	def __init__(self, name, code, syntax):
		self.__name	= name
		self.__code	= code

	@property
	def name(self):
		return self.__name
	
	@property
	def code(self):
		return self.__code

class Instruction(ABC):
	@property
	@abstractmethod
	def fields(self):
		pass

	@classmethod
	def getInstance(cls, data):
		pass
	
class InstructionTypeR(Instruction):
	
	fields = {
		'opcode': 6,
		'rs'	: 5,
		'rt'	: 5,
		'rd'	: 5,
		'shamt'	: 5,
		'funct'	: 6
	}
	
	def __init__(self, opcode, src_register_s, src_register_t, dest_register_d, shamt, funct):
		self.__opcode	= opcode
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

class InstructionTypeI(Instruction):
	
	fields = {
		'opcode': 6,
		'rs'	: 5,
		'rt'	: 5,
		'imm'	: 16
	}
	
	def __init__(self, src_register_s, target_register_t, immediate):
		self.__rs	= src_register_s
		self.__rt	= target_register_t
		self.__imm	= immediate

	@property
	def rs(self):
		return self.__rs
	
	@property
	def rt(self):
		return self.__rt

	@property
	def imm(self):
		return self.__imm

class InstructionTypeJ(Instruction):
	
	fields = {
		'opcode': 6,
		'addr'	: 26
	}
	
	def __init__(self, address):
		self.__addr	= address

	@property
	def addr(self):
		return self.__addr
