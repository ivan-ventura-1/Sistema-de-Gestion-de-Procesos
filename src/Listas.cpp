#include <iostream>
#include <string>
using namespace std;

// Estructura del nodo
struct Proceso {
    int id;
    string nombre;
    int prioridad;
    Proceso* siguiente;
};

// Puntero al inicio de la lista
Proceso* cabeza = NULL;

// Insertar al principio
void insertarAlPrincipio(int id, string nombre, int prioridad) {
    Proceso* nuevo = new Proceso();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->prioridad = prioridad;
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
    cout << "Proceso agregado al principio." << endl;
}

// Insertar al final
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

// Eliminar primer nodo
void eliminarPrimero() {
    if (cabeza == NULL) {
        cout << "Lista vacia." << endl;
        return;
    }
    Proceso* temp = cabeza;
    cabeza = cabeza->siguiente;
    delete temp;
    cout << "Primer proceso eliminado." << endl;
}

// Eliminar ultimo nodo
void eliminarUltimo() {
    if (cabeza == NULL) {
        cout << "Lista vacia." << endl;
        return;
    }
    if (cabeza->siguiente == NULL) {
        delete cabeza;
        cabeza = NULL;
        cout << "Proceso eliminado." << endl;
        return;
    }
    Proceso* temp = cabeza;
    while (temp->siguiente->siguiente != NULL) {
        temp = temp->siguiente;
    }
    delete temp->siguiente;
    temp->siguiente = NULL;
    cout << "Ultimo proceso eliminado." << endl;
}

// Eliminar nodo especifico por ID
void eliminarPorID(int id) {
    if (cabeza == NULL) {
        cout << "Lista vacia." << endl;
        return;
    }
    if (cabeza->id == id) {
        eliminarPrimero();
        return;
    }
    Proceso* temp = cabeza;
    while (temp->siguiente != NULL && temp->siguiente->id != id) {
        temp = temp->siguiente;
    }
    if (temp->siguiente == NULL) {
        cout << "Proceso no encontrado." << endl;
        return;
    }
    Proceso* aEliminar = temp->siguiente;
    temp->siguiente = aEliminar->siguiente;
    delete aEliminar;
    cout << "Proceso eliminado." << endl;
}

// Buscar nodo por ID
void buscarPorID(int id) {
    Proceso* temp = cabeza;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Proceso encontrado: " << temp->nombre 
                 << " | Prioridad: " << temp->prioridad << endl;
            return;
        }
        temp = temp->siguiente;
    }
    cout << "Proceso no encontrado." << endl;
}

// Verificar si lista esta vacia
void verificarVacia() {
    if (cabeza == NULL)
        cout << "La lista esta vacia." << endl;
    else
        cout << "La lista tiene procesos." << endl;
}

// Eliminar todos los nodos
void eliminarTodos() {
    while (cabeza != NULL) {
        eliminarPrimero();
    }
    cout << "Todos los procesos eliminados." << endl;
}

// Mostrar todos los nodos
void mostrarLista() {
    if (cabeza == NULL) {
        cout << "Lista vacia." << endl;
        return;
    }
    Proceso* temp = cabeza;
    cout << "\n--- Lista de Procesos ---" << endl;
    while (temp != NULL) {
        cout << "ID: " << temp->id 
             << " | Nombre: " << temp->nombre 
             << " | Prioridad: " << temp->prioridad << endl;
        temp = temp->siguiente;
    }
}

// Menu de la lista
void menuLista() {
    int opcion, id, prioridad;
    string nombre;
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
        cout << "0. Volver al menu principal" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin >> nombre;
                cout << "Prioridad: "; cin >> prioridad;
                insertarAlPrincipio(id, nombre, prioridad);
                break;
            case 2:
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin >> nombre;
                cout << "Prioridad: "; cin >> prioridad;
                insertarAlFinal(id, nombre, prioridad);
                break;
            case 3: eliminarPrimero(); break;
            case 4: eliminarUltimo(); break;
            case 5:
                cout << "ID a eliminar: "; cin >> id;
                eliminarPorID(id);
                break;
            case 6:
                cout << "ID a buscar: "; cin >> id;
                buscarPorID(id);
                break;
            case 7: verificarVacia(); break;
            case 8: eliminarTodos(); break;
            case 9: mostrarLista(); break;
            case 0: break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}
