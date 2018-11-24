#include <stdint.h>
#include "mux.h"

int32_t muxtiplex(int32_t src1, int32_t src2, int selector)
{
	return (selector == 0) ? src1 : src2;
}
