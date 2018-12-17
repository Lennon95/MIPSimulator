#ifndef MIPS_HEADER
#define MIPS_HEADER

typedef struct s_registerFile {
	int32_t genPurpose[32]; // Registradores de proposito geral
	int32_t* _PC;
	int32_t* _IR;
} registerFile;

extern registerFile* newRegisterFile();
extern void resetRegisterFile(registerFile* regFile);

#endif
