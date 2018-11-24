#include <stdio.h>
#include <stdlib.h>

#include "registerFile.h"

typedef struct s_registerFile {
	long int genPurpose[32]; // Registradores de proposito geral
	long int __PC;
	long int __IR;
} registerFile;

registerFile* newRegisterFile()
{
	registerFile* regFile = malloc(sizeof(registerFile));
	resetRegisterFile(regFile);

	return regFile;
}

void resetRegisterFile(registerFile* regFile)
{
	regFile->__PC = 0x0;
	regFile->__IR = 0x0;
	for (int i = 0; i < 32; i++) {
		regFile->genPurpose[i] = 0x0;
	}
}
