#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "registerUnitTest.h"
#include "instructionMemoryUnitTest.h"

int main(int argc, char **argv)
{
	char* tests;
	printf("****** REALIZANDO TESTES *****\n");

	tests = (registerTests() == true) ? "PASSOU" : "FALHOU";
	printf("Primeiro teste: módulo dos registradores..\n");
	printf("Resultado: %s\n", tests);

	tests = (instructionMemoryTests() == true) ? "PASSOU" : "FALHOU";
	printf("Segundo teste: módulo da memória de instruções..\n");
	printf("Resultado: %s\n", tests);

	printf("****** FIM DOS TESTES *****\n");
}

