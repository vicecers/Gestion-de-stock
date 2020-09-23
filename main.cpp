/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vicec
 *
 * Created on 16 de septiembre de 2020, 15:56
 */

#include <cstdlib>

using namespace std;
#include <iostream>

#define MAX 50
int codigo[MAX], cantidad[MAX], faltantes[MAX];
int stock_min = 100;
int cod, cant, pos;
void generaCodigo(int []); //funcion para generar codigos
void mostrarCodigo(int []);
void mostrarCantidad(int []);
void mostrarFaltantes(int []);
void generarCantidad(int []);
void verificarFaltantes(int []);

int main(int argc, char** argv) {

    int opc;

    generaCodigo(codigo);
    generarCantidad(cantidad);
    verificarFaltantes(cantidad);
   
    mostrarCantidad(cantidad);




    do {

        cout << "1- Entrada de mercaderia" << endl;
        cout << "2- Salida de mercaderia" << endl;
        cout << "3- Lista de mercaderia faltante" << endl;
        cout << "4- Salir del programa" << endl;

        cout << "Ingrese una opcion: ";
        cin>>opc;

        switch (opc) {
            case 1:
                cout << "Ingrese el codigo: ";
                cin >> cod;
                cout << "Ingrese la cantidad: ";
                cin >> cant;
                
                for (int i = 0; i < MAX; i++) {
                    if(codigo[i]==cod){
                        pos = i;
                        cantidad[pos]= cantidad[pos] + cant;
                        break;
                    }
                }
                             
                
                break;
            case 2:
                break;
            case 3:
                //mostrarFaltantes(faltantes);
                break;
        }

    } while (opc != 4);
 


 mostrarCantidad(cantidad);




return 0;
}

void generaCodigo(int codigo[]) {

    for (int i = 0; i < MAX; i++) {
        codigo[i] = 101 + i;
    }
}

void mostrarCodigo(int codigo[]) {

    for (int i = 0; i < MAX; i++) {
        cout << codigo[i] << endl;
    }
}

void generarCantidad(int cantidad[]) {
    for (int i = 0; i < MAX; i++) {
        cantidad[i] = 1 + rand() % 400;
    }
}

void mostrarCantidad(int codigo[]) {

    for (int i = 0; i < MAX; i++) {
        cout << "pos[" << i << "]  " << cantidad[i] << endl;
    }
}

void verificarFaltantes(int cantidad[]) {

    for (int i = 0; i < MAX; i++) {

        if (cantidad[i] >= stock_min) {

            faltantes[i] = 0;

        } else {

            faltantes[i] = stock_min - cantidad[i];
        }

    }

}

void mostrarFaltantes(int faltantes[]) {

    for (int i = 0; i < MAX; i++) {
        cout << faltantes[i] << endl;
    }
}