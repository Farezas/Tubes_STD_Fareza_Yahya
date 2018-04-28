/** Penyusun:
       Nama : Fareza Adityanto
       NIM  : 1301174228
       Kelas: IF 41-08
*/
#ifndef PRIMITIF_PENILAIAN_H_INCLUDED
#define PRIMITIF_PENILAIAN_H_INCLUDED

#include "relasi.h"
#include <stack>
#include <stdlib.h>


void insertParent(infotype_parent x);
void displayListParentOnly();
void insertChild(infotype_child x2,bool &c);
void displayListChildOnly();
void Connect(infotype_parent x, infotype_child x2);
void checkConnection(infotype_parent x, infotype_child x2);
void disconnect(infotype_parent x, infotype_child x2);
void printAll();
void printChildOfAParent(infotype_parent x);
void deleteChild(List_child &LC, List_relasi &LR, infotype_child x);
void deleteParent(infotype_parent x);
void cariDiChild_byName();
void cariDiChild_byID();
void cariDiParent_byID();
void StokLihat();


#endif // PRIMITIF_PENILAIAN_H_INCLUDED
