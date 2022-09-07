
#include <iostream>
using namespace std;

// insertar nodos en un árbol binario de búsqueda ABB

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



// mostrar el árbol completo

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



// buscar un nodo en el árbol

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



// recorrido de un árbol en PreOrden

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



// recorrido de un árbol en InOrden

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



// recorrido de un árbol en PostOrden

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



// eliminar un nodo del árbol - parte 2

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



// eliminar un nodo del árbol - parte 3

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



// eliminar un nodo del árbol - parte 4

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



// eliminar un nodo del árbol - parte 1

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