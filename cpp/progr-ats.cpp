
#include <iostream>
using namespace std;





/*
// 55_ estructuras
// 56_ estructuras || estructura básica en C++

struct Persona {
	char nombre[20];
	int edad;
}
persona1 = {"Alejandro", 20},
persona2 = {"Roberto", 15};

int main() {
	cout << "El nombre de la persona1 es: " << persona1.nombre << endl;
	cout << "La edad de la persona1 es: " << persona1.edad << "\n\n";

	cout << "El nombre de la persona2 es: " << persona2.nombre << endl;
	cout << "La edad de la persona2 es: " << persona2.edad << "\n\n";

	return 0;
}

struct Persona {
	char nombre[20];
	int edad;
} persona1, persona2;

int main() {
	cout << "Ingrese su nombre: ";
	cin.getline(persona1.nombre, 20, '\n');
	cout << "Ingrese su edad: ";
	cin >> persona1.edad;

	cout << "\nImprimiendo datos\n";
	cout << "El nombre es: " << persona1.nombre << "\n";
	cout << "La edad es: " << persona1.edad << "\n\n";

	return 0;
}





// 57_58_ estructuras anidadas

struct info_direccion {
	char direccion[30];
	char ciudad[20];
	char provincia[20];
};

struct {
	char nombre[20];
	struct info_direccion dir_empleado;
	double salario;
} empleados[3];


int main() {
	// solicitando los datos
	for (int i = 0; i < 3; ++i) {
		// vaciar el buffer y permitir digitar los valores
		fflush(stdin);

		cout << "Ingrese su nombre: ";
		cin.getline(empleados[i].nombre, 20, '\n');
		cout << "Ingrese su direccion: ";
		cin.getline(empleados[i].dir_empleado.direccion, 30, '\n');
		cout << "Ingrese su ciudad: ";
		cin.getline(empleados[i].dir_empleado.ciudad, 20, '\n');
		cout << "Ingrese su provincia: ";
		cin.getline(empleados[i].dir_empleado.provincia, 20, '\n');
		cout << "Ingrese su salario: ";
		cin >> empleados[i].salario;
		cout << '\n';
	}

	// imprimiendo los datos
	for (int i = 0; i < 3; ++i) {
		cout << "Nombre: " << empleados[i].nombre << endl;
		cout << "Direccion: " << empleados[i].dir_empleado.direccion << endl;
		cout << "Ciudad: " << empleados[i].dir_empleado.ciudad << endl;
		cout << "Provincia: " << empleados[i].dir_empleado.provincia << endl;
		cout << "Salario: " << empleados[i].salario << endl;
	}

	return 0;
}





// 59_ estructuras || ejercicio - categoría de un corredor
#include <string.h>

struct corredor {
	char nombre[20];
	int edad;
	char sexo[10];
	char club[20];
} c1;


int main() {
	char categoria[20];

	cout << "Nombre: ";
	cin.getline(c1.nombre, 20, '\n');
	cout << "Edad: ";
	cin >> c1.edad;
	fflush(stdin);
	cout << "Sexo: ";
	cin.getline(c1.sexo, 10, '\n');
	cout << "Club: ";
	cin.getline(c1.club, 20, '\n');

	if (c1.edad <= 18) {
		strcpy(categoria, "Juvenil");
	} else if (c1.edad <= 40) {
		strcpy(categoria, "Senior");
	} else {
		strcpy(categoria, "Veterano");
	}

	cout << "\n\nDatos del corredor: " << endl;
	cout << "Nombre: " << c1.nombre << endl;
	cout << "Edad: " << c1.edad << endl;
	cout << "Sexo: " << c1.sexo << endl;
	cout << "Club: " << c1.club << endl;
	cout << "Categoria: " << categoria << endl;

	return 0;
}





// 60_ estructuras || empleado con mayor y menor salario

struct empleado {
	char nombre[20];
	float salario;
} emp[100];


int main() {
	int n_empleados, posM = 0, posm = 0;
	float mayor = 0, menor = 999999;

	cout << "Ingrese el numero de empleados: ";
	cin >> n_empleados;

	for (int i = 0; i < n_empleados; ++i) {
		fflush(stdin);

		cout << i + 1 << ". Ingrese su nombre: ";
		cin.getline(emp[i].nombre, 20, '\n');
		cout << i + 1 << ". Ingrese su salario: ";
		cin >> emp[i].salario;

		// determinando empleado de mayor salario
		if (emp[i].salario > mayor) {
			mayor = emp[i].salario;
			posM = i;
		}
		// determinando empleado de menor salario
		if (emp[i].salario < menor) {
			menor = emp[i].salario;
			posm = i;
		}

		cout << '\n';
	}


	cout << "\n__ Datos del empleado con mayor salario __\n";
	cout << "Nombre: " << emp[posM].nombre << endl;
	cout << "Salario: " << emp[posM].salario << endl;

	cout << "\n__ Datos del empleado con menor salario __\n";
	cout << "Nombre: " << emp[posm].nombre << endl;
	cout << "Salario: " << emp[posm].salario << "\n\n";

	return 0;
}





// 61_ estructuras anidadas || promedio de un alumno

struct promedio {
	float nota1;
	float nota2;
	float nota3;
};

struct alumno {
	char nombre[20];
	char sexo[10];
	int edad;
	struct promedio prom;
} alumno1;


int main() {
	float promedio_alumno;

	cout << "Ingrese su nombre: ";
	cin.getline(alumno1.nombre, 20, '\n');
	cout << "Ingrese su sexo: ";
	cin.getline(alumno1.sexo, 10, '\n');
	cout << "Ingrese su edad: ";
	cin >> alumno1.edad;

	cout << "\n___ Notas del alumno ___\n";
	cout << "Nota1: "; cin >> alumno1.prom.nota1;
	cout << "Nota2: "; cin >> alumno1.prom.nota2;
	cout << "Nota3: "; cin >> alumno1.prom.nota3;

	promedio_alumno = (alumno1.prom.nota1 + alumno1.prom.nota2 + alumno1.prom.nota3) / 3;

	cout << "\n___ Datos del alumno ___\n";
	cout << "Nombre: " << alumno1.nombre << endl;
	cout << "Sexo: " << alumno1.sexo << endl;
	cout << "Edad: " << alumno1.edad << endl;
	cout << "Promedio: " << promedio_alumno << "\n\n";

	return 0;
}





// 62_ estructuras || etapas de un ciclista

struct Etapas {
	int horas;
	int minutos;
	int segundos;
} et[100];


int main() {
	int n_etapas, horasT = 0, minutosT = 0, segundosT = 0;

	cout << "Ingrese el numero de etapas: "; cin >> n_etapas;

	for (int i = 0; i < n_etapas; ++i) {
		// solicitando los datos al usuario
		cout << "Horas demoradas: "; cin >> et[i].horas;
		cout << "Minutos demorados: "; cin >> et[i].minutos;
		cout << "Segundos demorados: "; cin >> et[i].segundos;

		horasT += et[i].horas;
		minutosT += et[i].minutos;
		if (minutosT >= 60) {
			minutosT -= 60;
			horasT++;
		}
		segundosT += et[i].segundos;
		if (segundosT >= 60) {
			segundosT -= 60;
			minutosT++;
		}

		cout << '\n';
	}

	cout << "\nTiempo total empleado\n";
	cout << "Horas: " << horasT << endl;
	cout << "Minutos: " << minutosT << endl;
	cout << "Segundos: " << segundosT << "\n\n";

	return 0;
}





// 82_ punteros || declaración de punteros

//   &n = la dirección de n
//   *n = la variable cuya dirección está almacenada en n (puntero)

int main() {
	int num, *dir_num;

	num = 20;
	dir_num = &num;

	// imprimimos num
	cout << "Numero: " << num << "\n";

	// imprimimos la posición de memoria exacta donde se está guardando dicho número
	cout << "Direccion de memoria donde se esta guardando la variable: " << &num << "\n\n";


	// mostramos el número y la posición de memoria del número con punteros

	// mostramos lo que hay dentro de la posición de memoria que se le ha dado a un puntero
	cout << "Numero: " << *dir_num << "\n";

	// mostramos la dirección de memoria donde está almacenada la variable
	cout << "Direccion de mem: " << dir_num << "\n\n";

	return 0;
}





// 83_ punteros || número par o impar con punteros

int main() {
	int num, *dir_num;

	cout << "Ingrese un numero: "; cin >> num;
	dir_num = &num;  // guardamos la posición de memoria de la variable num

	if (*dir_num % 2 == 0) {
		cout << "El numero " << *dir_num << " es par" << '\n';
	} else {
		cout << "El numero " << *dir_num << " es impar" << '\n';
	}

	cout << "La posicion de memoria donde se ha guardado el numero es: "
		<< dir_num << "\n\n";		// 0x61ff08

	return 0;
}





// 83b_ punteros || número primo o no con punteros

bool esPrimo(int n) {
	if (n % 2 == 0) return false;

	for (int i = 3; i * i <= n; i += 2) {
		if (i % n == 0) return false;
	}

	return true;
}


int main() {
	int num, *dir_num;

	cout << "Ingrese un numero: "; cin >> num;
	dir_num = &num;  // guardamos la posición de memoria de la variable num

	if (esPrimo(*dir_num)) {
		cout << "El numero " << *dir_num << " no es primo" << '\n';
	} else {
		cout << "El numero " << *dir_num << " es primo" << '\n';
	}

	cout << "La posicion de memoria donde se ha guardado el numero es: "
		<< dir_num << "\n\n";		// 0x61ff08

	return 0;
}





// 84_ punteros || correspondencia entre arreglos y punteros

int main() {
	int numeros[] = {1,2,3,4,5};
	int *dir_numeros;

	// dir_numeros = &numeros[0];
	dir_numeros = numeros;  // es exactamente lo mismo que lo anterior

	for (int i = 0; i < 5; ++i) {
		//cout << "Elemento del vector [" << i << "]: " << *dir_numeros++ << '\n';
		//cout << "La posicion de memoria para " << numeros[i] << " es: " << dir_numeros++ << '\n';
		cout << dir_numeros++ << '\n';
	}
	cout << '\n';

	return 0;
}





// 85_ punteros || números pares de un arreglo con punteros

int main() {
	int numeros[10], *dir_numeros;

	for (int i = 0; i < 10; ++i) {
		cout << "Ingrese el numero en [" << i << "]: ";
		cin >> numeros[i];
	}

	dir_numeros = numeros;  // posición de memoria en que comienza numeros

	for (int i = 0; i < 10; ++i) {
		if (*dir_numeros % 2 == 0) {
			cout << "El numero " << * dir_numeros << " es par" << '\n';
			cout << "Posicion de memoria: " << dir_numeros << '\n';
		}

		dir_numeros++;
	}
	cout << '\n';

	return 0;
}





// 85b_ punteros || menor número de un arreglo con punteros

int main() {
	int numeros[100], *dir_numeros, q, menor = 99999;

	cout << "Ingrese el tamanio del arreglo: ";
	cin >> q;

	for (int i = 0; i < q; ++i) {
		cout << "Ingrese el numero en [" << i << "]: ";
		cin >> numeros[i];
	}

	dir_numeros = numeros;  // posición de memoria en que comienza numeros

	for (int i = 0; i < q; ++i) {
		if (*dir_numeros < menor) menor = *dir_numeros;
		dir_numeros++;
	}

	cout << "El numero " << menor << " es el menor" << '\n';
	cout << "Posicion de memoria: " << dir_numeros << '\n';
	cout << '\n';

	return 0;
}





// 86_ punteros || asignación dinámica de arreglos

// new : reserva el número de bytes solicitado por la declaración
// delete : libera un bloque de bytes reservado con anterioridad

//#include <stdlib.h>  // funciona new y delete (es al pepe)

int numCalif, *calif;

void pedirNotas() {
	cout << "Ingrese el numero de calificaciones: ";
	cin >> numCalif;

	calif = new int[numCalif];  // creamos el arreglo (de tipo dinámico)

	for (int i = 0; i < numCalif; ++i) {
		cout << "Ingrese una nota: ";
		cin >> calif[i];
	}
}

void mostrarNotas() {
	cout << "\n\nMostrando notas del usuario:\n";

	for (int i = 0; i < numCalif; ++i) {
		cout << calif[i] << '\n';
	}
}

int main() {
	pedirNotas();
	mostrarNotas();
	cout << '\n';

	delete[] calif;  // liberando el espacio en bytes utilizado anteriormente

	return 0;
}





// 87_ punteros || transmisión/paso de direcciones a una función

void intercambio(float *dirN1, float *dirN2) {
	float aux;

	// intercambiamos los valores de las variables
	aux = *dirN1;
	*dirN1 = *dirN2;
	*dirN2 = aux;
}


int main() {
	float num1 = 20.6, num2 = 6.83;

	cout << "\n___ Antes del intercambio ___\n";
	cout << "Primer numero: " << num1 << '\n';
	cout << "Segundo numero: " << num2 << '\n';

	intercambio(&num1, &num2);

	cout << "\n\n___ Despues del intercambio ___\n";
	cout << "El nuevo valor de num1: " << num1 << '\n';
	cout << "El nuevo valor de num2: " << num2 << '\n';
	cout << '\n';

	return 0;
}





// 88_ punteros || transmisión/paso de arreglos
// enviar arreglos a través de punteros como parámetros de función
// (hallar el máximo elemento de un arreglo)

//int hallarMax(int *, int);  // prototipo
int hallarMax(int *dirVec, int nElementos)
{
	int max = 0;

	for (int i = 0; i < nElementos; ++i)
	{
		if (*(dirVec + i) > max)
		{
			max = *(dirVec + i);
		}
	}

	return max;
}

int main() {
	const int nElementos = 5;
	int numeros[nElementos] = {3, 5, 2, 8, 1};

	cout << "El mayor elemento es: " << hallarMax(numeros, nElementos) << "\n\n";

	return 0;
}





// 89_ punteros || ejercicio - ordenar elementos de un arreglo con punteros

int nElementos, *elemento;

void pedirDatos()
{
	cout << "Ingrese el numero de elementos del arreglo: ";
	cin >> nElementos;

	elemento = new int[nElementos];  // creamos el arreglo

	for (int i = 0; i < nElementos; ++i)  // rellenamos el arreglo
	{
		cout << "Ingrese un numero [" << i << "]: ";
		//cin >> elemento[i];
		cin >> *(elemento + i);
	}
}

void ordenarArreglo(int *elemento, int nElementos)
{
	int aux;

	// ordenar el arreglo con el método burbuja (utilizando punteros)
	for (int i = 0; i < nElementos; ++i)
	{
		for (int j = 0; j < nElementos - 1; ++j)
		{
			if (*(elemento + j) > *(elemento + j + 1))  // elemento[j] > elemento[j + 1]
			{
				aux = *(elemento + j);
				*(elemento + j) = *(elemento + j + 1);
				*(elemento + j + 1) = aux;
			}
		}
	}
}

void mostrarArreglo(int *elemento, int nElementos)
{
	cout << "\n ___ Este es el arreglo ordenado ___ \n";

	for (int i = 0; i < nElementos; ++i)
	{
		cout << *(elemento + i) << ' ';  // elemento[i]
	}

	cout << "\n\n";
}


int main() {
	pedirDatos();
	ordenarArreglo(elemento, nElementos);
	mostrarArreglo(elemento, nElementos);

	delete[] elemento;  // libera la memoria utilizada para el arreglo dinámico

	return 0;
}





// 90_ punteros || ejercicio - contar vocales de un nombre con punteros

#include <string.h>

char nombreUsuario[30];

void pedirDatos()
{
	cout << "Ingrese su nombre: ";
	cin.getline(nombreUsuario, 30, '\n');

	strupr(nombreUsuario);  // transformando a mayúscula el nombre
}

int contarVocales(char *nombre)
{
	int contador = 0;

	while (*nombre)  // va a seguir mientras nombre no sea nulo '\0'
	{
		switch (*nombre)
		{
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U': contador++;
		}
		nombre++;
	}

	return contador;
}

void contarVocalesUnitarias(char *nombre)
{
	int contA = 0, contE = 0, contI = 0, contO = 0, contU = 0;

	while (*nombre)  // va a seguir mientras nombre no sea nulo '\0'
	{
		switch (*nombre)
		{
			case 'A': contA++;
			case 'E': contE++;
			case 'I': contI++;
			case 'O': contO++;
			case 'U': contU++;
		}
		nombre++;
	}

	cout << "A = " << contA << "  E = " << contE << "  I = " << contI << "  O = " << contO << "  U = " << contU;
}



int main()
{
	pedirDatos();
	cout << "\nEl numero de vocales del nombre es: " << contarVocales(nombreUsuario) << "\n\n";
	//nombreUsuario = &nombreUsuario[0]
	cout << "\nEl numero de vocales aisladas del nombre es: \n";
	contarVocalesUnitarias(nombreUsuario);
	cout << "\n\n";

	return 0;
}





// 91_ punteros || matrices dinámicas
// ejemplo: rellenar una matriz de NxM y mostrar su contenido
// matriz original: 1 2 3
//                  4 5 6
//                  7 8 9
//
// **puntero_matriz -> *puntero_fila -> [int] [int]
//                     *puntero_fila -> [int] [int]
//                     *puntero_fila -> [int] [int]
//         1        ->        2 3
//         4        ->        5 6
//         7        ->        8 9

// puntero de punteros: un puntero hacia otro puntero
// cada vez que hay una variable puntero con dos asteriscos iniciales señala a una matriz
int **puntero_matriz;
int nFilas, nColumnas;

void pedirDatos()
{
	cout << "Ingrese el numero de filas: ";
	cin >> nFilas;
	cout << "Ingrese el numero de columnas: ";
	cin >> nColumnas;


	// reservando memoria para la matriz dinámica
	puntero_matriz = new int *[nFilas];  // reservando memoria para las filas
	                                     // aquí necesita ser puntero porque las filas señalan
	                                     // a sus correspondientes columnas

	for (int i = 0; i < nFilas; ++i)
	{
		puntero_matriz[i] = new int[nColumnas];  // reservando memoria para las columnas
	}


	// cargando los datos
	cout << "\nIngrese los elementos de la matriz: \n";
	for (int i = 0; i < nFilas; ++i)
	{
		for (int j = 0; j < nColumnas; ++j)
		{
			cout << "Escriba un numero [" << i << "][" << j <<"]: ";
			cin >> *(*(puntero_matriz + i) + j);  // puntero_matriz[i][j]
		}
	}
}

void mostrarMatriz(int **puntero_matriz, int nFilas, int nColumnas)
{
	cout << "\n ___ Imprimiendo matriz ___ \n";

	for (int i = 0; i < nFilas; ++i)
	{
		for (int j = 0; j < nColumnas; ++j)
		{
			cout << *(*(puntero_matriz + i) + j) << ' ';  // puntero_matriz[i][j]
		}

		cout << '\n';
	}

	cout << '\n';
}



int main()
{
	pedirDatos();
	mostrarMatriz(puntero_matriz, nFilas, nColumnas);


	// liberando la memoria utilizada en la matriz
	for (int i = 0; i < nFilas; ++i)
	{
		delete[] puntero_matriz[i];  // liberando las columnas
	}

	delete[] puntero_matriz;  // liberando las filas

	return 0;
}





// 92_ punteros || suma de matrices dinámicas con punteros

int **puntero_matriz1, **puntero_matriz2, nFilas, nColumnas;

void pedirDatos()
{
	cout << "Ingrese el numero de filas: ";
	cin >> nFilas;
	cout << "Ingrese el numero de columnas: ";
	cin >> nColumnas;

	// reservamos memoria para la primera matriz
	puntero_matriz1 = new int*[nFilas];

	for (int i = 0; i < nFilas; ++i)
	{
		puntero_matriz1[i] = new int[nColumnas];
	}

	cout << "\nIngrese los elementos de la primera matriz: \n";
	for (int i = 0; i < nFilas; ++i)
	{
		for (int j = 0; j < nColumnas; ++j)
		{
			cout << "Ingrese un numero [" << i << "][" << j << "]: ";
			cin >> *(*(puntero_matriz1 + i) + j);
		}
	}


	// reservamos memoria para la segunda matriz
	puntero_matriz2 = new int*[nFilas];

	for (int i = 0; i < nFilas; ++i)
	{
		puntero_matriz2[i] = new int[nColumnas];
	}

	cout << "\nIngrese los elementos de la segunda matriz: \n";

	for (int i = 0; i < nFilas; ++i)
	{
		for (int j = 0; j < nColumnas; ++j)
		{
			cout << "Ingrese un numero [" << i << "][" << j << "]: ";
			cin >> *(*(puntero_matriz2 + i) + j);
		}
	}

}

void sumarMatrices(int **puntero_matriz1, int **puntero_matriz2, int nFilas, int nColumnas)
{
	for (int i = 0; i < nFilas; ++i)
	{
		for (int j = 0; j < nColumnas; ++j)
		{
			*(*(puntero_matriz1 + i) + j) += *(*(puntero_matriz2 + i) + j);
		}
	}
}

void mostrarMatrizFinal(int **puntero_matriz1, int nFilas, int nColumnas)
{
	cout << "\n___ Suma de las dos matrices ___\n";

	for (int i = 0; i < nFilas; ++i)
	{
		for (int j = 0; j < nColumnas; ++j)
		{
			cout << *(*(puntero_matriz1 + i) + j) << ' ';
		}
		cout << '\n';
	}
}

void mostrarMatrizTras(int **puntero_matriz1, int nFilas, int nColumnas)
{
	cout << "\n___ Matriz final traspuesta ___\n";

	for (int i = 0; i < nFilas; ++i)
	{
		for (int j = 0; j < nColumnas; ++j)
		{
			cout << *(*(puntero_matriz1 + j) + i) << ' ';
		}
		cout << '\n';
	}

	cout << "\n\n";	
}



int main()
{
	pedirDatos();
	sumarMatrices(puntero_matriz1, puntero_matriz2, nFilas, nColumnas);
	mostrarMatrizFinal(puntero_matriz1, nFilas, nColumnas);
	mostrarMatrizTras(puntero_matriz1, nFilas, nColumnas);


	// liberando memoria utilizada en la matriz1
	for (int i = 0; i < nFilas; ++i)
	{
		delete[] puntero_matriz1[i];
	}
	delete[] puntero_matriz1;


	// liberando memoria utilizada en la matriz2
	for (int i = 0; i < nFilas; ++i)
	{
		delete[] puntero_matriz2[i];
	}
	delete[] puntero_matriz2;

	return 0;
}





// 92_ punteros || punteros a estructuras

struct Persona
{
	char nombre[30];
	int edad;
} persona, *puntero_persona = &persona;

void pedirDatos()
{
	cout << "Ingrese su nombre: ";
	//cin.getline(persona.nombre, 30, '\n');
	cin.getline(puntero_persona -> nombre, 30, '\n');  // lo mismo que anterior
                                // el operador flecha señala hacia posiciones
                                // o campos de la estructura
	cout << "Ingrese su edad: ";
	cin >> puntero_persona -> edad;
}

void mostrarDatos(Persona *puntero_persona)
{
	cout << "\nSu nombre es: " << puntero_persona -> nombre << "\n";
	cout << "Su edad es: " << puntero_persona -> edad << "\n";
}



int main()
{
	pedirDatos();
	mostrarDatos(puntero_persona);

	cout << "\n\n";	
	return 0;
}





// 94_ punteros || ejercicio - mejor promedio de tres estudiantes con punteros

struct Alumno
{
	char nombre[30];
	int edad;
	float promedio;
} alumno[3], *puntero_alumno = alumno;

void pedirDatos()
{
	for (int i = 0; i < 3; ++i)
	{
		fflush(stdin);
		cout << "Ingrese un nombre: ";
		cin.getline((puntero_alumno + i) -> nombre, 30, '\n');
		cout << "Ingrese su edad: ";
		cin >> (puntero_alumno + i) -> edad;
		cout << "Ingrese el promedio: ";
		cin >> (puntero_alumno + i) -> promedio;
		cout << "\n";	
	}
}

void calcularMejorPromedio(Alumno *puntero_alumno)
{
	float mayor = 0.0;
	int posicion = 0;

	// comprobamos el mayor promedio
	for (int i = 0; i < 3; ++i)
	{
		if ((puntero_alumno + i) -> promedio > mayor)
		{
			mayor = (puntero_alumno + i) -> promedio;  // == puntero_alumno[i].promedio
			posicion = i;  // guardamos la posicion del mayor promedio
		}
	}

	// imprimimos los datos del alumno con mayor promedio
	cout << "\nEl alumno con mejor promedio es: \n";
	cout << "Nombre: " << (puntero_alumno + posicion) -> nombre << '\n';
	cout << "Edad: " << (puntero_alumno + posicion) -> edad << '\n';
	cout << "Promedio: " << (puntero_alumno + posicion) -> promedio << '\n';
}



int main()
{
	pedirDatos();
	calcularMejorPromedio(puntero_alumno);

	cout << "\n\n";	
	return 0;
}





// 94b_ punteros || ejercicio - tiempo empleado por ciclista con punteros

struct Etapa
{
	int horas;
	int minutos;
	int segundos;
} etapa[3], *puntero_etapa = etapa;

void pedirDatos()
{
	cout << "\nIngrese los tiempos empleados \n";

	for (int i = 0; i < 3; ++i)
	{
		cout << "Horas demoradas: "; cin >> (puntero_etapa + i) -> horas;
		cout << "Minutos demorados: "; cin >> (puntero_etapa + i) -> minutos;
		cout << "Segundos demorados: "; cin >> (puntero_etapa + i) -> segundos;
		cout << '\n';
	}
}

void calcularTiempo(Etapa *puntero_etapa)
{
	int horasT = 0, minutosT = 0, segundosT = 0;

	for (int i = 0; i < 3; ++i)
	{
		horasT += (puntero_etapa + i) -> horas;

		minutosT += (puntero_etapa + i) -> minutos;
		if (minutosT >= 60)
		{
			minutosT -= 60;
			horasT++;
		}

		segundosT += (puntero_etapa + i) -> segundos;
		if (segundosT >= 60)
		{
			segundosT -= 60;
			minutosT++;
		}
	}

	cout << "\nTiempo total empleado\n";
	cout << "Horas: " << horasT << '\n';
	cout << "Minutos: " << minutosT << '\n';
	cout << "Segundos: " << segundosT << '\n';
}



int main()
{
	pedirDatos();
	calcularTiempo(puntero_etapa);

	cout << "\n\n";	
	return 0;
}





// 95_ pilas || concepto de pilas

// estructura de un nodo
struct Nodo
{
	int dato;
	  // cualquier dato
	Nodo *siguiente;
	  // puntero siguiente, que apunta a otro nodo, por lo tanto debe ser
	  // de tipo 'nodo'
};





// 96_ pilas || insertar elementos a la pila

#include <stdlib.h>

struct Nodo
{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&pila, int n)
{
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = pila;
	pila = nuevo_nodo;

	cout << "Elemento " << n << " agregado a PILA correctamente\n";
}



int main()
{
	Nodo *pila = NULL;
	int n1, n2;

	cout << "Ingrese un numero: ";
	cin >> n1;
	agregarPila(pila, n1);  // agregando el primer elemento a la pila

	cout << "Ingrese otro numero: ";
	cin >> n2;
	agregarPila(pila, n2);

	cout << "\n\n";	
	return 0;
}





// 97_ pilas || quitar elementos de una pila

struct Nodo
{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&pila, int n)
{
	// 1. creamos el espacio en memoria para almacenar un valor
	// 2. cargamos el valor dentro del nodo(dato)
	// 3. cargamos el puntero pila dentro del nodo(*siguiente)
	// 4. asignamos el nuevo nodo a pila
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = pila;
	pila = nuevo_nodo;

	cout << "Elemento " << n << " agregado a PILA correctamente\n";
}

void sacarPila(Nodo *&pila, int &n)
{
	// 1. creamos una variable auxiliar y la igualamos a pila
	// 2. n es auxiliar que apunta a dato
	// 3. pila apunta hacia siguiente nodo. Si se va a eliminar un nodo,
	      // pila no puede estar apuntando a dicho nodo
	// 4. eliminamos el nodo
	Nodo *aux = pila;
	n = aux -> dato;
	pila = aux -> siguiente;
	delete aux;
}



int main()
{
	Nodo *pila = NULL;
	int dato;

	cout << "Ingrese un numero: ";
	cin >> dato;
	agregarPila(pila, dato);

	cout << "Ingrese otro numero: ";
	cin >> dato;
	agregarPila(pila, dato);

	cout << "Ingrese otro numero: ";
	cin >> dato;
	agregarPila(pila, dato);

	cout << "\n ___ Sacando los elementos de la pila ___\n";
	while (pila != NULL)  // mientras no sea el final de la pila
	{
		sacarPila(pila, dato);

		if (pila != NULL)
		{
			cout << dato << " , ";
		}
		else
		{
			cout << dato << '.';
		}
	}

	cout << "\n\n";	
	return 0;
}





// 98_ pilas || ejercicio - insertar y quitar elementos de una pila

struct Nodo
{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&pila, int n)
{
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = pila;
	pila = nuevo_nodo;

	cout << "\tElemento " << n << " agregado a PILA correctamente\n";
}

void sacarPila(Nodo *&pila, int &n)
{
	Nodo *aux = pila;
	n = aux -> dato;
	pila = aux -> siguiente;
	delete aux;
}



int main()
{
	Nodo *pila = NULL;
	int dato;
	char respuesta;

	do
	{
		cout << "Ingrese un numero: ";
		cin >> dato;
		agregarPila(pila, dato);

		cout << "Desea agregar otro elemento a PILA (s/n): ";
		cin >> respuesta;
	} while ((respuesta == 'S') || (respuesta == 's'));

	cout << "\n  ___ Sacando todos los elementos de PILA ___ \n";
	while (pila != NULL)
	{
		sacarPila(pila, dato);

		if (pila != NULL)
		{
			cout << dato << " , ";
		}
		else
		{
			cout << dato << " .";
		}
	}

	cout << "\n\n";	
	return 0;
}





// 98b_ pilas || ejercicio - insertar y quitar elementos de una pila

struct Nodo
{
	char dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&pila, char n)
{
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = pila;
	pila = nuevo_nodo;

	cout << "\tElemento " << n << " agregado a PILA correctamente\n";
}

void sacarPila(Nodo *&pila, char &n)
{
	Nodo *aux = pila;
	n = aux -> dato;
	pila = aux -> siguiente;
	delete aux;
}



int main()
{
	Nodo *pila = NULL;
	char dato, respuesta;

	do
	{
		cout << "Ingrese una letra: ";
		cin >> dato;
		agregarPila(pila, dato);

		cout << "Desea agregar otro elemento a PILA (s/n): ";
		cin >> respuesta;
	} while ((respuesta == 'S') || (respuesta == 's'));

	cout << "\n  ___ Sacando todos los elementos de PILA ___ \n";
	while (pila != NULL)
	{
		sacarPila(pila, dato);

		if (pila != NULL)
		{
			cout << dato << " , ";
		}
		else
		{
			cout << dato << " .";
		}
	}

	cout << "\n\n";	
	return 0;
}





// 99_ colas || concepto de cola



// 100_ colas || insertar elementos en una cola

struct Nodo
{
	int dato;
	Nodo *siguiente;
};

// función para determinar si la cola está vacía o no
bool colaVacia(Nodo *frente)
{
// 	if (frente == NULL)
// 	{
// 		return true;
// 	}
// 	else
// 	{
// 		return false;
// 	}

//	if (frente == NULL) return true;
//	return false;

	return (frente == NULL)? true : false;
}

// función para insertar elementos en una cola
void insertarCola(Nodo *&frente, Nodo *&fin, int n)
{
	// 1. creamos un nuevo nodo y le asignamos espacio en memoria
	// 2. asignamos al nuevo nodo los elementos correspondientes
	      // el dato que queremos insertar y "siguiente"
	// 3. asignamos los punteros frente y fin hacia el nuevo nodo
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;

	if (colaVacia(frente))
	{
		frente = nuevo_nodo;
	}
	else
	{
		fin -> siguiente = nuevo_nodo;
	}

	fin = nuevo_nodo;

	cout << "\tElemento " << n << " insertado a COLA correctamente\n";
}



// 101_ colas || eliminar elementos de una cola

// función para eliminar elementos de una cola
void suprimirCola(Nodo *&frente, Nodo *&fin, int &n)
{
	// 1. obtenemos el valor del nodo
	// 2. creamos un nodo aux y le asignamos el frente de la cola 
	// 3. eliminamos el nodo del frente de la cola
	n = frente -> dato;

	Nodo *aux = frente;

	if (frente == fin)
	{
		frente = NULL;
		fin = NULL;
	}
	else
	{
		frente = frente -> siguiente;
	}
	delete aux;
}



int main()
{
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato;

	// agregamos elementos

	cout << "\n ___ Agregando nodos a la cola ___ \n";

	cout << "Ingrese un numero: ";
	cin >> dato;
	insertarCola(frente, fin, dato);

	cout << "Ingrese otro numero: ";
	cin >> dato;
	insertarCola(frente, fin, dato);

	cout << "Ingrese otro numero: ";
	cin >> dato;
	insertarCola(frente, fin, dato);


	// eliminamos elementos

	cout << "\n ___ Quitando los nodos de la cola ___ \n";

	while (frente != NULL)
	{
		suprimirCola(frente, fin, dato);

		if (frente != NULL)
		{
			cout << dato << " , ";
		}
		else
		{
			cout << dato << " .";
		}
	}

	cout << "\n\n";	
	return 0;
}





// 102_ colas || ejercicio - insertar y eliminar elementos de una cola

struct Nodo
{
	char dato;
	Nodo *siguiente;
};


bool colaVacia(Nodo *frente)
{
	return (frente == NULL)? true : false;
}


void insertarCola(Nodo *&frente, Nodo *&fin, char n)
{
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;

	if (colaVacia(frente))
	{
		frente = nuevo_nodo;
	}
	else
	{
		fin -> siguiente = nuevo_nodo;
	}

	fin = nuevo_nodo;
}


void suprimirCola(Nodo *&frente, Nodo *&fin, char &n)
{
	n = frente -> dato;

	Nodo *aux = frente;

	if (frente == fin)
	{
		frente = NULL;
		fin = NULL;
	}
	else
	{
		frente = frente -> siguiente;
	}
	delete aux;
}


void menu()
{
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int opc;
	char dato;

	do
	{
		cout << "\t ___ MENU ___ \n";
		cout << "1. Insertar un caracter en la cola" << '\n';
		cout << "2. Mostrar todos los elementos de la cola" << '\n';
		cout << "3. Salir" << '\n';
		cout << "Opcion: ";
		cin >> opc;

		switch (opc)
		{
			case 1:
				cout << "\nIngrese el caracter para agregar a la cola: ";
				cin >> dato;
				insertarCola(frente, fin, dato);
				break;
			case 2:
				cout << "\nMostrando los elementos de la cola: \n";
				while (frente != NULL)
				{
					suprimirCola(frente, fin, dato);
					if (frente != NULL)
					{
						cout << dato << " , ";
					}
					else
					{
						cout << dato << " .\n\n";
					}
				}
				system("pause");
				break;
			case 3:
				break;
		}
		system("cls");
	} while (opc != 3);
}



int main()
{
	menu();

	cout << "\n\n";	
	return 0;
}





// 102b_ colas || ejercicio - insertar y eliminar nombres de una cola

struct Nodo {string dato; Nodo *siguiente;};

bool colaVacia(Nodo *frente) {return (frente == NULL)? true : false;}

void insertarCola(Nodo *&frente, Nodo *&fin, string n) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
	if (colaVacia(frente)) {frente = nuevo_nodo;}
	else {fin -> siguiente = nuevo_nodo;}
	fin = nuevo_nodo;
}

void suprimirCola(Nodo *&frente, Nodo *&fin, string &n) {
	n = frente -> dato;
	Nodo *aux = frente;
	if (frente == fin) {frente = NULL; fin = NULL;}
	else {frente = frente -> siguiente;}
	delete aux;
}

void menu() {
	Nodo *frente = NULL, *fin = NULL; int opc; string dato;
	do {
		cout << "\t ___ MENU ___ \n" << "1. Insertar un caracter en la cola\n";
		cout << "2. Mostrar todos los elementos de la cola\n";
		cout << "3. Salir\n" << "Opcion: "; cin >> opc;
		switch (opc) {
			case 1: cout << "\nIngrese el caracter para agregar a la cola: ";
					cin >> dato; insertarCola(frente, fin, dato); break;
			case 2: cout << "\nMostrando los elementos de la cola: \n";
					while (frente != NULL) {suprimirCola(frente, fin, dato);
						if (frente != NULL) {cout << dato << " , ";}
						else {cout << dato << " .\n\n";}}
					system("pause"); break;
			case 3: break;}
		system("cls");
	} while (opc != 3);
}


int main() {
	menu();
	cout << "\n\n";	
	return 0;}





// 103_ listas || concepto de lista enlazada



// 104_ listas || insertar elementos en una lista enlazada

struct Nodo
{
	int dato;
	Nodo *siguiente;
};

Nodo *lista = NULL;

void insertarLista(Nodo *&lista, int n)
{
	// 1. creamos un nuevo nodo
	// 2. asignamos a nuevo_nodo->dato el elemento que queremos incluir a la lista
	// 3. creamos dos nodos auxiliares y asignamos lista al primero de ellos
	// 4. insertamos el elemento a la lista
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo -> dato = n;

	Nodo *aux1 = lista;
	Nodo *aux2;

	while((aux1 != NULL) && (aux1 -> dato < n))
	{
		aux2 = aux1;
		aux1 = aux1 -> siguiente;
	}
	if (lista == aux1) 
	{
		lista = nuevo_nodo;
	}
	else
	{
		aux2 -> siguiente = nuevo_nodo;
	}
	nuevo_nodo -> siguiente = aux1;

	cout << "\tElemento " << n << " insertado a la lista correctamente\n";
}



// 105_ listas || mostrar elementos en una lista

void mostrarLista(Nodo *lista)
{
	// 1. creamos un nuevo nodo(actual)
	// 2. igualamos ese nuevo nodo(actual) a lista
	// 3. recorremos la lista de inicio a fin
	Nodo *actual = new Nodo();

	actual = lista;

	while (actual != NULL)
	{
		cout << actual -> dato << " -> ";
		actual = actual -> siguiente;
	}

	cout << "FINAL\n";
}



// 106_ listas || buscar un elemento en una lista

void buscarLista(Nodo *lista, int n)
{
	bool bandera = false;

	// 1. creamos un nuevo nodo(actual)
	// 2. igualamos ese nuevo nodo(actual) a lista
	// 3. recorremos la lista
	// 4. determinamos si el elemento existe o no en la lista
	Nodo *actual = new Nodo();

	actual = lista;

	while ((actual != NULL) && (actual -> dato <= n))
	{
		if (actual -> dato == n)
		{
			bandera = true;
		}
		actual = actual -> siguiente;
	}

	if (bandera == true)
	{
		cout << "El elemento " << n << " SI ha sido encontrado en la lista\n";
	} 
	else
	{
		cout << "El elemento " << n << " NO ha sido encontrado en la lista\n";
	}
}



// 107_ listas || eliminar un elemento de la lista

void eliminarNodo(Nodo *&lista, int n)
{
	// 1. averiguamos si la lista no está vacía
	// 2. creamos un *aux_borrar y *anterior = NULL
	// 3. igualamos *aux_borrar al inicio de la lista
	// 4. recorremos la lista
	// 5. eliminamos el elemento
	if (lista != NULL)
	{
		Nodo *aux_borrar;
		Nodo *anterior = NULL;

		aux_borrar = lista;

		while ((aux_borrar != NULL) && (aux_borrar -> dato != n))
		{
			anterior = aux_borrar;
			aux_borrar = aux_borrar -> siguiente;
		}

		if (aux_borrar == NULL)
		{
			cout << "El elemento no ha sido encontrado\n";
		}
		else if (anterior == NULL)
		{
			lista = lista -> siguiente;
			delete aux_borrar;
			cout << "\tElemento " << n << " eliminado correctamente\n";
		}
		else
		{
			anterior -> siguiente = aux_borrar -> siguiente;
			delete aux_borrar;
			cout << "\tElemento " << n << " eliminado correctamente\n";
		}
	}
}



// 108_ listas || eliminar todos los elementos de la lista

void eliminarLista(Nodo *&lista, int &n)
{
	// 1. creamos un nodo *aux y lo igualamos al inicio de la lista
	// 2. guardamos el dato que queremos eliminar dentro de *aux
	// 3. pasamos lista a siguiente nodo
	// 4. eliminamos aux
	while (lista != NULL)
	{
		Nodo *aux = lista;

		n = aux -> dato;

		lista = aux -> siguiente;

		delete aux;

		cout << n << " -> ";
	}

	cout << "FINAL\n";
}



void menu()
{
	int opcion, dato;

	do
	{
		cout << "\t\n ___ MENU ___ \n";
		cout << "1. Insertar elementos a la lista\n";
		cout << "2. Mostrar los elementos de la lista\n";
		cout << "3. Buscar un elemento en la lista\n";
		cout << "4. Eliminar un nodo de la lista\n";
		cout << "5. Eliminar todos los elementos de la lista\n";
		cout << "6. Salir\n";
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion)
		{
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
				cout << "\nIngrese el nodo que desea eliminar: ";
				cin >> dato;
				eliminarNodo(lista, dato);
				cout << "\n";
				system("pause");
				break;
			case 5:
				eliminarLista(lista, dato);
				cout << "\n";
				system("pause");
				break;
		}

		system("cls");
	} while (opcion != 6);
}



int main()
{
	menu();

	cout << "\n\n";	
	return 0;
}





// 109_ listas || ejercicio - calcular el mayor y el menor elemento de una lista

struct Nodo
{
	int dato;
	Nodo *siguiente;
};


// agregar elementos al final de la lista
void insertarLista(Nodo *&lista, int n)
{
	Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;

	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;

	if (lista == NULL)  // si la lista está vacía
	{
		lista = nuevo_nodo;  // agregamos el primer elemento a la lista
	}
	else
	{
		aux = lista;  // aux apunta al inicio de la lista

		while (aux -> siguiente != NULL)  // recorremos la lista
		{
			aux = aux -> siguiente;  // avanzamos posiciones en la lista
		}

		aux -> siguiente = nuevo_nodo;  // agregamos el nuevo nodo a la lista
	}

	cout << "\tElemento " << n << " agregado a la lista con exito\n";
}


// mostramos todos los elementos de la lista
void mostrarLista(Nodo *lista) {
	while (lista != NULL)  // mientras no sea el final de la lista
	{
		cout << lista -> dato << " -> ";
		lista = lista -> siguiente;  // avanzamos una posición en lista
	}

	cout << "FINAL\n";
}


// calculamos el mayor y menor elemento de la lista
void calcularMayorMenor(Nodo *lista) {
	int mayor = 0, menor = 99999;

	while (lista != NULL)  // recorremos la lista
	{
		if ((lista -> dato) > mayor)  // cálculo del mayor elemento
		{
			mayor = lista -> dato;
		}

		if ((lista -> dato) < menor)  // cálculo del menor elemento
		{
			menor = lista -> dato;
		}

		lista = lista -> siguiente;  // avanzamos una posición en lista
	}

	cout << "\nEl mayor elemento es: " << mayor << "\n";
	cout << "El menor elemento es: " << menor;
}


// calculamos la suma de los elementos de la lista
void sumaElementos(Nodo *lista)
{
	int suma = 0;

	while (lista != NULL)
	{
		suma += lista -> dato;

		lista = lista -> siguiente;
	}

	cout << "\nLa suma de los elementos de la lista es: " << suma;
}


// calculamos el promedio de los elementos de la lista
void promedioElementos(Nodo *lista)
{
	int contador = 0;
	float acumulado = 0.0, promedio = 0;

	while (lista != NULL)
	{
		contador += 1;
		acumulado += lista -> dato;
		promedio = acumulado / contador;

		lista = lista -> siguiente;
	}

	cout << "\nLa cantidad de elementos de la lista es: " << contador;	
	cout << "\nEl promedio de los elementos de la lista es: " << promedio << "\n";	
}


int main()
{
	Nodo *lista = NULL;
	int dato;
	char respuesta;

	do 
	{
		cout << "Ingrese un numero: ";
		cin >> dato;
		insertarLista(lista, dato);  // agregamos el nuevo elemento a la lista

		cout << "Desea agregar otro nodo? (s/n) ";
		cin >> respuesta;
	} while (respuesta == 's' || respuesta == 'S');

	cout << "\n\nLos elementos de la lista son los siguientes ==>   ";
	mostrarLista(lista);

	calcularMayorMenor(lista);
	sumaElementos(lista);
	promedioElementos(lista);
	cout << "\n\n";

	cout << "\n\n";	
	return 0;
}





// 110_ árboles || concepto de árbol




// 111_ árboles || árbol binario



// 112_ árboles || árbol binario de búsqueda - ABB




// 113_ árboles || insertar nodos en un árbol binario de búsqueda ABB

struct Nodo
{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

Nodo *arbol = NULL;

Nodo *crearNodo(int n, Nodo *padre)
{
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo -> dato = n;
	nuevo_nodo -> der = NULL;
	nuevo_nodo -> izq = NULL;
	nuevo_nodo -> padre = padre;

	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *padre)
{
	if (arbol == NULL)  // si el árbol está vacío
	{
		Nodo *nuevo_nodo = crearNodo(n, padre);  // creamos un nuevo nodo
		arbol = nuevo_nodo;  // a árbol le asignamos el nuevo nodo
	}
	else  // si el árbol tiene un nodo o más
	{
		int valorRaiz = arbol -> dato;

		if (n < valorRaiz)
		{
			insertarNodo(arbol -> izq, n, arbol);
		}
		else
		{
			insertarNodo(arbol -> der, n, arbol);
		}
	}
}



// 114_ árboles || mostrar el árbol completo

void mostrarArbol(Nodo *arbol, int contador)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		mostrarArbol(arbol -> der, contador + 1);
		for (int i = 0; i < contador; ++i)
		{
			cout << "   ";
		}
		cout << arbol -> dato << "\n";

		mostrarArbol(arbol -> izq, contador + 1);
	}
}



// 115_ árboles || buscar un nodo en el árbol

bool busqueda(Nodo *arbol, int n)
{
	if (arbol == NULL)
	{
		return false;
	}
	else if (arbol -> dato == n)
	{
		return true;
	}
	else if (n < arbol -> dato)
	{
		return busqueda(arbol -> izq, n);
	}
	else
	{
		return busqueda(arbol -> der, n);
	}
}



// 116_ árboles || recorrido de un árbol en PreOrden

void preOrden(Nodo *arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		cout << arbol -> dato << " - ";
		preOrden(arbol -> izq);
		preOrden(arbol -> der);
	}
}



// 117_ árboles || recorrido de un árbol en InOrden

void inOrden(Nodo *arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		inOrden(arbol -> izq);
		cout << arbol -> dato << " - ";
		inOrden(arbol -> der);
	}
}



// 118_ árboles || recorrido de un árbol en PostOrden

void postOrden(Nodo *arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		postOrden(arbol -> izq);
		postOrden(arbol -> der);
		cout << arbol -> dato << " - ";
	}
}



// 120_ árboles || eliminar un nodo del árbol - parte 2

// función para determinar el nodo más izquierdo posible

Nodo *minimo(Nodo *arbol)
{
	if (arbol == NULL)
	{
		return NULL;
	}

	if (arbol -> izq)  // si el árbol tiene hijo izquierdo
	{
		return minimo(arbol -> izq);  // buscamos la parte más izquierda posible
	}
	else  // si no tiene hijo izquierdo
	{
		return arbol;  // retornamos el mismo nodo
	}
}



// 121_ árboles || eliminar un nodo del árbol - parte 3

// función para reemplazar dos nodos

void reemplazar(Nodo *arbol, Nodo *nuevoNodo)
{
	if (arbol -> padre)  // a arbol -> padre hay que asignarle su nuevo hijo
	{
		if (arbol -> dato == arbol -> padre -> izq -> dato)
		{
			arbol -> padre -> izq = nuevoNodo;
		}
		else if (arbol -> dato == arbol -> padre -> der -> dato)
		{
			arbol -> padre -> der = nuevoNodo;
		}
	}

	if (nuevoNodo)  // procedemos a asignarle su nuevo padre
	{
		nuevoNodo -> padre = arbol -> padre;
	}
}



// función para destruir un nodo

void destruirNodo(Nodo *nodo)
{
	nodo -> izq = NULL;
	nodo -> der = NULL;

	delete nodo;
}



// 122_ árboles || eliminar un nodo del árbol - parte 4

// función para eliminar el nodo encontrado

void eliminarNodo(Nodo *nodoEliminar)
{
	if (nodoEliminar -> izq && nodoEliminar -> der)  // si el nodo tiene hijo izq && der
	{
		Nodo *menor = minimo(nodoEliminar -> der);
		nodoEliminar -> dato = menor -> dato;
		eliminarNodo(menor);
	}
	else if (nodoEliminar -> izq)
	{
		reemplazar(nodoEliminar, nodoEliminar -> izq);
		destruirNodo(nodoEliminar);
	}
	else if (nodoEliminar -> der)
	{
		reemplazar(nodoEliminar, nodoEliminar -> der);
		destruirNodo(nodoEliminar);
	}
	else  // si un nodo no tiene hijos
	{
		reemplazar(nodoEliminar, NULL);  // enviamos el nodo que queremos eliminar y lo reemplazamos por NULL
		destruirNodo(nodoEliminar);
	}
}



// 119_ árboles || eliminar un nodo del árbol - parte 1

// añadidos todos los campos "padre"

void eliminar(Nodo *arbol, int n)
{
	if (arbol == NULL)
	{
		return;
	}
	else if (n < arbol -> dato)  // si el valor es menor
	{
		eliminar(arbol -> izq, n);  // buscar por la izquierda
	}
	else if (n > arbol -> dato)  // contrario
	{
		eliminar(arbol -> der, n);  // buscar por la derecha
	}
	else  // si ya se encontró el elemento
	{
		eliminarNodo(arbol);
	}
}



// ----------------------------------------------------------------------------

void menu()
{
	int opcion, dato, contador = 0;

	do
	{
		cout << "\t\n ___ MENU ___ \n";
		cout << "1. Insertar un nuevo nodo\n";
		cout << "2. Mostrar el arbol completo:\n";
		cout << "3. Buscar un elemento en el arbol\n";
		cout << "4. Recorrer el arbol en PreOrden\n";
		cout << "5. Recorrer el arbol en PreOrden\n";
		cout << "6. Recorrer el arbol en PostOrden\n";
		cout << "7. Eliminar un nodo del arbol\n";
		cout << "8. Salir\n";
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion)
		{
			case 1:
				cout << "\nIngrese un numero: ";
				cin >> dato;
				insertarNodo(arbol, dato, NULL);
				cout << "\n";
				system("pause");
				break;
			case 2:
				cout << "\nMostrando el arbol completo:\n\n";
				mostrarArbol(arbol, contador);
				cout << "\n";
				system("pause");
				break;
			case 3:
				cout << "\nIngrese el elemento a buscar: ";
				cin >> dato;
				if (busqueda(arbol, dato) == true)
				{
					cout << "\nEl elemento " << dato << " se encuentra en el arbol\n";
				}
				else
				{
					cout << "\nElemento no encontrado\n";
				}
				cout << "\n";
				system("pause");
				break;
			case 4:
				cout << "\nRecorrido en PreOrden: \n";
				preOrden(arbol);
				cout << "FINAL\n\n";
				system("pause");
				break;
			case 5:
				cout << "\nRecorrido en InOrden: \n";
				inOrden(arbol);
				cout << "FINAL\n\n";
				system("pause");
				break;
			case 6:
				cout << "\nRecorrido en PostOrden: \n";
				postOrden(arbol);
				cout << "FINAL\n\n";
				system("pause");
				break;
			case 7:
				cout << "\nIngrese un nodo a eliminar: ";
				cin >> dato;
				eliminar(arbol, dato);
				cout << "\n";
				system("pause");
				break;
		}

		system("cls");
	} while (opcion != 8);
}



int main()
{
	menu();

	return 0;
}





// 123_ archivos || escribir un archivo de texto

#include <stdlib.h>
#include <fstream>


void escribir()
{
	ofstream archivo;
	string nombreArchivo, contenido;
	char respuesta;

	cout << "Ingrese el nombre del archivo: ";
	getline(cin, nombreArchivo);
	archivo.open(nombreArchivo.c_str(), ios::out);  // abriendo el archivo

	if (archivo.fail())
	{
		cout << "No se pudo abrir el archivo\n\n";
		exit(1);
	}

	//archivo << "Hola, que tal? Mi nombre es Alejandro.";
	//cout << "Ingrese el texto del archivo:";
	//getline(cin, contenido);
	//archivo << contenido;

	do
	{
		fflush(stdin);
		cout << "Ingrese el texto del archivo: ";
		getline(cin, contenido);
		archivo << contenido;

		cout << "Desea agregar mas texto al archivo (s/n): ";
		cin >> respuesta;
	} while ((respuesta == 'S') || (respuesta == 's'));

	archivo.close();  // cerramos el archivo
}



int main()
{
	escribir();
	return 0;
}





// 124_ archivos || lectura de un archivo de texto

#include <stdlib.h>
#include <fstream>


void lectura()
{
	ifstream archivo;
	string direccion, texto;

	cout << "Ingrese la direccion o el archivo que desea abrir: ";
	cin >> direccion;

	archivo.open(direccion, ios::in);  // abrimos el archivo en modo lectura

	if (archivo.fail())
	{
		cout << "No se pudo abrir el archivo\n\n";
		exit(1);
	}

	cout << "\nEl contenido del archivo es el siguiente:\n\n";
	while (!archivo.eof())  // mientras no sea el final del archivo
	{
		getline(archivo, texto);
		cout << texto << endl;
	}

	archivo.close();
}


int main()
{
	lectura();
	return 0;
}
*/





// 125_ archivos || añadir texto en un archivo

#include <stdlib.h>
#include <fstream>


void aniadir()
{
	ofstream archivo;
	string direccion, texto;
	char respuesta;

	cout << "Ingrese la direccion o el archivo que desea abrir: ";
//	cin >> direccion;
	getline(cin, direccion);

//	archivo.open("textos/programacion.txt", ios::app);  // abrimos el archivo en modo añadir
//	archivo.open(direccion, ios::in);
	archivo.open(direccion.c_str(), ios::app);

	if (archivo.fail())
	{
		cout << "No se pudo abrir el archivo\n\n";
		exit(1);
	}


	do
	{
		fflush(stdin);
		cout << "Ingrese el texto que desee aniadir: ";
		getline(cin, texto);
		archivo << texto << endl;

		cout << "Desea agregar mas texto al archivo (s/n): ";
		cin >> respuesta;
	} while ((respuesta == 'S') || (respuesta == 's'));


	archivo.close();
}


int main()
{
	aniadir();
	return 0;
}