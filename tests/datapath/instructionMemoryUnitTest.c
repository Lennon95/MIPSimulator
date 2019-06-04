#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "instructionMemoryUnitTest.h"

#include "../src/mips/datapath/imemory.h"

static bool testInitInstructionMem()
{
	// Testa se inicializou conforme esperado
	int32_t instructions[] = {0xDEADBEEF, 0xFA666FAF, 0x12332199, 0x01023F28};
	size_t length = 4;

	int32_t *memory = initInstructionMem(instructions, length);
	for (size_t i = 0; i < length; i++) {
		if (instructions[i] != *(memory + i))
			return false;
	}
	free(memory);

	memory = initInstructionMem(instructions, 101);
	if (memory != NULL) return false;
	
	memory = initInstructionMem(instructions, 0);
	if (memory != NULL) return false;

	return true;
}

bool instructionMemoryTests()
{
	if (!testInitInstructionMem()) {
		printf("- testInitInstructionMem() FAIL\n");
		return false;
	}

	return true;
}
