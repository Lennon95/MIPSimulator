#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "../src/mips/datapath/register.h"

void populateRegister(registerFile *r)
{
	for (size_t i = 0; i < TOTAL_GENERAL_REGISTERS; i++)
		r->genPurpose[i] = 10 * (i + 1);
}

bool testSetGetReg()
{
	registerFile *regFile = newRegisterFile();
	
	for (size_t i = 0; i < TOTAL_GENERAL_REGISTERS; i++)
		setReg(regFile, i, 10 * (i + 1));

	
	for (size_t i = 0; i < TOTAL_GENERAL_REGISTERS; i++) {
		if (getReg(regFile, i) != (10 * (i + 1))) return false;
	}
	
	return true;
}

void initTest()
{
}
