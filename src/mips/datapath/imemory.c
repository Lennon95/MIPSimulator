#include <stdint.h>
#include <stdlib.h>
#include "imemory.h"

#define MAX_INSTRUCTIONS 100

int32_t *initInstructionMem(int32_t* instructions, size_t length)
{
	if (length <= 0 || length > MAX_INSTRUCTIONS)
		return NULL;

	int32_t* _memory = malloc(sizeof(int32_t) * length);

	for (size_t i = 0; i < length; i++) {
		_memory[i] = *(instructions + i);
	}

	return _memory;
}
