#include <iostream>
#include <string>
using namespace std;

// Estructura del nodo de la cola
struct NodoCola {
    int id;
    string nombre;
    int prioridad;
    NodoCola* siguiente;
};

// Punteros al frente y final de la cola
NodoCola* frente = NULL;
NodoCola* final_cola = NULL;

// Insertar elemento al final de la cola
void encolar(int id, string nombre, int prioridad) {
    NodoCola* nuevo = new NodoCola();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->prioridad = prioridad;
    nuevo->siguiente = NULL;
    if (frente == NULL) {
        frente = nuevo;
        final_cola = nuevo;
    } else {
        final_cola->siguiente = nuevo;
        final_cola = nuevo;
    }
    cout << "Proceso encolado correctamente." << endl;
}

// Eliminar primer elemento de la cola
void desencolar() {
    if (frente == NULL) {
        cout << "Cola vacia." << endl;
        return;
    }
    NodoCola* temp = frente;
    cout << "Proceso ejecutado: " << frente->nombre << endl;
    frente = frente->siguiente;
    if (frente == NULL) {
        final_cola = NULL;
    }
    delete temp;
}

// Mostrar primer elemento
void mostrarPrimero() {
    if (frente == NULL) {
        cout << "Cola vacia." << endl;
        return;
    }
    cout << "Primer proceso en cola: " << frente->nombre 
         << " | ID: " << frente->id 
         << " | Prioridad: " << frente->prioridad << endl;
}

// Verificar si la cola esta vacia
void verificarColaVacia() {
    if (frente == NULL)
        cout << "La cola esta vacia." << endl;
    else
        cout << "La cola tiene procesos en espera." << endl;
}

// Mostrar tamanio de la cola
void tamanioCol() {
    int count = 0;
    NodoCola* temp = frente;
    while (temp != NULL) {
        count++;
        temp = temp->siguiente;
    }
    cout << "Procesos en cola: " << count << endl;
}

// Imprimir todos los elementos de la cola
void mostrarCola() {
    if (frente == NULL) {
        cout << "Cola vacia." << endl;
        return;
    }
    NodoCola* temp = frente;
    cout << "\n--- Cola de Procesos (CPU) ---" << endl;
    while (temp != NULL) {
        cout << "ID: " << temp->id 
             << " | Nombre: " << temp->nombre 
             << " | Prioridad: " << temp->prioridad << endl;
        temp = temp->siguiente;
    }
}

// Eliminar todos los elementos
void eliminarTodosCola() {
    while (frente != NULL) {
        desencolar();
    }
    cout << "Cola vaciada completamente." << endl;
}

// Menu de la cola
void menuCola() {
    int opcion, id, prioridad;
    string nombre;
    do {
        cout << "\n=== PLANIFICADOR DE CPU (Cola) ===" << endl;
        cout << "1. Insertar proceso al final de la cola" << endl;
        cout << "2. Eliminar primer proceso (ejecutar)" << endl;
        cout << "3. Mostrar primer proceso" << endl;
        cout << "4. Verificar si cola esta vacia" << endl;
        cout << "5. Mostrar tamanio de la cola" << endl;
        cout << "6. Mostrar todos los procesos" << endl;
        cout << "7. Eliminar todos los procesos" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin >> nombre;
                cout << "Prioridad: "; cin >> prioridad;
                encolar(id, nombre, prioridad);
                break;
            case 2: desencolar(); break;
            case 3: mostrarPrimero(); break;
            case 4: verificarColaVacia(); break;
            case 5: tamanioCol(); break;
            case 6: mostrarCola(); break;
            case 7: eliminarTodosCola(); break;
            case 0: break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}
