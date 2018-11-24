#include <stdlib.h>
#include <string.h>
#include "dmemory.h"

// 10MB Data Memory
#define MEMORY_SIZE (10*1024*1024)

static void* data = NULL;

void initDataMem()
{
	free(data);
	data = malloc(MEMORY_SIZE);
	memset(_data, '\0', MEMORY_SIZE);

	return data;
}

void* readData(void* dest, void* offset, size_t length)
{
	return memcpy(dest, (data + offset), length);
}

bool writeData(void* src, void* offset, size_t length)
{
	return memcpy((data + offset), src, length);
}
