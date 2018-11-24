#include "imemory.h"
#include <stdint.h>
#include <stdlib.h>

#define MAX_INSTRUCTIONS 100

int32_t* initInstructionMem(int32_t** instructions, size_t length)
{
	int32_t* _memory[MAX_INSTRUCTIONS] = malloc(sizeof(int32_t) * MAX_INSTRUCTIONS);

	size_t limit = (length > MAX_INSTRUCTIONS) ? length : MAX_INSTRUCTIONS;

	for (size_t i = 0; i < limit; i++) {
		_memory[i] = **(instructions++);
	}

	return _memory;
}
