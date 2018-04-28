#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
using namespace std;

#include "child.h"
#include "parent.h"

#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi first;
};

/** TIDAK PERLU MODIFIKASI */
void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi &P);
void deleteFirst_relasi(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter_relasi(List_relasi &L, address_relasi Prec, address_relasi &P);


/** PERLU MODIFIKASI */
address_relasi alokasi( address_parent P, address_child C);
void dealokasi(address_relasi &P);
address_relasi findElmRelasi(List_relasi L, address_parent P, address_child C);
void printInfo_childRelasi(List_relasi L);
address_relasi findElm_parent(List_relasi L, address_parent P);
address_relasi findElm_child(List_relasi L, address_child C);
void delete_relasi(List_relasi &L, address_relasi A, address_relasi &P);


#endif // RELASI_H_INCLUDED
