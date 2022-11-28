#include<iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
using namespace std;

void main(), agregar(), modificar(), eliminar(), menu(), leer();
struct vg {
	int id;
	string nombre;
	int anio;
	string clas; // clasificacion
	string genero;
	string caract;// caracteristicas
	string desc; //descripcion
	int precio;
	float piva;// precio con IVA

}juego[10];

bool loopmenu = true,otherG=true; // otherG=otro juego
char op;
string ler, write;
ofstream archivo;

void main() {
	while (loopmenu == true) {
		system("cls");
		cout << " Bienvenidos a FCFM games mejores juegos \n ";
		archivo.open("base de datos.txt", ios::in);
		if (!archivo.fail()) {
			cout << " No se pudo abrir el archivo\n";
			archivo.open("base de datos.txt", ios::out);
			system("pause");			
			
		}
		else {
			menu();// menu de seleccion
			system("cls");
		}
	}
	system("cls");
	cout << " Gracias por usar FCFM games, vuelva pronto\n ";
	system("pause");
}

void menu() {
	while (loopmenu == true) {
		system("color 0b");
		cout << " Escoja la opcion que desea hacer.\n ";
		cout << " 1.- Para agregar un juego nuevo \n ";
		cout << " 2.- Para modificar los datos de un juego \n ";
		cout << " 3.- Para eliminar un articulo \n ";
		cout << " 4.- Para ver juegos existentes \n ";
		cout << " 5.- Para limpiar la pantalla \n ";
		cout << " 6.- Para salir \n\n ";
		cin >> op;
		switch (op) {
		case '1': {agregar(); break; }
		case '2': {modificar();  break; }
		case '3': {eliminar(); break; }
		case '4': {leer();  break; }
		case '5': {system("cls"); break; }
		case '6': {loopmenu = false; break; archivo.close(); }
		default:{cout << "Opcion no valida. Presione para continuar e intente nuevamente \n "; 
		}
		system("pause>nul");
		}
		system("cls");
	}

}

void agregar() {
		system("cls");
		system("color 0a");
		archivo.open("base de datos.txt", ios::out);
		for (int i = 0; i < 1; i++) {
			juego[i].id++;
			cout << " Ingrese el nombre de su juego:  "; cin.ignore();  getline(cin, juego[i].nombre);
			cout << "\n Introduzca el anio de lanzamiento del juego:  "; cin >> (cin, juego[i].anio);
			cout << "\n Introduzca la clasificacion del juego:  "; cin.ignore(); getline(cin, juego[i].clas);
			cout << "\n Introduzca el genero principal de su juego:  "; cin.ignore();  getline(cin, juego[i].genero);
			cout << "\n Introduzca algunas caracteristicas de su juego separadas por espacios: "; cin.ignore();  getline(cin, juego[i].caract);
			cout << "\n Escriba una breve descripcion de su juego \n "; cin.ignore(); getline(cin, juego[i].desc);
			cout << "\n Establezca un precio a su juego en peso mexicano.    NO INCLUYE IVA "; cin >> juego[i].precio;
			juego[i].piva = juego[i].precio * 1.16;
			cout << "\n  Precio: " << "$ " << juego[i].piva << endl;
			system("cls");
		}
		for (int i = 0; i < 1; i++) {
			archivo << "  " << juego[i].id << endl;
			archivo << "\tNombre: " << juego[i].nombre << "       ";
			archivo << juego[i].anio << endl;
			archivo << "\tClasificaion: " << juego[i].clas << "       ";
			archivo << juego[i].genero << endl;
			archivo << "\tCaracteristicas: " << juego[i].caract << endl;
			archivo << "\t" << juego[i].desc << endl;
			archivo << "\tPrecio: " << juego[i].piva << endl;
		}
		
		
}
void modificar() {
	

}
void eliminar() {
	cout << "4";
	system("pause");
}

void leer() {
	ifstream read;
	system("cls");
	read.open("base de datos.txt", ios::in);
	while (!read.eof()) {
		getline(read, ler);
		cout << ler << endl;
	}
	system("pause");
	system("cls");
	
}
