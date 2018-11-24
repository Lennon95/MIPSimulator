#ifndef DMEMORY_HEADER
#define DMEMORY_HEADER

// Declarations
void initDataMem();
void* readData(void* dest, void* offset, size_t length);
bool writeData(void* src, void* offset, size_t length);

#endif
