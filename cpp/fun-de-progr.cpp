/*
#include <stdio.h>

main(){
	printf("Hola Mundo! \n");
}



#include <iostream>

using namespace std;
int main()
{
	cout << "Hola Mundo!" << endl;
	return 0;
}



// cuenta a 10
int x = 0;
do
	cout << "x:" << x++;
while (x < 10);




using namespace std;
int main()
{
	std::cout << "áéíóúñ" << std::endl;
	return 0;
}



#include <iostream>

using namespace std;

// imprimir letras minúsculas del alfabeto
char car = 'a';

int main()
{
	do
	{
		cout << car << '';
		car++;
	}
	return 0;
} while (car <= 'z');




#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	int i;
	i = 1;

	do{
		cout << i << endl;
		i++;
	} while(i <= 10);

	system("pause");

	return 0;
}



#include <iostream>
// Ejemplo 1, página  197
// cuenta a 10

using namespace std;

int main(){
	int x = 0;

	do{
		cout << x << endl;
		x++;
	} while(x < 10);

	return 0;
}



#include <iostream>
// Ejemplo 1, página  197
// cuenta a 10

using namespace std;

int main(){
	int x = 0;

	do{
		cout << "X: " << x++;
		
	} while(x < 10);

	return 0;
}



#include <iostream>
// Ejemplo 2, página  198
// imprimir letras minúsculas del alfabeto

using namespace std;

int main(){
	char car = 'a';

	do{
		cout << car << endl;
		car++;
	} while(car <= 'z');

	return 0;
}



#include <iostream>
// Ejemplo 5.7, página  198
// visualizar las potencias de dos cuerpos

using namespace std;

int main(){
	int potencia = 1;

	while(potencia < 1000){
		cout << potencia << endl;
		potencia *= 2;
	} 

	return 0;
}



#include <iostream>
// Ejemplo 5.7, página  198
// visualizar las potencias de dos cuerpos

using namespace std;

int main(){
	int potencia = 1;

	do {
		cout << potencia << endl;
		potencia *= 2;
	} while(potencia < 1000);

	return 0;
}



#include <iostream>
// Ejemplo 5.10.1, página  209
// lectura de una lista de números y calcular su suma

using namespace std;

int main(){
	int suma = 0;

	for (int cuenta = 1; cuenta <= 10; cuenta++)
	{
		cin >> cuenta;
		suma = suma + cuenta;
	}
	cout << "La suma es: " << suma;

	return 0;
}



#include <iostream>
// página  210

using namespace std;

int main(){
	int suma = 0;
	int numero;
	cout << "¿Existen números en la lista?:\n"
	     << "Teclee S para Sí, N para No y Final, Intro";
	char resp;
	cin >> resp;

	while ((resp == 'S') || (resp == 's'))
	{
		cout << "Introduzca un número";
		cin >> numero;
		suma = suma + numero;
		cout << "¿Existen más números?:\n"
		     << "S para Sí, N para No. Final con Intro";
		cin >> resp;
	}
	cout << "La suma es: " << suma;

	return 0;
}



#include <iostream>
// ejemplo de valor centinela (número negativo)
// página  210

using namespace std;

int main(){
	int suma = 0;
	int numero;
	cout << "Introduzca una lista de enteros positivos" << endl
	     << "Termine la lista con un número negativo" << endl;
	cin >> numero;

	while (numero >= 0)
	{
		suma = suma + numero;
		cin >> numero;
	}
	cout << "La suma es: " << suma;

	return 0;
}



// ejemplo 5.20 página 214
// aplicación de bucles anidados

#include <iostream>
#include <iomanip>	// necesario para cin y cout
using namespace std;	// necesario para setw

int main(){
	// cabecera de impresión
	cout << setw(12) << " i " << setw(6) << " j " << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << " Externo " << setw(7) << i << endl;
		for (int j = 0; j < i; j++)
		{
			cout << "Interno " << setw(10) << j << endl;
		}
	} // fin del bucle externo

	return 0;
}



// ejercicio 5.1 página 214
// escribir un programa que visualice un triángulo isósceles

#include <iostream>
//#include <iomanip>	// necesario para cin y cout
using namespace std;	// necesario para setw

int main(){
	// datos locales...
	const int num_lineas = 5;
	const char blanco = ' ';
	const char asterisco = '*';

	// comienzo de una nueva línea
	cout << endl;

	//dibujar cada línea: bucle externo
	for (int fila = 1; fila <= num_lineas; fila++)
	{
		// imprimir espacios en blanco: primer bucle interno
		for (int blancos = num_lineas -fila; blancos > 0; blancos--)
			cout << blanco;
		for (int cuenta_as = 1; cuenta_as < 2 * fila; cuenta_as++)
			cout << asterisco;

		// terminar línea
		cout << endl;
	} // fin del bucle externo

	return 0;
}



// ejercicio 5.2 página 215
// imprimir una tabla de m filas por n columnas y un carácter prefijado

// listado
// ilustra bucles for anidados

#include <iostream>
using namespace std;

int main(){
	int filas, columnas;
	char elCar;
	cout << "¿Cuantas filas?";
	cin >> filas;
	cout << "¿Cuantas columnas?";
	cin >> columnas;
	cout << "¿Que caracter?";
	cin >> elCar;

	for (int i = 0; i <= filas; i++)
	{
		for (int j = 0; j < columnas; j++)
			cout << elCar;
		cout << "\n";
	}

	return 0;
}



// actividad resuelta 5.13 página 213
// imprimir las tablas de multiplicar

#include <iostream>
using namespace std;

int main(){
	int I, J, PROD;

	for (I = 1; I <= 9; I++)
	{
		cout << "Tabla del " << I << '\n';

		for (J = 1; J <= 9; J++)
			cout << I << " por " << J << " = " << (I * J) << "\n" ;

		cout << "\n \n";
	}

	return 0;
}



// actividad resuelta 5.18 página 225
// calcular el factorial de un número positivos

#include <iostream>
using namespace std;

int main(){
	int i, NUM, FACT;
	cout << "Ingrese un numero ";
	cin >> NUM;

	if (NUM < 0)
	{
		cout << "El numero debe ser positivo" << "\n \n";
	}
	else
	{
		FACT = 1;
		if (NUM > 1)
		{
			for (i = 1; i <= NUM; i++)
			{
				FACT = FACT * i;
			}
		}

		cout << "El factorial de " << NUM << " es " << FACT << "\n \n";
	}

	return 0;
}



// actividad resuelta 5.18 página 225
// calcular el factorial de un número positivos

#include <iostream>
using namespace std;

int main(){
	int i, NUM, FACT;
	cout << "Ingrese un numero ";
	cin >> NUM;

	while (NUM < 0)
	{
		cout << "El numero debe ser positivo" << "\n";
		cout << "Ingrese un nuevo numero ";
		cin >> NUM;
	}

	FACT = 1;
	if (NUM > 1)
	{
		for (i = 1; i <= NUM; i++)
		{
			FACT = FACT * i;
		}
	}

	cout << "El factorial de " << NUM << " es " << FACT << "\n \n";
	
	return 0;
}



// prueba sin concluir

#include <iostream>
using namespace std;

int main(){
	int x, func, NUM;
	cout << "Ingrese un numero ";
	cin >> NUM;

	while (NUM < 0)
	{
		cout << "El numero debe ser positivo" << "\n";
		cout << "Ingrese un nuevo numero ";
		cin >> NUM;
	}

	int func(x)
	{
		x = NUM / (1 + NUM);
	}

	cout << "La funcion de " << x << " es " << func(NUM) << "\n \n";

	return 0;
}



// prueba sin concluir

#include <iostream>
using namespace std;

int main(){
	int num, exp, pot;
	cout << "Ingrese un numero ";
	cin >> num;
	cout << "Ingrese un exponente ";
	cin >> exp;

	pot = 1;
	for (int i = 1; i <= exp; i++)
	{
		pot = pot * num;
	}

	cout << "La " << exp << "a potencia de " << num << " es " << pot << "\n \n";	

	return 0;
}



// ejemplo 6.1 y 6.2 página 236

#include <iostream>
using namespace std;

int potencia(int x, int n) {
	int i, y;
	y = 1;
	for (int i = 0; i < n; i++)
	{
		y = y * x;
	}

	return y;
}

int main(){
	int num, exp, algo;
	cout << "Ingrese un numero ";
	cin >> num;
	cout << "Ingrese un exponente ";
	cin >> exp;

	algo = potencia(num, exp);
	cout << algo << "\n \n";

	return 0;
}



// ejemplo 6.4 página 237

#include <iostream>
using namespace std;

int cubo(int x)
{
	return x * x * x;
}

int main(){
	int num;
	num = cubo(2);
	cout << "2 al cubo es " << num << "\n";;
	cout << "3 al cubo es " << cubo(3) << "\n \n";;

	return 0;
}



// ejemplo 6.1 y 6.2 página 236

#include <iostream>
using namespace std;

int potencia(int x, int n)
{
	int i, y;
	y = 1;
	for (int i = 0; i < n; i++)
	{
		y = y * x;
	}

	return y;
}

int main(){
	int num, exp, algo;
	cout << "Ingrese un numero ";
	cin >> num;
	cout << "Ingrese un exponente ";
	cin >> exp;

	algo = potencia(num, exp);
	cout << algo << "\n \n";

	return 0;
}



// ejemplo suelto página 241
// me da cualquier cosa

#include <iostream>
using namespace std;

int division(int dividendo, int divisor, int cociente, int resto)
{
	cociente = dividendo / divisor;
	resto = dividendo - cociente * divisor;

	return cociente, resto;
}

int main(){
	int M, N, P, Q, S, T;
	cout << "Ingrese un numero ";
	cin >> M;
	cout << "Ingrese otro numero ";
	cin >> N;

	division(M, N, P, Q);
	cout << P << ' ' << Q << "\n \n";

	return 0;
}



// ejemplo 6.8 página 242
// modificado con sentencias <else if>

#include <iostream>
using namespace std;

int calccifrarom(int digito, char v1, char v2, char v3)
{
	int j;
	if (digito == 9){
		cout << v1 << v3;
	} else if (digito > 4) {
		cout << v2;
		for (j = 0; j < digito - 5; j++) {
			cout << v1;
		}
	} else if (digito == 4) {
		cout << v1 << v2;
	} else {
		for (int j = 0; j < digito; j++) {
			cout << v1;
		}
	}

	return 0;
}

int main()
{
	string traduccion;
	traduccion = calccifrarom(8, 'I', 'V', 'X');
	cout << traduccion << "\n \n";
	//return 0;

	int num;

	while (num >= 0){
		cout << "Ingrese un numero ";
		cin >> num;
	}
}



// ejemplo 6.8 página 242
// modificado para ingresar cualquier número, indefinidamente, mayor
// que cero y menor que 3999

#include <iostream>
using namespace std;

int calccifrarom(int n)
{
	int digito, r, i;
	r = n;

	digito = r / 1000;
	r = r % 1000;
	for (i = 1; i <= digito; i++) {
		cout << 'M';
	}

	digito = r / 100;
	r = r % 100;
	if (digito == 9) {
		cout << 'C' << 'M';
	} else {
		if (digito > 4)	{
			cout << 'D';
			for (i = 1; i <= (digito - 5); i++)	{
				cout << 'C';
			} 
		} else {
			if (digito == 4) {
				cout << 'C' << 'D';
			} else {
				for (i = 1; i <= digito; i++) {
					cout << 'C';
				}
			}
		}
	}

	digito = r / 10;
	r = r % 10;
	if (digito == 9) {
		cout << 'X' << 'C';
	} else {
		if (digito > 4)	{
			cout << 'L';
			for (int i = 1; i <= (digito - 5); i++)	{
				cout << 'X';
			}
		} else {
			if (digito == 4) {
				cout << 'X' << 'L';
			} else {
				for (int i = 1; i <= digito; i++) {
					cout << 'X';
				}
			}
		}
	}

	digito = r;
	if (digito == 9) {
		cout << 'I' << 'X';
	} else {
		if (digito > 4)	{
			cout << 'V';
			for (int i = 1; i <= (digito - 5); i++)	{
				cout << 'I';
			}
		} else {
			if (digito == 4) {
				cout << 'I' << 'V';
			} else {
				for (int i = 1; i <= digito; i++) {
					cout << 'I';
				}
			}
		}
	}

	return 0;
}

int main()
{
	int num;
	string traduccion;
	
	cout << "Programa para calcular los numeros romanos en base a un numero indo-arabigo." << "\n";
	cout << "El programa finaliza ingresando un numero cero o menor, o 3999 o mayor." << "\n \n";
	cout << "Ingrese un numero >> ";
	cin >> num;

	while ((num > 0) && (num <= 3999)) {
		cout << num << " en numeros romanos es ";
		traduccion = calccifrarom(num);
		cout << traduccion << "\n \n";

		cout << "Ingrese un numero ";
		cin >> num;
	}
	
	return 0;
}



// ejemplo 6.8 página 242
// igual que anterior, pero  modificado con sentencias <else if>; y para
// ingresar cualquier número, indefinidamente, mayor que cero y menor que 3999

#include <iostream>
using namespace std;

int calccifrarom(int n)
{
	int digito, r, i;
	r = n;

	digito = r / 1000;
	r = r % 1000;
	for (i = 1; i <= digito; i++) {
		cout << 'M';
	}

	digito = r / 100;
	r = r % 100;
	if (digito == 9) {
		cout << 'C' << 'M';
	} else if (digito > 4)	{
		cout << 'D';
		for (i = 1; i <= (digito - 5); i++)	{
			cout << 'C';
		}
	} else if (digito == 4) {
			
		cout << 'C' << 'D';
	} else {
		for (i = 1; i <= digito; i++) {
			cout << 'C';
		}
	}

	digito = r / 10;
	r = r % 10;
	if (digito == 9) {
		cout << 'X' << 'C';
	} else if (digito > 4) {
		cout << 'L';
		for (int i = 1; i <= (digito - 5); i++)	{
			cout << 'X';
		}
	} else if (digito == 4) {
		cout << 'X' << 'L';
	} else {
		for (int i = 1; i <= digito; i++) {
			cout << 'X';
		}
	}

	digito = r;
	if (digito == 9) {
		cout << 'I' << 'X';
	} else if (digito > 4) {
		cout << 'V';
		for (int i = 1; i <= (digito - 5); i++)	{
			cout << 'I';
		}
	} else if (digito == 4) {
		cout << 'I' << 'V';
	} else {
		for (int i = 1; i <= digito; i++) {
			cout << 'I';
		}
	}

	return 0;
}

int main()
{
	int num;
	string traduccion;
	
	cout << "Programa para calcular los numeros romanos en base a un numero indo-arabigo." << "\n";
	cout << "El programa finaliza ingresando un numero cero o menor; o 3999 o mayor." << "\n \n";
	cout << "Ingrese un numero >> ";
	cin >> num;

	while ((num > 0) && (num <= 3999)) {
		cout << num << " en numeros romanos es ";
		traduccion = calccifrarom(num);
		cout << traduccion << "\n \n";

		cout << "Ingrese un numero ";
		cin >> num;
	}
	
	return 0;
}



// ejemplo 6.9 página 246

#include <iostream>
using namespace std;
//#include <cctype>

int signo(float n) {
	if (n > 0) {
		cout << 1;
	} else if (n == 0)	{
		cout << 0;
	} else {
		cout << -1;
	}

	return 0;
}

int main() {
	float num;
	int prueba;
	cout << "Ingrese un numero >> ";
	cin >> num;

	while (!isdigit(num)) {
		prueba = signo(num);
		cout << prueba << "\n \n";

		cout << "Ingrese un numero >> ";
		cin >> num;
	}
	
	return 0;
}



// ejemplo 6.10 página 247

#include <iostream>
using namespace std;
//#include <cctype>

int signo(float n) {
	if (n > 0) {
		cout << 1;
	} else if (n == 0)	{
		cout << 0;
	} else {
		cout << -1;
	}

	return 0;
}

int main() {
	float num;
	int prueba;
	cout << "Ingrese un numero >> ";
	cin >> num;

	while (!isdigit(num)) {
		prueba = signo(num);
		cout << prueba << "\n \n";

		cout << "Ingrese un numero >> ";
		cin >> num;
	}
	
	return 0;
}



// ejemplo 6.10 página 247

#include <iostream>
using namespace std;
//#include <cctype>

int signo(int n) {
	n = n + 1;

	return n;
}

int main() {
	int num, prueba;
	cout << "Ingrese un numero >> ";
	cin >> num;

	while (!isdigit(num)) {
		cout << num << "\n";
		prueba = signo(num);
		cout << num << "\n \n";

		cout << "Ingrese un numero >> ";
		cin >> num;
	}
	
	return 0;
}



// ejemplo 6algo página 260

#include <iostream>
using namespace std;

int factorial(int n) {
	int f;
	if (n == 0) {
		f = 1;
	} else {
		f = n * factorial(n - 1);
	}

	return f;
}

int main() {
	int num, prueba;
	cout << "Ingrese un numero >> ";
	cin >> num;

	while (!isdigit(num)) {
		prueba = factorial(num);
		cout << prueba << "\n \n";

		cout << "Ingrese un numero >> ";
		cin >> num;
	}
	
	return 0;
}



// ejemplo 6algo página 260
// variante del anterior

#include <iostream>
using namespace std;

long factorial(int n) {
	if (n == 0)
		return 1;
	
	return n * factorial(n - 1);
}

int main() {
	int num;
	cout << "Ingrese un numero >> ";
	cin >> num;

	while (!isdigit(num)) {
		cout << factorial(num) << "\n \n";

		cout << "Ingrese un numero >> ";
		cin >> num;
	}
	
	return 0;
}



// ejemplo 6.14 página 261
// variante del anterior

#include <iostream>
using namespace std;

long fibonacci(int n) {
	if ((n == 0) || (n == 1))
		return 1;
	
	return n + fibonacci(n - 1);
}

int main() {
	int num;
	cout << "Ingrese un numero >> ";
	cin >> num;

	while (num > 0) {
		cout << fibonacci(num) << "\n \n";

		cout << "Ingrese un numero >> ";
		cin >> num;
	} 

	return 0;
}



// ejemplo suelto

#include <iostream>
using namespace std;

float potencia(double base, int exp) {
	if (exp == 0) 
		return 1;

	float resultado = base * potencia(base, (exp - 1));
	return 1;
	
	return resultado;
}

int main() {
	float num, pot;
	cout << "Ingrese un numero > ";
	cin >> num;
	cout << "Ingrese una potencia > ";
	cin << pot;

	while (num > 0) {
		cout << potencia(num, pot) << "\n \n";

		cout << "Ingrese un numero > ";
		cin >> num;
		cout << "Ingrese una potencia > ";
		cin << pot;
	} 

	return 0;
}



// ejemplo 6.14 página 261

#include <iostream>
using namespace std;

float potencia(float base, int exp) {
	if (exp == 0) 
		return 1;

	float resultado = base * potencia(base, (exp - 1));
	return resultado;
}

int main() {
	float num;
	int pot;
	cout << "Ingrese un numero >> ";
	cin >> num;
	cout << "Ingrese una potencia >> ";
	cin >> pot;

	while (num > 0) {
		cout << potencia(num, pot) << "\n \n";

		cout << "Ingrese un numero >> ";
		cin >> num;
		cout << "Ingrese una potencia >> ";
		cin >> pot;
	} 

	return 0;
}



// ejemplo 6.15 página 262

#include <iostream>
using namespace std;
#include <cmath>

float triangulo(float l1, float l2, float l3) {
	float p, area;
	p = (l1 + l2 + l3) / 2;
	if ((p > l1) && (p > l1) && (p > l1)) {
		area = sqrt(p * (p - l1) * (p - l2) * (p - l3));
		return area;
	}

	cout << "No es un triangulo.";
	return 0;
}

float prueba(float num, float div) {
	float resultado = num / div;
	return resultado;
}

int main() {
	float l1, l2, l3;
	cout << "Ingrese el lado1 >> ";
	cin >> l1;
	cout << "Ingrese el lado2 >> ";
	cin >> l2;
	cout << "Ingrese el lado3 >> ";
	cin >> l3;

	while ((l1 > 0) && (l2 > 0) && (l3 > 0)) {
		cout << triangulo(l1, l2, l3) << "\n \n";

		cout << "Ingrese el lado1 >> ";
		cin >> l1;
		cout << "Ingrese el lado2 >> ";
		cin >> l2;
		cout << "Ingrese el lado3 >> ";
		cin >> l3;
	} 

	return 0;
}



// ejemplo 6.15 página 262
// variante del anterior

#include <iostream>
using namespace std;
#include <cmath>

float triangulo(float l1, float l2, float l3) {
	float p, area;
	p = (l1 + l2 + l3) / 2;
	if ((p > l1) && (p > l1) && (p > l1)) {
		area = sqrt(p * (p - l1) * (p - l2) * (p - l3));
		return area;
	}

	cout << "No es un triangulo.";
	return 0;
}

float prueba(float num, float div) {
	float resultado = num / div;
	return resultado;
}

int main() {
	float l1, l2, l3;
	cout << "Ingrese el lado1 >> ";
	cin >> l1;
	cout << "Ingrese el lado2 >> ";
	cin >> l2;
	cout << "Ingrese el lado3 >> ";
	cin >> l3;

	while (true) {
		if ((l1 <= 0) || (l2 <= 0) || (l3 <= 0))
			break;

		cout << triangulo(l1, l2, l3) << "\n \n";

		cout << "Ingrese el lado1 >> ";
		cin >> l1;
		cout << "Ingrese el lado2 >> ";
		cin >> l2;
		cout << "Ingrese el lado3 >> ";
		cin >> l3;
	} 

	return 0;
}



// ejemplo 6 algo página 265

#include <iostream>
using namespace std;

imprimir(double dato) {
	cout << dato << "\n \n";
	return 0;
}

imprimir(int dato) {
	cout << dato << "\n \n";
	return 0;
}

imprimir(char dato) {
	cout << dato << "\n \n";
	return 0;
}

imprimir(string dato) {
	cout << dato << "\n \n";
	return 0;
}

imprimir(bool dato) {
	cout << dato << "\n \n";
	return 0;
}


int main() {
//	imprimir(3.141652);
//	imprimir(17);
//	imprimir('w');
//	imprimir("Cadena");
	imprimir(true);

	return 0;
}



// ejemplo 6 algo página 267

#include <iostream>
using namespace std;

float media(float n1, float n2) {
	float p;
	p = (n1 + n2) / 2;
	return p;
}

float media(float n1, float n2, float n3) {
	float p;
	p = (n1 + n2 + n3) / 3;
	return p;
}

float media(float n1, float n2, float n3, float n4) {
	float p;
	p = (n1 + n2 + n3 + n4) / 4;
	return p;
}

int main() {
	cout << media(2.33, 3) << "\n \n";
	cout << media(2, 3, 5) << "\n \n";
	cout << media(2, 3, 4, 7) << "\n \n";
	return 0;
}



// actividad resuelta 6.4 algo página 269
// no lo puedo sacar tal cual

#include <iostream>
using namespace std;

float ordenar3(float x, float y, float z) {
	float aux;
	
	if (x > y) {
		aux = x;
		x = y;
		y = aux;
	};
	if (y > z) {
		aux = y;
		y = z;
		z = aux;
	};
	if (x > y) {
		aux = x;
		x = y;
		y = aux;
	};

	cout << x << ' ' << y << ' ' << z << "\n \n";
	return 0;
}

int main() {
	float x, y, z;

	cout << "Ingrese un numero >> ";
	cin >> x;
	cout << "Ingrese otro numero >> ";
	cin >> y;
	cout << "Ingrese otro numero >> ";
	cin >> z;

	while (true) {
		if ((x <= 0) || (y <= 0) || (z <= 0))
			break;

		cout << ordenar3(x, y, z) << "\n \n";

		cout << "Ingrese un numero >> ";
		cin >> x;
		cout << "Ingrese otro numero >> ";
		cin >> y;
		cout << "Ingrese otro numero >> ";
		cin >> z;
	} 

	return 0;
}



// programa que solicita un número entero  entre 1 y 100. Luego genera
// un número aleatorio en ese mismo rango, y le indica al usuario si el
// número que digitó es menor o mayor que el número aleatorio, y así hasta
// que lo adivine. por último muestra el número de intentos

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	int numero, dato, contador = 0; 

	srand(time(NULL)); // genera un número aleatorio
	dato = 1 + rand() % 100;

	do {
		cout << "Ingrese un numero: "; cin >> numero;

		if (numero > dato)
			cout << "\nIngrese un numero menor: \n";
		if (numero < dato)
			cout << "\nIngrese un numero mayor: \n";

		contador++;
	} while (numero != dato);

	cout << "\nFELICIDADES ADIVINASTE EL NUMERO\n";
	cout << "Numero de intentos: " << contador << endl;

	return 0;
}



// definimos un vector y calculamos la suma de sus elementos

#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	int arr[] = {1,2,3,4,5}; 
	int suma = 0;

	for (int i = 0; i < 5; ++i) {
		suma += arr[i];
	}

	cout << suma << "\n \n";

	getch();
	return 0;
}



// leer números ingresados a un vector y mostrar los números del mismo
// con sus índices asociados

#include <iostream>
using namespace std;

int main() {
	int arr[100], n;
	int suma = 0;

	cout << "Ingrese el numero de elementos que va a tener el arreglo >> ";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cout << "Ingrese un numero >> ";
		cin >> arr[i]; // guardando todos los elementos del vector
	}

	for (int i = 0; i < n; ++i) {
		cout << i << " -> " << arr[i] << "\n";
	}

	return 0;
}



// ejemplo suelto

#include <iostream>
using namespace std;

int main() {
	int arr[] = {1,2,3,4,5,6,7,8};

	arr[3] = 8;

	cout << arr[3] << "\n \n";

	return 0;
}



// ejemplo suelto

#include <iostream>
using namespace std;

int main() {
	int arr[8];

	for (int i = 0; i < 8; ++i) {
		arr[i] = 8;
	}

	for (int i = 0; i < 8; ++i) {
//		cout << i << " -> " << arr[i] << "\n";
		cout << arr[i] << " ";
	}

	cout << "\n \n";
	return 0;
}



// ejemplo 7.1 página 283

#include <iostream>
using namespace std;

int main() {
	int arr[5], num;

	for (int i = 0; i < 5; ++i) {
		cout << "Introduzca un numero >> ";
		cin >> num;
		arr[i] = num;
	}

	for (int i = 0; i < 5; ++i) {
//		cout << i << " -> " << arr[i] << "\n";
		cout << arr[i] << " ";
	}

	cout << "\n \n";
	return 0;
}



// ejemplo 7.2 página 284

#include <iostream>
using namespace std;

int main() {
	float arr[5], num, suma = 0, media;

	cout << "Cargar datos del arreglo" << "\n";

	for (int i = 0; i < 5; ++i) {
		cout << "Introduzca un numero >> ";
		cin >> num;
		arr[i] = num;
		suma += num;
	}

	// mostramos cómo quedó el arreglo
	cout << "\nEl arreglo es [";
	for (int i = 0; i < 5; ++i) {
		if (i < 4)
			cout << arr[i] << " ";
	}
	cout << arr[4] << ']' << "\n \n";

	// calculamos la media y la suma, y las mostramos
	media = suma / 5;
	cout << "La suma de todos los elementos es: " << suma << "\n";
	cout << "La media de los elementos es: " << media;

	cout << "\n \n";
	return 0;
}



// ejemplo 7.3 página 285

#include <iostream>
using namespace std;

int main() {
	int q, altos = 0, bajos = 0;
	float arr[100], num, suma = 0, media;

	cout << "CARGAR LOS DATOS DEL ARREGLO" << "\n";
	cout << "Introduzca la cantidad de alumnos >> ";
	cin >> q;

	for (int i = 0; i < q; ++i) {
		cout << "Introduzca un numero >> ";
		cin >> num;
		arr[i] = num;
		suma += num;
	}

	// mostramos cómo quedó el arreglo
	cout << "\nLas alturas de los alumnos son [";
	for (int i = 0; i < q; ++i) {
		if (i < (q - 1))
			cout << arr[i] << "cm ";
	}
	cout << arr[(q - 1)] << "cm]" << "\n \n";

	// calculamos la media y la mostramos. También la cantidad de alum
	media = suma / q;
	cout << "La cantidad de alumnos es: " << q << "\n";
	cout << "La media de altura de los alumnos es: " << media << "cm" << "\n";

	// calculamos cuántos superan o no la media y los mostramos
	for (int i = 0; i < q; ++i) {
		if (arr[i] > media) {
			altos += 1;
		} else if (arr[i] < media) {
			bajos += 1;
		}
	}
	cout << "La cantidad de alumnos de estatura mayor que la media es: " << altos << "\n";
	cout << "La cantidad de alumnos de estatura menor que la media es: " << bajos << "\n";

	cout << "\n \n";
	return 0;
}



// ejemplo 7.5 página 286

#include <iostream>
using namespace std;

int main() {
	string arr[9];

	arr[0] = "Audi";
	arr[1] = "Fiat";
	arr[2] = "Ford";
	arr[3] = "Lancia";
	arr[4] = "";
	arr[5] = "";
	arr[6] = "Opel";
	arr[7] = "Renault";
	arr[8] = "";

	// mostramos el arreglo
	cout << "\nLas posiciones de los autos en el arreglo son" << "\n";
	for (int i = 0; i < 9; ++i)
		cout << "Posicion " << i << " -> " << arr[i] << "\n";

	cout << "\n \n";
	return 0;
}



// ejemplo suelto 

#include <iostream>
using namespace std;

int main(){
 float ventas[2][3];
 int fila, columna;
 for(fila = 0; fila < 2; fila++){
  for(columna = 0; columna < 3; columna++){
   cin>>ventas[fila][columna];
  }
 }
 for(fila = 0; fila < 2; fila++){
  for(columna = 0; columna < 3; columna++){
   cout<<ventas[fila][columna]<<endl;
  }
 }
 return 0;
}



// ejemplo 7.5 página 286

#include <iostream>
using namespace std;

int main() {
	int fila, colum;
	int arr[8] = {1,2,3,4,5,6,7,8};
	int mtz[3]   [3];
//         filas columnas

	string tbl[2][3] = {{"A1","A2","A3"},
                        {"B1","B2","B3"}};

	tbl[0][1] = "2 ";
	tbl[1] = 2;
	tbl[2] = 3;
	tbl[3] = "Lancia";
	tbl[4] = "";
	tbl[5] = "";
	tbl[6] = "Opel";
	tbl[7] = "Renault";
	tbl[8] = "";

	// mostramos el arreglo 'arr'
	cout << "\nEl arreglo 'arr' es:  [";
	for (int i = 0; i < 8; ++i) {
		if (i < 7)
			cout << arr[i] << " ";
	}
	cout << arr[7] << ']' << "\n \n";

	// mostramos la matriz 'tbl'
	cout << "La matriz 'tbl' es:" << "\n";
	for (fila = 0; fila < 2; fila++) {
		for (colum = 0; colum < 3; colum++) {
			cout << tbl[fila][colum] << ' ';
		};
		cout << "\n";
	}

	cout << "\n \n";
	return 0;
}



// ejemplo 7.5 página 286

#include <iostream>
using namespace std;

int main() {
	int fila, colum;
	int mtz[3]   [3];
//         filas columnas

	string tbl[3][3];// = {{"A1","A2","A3"},
                     //    {"B1","B2","B3"}};

	// cargamos la matriz
	cout << "Cargar datos de la matriz" << "\n";
	for (fila = 0; fila < 3; fila++) {
		for (colum = 0; colum < 3; colum++) {
			cout << "Ingrese dato >> ";
			cin >> tbl[fila][colum];
		}
	}
	cout << "\n";

	// mostramos la matriz 'tbl'
	cout << "La matriz 'tbl' es:" << "\n";
	for (fila = 0; fila < 3; fila++) {
		for (colum = 0; colum < 3; colum++) {
			cout << tbl[fila][colum] << ' ';
		};
		cout << "\n";
	}

	cout << "\n \n";
	return 0;
}



// funciones y experimentos a partir de página 328

#include <iostream>
using namespace std;

char recortar(string t, int p1, int p2 = 1000) {
	// t --> texto o cadena que se va a recortar
	// p1 --> posición a partir de la cual se va a recortar
	// p2 --> posición final del recorte (es un parámetro predeterminado
	//        para caso de que no se ingrese ninguno)

	int ln = t.length();
	auto arr = t.c_str();  // convierte un string en un arreglo de char

	if (p2 == 1000) {
		for (int i = p1; i <= ln; ++i)
			cout << arr[i];
	} else {
		for (int i = p1; i < p2; ++i)
			cout << arr[i];
	}

	return 0;
}

char insertar(string t, int p, string s) {
	// t --> texto o cadena donde se va a insertar
	// p --> posición a partir de la cual se va a insertar
	// s --> subcadena que se va a insertar  

	recortar(t, 0, p);
	cout << s;
	recortar(t, p);

	return 0;
} 

char tronchar(string t, int p, int l) {
	// t --> texto o cadena donde se va eliminar subcadena
	// p --> posición a partir de la cual se va borrar
	// l --> longitud de la subcadena a eliminar  

	recortar(t, 0, p);
	recortar(t, (p + l));

	return 0;
} 

int main() {
//	recortar("supercalifragilistico", 2, 4);
//	insertar("supercalifragilistico", 2, "XXX");
//	tronchar("supercalifragilistico", 5, 4);
	tronchar("supercalifragilistico", 2, 10);

	cout << "\n \n";
	return 0;
}



// Ejemplo 10.2.1 página 388
// Método burbuja

#include <iostream>
using namespace std;

int main() {
	int numeros[] = {4,1,2,3,5};
	int aux;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (numeros[j] > numeros[j+1]) {
				aux = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = aux;
			}
		}
	}

	cout << "Orden ascendente: ";
	for (int i = 0; i < 5; ++i) {
		cout << numeros[i] << ' ' ;
	}
	cout << "\n \n";

	cout << "Orden descendente: ";
	for (int i = 4; i >= 0; --i) {
		cout << numeros[i] << ' ' ;
	}
	cout << "\n \n";

	return 0;
}



// Ejemplo 10.2.1 página 391
// Método burbuja mejorado

#include <iostream>
using namespace std;

int main() {
	int numeros[] = {4,1,2,3,5};
	int aux;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < (5 - i); ++j) {
			if (numeros[j] > numeros[j+1]) {
				aux = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = aux;
			}
		}
	}

	cout << "Orden ascendente: ";
	for (int i = 0; i < 5; ++i) {
		cout << numeros[i] << ' ' ;
	}
	cout << "\n \n";

	return 0;
}



// Ejemplo 10.2.2 página 393
// ordenamiento por inserción o método de la baraja

#include <iostream>
using namespace std;

int main() {
	int numeros[] = {4,2,3,1,5};
	int pos, aux;

	for (int i = 0; i < 5; ++i) {
		pos = i;
		aux = numeros[i];

		while ((pos > 0) && (numeros[pos - 1] > aux)) {
			numeros[pos] = numeros[pos - 1];
			pos--;
		}

		numeros[pos] = aux;
	}

	cout << "Orden ascendente: ";
	for (int i = 0; i < 5; ++i) {
		cout << numeros[i] << ' ' ;
	}
	cout << "\n \n";

	return 0;
}



// Ejemplo suelto a partir de los anteriores
// ordenamiento por selección

#include <iostream>
using namespace std;

int main() {
	int numeros[] = {4,2,3,1,5};
	int aux, min;

	for (int i = 0; i < 5; ++i) {
		min = i;
		for (int j = i + 1; j < 5; ++j) {
			if (numeros[j] < numeros[min]) {
				min = j;
			}
		}

		aux = numeros[i];
		numeros[i] = numeros[min];
		numeros[min] = aux;
	}

	cout << "Orden ascendente: ";
	for (int i = 0; i < 5; ++i)
		cout << numeros[i] << ' ' ;
	cout << "\n \n";

	return 0;
}



// Ejemplo suelto método de búsqueda hash

#include <iostream>
using namespace std;

struct Alumno {
	char nombre[50];
	int nota;
	int estado = 0;
	int clave;
};

int insertar(Alumno* A, Alumno* B, int, int);
int buscaHash(Alumno* A, int, int);


int main() {
	int op = 0, n, clave, x;

	do {
		cout << "Ingrese la cantidad de alumnos: ";
		cin >> n;
	} while (n <= 0);

	Alumno* A = new Alumno[n];
	Alumno* B = new Alumno[n];
	system("cls");

	do {
		cout << "\t  ___________________________\n";
		cout << "\t | Metodo de busqueda - HASH |\n";
		cout << "\t |---------------------------|\n";
		cout << "\t | 1. Insertar | 2. Buscar   |\n";
		cout << "\t |           3. Salir        |\n";
		cout << "\t |                           |\n";
		cout << "\t |___________________________|\n";
		cout << "\t >> Ingrese opcion: ";
		cin >> op;
		system("cls");

		switch (op) {
			case 1:
				for (int i = 0; i < n; ++i) {
					cout << "DATOS DEL ALUMNO " << i + 1 << endl;
					fflush(stdin);
					cout << "Nombre: ";
					cin.getline(A[i].nombre, 50);

					do {
						cout << "Nota: ";
						cin >> A[i].nota;
					} while ((A[i].nota < 0) || (A[i].nota > 20));

					A[i].clave = insertar(A, B, i, n);
					cout << "Clave: ";
					cout << A[i].clave << endl;
				}
				break;

			case 2:
				cout << "Introduzca el codigo que desea buscar: ";
				fflush(stdin);
				cin >> clave;
				x = buscaHash(A, n, clave);

				if (x == -1) {
					cout << "Numero no encontrado" << endl;
				} else {
					cout << "Numero encontrado" << endl;
					cout << "Nombre: " << B[x].nombre << endl;
					cout << "Nota: " << B[x].nota << endl;
				}
				break;

			case 3:
			 	cout << "GRACIAS\n\n";
				return 0;

			default:
			 	cout << "\n\nOPCION INCORRECTA\n\n";
			 	system("pause");
		}
	} while (op != 3);

	return 0;
}


int insertar(Alumno* A, Alumno* B, int i, int n) {
	int j = (A[i].nota + 1) % n;

	do {
		if (A[j].estado == 0) {
			B[j] = A[j];
			A[j].estado = 1;
		} else {
			j++;
		}
	} while (j > n);

	return j;
}


int buscaHash(Alumno* A, int n, int clave) {
	int j = 0;

	while (j < n) {
		if (A[j].clave == clave) {
			return j;
		} else {
			j++;
		}
	}

	return -1;
}



// Ejemplo suelto búsqueda secuencial

#include <iostream>
using namespace std;

int main() {
	int a[] = {3,4,2,1,5};
	int i, dato;
	char band = 'F';

	dato = 4;
	// búsqueda secuencial
	i = 0;
	while ((band == 'F') && (i < 5)) {
		if (a[i] == dato) {
			band = 'V';
		}
		i++;
	}

	if (band == 'F') {
		cout << "El numero a buscar no existe en el arreglo";
	} else if (band == 'V') {
		cout << "El numero ha sido encontrado en la posicion: " << i - 1 << endl;
	}

	return 0;
}



// Ejemplo suelto búsqueda binaria

#include <iostream>
using namespace std;

int main() {
	int numeros[] = {1,2,3,4,5};
	int inf, sup, mitad, dato, i;
	char band = 'F';

	dato = 1;

	inf = 0;
	sup = 5;
	i = 0;

	while ((inf <= sup) && (i < 5)) {
		mitad = (inf + sup) / 2;

		if (numeros[mitad] == dato) {
			band = 'V';
			break;
		}

		if (numeros[mitad] > dato) {
			sup = mitad;
			mitad = (inf + sup) / 2;
		}

		if (numeros[mitad] < dato) {
			inf = mitad;
			mitad = (inf + sup) / 2;
		}

		i++;
	}

	if (band == 'V') {
		cout << "El numero ha sido encontrado en la posicion: " << mitad << "\n\n";
	} else {
		cout << "El numero no ha sido encontrado\n\n";
	}

	return 0;
}



// Ejemplo suelto almacenado del contenido de dos vectores en uno

#include <iostream>
using namespace std;

int main() {
	char letras1[] = {'a', 'b', 'c', 'd', 'e'};
	char letras2[] = {'f', 'g', 'h', 'i', 'j'};
	char letras3[10];

	// copiamos los elementos de letras1 hacia letras3
	for (int i = 0; i < 5; ++i) {
	 	letras3[i] = letras1[i];
	 }

	// copiamos los elementos de letras2 hacia letras3
	 for (int i = 5; i < 10; ++i) {
	 	letras3[i] = letras2[i - 5];
	 }

	 // mostramos el nuevo arreglo
	 for (int i = 0; i < 10; ++i) {
	 	cout << letras3[i] << "\n";
	 }

	return 0;
}



// Ejemplo suelto de intersección de dos vectores en uno

#include <iostream>
using namespace std;

int main() {
	int x[] = {1,2,3,4,5};
	int y[] = {0,2,5,6};

	cout << "Elementos del vector x" << endl;
	cout << " _____________________" << endl;
	cout << "| ";
	for (int i = 0; i < 5; ++i) {
		cout << x[i] << ' ';
	}
	cout << '\n' << "|_____________________" << "\n\n\n";


	cout << "Elementos del vector y" << endl;
	cout << " _____________________" << endl;
	cout << "| ";
	for (int i = 0; i < 4; ++i) {
		cout << y[i] << ' ';
	}
	cout << '\n' << "|_____________________" << "\n\n\n";


	cout << "La interseccion es" << endl;
	cout << " _________________" << endl;
	cout << "| ";
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (x[i] == y[j]) cout << x[i] << ' ';
		}
	}
	cout << '\n' << "|_________________" << "\n\n\n";

	return 0;
}



// Ejemplo página 420 de intercalación de dos vectores en uno

#include <iostream>
using namespace std;

int main() {
	int A[] = {1,2,3,4,5};
	int B[] = {0,2,5,6};
	int C[80], i = 0, j = 0, k = 0;


	while ((i <= 4) && (j <= 3)) {
		if (A[i] < B[j]) {
			C[k] = A[i];
			i += 1;
		} else {
			C[k] = B[j];
			j += 1;
		}
		k += 1;
	}


	if (i <= 4) {
		for (int r = i; r <= 4; ++r) {
			C[k] = A[r];
			k += 1;
		}
	} else {
		for (int r = j; r <= 3; ++r) {
			C[k] = B[r];
			k += 1;
		}
	}


	cout << "\nElementos del vector C" << "\n\n";
	for (int z = 0; z < 9; ++z) {
		cout << C[z] << ' ';
	}
	cout << "\n\n\n";

	return 0;
}



// Ejemplo página 420 de intercalación de dos vectores en uno
// complicación del anterior

#include <iostream>
using namespace std;

int main() {
	// primer vector ("A"), con números de la serie Fibonacci
	int A[1000], n = 1, p = 1;
	A[0] = 1, A[1] = 1;

	cout << "\nElementos del vector \"A\"" << "\n\n";
	cout << A[0] << ' ' << A[1];
	for (int z = 2; z < 46; ++z) {
		A[z] = n + p;
		cout << ' ' << A[z];

		n = p;
		p = A[z];
	}
	cout << "\n\n\n";



	// experimento para generar sucesivos números áureos en base al arreglo "A"
	// no consigo imprimir más de cinco decimales
//	double Au[1000];
//	for (int i = 2; i < 30; ++i) {
//		Au[i] = ((A[i - 1] + 1.0) - 1) / A[i - 2];
//		cout << Au[i] << endl;
//	}
//	cout << "\n\n\n";



	// segundo vector ("B") con una serie sencilla de números
	cout << "\nElementos del vector \"B\"" << "\n\n";
	int B[1000];
	for (int i = 0; i < 46; ++i) {
		B[i] = i;
		cout << ' ' << B[i];
	}
	cout << "\n\n\n";



	// intercalación de ambos vectores ("A" y "B")
	int C[1000], i = 0, j = 0, k = 0;


	while ((i < 46) && (j < 46)) {
		if (A[i] < B[j]) {
			C[k] = A[i];
			i += 1;
		} else {
			C[k] = B[j];
			j += 1;
		}
		k += 1;
	}


	if (i < 46) {
		for (int r = i; r < 46; ++r) {
			C[k] = A[r];
			k += 1;
		}
	} else {
		for (int r = j; r < 46; ++r) {
			C[k] = B[r];
			k += 1;
		}
	}


	cout << "\nElementos del vector C" << "\n\n";
	for (int z = 0; z < 92; ++z) {
		cout << C[z] << ' ';
	}
	cout << "\n\n\n";


	return 0;
}



// Ejemplo listas enlazadas
// Insertar elementos en una lista y mostrarlos

#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};


// Prototipos de funciones
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);


int main() {
	Nodo *lista = NULL;
	int dato;

	// - - - -
	cout << "Ingrese un numero: ";
	cin >> dato;
	insertarLista(lista, dato);

	cout << "Ingrese un numero: ";
	cin >> dato;
	insertarLista(lista, dato);

	cout << "Ingrese un numero: ";
	cin >> dato;
	insertarLista(lista, dato);
	// - - - -

	mostrarLista(lista);

	return 0;
}


void insertarLista(Nodo *&lista, int n) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;

	Nodo *aux1 = lista;
	Nodo *aux2;

	while ((aux1 != NULL) && (aux1 -> dato < n)) {
		aux2 = aux1;
		aux1 = aux1 -> siguiente;
	}

	if (lista == aux1) {
		lista = nuevo_nodo;
	} else {
		aux2 -> siguiente = nuevo_nodo;
	}

	nuevo_nodo -> siguiente = aux1;

	cout << "\tElemento " << n << " insertado a lista correctamente\n";
}


void mostrarLista(Nodo *lista) {
	Nodo *actual = new Nodo();
	actual = lista;

	while (actual != NULL) {
		cout << actual -> dato << " -> ";
		actual = actual -> siguiente;
	}

	cout << "FINAL" << "\n\n\n";
}



// Ejemplo listas enlazadas (continuación del anterior)
// Insertar elementos en una lista y mostrarlos

#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};


// Prototipos de funciones
void menu();
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);

Nodo *lista = NULL;

int main() {
	menu();

	return 0;
}


void menu() {
	int opcion, dato;

	do {
		cout << "\t.:MENU:.\n";
		cout << "1. Insertar elementos a la lista\n";
		cout << "2. Mostrar los elementos de la lista\n";
		cout << "3. Salir\n";
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion) {
			case 1:
				cout << "\nIngrese un numero: ";
				cin >> dato;
				insertarLista(lista, dato);
				cout << "\n";
				system("pause");
				break;
			case 2:
				mostrarLista(lista);
				cout << "\n";
				system("pause");
				break;
		}

		system("cls");
	} while (opcion != 3);
}


void insertarLista(Nodo *&lista, int n) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;

	Nodo *aux1 = lista;
	Nodo *aux2;

	while ((aux1 != NULL) && (aux1 -> dato < n)) {
		aux2 = aux1;
		aux1 = aux1 -> siguiente;
	}

	if (lista == aux1) {
		lista = nuevo_nodo;
	} else {
		aux2 -> siguiente = nuevo_nodo;
	}

	nuevo_nodo -> siguiente = aux1;

	cout << "\tElemento " << n << " insertado a lista correctamente\n";
}


void mostrarLista(Nodo *lista) {
	Nodo *actual = new Nodo();
	actual = lista;

	while (actual != NULL) {
		cout << actual -> dato << " -> ";
		actual = actual -> siguiente;
	}

	cout << "FINAL" << "\n\n\n";
}



// Ejemplo listas enlazadas (continuación del anterior)
// Insertar elementos en una lista, mostrarlos y buscar dentro de ella

#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};


// Prototipos de funciones
void menu();
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int);

Nodo *lista = NULL;


int main() {
	menu();

	return 0;
}


void menu() {
	int opcion, dato;

	do {
		cout << "\t.:MENU:.\n";
		cout << "1. Insertar elementos a la lista\n";
		cout << "2. Mostrar los elementos de la lista\n";
		cout << "3. Buscar un elemento en la lista\n";
		cout << "4. Salir\n";
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion) {
			case 1:
				cout << "\nIngrese un numero: ";
				cin >> dato;
				insertarLista(lista, dato);
				cout << "\n";
				system("pause");
				break;
			case 2:
				mostrarLista(lista);
				cout << "\n";
				system("pause");
				break;
			case 3:
				cout << "\nIngrese un numero a buscar: ";
				cin >> dato;
				buscarLista(lista, dato);
				cout << "\n";
				system("pause");
				break;
		}

		system("cls");
	} while (opcion != 4);
}


void insertarLista(Nodo *&lista, int n) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;

	Nodo *aux1 = lista;
	Nodo *aux2;

	while ((aux1 != NULL) && (aux1 -> dato < n)) {
		aux2 = aux1;
		aux1 = aux1 -> siguiente;
	}

	if (lista == aux1) {
		lista = nuevo_nodo;
	} else {
		aux2 -> siguiente = nuevo_nodo;
	}

	nuevo_nodo -> siguiente = aux1;

	cout << "\tElemento " << n << " insertado a lista correctamente\n";
}


void mostrarLista(Nodo *lista) {
	Nodo *actual = new Nodo();
	actual = lista;

	while (actual != NULL) {
		cout << actual -> dato << " -> ";
		actual = actual -> siguiente;
	}

	cout << "FINAL" << "\n\n\n";
}


void buscarLista(Nodo *lista, int n) {
	bool band = false;

	Nodo *actual = new Nodo();
	actual = lista;

	while ((actual != NULL) && (actual -> dato <= n)) {
		if (actual -> dato == n) band = true;
		actual = actual -> siguiente;
	}

	if (band == true) {
		cout << "El elemento " << n << " SI ha sido encontrado en la lista\n";
	} else {
		cout << "El elemento " << n << " NO ha sido encontrado en la lista\n";
	}
}



// el principio de listas enlazadas

#include <iostream>
using namespace std;

int main() {
	int a = 3;
	cout << "\nEl valor de 'a' es: " << a;

	// mostramos la dirección de 'a'
	cout << "\nLa direccion de 'a' es: " << &a << "\n";

	// creamos un puntero
	int* b = &a;  // referenciando 'a'
	cout << "\nEl valor de 'b' es: " << b;
	cout << "\nLa direccion de 'b' es: " << &b << "\n";
	cout << "El valor de la direccion donde apunta 'b' es: " << *b << "\n\n";  // deferenciando 'b'


	cout << "-----------------------------------------------\n";
	a = 5;

	cout << "\nEl valor de 'a' es: " << a;
	cout << "\nLa direccion de 'a' es: " << &a << "\n";

	cout << "\nEl valor de 'b' es: " << b;
	cout << "\nLa direccion de 'b' es: " << &b << "\n";
	cout << "El valor de la direccion donde apunta 'b' es: " << *b << "\n\n";


	cout << "-----------------------------------------------\n";
	*b = 8;

	cout << "\nEl valor de 'a' es: " << a;
	cout << "\nLa direccion de 'a' es: " << &a << "\n\n";

	cout << "\nEl valor de 'b' es: " << b;
	cout << "\nLa direccion de 'b' es: " << &b << "\n\n";
	cout << "El valor de la direccion donde apunta 'b' es: " << *b << "\n\n\n";


	return 0;
}



// Ejemplo listas enlazadas (continuación)
//   -> insertar elementos en una lista
//   -> mostrarlos
//   -> buscar dentro de ella
//   -> eliminar un elemento
//   -> eliminar lista completa

#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};


// Prototipos de funciones
void menu();
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int);
void eliminarNodo(Nodo *&, int);
void eliminarLista(Nodo *&,int &);

Nodo *lista = NULL;


int main() {
	menu();

	return 0;
}


void menu() {
	int opcion, dato;

	do {
		cout << "\t.:MENU:.\n";
		cout << "1. Insertar elementos a la lista\n";
		cout << "2. Mostrar los elementos de la lista\n";
		cout << "3. Buscar un elemento en la lista\n";
		cout << "4. Eliminar un nodo de la lista\n";
		cout << "5. Eliminar todos los elementos de la lista\n";
		cout << "6. Salir\n";
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion) {
			case 1:
				cout << "\nIngrese un numero: ";
				cin >> dato;
				insertarLista(lista, dato);
				cout << "\n";
				system("pause");
				break;
			case 2:
				mostrarLista(lista);
				cout << "\n";
				system("pause");
				break;
			case 3:
				cout << "\nIngrese un numero a buscar: ";
				cin >> dato;
				buscarLista(lista, dato);
				cout << "\n";
				system("pause");
				break;
			case 4:
				cout << "\nIngrese el elemento que desea eliminar: ";
				cin >> dato;
				eliminarNodo(lista, dato);
				cout << "\n";
				system("pause");
				break;
			case 5:
				while (lista != NULL) {  // mientras no sea el final de la lista
					eliminarLista(lista, dato);
					cout << dato << " -> ";
				}
				cout << "FIN" << "\n";
				system("pause");
				break;
		}

		system("cls");
	} while (opcion != 6);
}


void insertarLista(Nodo *&lista, int n) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;

	Nodo *aux1 = lista;
	Nodo *aux2;

	while ((aux1 != NULL) && (aux1 -> dato < n)) {
		aux2 = aux1;
		aux1 = aux1 -> siguiente;
	}

	if (lista == aux1) {
		lista = nuevo_nodo;
	} else {
		aux2 -> siguiente = nuevo_nodo;
	}

	nuevo_nodo -> siguiente = aux1;

	cout << "\tElemento " << n << " insertado a lista correctamente\n";
}


void mostrarLista(Nodo *lista) {
	Nodo *actual = new Nodo();
	actual = lista;

	while (actual != NULL) {
		cout << actual -> dato << " -> ";
		actual = actual -> siguiente;
	}

	cout << "FINAL" << "\n\n\n";
}


void buscarLista(Nodo *lista, int n) {
	bool band = false;

	Nodo *actual = new Nodo();
	actual = lista;

	while ((actual != NULL) && (actual -> dato <= n)) {
		if (actual -> dato == n) band = true;
		actual = actual -> siguiente;
	}

	if (band == true) {
		cout << "El elemento " << n << " SI ha sido encontrado en la lista\n";
	} else {
		cout << "El elemento " << n << " NO ha sido encontrado en la lista\n";
	}
}


void eliminarNodo(Nodo *&lista, int n) {
	// aberiguamos si la lista NO está vacía
	if (lista != NULL) {
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		aux_borrar = lista;

		// recorremos la lista
		while ((aux_borrar != NULL) && (aux_borrar -> dato != n)) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar -> siguiente;
		}

		// el elemento no ha sido encontrado
		if (aux_borrar == NULL) {
			cout << "Elemento no encontrado\n";
		} else if (anterior == NULL) {  // el primer elemento se va a eliminar
			lista = lista -> siguiente;
			delete aux_borrar;
			cout << "Elemento eliminado\n";
		} else {  // el elemento está en la lisat pero no es el primer nodo
			anterior -> siguiente = aux_borrar -> siguiente;
			delete aux_borrar;
			cout << "Elemento eliminado\n";
		}
	}
}


void eliminarLista(Nodo *&lista, int &n) {
	Nodo *aux = lista;
	n = aux -> dato;
	lista = aux -> siguiente;
	delete aux;
}
*/



// ejercicios con listas
// crear una lista que almacene 'n' números enteros y:
//   -> mostrar los elementos
//   -> calcular el mayor y el menor y mostrarlos
//   -> calcular y mostrar la suma de los elementos
//   -> calcular y mostrar el promedio de los elementos

#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void calcularMayorMenor(Nodo *);
void sumaElementos(Nodo *);
void promedioElementos(Nodo *);


int main() {
	Nodo *lista = NULL;
	int dato;
	char resp;

	do {
		cout << "Ingrese un numero: ";
		cin >> dato;
		insertarLista(lista, dato);  // agregamos el nuevo elemento a la lista

		cout << "Desea agregar otro nodo? (s/n) ";
		cin >> resp;
	} while (resp == 's' || resp == 'S');

	cout << "\n\nLos elementos de la lista son los siguientes ==>   ";
	mostrarLista(lista);

	calcularMayorMenor(lista);
	sumaElementos(lista);
	promedioElementos(lista);
	cout << "\n\n";

	return 0;
}




// agregar elementos al final de la lista
void insertarLista(Nodo *&lista, int n) {
	Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;

	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;

	if (lista == NULL) {  // si la lista está vacía
		lista = nuevo_nodo;  // agregamos el primer elemento a la lista
	} else {
		aux = lista;  // aux apunta al inicio de la lista

		while (aux -> siguiente != NULL) {  // recorremos la lista
			aux = aux -> siguiente;  // avanzamos posiciones en la lista
		}

		aux -> siguiente = nuevo_nodo;  // agregamos el nuevo nodo a la lista
	}

	cout << "\tElemento " << n << " agregado a la lista con exito\n";
}


// mostramos todos los elementos de la lista
void mostrarLista(Nodo *lista) {
	while (lista != NULL) {  // mientras no sea el final de la lista
		cout << lista -> dato << " -> ";
		lista = lista -> siguiente;  // avanzamos una posición en lista
	}

	cout << "FINAL";
}


// calculamos el mayor y menor elemento de la lista
void calcularMayorMenor(Nodo *lista) {
	int mayor = 0, menor = 99999;

	while (lista != NULL) {  // recorremos la lista
		if ((lista -> dato) > mayor) {  // cálculo del mayor elemento
			mayor = lista -> dato;
		}

		if ((lista -> dato) < menor) {  // cálculo del menor elemento
			menor = lista -> dato;
		}

		lista = lista -> siguiente;  // avanzamos una posición en lista
	}

	cout << "\nEl mayor elemento es: " << mayor << "\n";
	cout << "El menor elemento es: " << menor;
}


// calculamos la suma de los elementos de la lista
void sumaElementos(Nodo *lista) {
	int suma = 0;

	while (lista != NULL) {
		suma += lista -> dato;

		lista = lista -> siguiente;
	}

	cout << "\nLa suma de los elementos de la lista es: " << suma;
}


// calculamos el promedio de los elementos de la lista
void promedioElementos(Nodo *lista) {
	int contador = 0;
	float acumulado = 0.0, promedio = 0;

	while (lista != NULL) {
		contador += 1;
		acumulado += lista -> dato;
		promedio = acumulado / contador;

		lista = lista -> siguiente;
	}

	cout << "\nLa cantidad de elementos de la lista es: " << contador;	
	cout << "\nEl promedio de los elementos de la lista es: " << promedio << "\n";	
}