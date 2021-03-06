/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "prueba.h"
#include "prueba_client.h"
#include <string.h>

int main(int argc, char *argv[]) {
	char *host;
	int operation;
	operandos numbers;
	CLIENT *client;

	// Variables assignment logic
	checkCommandLineArguments(argc, argv);
	host = argv[1];
	operation = parseOperation(argv[2], argv[0]);
	numbers.a = atoi(argv[3]);
	numbers.b = atoi(argv[4]);
	client = createClient(host);

	// Server calling logic
	callServerFunction(client, operation, &numbers);
	clnt_destroy(client);
	
	exit(0);
}

void checkCommandLineArguments(int argc, char *argv[]) {
	if (argc != 5) {
		wrongInputMessage(argv[0]);
	}
}

void wrongInputMessage(char *programName) {
	fprintf(stderr, "uso: %s <IP_HOST> <SUMA|RESTA|MULTIPLICACION|DIVISION> <NÚMERO_1> <NÚMERO_2>\n", programName);
	exit (1);
}

int parseOperation(char *operation, char *programName) {
	if(strcmp(operation, "SUMA") == 0) {
		return 0;
	}
	else if(strcmp(operation, "RESTA") == 0) {
		return 1;
	}
	else if(strcmp(operation, "MULTIPLICACION") == 0) {
		return 2;
	}
	else if(strcmp(operation, "DIVISION") == 0) {
		return 3;
	}
	else {
		wrongInputMessage(programName);
	}
}

CLIENT * createClient(char *host) {
	CLIENT *client;

	client = clnt_create(host, CALCULADORA_PROG, CALCULADORA_VERS, "udp");
	if (client == NULL) {
		clnt_pcreateerror(host);
		exit (1);
	}

	return client;
}

void callServerFunction(CLIENT *client, int operation, operandos *numbers) {
	switch (operation) {
		case 0:
			callAdditionFunction(client, numbers);
			break;
		case 1:
			callSubstractionFunction(client, numbers);
			break;
		case 2:
			callMultiplicationFunction(client, numbers);
			break;
		case 3:
			callDivisionFunction(client, numbers);
			break;
		default:
			fprintf(stderr, "Error identificando la operación\n");
			exit(1);
			break;
	}
}

void callAdditionFunction(CLIENT *client, operandos *numbers) {
	int *result;

	result = suma_1(numbers, client);
	if(result == NULL) {
		clnt_perror (client, "Llamada a suma fallida\n");
	}

	printf("El resultado de la suma es %d\n", *result);
}

void callSubstractionFunction(CLIENT *client, operandos *numbers) {
	int *result;

	result = resta_1(numbers, client);
	if(result == NULL) {
		clnt_perror (client, "Llamada a resta fallida\n");
	}

	printf("El resultado de la resta es %d\n", *result);
}

void callMultiplicationFunction(CLIENT *client, operandos *numbers) {
	int *result;

	result = multiplicacion_1(numbers, client);
	if(result == NULL) {
		clnt_perror (client, "Llamada a multiplicación fallida\n");
	}

	printf("El resultado de la multiplicación es %d\n", *result);
}

void callDivisionFunction(CLIENT *client, operandos *numbers) {
	float *result;

	if(numbers->b == 0) {
		fprintf(stderr, "No es posible dividir un número entre 0\n");
		exit(1);
	}

	result = division_1(numbers, client);
	if(result == NULL) {
		clnt_perror (client, "Llamada a división fallida\n");
	}

	printf("El resultado de la división es %f\n", *result);
}