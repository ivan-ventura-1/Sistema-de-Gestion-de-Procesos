#include <iostream>
#include <string>
using namespace std;

// Estructura del nodo de la pila
struct NodoPila {
    int id;
    string nombre;
    int memoria; // tamanio del bloque en MB
    NodoPila* siguiente;
};

// Puntero al tope de la pila
NodoPila* tope = NULL;

// Insertar elemento en la parte superior (push)
void push(int id, string nombre, int memoria) {
    NodoPila* nuevo = new NodoPila();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->memoria = memoria;
    nuevo->siguiente = tope;
    tope = nuevo;
    cout << "Bloque de memoria asignado correctamente." << endl;
}

// Eliminar elemento de la parte superior (pop)
void pop() {
    if (tope == NULL) {
        cout << "Pila vacia. No hay memoria asignada." << endl;
        return;
    }
    NodoPila* temp = tope;
    cout << "Memoria liberada: " << tope->nombre 
         << " | " << tope->memoria << " MB" << endl;
    tope = tope->siguiente;
    delete temp;
}

// Ver elemento superior
void verTope() {
    if (tope == NULL) {
        cout << "Pila vacia." << endl;
        return;
    }
    cout << "Elemento en tope: " << tope->nombre 
         << " | ID: " << tope->id 
         << " | Memoria: " << tope->memoria << " MB" << endl;
}

// Verificar si la pila esta vacia
void verificarPilaVacia() {
    if (tope == NULL)
        cout << "La pila esta vacia." << endl;
    else
        cout << "La pila tiene bloques de memoria asignados." << endl;
}

// Mostrar tamanio de la pila
void tamanioPila() {
    int count = 0;
    NodoPila* temp = tope;
    while (temp != NULL) {
        count++;
        temp = temp->siguiente;
    }
    cout << "Bloques de memoria asignados: " << count << endl;
}

// Mostrar todos los elementos
void mostrarPila() {
    if (tope == NULL) {
        cout << "Pila vacia." << endl;
        return;
    }
    NodoPila* temp = tope;
    cout << "\n--- Gestor de Memoria (Pila) ---" << endl;
    while (temp != NULL) {
        cout << "ID: " << temp->id 
             << " | Proceso: " << temp->nombre 
             << " | Memoria: " << temp->memoria << " MB" << endl;
        temp = temp->siguiente;
    }
}

// Eliminar todos los elementos
void eliminarTodosPila() {
    while (tope != NULL) {
        pop();
    }
    cout << "Toda la memoria ha sido liberada." << endl;
}

// Menu de la pila
void menuPila() {
    int opcion, id, memoria;
    string nombre;
    do {
        cout << "\n=== GESTOR DE MEMORIA (Pila) ===" << endl;
        cout << "1. Asignar bloque de memoria (push)" << endl;
        cout << "2. Liberar bloque de memoria (pop)" << endl;
        cout << "3. Ver elemento superior" << endl;
        cout << "4. Verificar si pila esta vacia" << endl;
        cout << "5. Mostrar tamanio de la pila" << endl;
        cout << "6. Mostrar todos los bloques" << endl;
        cout << "7. Liberar toda la memoria" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Nombre del proceso: "; cin >> nombre;
                cout << "Memoria a asignar (MB): "; cin >> memoria;
                push(id, nombre, memoria);
                break;
            case 2: pop(); break;
            case 3: verTope(); break;
            case 4: verificarPilaVacia(); break;
            case 5: tamanioPila(); break;
            case 6: mostrarPila(); break;
            case 7: eliminarTodosPila(); break;
            case 0: break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}
