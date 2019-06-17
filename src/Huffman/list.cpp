#include "list.h"

// Constructor por defecto
List::List(){
    m_num_nodes = 0;
    m_head = NULL;
}

// Insertar al inicio
void List::add_head(int frecuency, string name) {
    ListNode *new_node = new ListNode(frecuency, name);
    ListNode *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}

void List::add_end(int frecuency, string name)
{
    ListNode *new_node = new ListNode (frecuency, name);
    ListNode *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    m_num_nodes++;
}

// Eliminar todos los nodos
void List::del_all(){
    m_head->delete_all();
    m_head = 0;
}

void List::del_by_data(string name)
{
    ListNode *temp = m_head;
    ListNode *temp1 = m_head->next;

    int cont = 0;

    if (m_head->name == name) {
        m_head = temp->next;
    } else {
        while (temp1) {
            if (temp1->name == name) {
                ListNode *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                cont++;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}

void List::del_first_two(ListNode *node) {
    ListNode *tempNode = m_head;
    m_head = m_head->next;
    tempNode = nullptr;
    delete tempNode;
    m_head->frecuency = node->frecuency;
    m_head->name = node->name;
    m_num_nodes--;
}


// Imprimir la Lista
void List::print(){
    ListNode *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
            temp = temp->next;
        }
    }
    cout << endl << endl;
}

// Buscar el dato de un nodo

bool List::search(string name){
    ListNode *temp = m_head;

    while (temp) {

//        cout << "(" << elementX << ", " << elementY << ")" << " -> ";
//        cout << "(" << temp->element->getX() << ", " << temp->element->getY() << ")" << endl;

        if (temp->name == name){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void List::sort()
{
    int tempFrecuency;
    string tempName;
    ListNode* tempRight;
    ListNode* tempLeft;

    ListNode *aux_node = m_head;
    ListNode *temp = aux_node;

    while (aux_node) {
        temp = aux_node;

        while (temp->next) {
            temp = temp->next;

            if (aux_node->frecuency > temp->frecuency) {

                tempFrecuency = aux_node->frecuency;
                tempName = aux_node->name;

                aux_node->frecuency = temp->frecuency;
                aux_node->name = temp->name;

                temp->frecuency = tempFrecuency;
                temp->name = tempName;
            }
        }

        aux_node = aux_node->next;
    }
}

int List::getM_num_nodes() const {
    return m_num_nodes;
}

string List::find(string letter){
    ListNode *tempNode = m_head;
    while(tempNode){
        if(tempNode->name == letter){
            return tempNode->numberRepresentation;
        }
        tempNode = tempNode->next;
    }
}
