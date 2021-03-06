//UNIVERSIDAD DE MARIANO GALVEZ DE GUATEMALA
//AUTOMATAS Y LENGUAJES FORMALES
//REYNEER MOISES MORALES LEON 0901-14-9769

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "windows.h"

FILE *archivoSalida; //me va a servir para usarlo en varias funciones

int tokens = 0;
char n[2];
char lexema[170];
int letrasA;
int estado = 1;
char letra[2];
char nombre[100];
char salida[100];
char aux[100];
char simbolo[2];
char anterior[2];

// aqui creo mi alfabeto
char cadena1[170] = "void";
char cadena2[170] = "main";
char cadena3[170] = "include";
char cadena4[170] = "iostream";
char cadena5[170] = "conio";
char cadena6[170] = "int";
char cadena7[170] = "char";
char cadena8[170] = "string";
char cadena9[170] = "getch";
char cadena10[170] = "h";
char cadena11[170] = "switch";
char cadena12[170] = "case";
char cadena13[170] = "break";
char cadena14[170] = "system";
char cadena15[170] = "exit";
char cadena16[170] = "double";
char cadena17[170] = "float";
char cadena18[170] = "bool";
char cadena19[170] = "length";
char cadena20[170] = "size";
char cadena21[170] = "strlen";
char cadena22[170] = "strcat";
char cadena23[170] = "strcmp";
char cadena24[170] = "stdio";
char cadena25[170] = "stdlib";
char cadena26[170] = "fstream";
char cadena27[170] = "ofstream";
char cadena28[170] = "ifstream";
char cadena29[170] = "FILE";
char cadena30[170] = "append";
char cadena31[170] = "new";
char cadena32[170] = "pause";
char cadena33[170] = "fopen";
char cadena34[170] = "while";
char cadena35[170] = "for";
char cadena36[170] = "do";
char cadena37[170] = "if";
char cadena38[170] = "else";
char cadena39[170] = "cin";
char cadena40[170] = "cout";
char cadena41[170] = "scanf";
char cadena42[170] = "printf";
char cadena43[170] = "malloc";
char cadena44[170] = "sizeof";
char cadena45[170] = "return";
char cadena46[170] = "cls";
char cadena47[170] = "struct";
char cadena48[170] = "//";
char cadena49[170] = "/*";
char cadena50[170] = "*/";



int i;
int Espacio = 0;
int Signo = 0;
int dato = 0, dato1 = 0;

int EvaluaCaracter(char S) {

	int asciiL = S;
	
	switch (asciiL) {

	case 47:
		return 2;
		break;
	default:
		return 1;
		break;
	}

}

int EvaluaSimbolo(char simbolo) {

	int ascii = simbolo;
	archivoSalida = fopen("salida.txt", "a");

	switch (ascii) {

	case 43:
		fprintf(archivoSalida, "Lexema: - %c ; Token: -Suma\n", simbolo);
		tokens++;
		return 1;
		break;
	case 45:
		fprintf(archivoSalida, "Lexema: - %c ; Token: -Guion\n", simbolo);
		tokens++;
		return 2;
		break;
	case 42:
		fprintf(archivoSalida, "Lexema: - %c ; Token: -Asterisco\n", simbolo);
		tokens++;
		return 3;
		break;
	case 47:
		fprintf(archivoSalida, "Lexema: - %c ; Token: -Diagonal\n", simbolo);
		tokens++;
		return 4;
		break;
	case 46:
		fprintf(archivoSalida, "Lexema: - %c ; Token: -Punto\n", simbolo);
		tokens++;
		return 5;
		break;
	case 58:
		fprintf(archivoSalida, "Lexema: - %c ; Token: -Dos Puntos\n", simbolo);
		tokens++;
		return 6;
		break;
	case 59:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Punto y Coma\n", simbolo);
		tokens++;
		return 7;
		break;
	case 33:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Signo de Admiracion\n", simbolo);
		tokens++;
		return 8;
		break;
	case 173:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Signo de Admiracion\n", simbolo);
		tokens++;
		return 9;
		break;
	case 168:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Signo de interrogacion\n", simbolo);
		tokens++;
		return 10;
		break;
	case 63:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Signo de interrogacion\n", simbolo);
		tokens++;
		return 11;
		break;
	case 34:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Comillas\n", simbolo);
		tokens++;
		return 12;
		break;
	case 35:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Numeral\n", simbolo);
		tokens++;
		return 13;
		break;
	case 36:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Peso\n", simbolo);
		tokens++;
		return 14;
		break;
	case 37:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Porcentaje\n", simbolo);
		tokens++;
		return 15;
		break;
	case 38:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Amperson\n", simbolo);
		tokens++;
		return 16;
		break;
	case 40:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Parentesis Izquierdo\n", simbolo);
		tokens++;
		return 17;
		break;
	case 41:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Parentesis Derecho\n", simbolo);
		tokens++;
		return 18;
		break;
	case 123:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Llave Izquierda\n", simbolo);
		tokens++;
		return 19;
		break;
	case 125:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Llave Derecha\n", simbolo);
		tokens++;
		return 20;
		break;
	case 91:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Corchete Izquierdo\n", simbolo);
		tokens++;
		return 21;
		break;
	case 93:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Corchete Derecho\n", simbolo);
		tokens++;
		return 22;
		break;
	case 95:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Guion Bajo\n", simbolo);
		tokens++;
		return 23;
		break;
	case 64:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Arroba\n", simbolo);
		tokens++;
		return 24;
		break;
	case 94:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Acento\n", simbolo);
		tokens++;
		return 25;
		break;
	case 239:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Coma\n", simbolo);
		tokens++;
		return 26;
		break;
	case 61:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Igual\n", simbolo);
		tokens++;
		return 27;
		break;
	case 60:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Menor Que\n", simbolo);
		tokens++;
		return 28;
		break;
	case 62:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Mayor Que\n", simbolo);
		tokens++;
		return 29;
		break;
	case 44:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Coma\n", simbolo);
		tokens++;
		return 30;
		break;
	case 124:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Pipe\n", simbolo);
		tokens++;
		return 31;
		break;
	case 92:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Barra Invertida\n", simbolo);
		tokens++;
		return 32;
		break;
	case 39:
		fprintf(archivoSalida, "Lexema: - %c ; Token: Comilla Simple\n", simbolo);
		tokens++;
		return 33;
		break;
	}

	fflush(archivoSalida);
	fclose(archivoSalida);

}

void EvaluaMuestra(char Cadena[]) {

	archivoSalida = fopen("salida.txt", "a");
	if ((strcmp(Cadena, cadena46) == 0) || (strcmp(Cadena, cadena32) == 0)) {

		fprintf(archivoSalida, "Lexema: - %s ; Token: reservada\n", Cadena);
		tokens++;

	}
	else {

		fprintf(archivoSalida, "Lexema: - %s ; Token: Es una salida en pantalla\n", Cadena);
		tokens++;

	}
	fflush(archivoSalida);
	fclose(archivoSalida);
}

int EvaluaLexema(char Lex[]) {

	archivoSalida = fopen("salida.txt", "a");

	if ((strcmp(Lex, cadena1) == 0) || (strcmp(Lex, cadena2) == 0) || (strcmp(Lex, cadena3) == 0) || (strcmp(Lex, cadena4) == 0) ||
		(strcmp(Lex, cadena5) == 0) || (strcmp(Lex, cadena6) == 0) || (strcmp(Lex, cadena7) == 0) || (strcmp(Lex, cadena8) == 0) ||
		(strcmp(Lex, cadena9) == 0) || (strcmp(Lex, cadena10) == 0)) {

		fprintf(archivoSalida, "Lexema: %s ; Token: reservada\n", Lex);
		tokens++;

	}
	else if ((strcmp(Lex, cadena48) == 0)) {

		fprintf(archivoSalida, "Lexema: - %s ; Token: Simbolo comentario\n", Lex);
		tokens++;

	}
	else if ((strcmp(Lex, cadena49) == 0)) {

		fprintf(archivoSalida, "Lexema: - %s ; Token: Comentario Izquierdo\n", Lex);
		tokens++;

	}
	else if ((strcmp(Lex, cadena50) == 0)) {

		fprintf(archivoSalida, "Lexema: - %s ; Token: Comentario Derecho\n", Lex);
		tokens++;

	}
	else {

		fprintf(archivoSalida, "Lexema: - %s ; Token: Es un ID\n", Lex);
		tokens++;

	}
	fflush(archivoSalida);
	fclose(archivoSalida);
	return 2;

}

int LimpiaCadena(char Limpia[]) {

	for (i = 0; i < strlen(Limpia); i++) {

		Limpia[i] = '\0';
	}

	return 1;
}

void Scanner(char caracter) {

	char letraAnterior;
	archivoSalida = fopen("salida.txt", "a");

	letra[0] = caracter;

	switch (estado) {

	case 1:

		if (isalpha(letra[0])) {

			letrasA++;
			strcat(lexema, letra);
			estado = 1;

		}
		else if (letra[0] == '"') {

			EvaluaSimbolo(caracter);
			estado = 5;

		}
		else if (isspace(letra[0])) {

			if (letrasA > 0) {

				EvaluaLexema(lexema);
				LimpiaCadena(lexema);
				letrasA = 0;
				estado = 2;

			}
			else if (letrasA == 0) {

				estado = 1;
				letrasA = 0;
			}

		}
		else if (isdigit(letra[0])) {

			if (letrasA > 0) {

				strcat(lexema, letra);
				estado = 1;

			}
			else if (letrasA == 0) {

				strcat(lexema, letra);
				estado = 3;
				letrasA++;
			}

		}
		else {

			if (letrasA > 0) {

				EvaluaLexema(lexema);
				dato = EvaluaCaracter(caracter);
				LimpiaCadena(lexema);

				if (dato == 2) {

					anterior[0] = caracter;
					strcat(lexema, anterior);
					letraAnterior = caracter;
					estado = 6;

				}
				else if (dato == 1) {

					EvaluaSimbolo(caracter);
					estado = 1;
				}
				letrasA = 0;
			}
			else if (letrasA == 0) {

				dato1 = EvaluaCaracter(caracter);

				if (dato1 == 2) {

					simbolo[0] = caracter;
					letraAnterior = caracter;
					strcat(lexema, simbolo);
					estado = 6;
					letrasA = 0;

				}
				else if (dato1 == 1) {

					EvaluaSimbolo(caracter);
					estado = 1;
					letrasA = 0;

				}
			}
		}

		break;

	case 2:

		if (isalpha(letra[0])) {

			strcat(lexema, letra);
			estado = 1;
			letrasA++;

		}
		else if (isspace(letra[0])) {

			estado = 1;

		}
		else {

			if (letrasA > 0) {

				EvaluaLexema(lexema);
				EvaluaSimbolo(caracter);
				LimpiaCadena(lexema);
				letrasA = 0;
				estado = 1;

			}
			else {

				EvaluaSimbolo(caracter);
				estado = 1;

			}
		}

		break;

	case 3:

		if (isdigit(letra[0])) {

			estado = 3;
			strcat(lexema, letra);
			letrasA++;

		}
		else if (isspace(letra[0])) {

			if (letrasA > 0) {

				fprintf(archivoSalida, "Lexema: - %s ; Token: Es un digito\n", lexema);
				tokens++;
				LimpiaCadena(lexema);
				letrasA = 0;
				estado = 1;

			}
			else if (letrasA == 0) {

				estado = 1;
			}

		}
		else if (letra[0] == '.') {

			strcat(lexema, letra);
			letrasA++;
			estado = 4;

		}
		else {

			if (letrasA > 0) {

				fprintf(archivoSalida, "Lexema: - %s ; Token: Es un digito\n", lexema);
				tokens++;
				EvaluaSimbolo(caracter);
				LimpiaCadena(lexema);
				letrasA = 0;
				estado = 1;

			}
			else if (letrasA == 0) {

				estado = 1;

			}
		}
		break;

	case 4:

		if (isdigit(letra[0])) {

			strcat(lexema, letra);
			estado = 4;

		}
		else if (isspace(letra[0])) {

			if (letrasA > 0) {

				fprintf(archivoSalida, "Lexema: - %s ; Token: Es un decimal\n", lexema);
				tokens++;
				LimpiaCadena(lexema);
				letrasA = 0;
				estado = 1;

			}
			else if (letrasA == 0) {

				estado = 1;
			}

		}
		else {

			if (letrasA >  0) {

				fprintf(archivoSalida, "Lexema: - %s ; Token: Es un decimal\n", lexema);
				tokens++;
				EvaluaSimbolo(caracter);
				LimpiaCadena(lexema);
				letrasA = 0;
				estado = 1;
			}
		}
		break;

	case 5:

		if (isalpha(letra[0])) {

			strcat(lexema, letra);
			estado = 5;

		}
		else if (isdigit(letra[0])) {

			strcat(lexema, letra);
			estado = 5;

		}
		else if (isspace(letra[0])) {

			strcat(lexema, letra);
			estado = 5;

		}
		else if (letra[0] == '"') {

			EvaluaMuestra(lexema);
			LimpiaCadena(lexema);
			EvaluaSimbolo(caracter);
			estado = 1;
			letrasA = 0;
			dato1 = 0;
			dato = 0;

		}
		else {

			strcat(lexema, letra);
			estado = 5;

		}
		break;

	case 6:
		if (letra[0] == '/') {

			strcat(lexema, letra);
			EvaluaLexema(lexema);
			LimpiaCadena(lexema);
			estado = 7;
			dato1 = 0;
			dato = 0;

		}
		else if (isalpha(letra[0])) {

			EvaluaSimbolo(letraAnterior);
			LimpiaCadena(lexema);
			strcat(lexema, letra);
			letrasA++;
			estado = 1;
			dato1 = 0;
			dato = 0;

		}
		else if (isdigit(letra[0])) {

			EvaluaSimbolo(letraAnterior);
			LimpiaCadena(lexema);
			strcat(lexema, letra);
			letrasA++;
			estado = 3;
			dato1 = 0;
			dato = 0;

		}
		else if (letra[0] == '*') {

			strcat(lexema, letra);
			EvaluaLexema(lexema);
			LimpiaCadena(lexema);
			estado = 8;
			dato1 = 0;
			dato = 0;

		}
		else if (letra[0] == '\n') {

			EvaluaSimbolo(letraAnterior);
			LimpiaCadena(lexema);
			dato1 = 0;
			dato = 0;
			estado = 1;

		}
		break;

	case 7:
		if (letra[0] == '\n') {

			fprintf(archivoSalida, "Lexema: - %s ; Token: Es un comentario\n", lexema);
			tokens++;
			LimpiaCadena(lexema);
			estado = 1;

		}
		else {

			strcat(lexema, letra);
			estado = 7;
		}
		break;

	case 8:

		if (letra[0] == '*') {

			fprintf(archivoSalida, "Lexema: - %s ; Token: Es un comentario\n", lexema);
			tokens++;
			LimpiaCadena(lexema);
			estado = 9;
			strcat(lexema, letra);

		}
		else {

			strcat(lexema, letra);
			estado = 8;

		}
		break;

	case 9:

		if (letra[0] == '/') {

			strcat(lexema, letra);
			EvaluaLexema(lexema);
			LimpiaCadena(lexema);
			estado = 1;

		}
		else {
			estado = 1;
		}

		break;
	}
	fflush(archivoSalida);
	fclose(archivoSalida);

}

void lecturaArchivo() {

	char caracter1;

	FILE *archivo;


	archivo = fopen("entrada.txt", "r");

       if (archivo != NULL) {

		while (!feof(archivo)) {

			caracter1 = fgetc(archivo);
			//printf("%c\n",caracter1);
			Scanner(caracter1);

		}

		fclose(archivo);

	}

}
int main(int argn, char *argv[]) {

printf("REYNEER MOISES MORALES LEON 0901-14-9769\n") ;

lecturaArchivo();
	int i, j, k, l;


	for (i = 1; i < argn; i++) {


		strcat("entrada.txt", argv[i]);
		///////////////////////////////////////////////
		strcat("salida.txt", "arch");
		strcat("salida.txt", argv[i]);

		/////////////////////////////////////////////
		archivoSalida = fopen("salida.txt", "a");

		LimpiaCadena("salida.txt");
		LimpiaCadena("entrada.txt");
		fflush(archivoSalida);
		fclose(archivoSalida);
		tokens = 0;

	}

	
	system("pause");
	exit(1);

	return 0;
   }