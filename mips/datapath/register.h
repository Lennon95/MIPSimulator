#ifndef MIPS_HEADER
#define MIPS_HEADER

typedef struct s_registerFile registerFile;

extern registerFile* newRegisterFile();
extern void resetRegisterFile(registerFile* regFile);

#endif
