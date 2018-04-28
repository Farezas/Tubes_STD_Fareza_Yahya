#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>
  /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */

using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev

struct infotype_child {
    unsigned int id_brg;
    string nama_brg;
    unsigned int stok;
};
typedef struct elmlist_child *address_child;

struct elmlist_child {
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_child {
    address_child first;
    address_child last;
};



void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertAfter(List_child &L, address_child Prec, address_child P);
void insertLast(List_child &L, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(List_child &L, address_child Prec, address_child &P);
address_child alokasi(infotype_child x);
void dealokasi(address_child &P);
address_child findElmByName(List_child L, infotype_child x);
address_child findElmById(List_child L, infotype_child x);
void delete_child(List_child &L, address_child A, address_child &P);

#endif // CHILD_H_INCLUDED
