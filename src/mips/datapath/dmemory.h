#ifndef DMEMORY_HEADER
#define DMEMORY_HEADER

// Declarations
void initDataMem();
int32_t readData(int32_t offset);
void writeData(void* src, void* offset, size_t length);

#endif
