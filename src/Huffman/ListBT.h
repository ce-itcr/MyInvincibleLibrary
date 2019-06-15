#ifndef  LISTBT_H
#define  LISTBT_H

#include "ListNode.h"

class ListBT {
public:
    ListBT();

    void add_head(int frecuency, string name);
    void add_end(int frecuency, string name);
    void del_all();
    void del_by_data(string name);
    void del_first_two(ListNode *node);
    void print();
    bool search(string name);
    void sort();
    string find(string letter);
    ListNode *m_head;

private:
    int m_num_nodes;
public:
    int getM_num_nodes() const;
};


#endif // LISTBT_H
