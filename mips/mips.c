#include <stdio.h>

#include "mips.h"

struct registerFile {
	long int genPurpose[32]; // Registradores de proposito geral
	long int __PC;
	long int __IR;
}



