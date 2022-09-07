
#include <iostream>
using namespace std;


struct Nodo
{
	int dato;
	Nodo *siguiente;
};

Nodo *lista = NULL;


// insertar elementos en una lista enlazada

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


// mostrar elementos en una lista

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


// buscar un elemento en una lista

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


// eliminar un elemento de la lista

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


// eliminar todos los elementos de la lista

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


// calculamos la suma de los elementos de la lista

void sumaElementos(Nodo *lista)
{
	int suma = 0;

	while (lista != NULL)
	{
		suma += lista -> dato;

		lista = lista -> siguiente;
	}

	cout << "\nLa suma de los elementos de la lista es: " << suma<< "\n";
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



void menu()
{
	int opcion, dato;

	do
	{
		cout << "\t\n ___ MENU ___ \n";
		cout << "1. Insertar elementos a la lista\n";
		cout << "2. Mostrar los elementos de la lista\n";
		cout << "3. Buscar un elemento en la lista\n";
		cout << "4. Calcular la suma de los elementos de la lista\n";
		cout << "5. Calcular el promedio de los elementos de la lista\n";
		cout << "6. Eliminar un nodo de la lista\n";
		cout << "7. Eliminar todos los elementos de la lista\n";
		cout << "8. Salir\n";
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
				sumaElementos(lista);
				cout << "\n";
				system("pause");
				break;
			case 5:
				promedioElementos(lista);
				cout << "\n";
				system("pause");
				break;
			case 6:
				cout << "\nIngrese el nodo que desea eliminar: ";
				cin >> dato;
				eliminarNodo(lista, dato);
				cout << "\n";
				system("pause");
				break;
			case 7:
				eliminarLista(lista, dato);
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

	cout << "\n\n";	
	return 0;
}