#ifndef MIPS_HEADER
#define MIPS_HEADER

#define TOTAL_GENERAL_REGISTERS 32

typedef struct s_registerFile {
	int32_t* _PC;
	int32_t* _IR;
	int32_t genPurpose[TOTAL_GENERAL_REGISTERS]; // Registradores de proposito geral
} registerFile;

void freeRegisterFile(registerFile* regFile);
extern registerFile* newRegisterFile();
extern void setReg(registerFile* regFile, size_t r, int32_t val);
extern int32_t getReg(registerFile* regFile, size_t r);

#endif
