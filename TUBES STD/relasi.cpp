#include "relasi.h"

void createList(List_relasi &L) {
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    first(L) = NULL;
}

void dealokasi(address_relasi &P){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    delete P;
}

address_relasi alokasi(address_parent P, address_child C) {
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}

void insertFirst(List_relasi &L, address_relasi P) {
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    next(P) = first(L);
    first(L) = P;
}

void printInfo_childRelasi(List_relasi L) {
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<info(child(P)).nama_brg<<"->"<<info(parent(P)).kategori<<endl;
        P = next(P);
    }
}

address_relasi findElmRelasi(List_relasi L, address_parent P, address_child C) {
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(parent(Q)==P && child(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

address_relasi findElm_child(List_relasi L, address_child C) {
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(child(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

address_relasi findElm_parent(List_relasi L, address_parent P) {
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(parent(Q)== P) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void insertAfter(address_relasi Prec, address_relasi &P) {
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteAfter_relasi(List_relasi &L, address_relasi Prec,address_relasi &P){
    /** Penyusun:
       Nama : Fareza Adityanto
       NIM  : 1301174228
       Kelas: IF 41-08
    */
    /**next(Prec)=next(P);
    next(P)=NULL; */
    if(Prec!=NULL){
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }return;
}

void deleteFirst_relasi(List_relasi &L, address_relasi &P){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
     if(first(L)==NULL){
        return;
    }else{
        if(next(first(L))==NULL){
            P=first(L);
            first(L)=NULL;
        }else{
            P=first(L);
            first(L)=next(P);
            next(P)=NULL;
        }
    }
}
void delete_relasi(List_relasi &L, address_relasi A, address_relasi &P){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    if (A == first(L)){
        deleteFirst_relasi(L, P);
    }
    else {
        deleteAfter_relasi(L,A,P);
    }
}
