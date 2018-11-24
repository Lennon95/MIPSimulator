#include <stdint.h>
#include "alu.h"

int32_t alu_execute(int32_t src1, int32_t src2, char ctrl)
{
	switch (op) {
		case 0x0: // Operacao AND
		return (src1 & src2);

		case 0x1: // Operacao OR
		return (src1 | src2);

		case 0x2: // Operacao ADD
		return (src1 + src2);

		case 0x4: // Operacao SUBTRACT
		return (src1 - src2);

		case 0x7: // Operacao SET ON LESS THAN
		return (src1 < src2) 1 : 0;
	}	
}

