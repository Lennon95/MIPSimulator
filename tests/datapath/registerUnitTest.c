#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "registerUnitTest.h"

#include "../src/mips/datapath/register.h"

static bool testNewRegisterFile()
{
	// Testa se inicializou conforme esperado
	registerFile *regFile = newRegisterFile();
	if (regFile == NULL) return false;
	if (regFile->_PC == NULL) return false;
	if (regFile->_IR == NULL) return false;

	return true;
}

static bool testSetGetReg()
{
	registerFile *regFile = newRegisterFile();
	
	for (size_t i = 0; i < TOTAL_GENERAL_REGISTERS; i++)
		setReg(regFile, i, 10 * (i + 1));
	
	for (size_t i = 0; i < TOTAL_GENERAL_REGISTERS; i++) 
		if (getReg(regFile, i) != (10 * (i + 1))) return false;
	
	return true;
}

bool registerTests()
{
	if (!testSetGetReg()) {
		printf("- testSetGetReg() FAIL\n");
		return false;
	}

	if (!testNewRegisterFile()) {
		printf("- testNewRegisterFile() FAIL\n");
		return false;
	}

	return true;
}
