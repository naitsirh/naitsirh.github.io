// ejemplo 6.8 página 242 del libro "Fundamentos de programación, 4° edición",
// del autor Luis Joyanes Aguilar
//
// modificado con sentencias <else if> y para ingresar cualquier número,
// indefinidamente, mayor que cero y menor que 3999

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