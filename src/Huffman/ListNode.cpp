#include "ListNode.h"

ListNode::ListNode(int frecuency, string name) {
    this->frecuency = frecuency;
    this->name = name;
    numberRepresentation = "";
}

// Eliminar todos los Nodos
void ListNode::delete_all(){
    if (next)
        next->delete_all();
    name = "";
    frecuency = 0;
    delete this;
}

// Imprimir un Nodo
void ListNode::print(){
    //cout << "ListNode-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << "Name: " << name << ", Frecuency: " << frecuency << endl;
}
