#include <iostream>
#include <string>
using namespace std;

// ==================== LISTA ENLAZADA ====================
struct Proceso {
    int id;
    string nombre;
    int prioridad;
    Proceso* siguiente;
};

Proceso* cabeza = NULL;

void insertarAlPrincipio(int id, string nombre, int prioridad) {
    Proceso* nuevo = new Proceso();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->prioridad = prioridad;
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
    cout << "Proceso agregado al principio." << endl;
}

void insertarAlFinal(int id, string nombre, int prioridad) {
    Proceso* nuevo = new Proceso();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->prioridad = prioridad;
    nuevo->siguiente = NULL;
    if (cabeza == NULL) {
        cabeza = nuevo;
    } else {
        Proceso* temp = cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
    cout << "Proceso agregado al final." << endl;
}

void eliminarPrimero() {
    if (cabeza == NULL) { cout << "Lista vacia." << endl; return; }
    Proceso* temp = cabeza;
    cabeza = cabeza->siguiente;
    delete temp;
    cout << "Primer proceso eliminado." << endl;
}

void eliminarUltimo() {
    if (cabeza == NULL) { cout << "Lista vacia." << endl; return; }
    if (cabeza->siguiente == NULL) {
        delete cabeza; cabeza = NULL;
        cout << "Proceso eliminado." << endl; return;
    }
    Proceso* temp = cabeza;
    while (temp->siguiente->siguiente != NULL)
        temp = temp->siguiente;
    delete temp->siguiente;
    temp->siguiente = NULL;
    cout << "Ultimo proceso eliminado." << endl;
}

void eliminarPorID(int id) {
    if (cabeza == NULL) { cout << "Lista vacia." << endl; return; }
    if (cabeza->id == id) { eliminarPrimero(); return; }
    Proceso* temp = cabeza;
    while (temp->siguiente != NULL && temp->siguiente->id != id)
        temp = temp->siguiente;
    if (temp->siguiente == NULL) { cout << "Proceso no encontrado." << endl; return; }
    Proceso* aEliminar = temp->siguiente;
    temp->siguiente = aEliminar->siguiente;
    delete aEliminar;
    cout << "Proceso eliminado." << endl;
}

void buscarPorID(int id) {
    Proceso* temp = cabeza;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Encontrado: " << temp->nombre << " | Prioridad: " << temp->prioridad << endl;
            return;
        }
        temp = temp->siguiente;
    }
    cout << "Proceso no encontrado." << endl;
}

void verificarVacia() {
    if (cabeza == NULL) cout << "La lista esta vacia." << endl;
    else cout << "La lista tiene procesos." << endl;
}

void eliminarTodos() {
    while (cabeza != NULL) eliminarPrimero();
    cout << "Todos los procesos eliminados." << endl;
}

void mostrarLista() {
    if (cabeza == NULL) { cout << "Lista vacia." << endl; return; }
    Proceso* temp = cabeza;
    cout << "\n--- Lista de Procesos ---" << endl;
    while (temp != NULL) {
        cout << "ID: " << temp->id << " | Nombre: " << temp->nombre << " | Prioridad: " << temp->prioridad << endl;
        temp = temp->siguiente;
    }
}

void menuLista() {
    int opcion, id, prioridad; string nombre;
    do {
        cout << "\n=== GESTOR DE PROCESOS (Lista Enlazada) ===" << endl;
        cout << "1. Insertar al principio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Eliminar primer nodo" << endl;
        cout << "4. Eliminar ultimo nodo" << endl;
        cout << "5. Eliminar nodo especifico" << endl;
        cout << "6. Buscar proceso por ID" << endl;
        cout << "7. Verificar si lista esta vacia" << endl;
        cout << "8. Eliminar todos los procesos" << endl;
        cout << "9. Mostrar todos los procesos" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: "; cin >> opcion;
        switch(opcion) {
            case 1: cout << "ID: "; cin >> id; cout << "Nombre: "; cin >> nombre; cout << "Prioridad: "; cin >> prioridad; insertarAlPrincipio(id, nombre, prioridad); break;
            case 2: cout << "ID: "; cin >> id; cout << "Nombre: "; cin >> nombre; cout << "Prioridad: "; cin >> prioridad; insertarAlFinal(id, nombre, prioridad); break;
            case 3: eliminarPrimero(); break;
            case 4: eliminarUltimo(); break;
            case 5: cout << "ID a eliminar: "; cin >> id; eliminarPorID(id); break;
            case 6: cout << "ID a buscar: "; cin >> id; buscarPorID(id); break;
            case 7: verificarVacia(); break;
            case 8: eliminarTodos(); break;
            case 9: mostrarLista(); break;
            case 0: break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}

// ==================== COLA ====================
struct NodoCola {
    int id;
    string nombre;
    int prioridad;
    NodoCola* siguiente;
};

NodoCola* frente = NULL;
NodoCola* final_cola = NULL;

void encolar(int id, string nombre, int prioridad) {
    NodoCola* nuevo = new NodoCola();
    nuevo->id = id; nuevo->nombre = nombre; nuevo->prioridad = prioridad; nuevo->siguiente = NULL;
    if (frente == NULL) { frente = nuevo; final_cola = nuevo; }
    else { final_cola->siguiente = nuevo; final_cola = nuevo; }
    cout << "Proceso encolado correctamente." << endl;
}

void desencolar() {
    if (frente == NULL) { cout << "Cola vacia." << endl; return; }
    NodoCola* temp = frente;
    cout << "Proceso ejecutado: " << frente->nombre << endl;
    frente = frente->siguiente;
    if (frente == NULL) final_cola = NULL;
    delete temp;
}

void mostrarPrimero() {
    if (frente == NULL) { cout << "Cola vacia." << endl; return; }
    cout << "Primer proceso: " << frente->nombre << " | ID: " << frente->id << " | Prioridad: " << frente->prioridad << endl;
}

void verificarColaVacia() {
    if (frente == NULL) cout << "La cola esta vacia." << endl;
    else cout << "La cola tiene procesos en espera." << endl;
}

void tamanioCola() {
    int count = 0;
    NodoCola* temp = frente;
    while (temp != NULL) { count++; temp = temp->siguiente; }
    cout << "Procesos en cola: " << count << endl;
}

void mostrarCola() {
    if (frente == NULL) { cout << "Cola vacia." << endl; return; }
    NodoCola* temp = frente;
    cout << "\n--- Cola de Procesos (CPU) ---" << endl;
    while (temp != NULL) {
        cout << "ID: " << temp->id << " | Nombre: " << temp->nombre << " | Prioridad: " << temp->prioridad << endl;
        temp = temp->siguiente;
    }
}

void eliminarTodosCola() {
    while (frente != NULL) desencolar();
    cout << "Cola vaciada completamente." << endl;
}

void menuCola() {
    int opcion, id, prioridad; string nombre;
    do {
        cout << "\n=== PLANIFICADOR DE CPU (Cola) ===" << endl;
        cout << "1. Insertar proceso al final" << endl;
        cout << "2. Eliminar primer proceso (ejecutar)" << endl;
        cout << "3. Mostrar primer proceso" << endl;
        cout << "4. Verificar si cola esta vacia" << endl;
        cout << "5. Mostrar tamanio de la cola" << endl;
        cout << "6. Mostrar todos los procesos" << endl;
        cout << "7. Eliminar todos los procesos" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: "; cin >> opcion;
        switch(opcion) {
            case 1: cout << "ID: "; cin >> id; cout << "Nombre: "; cin >> nombre; cout << "Prioridad: "; cin >> prioridad; encolar(id, nombre, prioridad); break;
            case 2: desencolar(); break;
            case 3: mostrarPrimero(); break;
            case 4: verificarColaVacia(); break;
            case 5: tamanioCola(); break;
            case 6: mostrarCola(); break;
            case 7: eliminarTodosCola(); break;
            case 0: break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}

// ==================== PILA ====================
struct NodoPila {
    int id;
    string nombre;
    int memoria;
    NodoPila* siguiente;
};

NodoPila* tope = NULL;

void push(int id, string nombre, int memoria) {
    NodoPila* nuevo = new NodoPila();
    nuevo->id = id; nuevo->nombre = nombre; nuevo->memoria = memoria;
    nuevo->siguiente = tope;
    tope = nuevo;
    cout << "Bloque de memoria asignado correctamente." << endl;
}

void pop() {
    if (tope == NULL) { cout << "Pila vacia." << endl; return; }
    NodoPila* temp = tope;
    cout << "Memoria liberada: " << tope->nombre << " | " << tope->memoria << " MB" << endl;
    tope = tope->siguiente;
    delete temp;
}

void verTope() {
    if (tope == NULL) { cout << "Pila vacia." << endl; return; }
    cout << "Tope: " << tope->nombre << " | ID: " << tope->id << " | Memoria: " << tope->memoria << " MB" << endl;
}

void verificarPilaVacia() {
    if (tope == NULL) cout << "La pila esta vacia." << endl;
    else cout << "La pila tiene bloques asignados." << endl;
}

void tamanioPila() {
    int count = 0;
    NodoPila* temp = tope;
    while (temp != NULL) { count++; temp = temp->siguiente; }
    cout << "Bloques de memoria asignados: " << count << endl;
}

void mostrarPila() {
    if (tope == NULL) { cout << "Pila vacia." << endl; return; }
    NodoPila* temp = tope;
    cout << "\n--- Gestor de Memoria (Pila) ---" << endl;
    while (temp != NULL) {
        cout << "ID: " << temp->id << " | Proceso: " << temp->nombre << " | Memoria: " << temp->memoria << " MB" << endl;
        temp = temp->siguiente;
    }
}

void eliminarTodosPila() {
    while (tope != NULL) pop();
    cout << "Toda la memoria ha sido liberada." << endl;
}

void menuPila() {
    int opcion, id, memoria; string nombre;
    do {
        cout << "\n=== GESTOR DE MEMORIA (Pila) ===" << endl;
        cout << "1. Asignar bloque de memoria (push)" << endl;
        cout << "2. Liberar bloque de memoria (pop)" << endl;
        cout << "3. Ver elemento superior" << endl;
        cout << "4. Verificar si pila esta vacia" << endl;
        cout << "5. Mostrar tamanio de la pila" << endl;
        cout << "6. Mostrar todos los bloques" << endl;
        cout << "7. Liberar toda la memoria" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: "; cin >> opcion;
        switch(opcion) {
            case 1: cout << "ID: "; cin >> id; cout << "Nombre: "; cin >> nombre; cout << "Memoria (MB): "; cin >> memoria; push(id, nombre, memoria); break;
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

// ==================== MENU PRINCIPAL ====================
int main() {
    int opcion;
    do {
        cout << "\n========================================" << endl;
        cout << "   SISTEMA DE GESTION DE PROCESOS" << endl;
        cout << "========================================" << endl;
        cout << "1. Gestor de Procesos (Lista Enlazada)" << endl;
        cout << "2. Planificador de CPU (Cola)" << endl;
        cout << "3. Gestor de Memoria (Pila)" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: "; cin >> opcion;
        switch(opcion) {
            case 1: menuLista(); break;
            case 2: menuCola(); break;
            case 3: menuPila(); break;
            case 0: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
    return 0;
}
