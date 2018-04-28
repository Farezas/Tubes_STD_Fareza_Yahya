#include "child.h"
#include <iostream>

using namespace std;
//NAMA BARANG
void createList(List_child &L){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    first(L) = NULL;
    last(L) = NULL;

}
address_child alokasi(infotype_child x){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    address_child P;
    P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void dealokasi(address_child &P){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    delete P;
}
address_child findElmByName(List_child L, infotype_child x){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    address_child P = first(L);
    do {
        if(info(P).nama_brg == x.nama_brg) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
address_child findElmById(List_child L, infotype_child x){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    address_child P = first(L);
    do {
        if(info(P).id_brg == x.id_brg) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}


void insertFirst(List_child &L, address_child P){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L))=P;
        next(last(L)) = P;
        prev(P) = last(L);
        first(L) = P;
    }
}
void insertAfter(List_child &L, address_child Prec, address_child P){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    if(Prec==NULL){
        return;
    }else{
        next(P)=next(Prec);
        prev(next(P))=P;
        next(Prec)=P;
        prev(P)=Prec;
    }
}
void insertLast(List_child &L, address_child P){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    if(first(L)==NULL){
        first(L)=P;
        last(L)=P;
        next(P)=P;
        prev(P)=P;
    }else{
        next(P)=first(L);
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
        prev(first(L))=last(L);
    }
}
void deleteFirst(List_child &L, address_child &P){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    if(first(L)==NULL){
        cout<<"list kosong"<<endl;
    }else{
        if(next(first(L))==first(L)){
            P=first(L);
            next(P)=NULL;
            prev(P)=NULL;
            first(L)=NULL;
            last(L)=NULL;
        }else{
            P=first(L);
            next(last(L))=next(P);
            prev(next(P))=last(L);
            first(L)=next(P);
            prev(P)=NULL;
            next(P)=NULL;
        }
    }
}
void deleteLast(List_child &L, address_child &P){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    if(last(L)==NULL){
        cout<<"list kosong"<<endl;
    }else{
        if(next(first(L))==first(L)){
            P=first(L);
            next(P)=NULL;
            prev(P)=NULL;
            first(L)=NULL;
            last(L)=NULL;
        }else{
            P=last(L);
            next(prev(P))=first(L);
            prev(first(L))=prev(P);
            last(L)=prev(P);
            prev(P)=NULL;
            next(P)=NULL;
        }
    }
}
void deleteAfter(List_child &L, address_child Prec, address_child &P){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    if(Prec!=NULL){
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        prev(P) = NULL;
        next(P) = NULL;
    }return;
}
void delete_child(List_child &L, address_child A, address_child &P){
      /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    if (A == first(L)){
        deleteFirst(L, P);
    }
    else if (A == last(L)){
        deleteLast(L, P);
    }
    else {
        deleteAfter(L, A, P);
    }
}
