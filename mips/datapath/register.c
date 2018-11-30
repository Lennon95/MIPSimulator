#include <stdint.h>
#include <stdlib.h>
#include "registerFile.h"

typedef struct s_registerFile {
	int32_t genPurpose[32]; // Registradores de proposito geral
	int32_t* _PC;
	int32_t* _IR;
} registerFile;

registerFile* newRegisterFile()
{
	registerFile* regFile = malloc(sizeof(registerFile));
	regfile->_PC = malloc(sizeof(int32_t);
	regfile->_IR = malloc(sizeof(int32_t);
	resetRegisterFile(regFile);

	return regFile;
}

void resetRegisterFile(registerFile* regFile)
{
	regFile->*_PC = 0x0;
	regFile->*_IR = 0x0;
	for (int i = 0; i < 32; i++) {
		regFile->genPurpose[i] = 0x0;
	}
}

void setReg(registerFile* regFile, int r, int32_t val)
{
	regFile->genPurpose[r] = val;
}

int32_t getReg(registerFile* regFile, int r)
{
	return regFile->genPurpose[r];
}

void setPC(registerFile* regFile, int32_t val)
{
	regFile->*_PC = val;
}

void incPC(registerFile* regFile)
{
	regFile->_PC++;
}

int32_t getPC(registerFile* regFile)
{
	return regFile->*_PC;
}

void setIR(registerFile* regFile, int32_t val)
{
	regFile->*_IR = val;
}


int32_t getIR(registerFile* regFile)
{
	return regFile->*_IR;
}
