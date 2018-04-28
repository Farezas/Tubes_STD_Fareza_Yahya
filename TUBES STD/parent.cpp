#include "parent.h"
//  KATEGORI

void createList(List_parent &L){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    first(L) = NULL;
}
address_parent alokasi(infotype_parent x) {
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    address_parent P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    return P;
}
void printInfoParent(List_parent L) {
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    if(first(L)==NULL){
        cout<<"list kategori kosong"<<endl;
        return;
    }
    address_parent P = first(L);
    int i=1;
    while(P !=NULL) {
        cout<<i<<". id = "<<info(P).id_kategori<<endl;
        cout<<"    nama kategori = "<<info(P).kategori<<endl;
        cout<<"--------------------------------------"<<endl;
        P = next(P);
        i++;
    }
}
address_parent findElmParent_byName(List_parent L, infotype_parent x) {
    /** Penyusun:
       Nama : Fareza Adityanto
       NIM  : 1301174228
       Kelas: IF 41-08
    */
    address_parent P = first(L);
    while(P != NULL) {
        if(info(P).kategori==x.kategori) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

address_parent findElmParent_byID(List_parent L, infotype_parent x) {
    /** Penyusun:
       Nama : Fareza Adityanto
       NIM  : 1301174228
       Kelas: IF 41-08
    */
    address_parent P = first(L);
    while(P != NULL) {
        if(info(P).id_kategori==x.id_kategori) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertFirst(List_parent &L, address_parent P){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    if(first(L) == NULL) {
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(address_parent Prec, address_parent P){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    next(P) = next(Prec);
    next(Prec) = P;
}
void deleteFirst(List_parent &L, address_parent &P){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
        if(first(L)==NULL){
        return;
    }else if(next(first(L))==NULL){
        P=first(L);
        first(L)=NULL;
    }else{
        P=first(L);
        first(L)=next(P);
        next(P)=NULL;
    }
}
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    if(Prec!=NULL){
      P=next(Prec);
      next(Prec)=next(P);
      next(P)=NULL;
    }return;
}
void delete_parent(List_parent L, address_parent A, address_parent P){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    if(A == first(L)){
        deleteFirst(L, P);
    }
    else{
        deleteAfter(L, A, P);
    }
}
