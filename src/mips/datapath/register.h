#ifndef MIPS_HEADER
#define MIPS_HEADER

#define TOTAL_GENERAL_REGISTERS

typedef struct s_registerFile {
	int32_t genPurpose[TOTAL_GENERAL_REGISTERS]; // Registradores de proposito geral
	int32_t* _PC;
	int32_t* _IR;
} registerFile;

extern registerFile* newRegisterFile();
extern void resetRegisterFile(registerFile* regFile);

#endif
