#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "mips.h"
#include "datapath/register.h"
#include "datapath/imemory.h"
#include "datapath/dmemory.h"

static registerFile*	_regs;
static int32_t*		_memData;
static int32_t*		_instData;

enum _INSTRUCTIONS = {
	LUI, ORI, ADDIU, LW,
	SW, BEQ, J, ANDI
};

enum _FUNCT_INST = {
	XOR, ADDU, SLT,
	SLL, SRL
};

const char* _OPCODES = {
	0xF, 0xD, 0x9, 0x24
	0x2C, 0x4, 0x2, 0xC
};

const char* _FUNCT = {
	0x26, 0x21, 0x2A
	0x0, 0x2	
};

void init(int32_t* instructions, size_t len)
{
	_regs = newRegisterFile();
	setPC(_regs, *instructions);
//	initDataMem();
}


void execute()
{
	int32_t instruction = getPC(_regs);
	setIR(_regs, instruction);
	incPC(_regs);

	char opcode = (instruction >> 26) & 0x3F; // Bitmask 111111
	
	// instrucoes tipo-R (rs e rt sao usados em tipo-I tambem)
	char rs = (instruction >> 20) & 0x1F; // 11111
	char rt = (instruction >> 15) & 0x1F;
	char rd = (instruction >> 10) & 0x1F;
	char shamt = (instruction >> 6) & 0x1F;
	char funct = instruction & 0x3F;

	// instrucoes tipo-I
	int32_t imm = (instruction & 0x0000FFFF);

	// instrucoes tipo-J
	int32_t addr = (instruction & 0x03FFFFFF);

	int32_t result;
	if (opcode == 0x0) { // Somente instrucoes tipo-R tem opcode 0x0 nesse conjunto de instrucoes
		switch (funct) {
			case _FUNCT[XOR]:
			result = getReg(_regs, (int )rs) ^ getReg(_regs, (int ) rt);
			break;
			
			case _FUNCT[ADDU]:
			result = getReg(_regs, (int )rs) + getReg(_regs, (int ) rt);
			break;
	
			case _FUNCT[SLT]:
			result = (getReg(_regs, (int )rs) < getReg(_regs, (int ) rt)) ? 1 : 0;
			break;
			
			case _FUNCT[SLL]:
			result = getReg(_regs, (int )rt) << funct;
			break;

			case _FUNCT[SLR]:
			result = getReg(_regs, (int )rt) ^ >> funct;
			break;
		}
		setReg(_regs, (int ) rd, result);
		// char* c = (char* ) malloc(30 * sizeof(char));
		// sprintf(c, "Registrador $%d: %x", (int )rd,  getReg(_regs));
		// updateRegBuff(c, 30);
	} else {
		switch (opcode) {
			case _OPCODES[LUI]:
			result = imm << 16;
			setReg(_regs, (int ) rt, result);		
			break;

			case _OPCODES[ORI]:
			result = getReg(_regs, (int ) rs) | imm;
			setReg(_regs, (int ) rt, result);		
			break;

			case _OPCODES[ADDIU]:
			result = getReg(_regs, (int ) rs) + imm;
			setReg(_regs, (int ) rt, result);		
			break;

			case _OPCODES[LW]:
			result = *(getReg(_regs, (int ) rs) + imm);
			setReg(_regs, (int ) rt, result);		
			break;

			case _OPCODES[SW]:
			result = getReg(_regs, (int ) rt);
			memcpy(getReg(_regs, (int ) rs) + imm, result, sizeof(int32_t));
			break;
			
			case _OPCODES[BEQ]:

			break;

			case _OPCODES[J]:
			break;

			case _OPCODES[ANDI]:
			result = getReg(_regs, (int ) rs) & imm;
			setReg(_regs, (int ) rt, result);
			break;
		}
	}
	
}
