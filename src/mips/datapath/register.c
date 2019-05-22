#include <stdint.h>
#include <stdlib.h>
#include "register.h"

registerFile* newRegisterFile()
{
	registerFile* regFile = malloc(sizeof(registerFile));
	regFile->_PC = malloc(sizeof(int32_t));
	regFile->_IR = malloc(sizeof(int32_t));

	return regFile;
}

void freeRegisterFile(registerFile* regFile)
{
	free(regFile->_PC);
	free(regFile->_IR);
	free(regFile);
}

void setReg(registerFile* regFile, size_t r, int32_t val)
{
	regFile->genPurpose[r] = val;
}

int32_t getReg(registerFile* regFile, size_t r)
{
	return regFile->genPurpose[r];
}
