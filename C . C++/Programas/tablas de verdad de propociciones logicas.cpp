#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LMAX 100

//DECLARACION DE PROTOTIPOS

int leer_entrada(char *prop);
int max_precedencia(char *prop, int ini, int fin);
int precedencia(char c);
bool validar_sintaxis(char *prop, int ini, int fin);
bool evaluar_proposicion(char *prop, bool *vals, char *vars, char *resp, int ini, int fin);
int buscar_variables(char *prop, char *vars);


//PROGRAMA PRINCIPAL

int main() {
	char prop[LMAX];
	char *vars;
	char *resp;
	bool *vals;	
	
	
	printf("Este programa construye la tabla de verdad de una exprecion logica.\n");
	printf("Los operadores logicos validos son:\n\n");
	printf("\"!\"\tNEGACION\n");
	printf("\"&\"\tCONJUNCION\n");
	printf("\"|\"\tDISYUNCION\n");
	printf("\":\"\tIMPLICACION\n");
	printf("\"=\"\tBICONDICIONAL\n\n");
	printf("Puede usar expreciones anidadas con parentesis.\n\n");
	
	printf("EXPRECION> ");
	int n = leer_entrada(prop);
	
	resp = new char[n];
	vars = new char[n];
	vals = new bool[n];
	for(int i=0; i<n; i++) {
		resp[i] = ' ';
		vars[i] = '\0';
		vals[i] = false;
	}
	resp[n-1] = '\0';
	
	if(validar_sintaxis(prop, 0, n)) {
		int nvars = buscar_variables(prop, vars);
 		int reps = (int)pow(2, nvars);

        printf("\n");
		for(int i=0; i<nvars; i++)
			printf("%c ", vars[i]);
		printf("| ");
		for(int i=0; i<n; i++)
			printf("%c ", prop[i]);
		printf("\n\n");		
		for(int i=0; i<reps; i++) {
			for(int j=0; j<nvars; j++) {
				if(i%(int)pow(2, nvars-j-1) == 0) {
					vals[j] = !vals[j];
				}
				if(vals[j]) printf("V "); else printf("F ");
			}
			printf("| ");
			evaluar_proposicion(prop, vals, vars, resp, 0, n);
			for(int j=0; j<n; j++)
				printf("%c ", resp[j]);
			printf("\n");
		}
	}
	else {
		printf("ERROR LA SINTAXIS DE LA EXPRECION ES INCORRECTA.\n");
	}
    system("pause>nul");
	return 0;
}


//IMPLEMENTACION DE FUNCIONES

/*
Lee una exprecion por teclado anulando los espacios en blanco y devuelve el 
numero de caracteres que conforman la exprecion.
*/
int leer_entrada(char *prop) {
	char c; int i=0;
	while((c=getchar()) != '\n' && i < (LMAX-1))
		if(c!=' ')
			prop[i++] = c;
	prop[i] = '\0';
	return i;
}

/*
Busca dentro de una exprecion el operador que tiene mayor precedencia, es decir,
el que se resolvera al final y devuelve su indice dentro de la exprecion.
*/
int max_precedencia(char *prop, int ini, int fin) {
	int npar=0, prec=0, anid=0, index=0;
	bool prim=true;
	for(int i=ini; i<fin; i++) {
		if(prop[i] == '(') {
			npar++;
		}
		else if(prop[i] == ')') {
			npar--;
		}
		else {
			if(npar<0) return -1;	//error de sintaxis
			int p = precedencia(prop[i]);
			if(prim) {
				anid = npar;
				prec = p;
				index = i;
				prim = false;
				continue;
			}
			if(npar<anid) {
				anid = npar;
				prec = p;
				index = i;
			}
			else if(anid==npar) {
				if(p>prec) {
					prec = p;
					index = i;
				}
				else if(p==prec) {
					if(prop[index] != prop[i])
						return -1;	//error de doble interpretacion
					if(prop[index] != '!')
						index = i;
				}
			}
		}
	}
	if(npar != 0 || prim) return -1;	//error de sintaxis
	return index;
}

/*
Esta funcion recibe un caracter por parametro y devuelve un entero de 0 a 4 que
representa la precedencia del operador. Los operadores con menor precedencia
se resuelven primero y los que tienen mayor precedencia se resuelven al final.
*/
int precedencia(char c) {
	switch(c) {
		case '!': return 1;	//negacion
		case '&': return 2;	//conjuncion
		case '|': return 2;	//disyuncion
		case ':': return 3;	//implicacion
		case '=': return 4;	//bicondicional
	}
	return 0;
}

/*
Esta funcion se encarga de validar la sintaxis de una exprecion de forma recursiva
usando la siguiente definicion:

	P ::= p / (!P) / (P&Q) / (P|Q) / (P:Q) / (P=Q)

Devuelve verdadero si la proposicion cumple la definicion y falso si no.
*/
bool validar_sintaxis(char *prop, int ini, int fin) {
	int index = max_precedencia(prop, ini, fin);
	if(index == -1) return false;
	if(prop[index] == '!') {
		int npar=0, i=index+1, f;
		for(f=i; f<fin; f++) {
			if(prop[f]=='(') {
				npar++;
			}
			else if(prop[f]==')') {
				npar--;
				if(npar<0) break;
			}
		}
		return validar_sintaxis(prop, i, f);
	}
	else if(prop[index]=='&' || prop[index]=='|' || prop[index]==':' || prop[index]=='=') {
		int npar=0, i, f=index;
		bool p, q;
		for(i=f-1; i>=ini; i--) {
			if(prop[i]==')') {
				npar++;
			}
			else if(prop[i]=='(') {
				npar--;
				if(npar<0) break;
			}
		}
		p = validar_sintaxis(prop, i+1, f);
		npar=0; i=index+1;
		for(f=i; f<fin; f++) {
			if(prop[f]=='(') {
				npar++;
			}
			else if(prop[f]==')') {
				npar--;
				if(npar<0) break;
			}
		}
		q = validar_sintaxis(prop, i, f);
		return (p && q);
	}
	else {
		int vars=0;
		for(int i=ini; i<fin; i++)
			if(prop[i]!='(' && prop[i]!=')')
				vars++;
		if(vars == 1)
			return true;
	}
	return false;
}

bool evaluar_proposicion(char *prop, bool *vals, char *vars, char *resp, int ini, int fin) {
	int index = max_precedencia(prop, ini, fin);
	if(prop[index] == '!') {
		int npar=0, i=index+1, f;
		bool b;
		for(f=i; f<fin; f++) {
			if(prop[f]=='(') {
				npar++;
			}
			else if(prop[f]==')') {
				npar--;
				if(npar<0) break;
			}
		}
		b = !evaluar_proposicion(prop, vals, vars, resp, i, f);
		if(b) resp[index] = 'V'; else resp[index] = 'F';
		return b;
	}
	else if(prop[index]=='&' || prop[index]=='|' || prop[index]==':' || prop[index]=='=') {
		int npar=0, i, f=index;
		bool p, q, r;
		for(i=f-1; i>=ini; i--) {
			if(prop[i]==')') {
				npar++;
			}
			else if(prop[i]=='(') {
				npar--;
				if(npar<0) break;
			}
		}
		p = evaluar_proposicion(prop, vals, vars, resp, i+1, f);
		npar=0; i=index+1;
		for(f=i; f<fin; f++) {
			if(prop[f]=='(') {
				npar++;
			}
			else if(prop[f]==')') {
				npar--;
				if(npar<0) break;
			}
		}
		q = evaluar_proposicion(prop, vals, vars, resp, i, f);
		switch(prop[index]) {
			case '&': r = p&&q; break;
			case '|': r = p||q; break;
			case ':': r = !p||q; break;
			case '=': r = (!p||q)&&(!q||p); break;
		}
		if(r) resp[index] = 'V'; else resp[index] = 'F';
		return r;
	}
	else {
		for(int i=0; vars[i]!='\0'; i++)
			if(prop[index] == vars[i]){
				if(vals[i])
					resp[index] = 'V';
				else
					resp[index] = 'F';
				return vals[i];
			}
	}
}

int buscar_variables(char *prop, char *vars){
	int nvars = 0;
	for(int i=0; prop[i]!='\0'; i++) {
		if(prop[i]!='(' && prop[i]!=')' && prop[i]!='!' && prop[i]!='&' && prop[i]!='|' && prop[i]!=':' && prop[i]!='=') {
			bool existe = false;
			for(int j=0; j<nvars && !existe; j++) {
				if(prop[i] == vars[j]) {
					existe = true;
				}
			}
			if(!existe) {
				vars[nvars++] = prop[i];
			}
		}
	}
	return nvars;
}
