#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
//KATEGORI
#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

/** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */

struct infotype_parent{
    string kategori;
    unsigned int id_kategori;
};

typedef struct elmlist_parent *address_parent;

struct elmlist_parent{
    infotype_parent info;
    address_parent next;
};

struct List_parent{
    address_parent first;
};

void createList(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(address_parent Prec, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);
address_parent alokasi(infotype_parent x);
void printInfoParent(List_parent L);
address_parent findElmParent_byID(List_parent L, infotype_parent x);
address_parent findElmParent_byName(List_parent L, infotype_parent x);
void delete_parent(List_parent L, address_parent A, address_parent P);

#endif // PARENT_H_INCLUDED
