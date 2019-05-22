#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "dmemory.h"

// 10MB Data Memory
#define MEMORY_SIZE (10*1024*1024)

static int32_t* data;

void initDataMem()
{
	free(data);
	data = (int32_t*) malloc(MEMORY_SIZE * sizeof(int32_t));
	memset(data, '\0', MEMORY_SIZE);
}

int32_t* getActualAddr()
{
	return data;
}

int32_t readData(size_t offset)
{
	return *(data + offset);
}

void writeData(void* src, void* offset, size_t length)
{
	memcpy((data + offset), src, length);
}
