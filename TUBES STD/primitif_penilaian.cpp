#include "primitif_penilaian.h"
List_parent LP;
List_child LC;
List_relasi LR;
stack <int> SP;
stack <int> SC;
int id_ktg=2200;
int id_brg2=1000;

void insertParent(infotype_parent x){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    //kategori barang
    address_parent a;
    string nama_kategori;

    if(first(LP)==NULL){                        //list parent kosong
        id_ktg=id_ktg-110;
        x.id_kategori=id_ktg;
        address_parent P=alokasi(x);
        insertFirst(LP,P);
        cout<<"Kategori berhasil ditambahkan!!"<<endl;
    }else{                                      //list parent tidak kosong
        if(SP.empty()){
            a=findElmParent_byName(LP,x);
            if(a==NULL&&id_ktg>0){                            //tidak ada duplikasi
                id_ktg=id_ktg-110;
                x.id_kategori=id_ktg;
                address_parent P=alokasi(x);
                insertFirst(LP,P);
                cout<<"Kategori berhasil ditambahkan!!"<<endl;
            }else{
                cout<<"Maaf kategori sudah ada atau sudah penuh"<<endl;
                return;
            }
        }else{
            a=findElmParent_byName(LP,x);
            if(a==NULL&&id_ktg>0){                            //tidak ada duplikasi
                x.id_kategori=SP.top();
                SP.pop();
                address_parent P=alokasi(x);
                insertFirst(LP,P);
                cout<<"Kategori berhasil ditambahkan!!"<<endl;
            }else{
                cout<<"Maaf kategori sudah ada atau sudah penuh"<<endl;
                return;
            }
        }
    }
}

void displayListParentOnly(){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    printInfoParent(LP);
}

void insertChild(infotype_child x2, bool &c){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    //child = nama barang
    address_child a;

    if(first(LC)==NULL){
        id_brg2=id_brg2-1;
        x2.id_brg=id_brg2;
        address_child P=alokasi(x2);
        insertFirst(LC,P);
    }else{
        if(SP.empty()){
            a=findElmByName(LC,x2);
            if(a==NULL){
                id_brg2=id_brg2-1;
                x2.id_brg=id_brg2;
                address_child P=alokasi(x2);
                insertFirst(LC,P);
            }else{
                cout<<"Maaf, barang sudah ada"<<endl;
                c=false;
                return;
            }
        }else{
            a=findElmByName(LC,x2);
            if(a==NULL){
                x2.id_brg=SC.top();
                SC.pop();
                address_child P=alokasi(x2);
                insertFirst(LC,P);
            }else{
                cout<<"Maaf, barang sudah ada"<<endl;
                c=false;
                return;
            }
        }
    }c=true;
    cout<<"Barang sudah ditambahkan!!"<<endl;
}

void displayListChildOnly(){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    if(first(LC)==NULL){
        cout<<"list barang kosong"<<endl;
        return;
    }
    address_child P=first(LC);
    int i=1;
    do{
        cout<<i<<". ID barang = "<<info(P).id_brg<<endl;
        cout<<"   Nama barang = "<<info(P).nama_brg<<endl;
        cout<<"   Stok barang = "<<info(P).stok<<endl;
        cout<<"---------------------------------------------"<<endl;
        P=next(P);
        i++;
    }while(P!=first(LC));
}

void Connect(infotype_parent x, infotype_child x2){
   /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    address_parent a;
    address_child b;
    address_relasi c,d;

    if(first(LP)!=NULL&&first(LC)!=NULL){
        a=findElmParent_byID(LP,x);
        b=findElmById(LC,x2);
        if(a!=NULL&&b!=NULL){
            d=findElm_child(LR,b);
            if(d==NULL){
                c=alokasi(a,b);
                insertFirst(LR,c);
                cout<<"barang berhasil dimasukkan ke list relasi!!"<<endl;
            }else{
                cout<<endl<<endl<<endl<<endl<<endl;
                cout<<"\t\t\t\t\t\tduplikat"<<endl;
            }
        }else{
            cout<<"barang atau kategori tidak ditemukan"<<endl;
        }
    }else{cout<<"List kategori atau list barang kosong"<<endl;}
}

void checkConnection(infotype_parent x, infotype_child x2){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    address_parent a;
    address_child b;
    address_relasi c;

    if(first(LP)!=NULL&&first(LC)!=NULL){
        a=findElmParent_byID(LP,x);
        b=findElmById(LC,x2);
        if(a!=NULL&&b!=NULL){
            c=findElmRelasi(LR,a,b);
            if(c!=NULL){
                if(parent(c)==a&&child(c)==b){
                    cout<<"ID Kategori : "<<info(parent(c)).id_kategori<<endl;
                    cout<<"Nama Kategori : "<<info(parent(c)).kategori<<endl;
                    cout<<"ID Barang : "<<info(child(c)).id_brg<<endl;
                    cout<<"Nama Barang : "<<info(child(c)).nama_brg<<endl;
                    return;
                }cout<<"Tidak berhasil ditemukan"<<endl;
            }else{
                cout<<"Tidak berhasil ditemukan"<<endl;
            }
        }else{cout<<"list kosong"<<endl;}
    }else{cout<<"List kategori atau list barang kosong"<<endl;}
}

void disconnect(infotype_parent x, infotype_child x2){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    address_parent a;
    address_child b;
    address_relasi c,P;

        a=findElmParent_byID(LP,x);
        b=findElmById(LC,x2);
        if(a!=NULL&&b!=NULL){
            c=findElmRelasi(LR,a,b);
            if(c!=NULL){
                delete_relasi(LR, c, P);
                cout<<"berhasil dihapus!!"<<endl;
            }else{
                cout<<"elemen relasi tidak ditemukan"<<endl;
            }
        }else{cout<<"kategori atau barang tidak ditemukan"<<endl;}
}

void printAll(){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    address_parent P;
    address_relasi Q;
//    List_parent LP;
//    List_relasi LR;
    int i=1;

    if(first(LP)!=NULL&&first(LR)!=NULL){
        P=first(LP);
        while(P!=NULL){
            Q=first(LR);
            while(Q!=NULL){
                if(parent(Q)==P){
                    cout<<i<<". "<<info(parent(Q)).kategori<<" : id = "<<info(child(Q)).id_brg<<endl;
                    cout<<"\tNama barang = "<<info(child(Q)).nama_brg<<endl;
                    cout<<"\tStok = "<<info(child(Q)).stok<<endl;
                    cout<<"---------------------------------------------------------------------------"<<endl;
                    i++;
                }Q=next(Q);
            }P=next(P);
        }
    }else{
        cout<<"list kosong"<<endl;
    }
}

void printChildOfAParent(infotype_parent x){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    address_parent a;
    address_relasi Q;
    int i=1;
    bool b=false;

    if(first(LP)!=NULL){
        a=findElmParent_byID(LP,x);
        if(a!=NULL){
            Q=first(LR);
            while(Q!=NULL){
                if(parent(Q)==a){
                    cout<<i<<". "<<info(parent(Q)).kategori<<" : id = "<<info(child(Q)).id_brg<<endl;
                    cout<<"\tNama barang = "<<info(child(Q)).nama_brg<<endl;
                    cout<<"\tStok = "<<info(child(Q)).stok<<endl;
                    cout<<"---------------------------------------------------------------------------"<<endl;
                    i++;
                    b=true;
                }Q=next(Q);
            }if(b==false){
                cout<<"------------------------------------------"<<endl;
                cout<<"-       Barang tidak terkoneksi          -"<<endl;
                cout<<"------------------------------------------"<<endl;
            }
        }else{
            cout<<"kategori tidak ada"<<endl;
        }
    }else{
        cout<<"list kategori kosong"<<endl;
    }
}

void deleteChild(List_child &LC, List_relasi &LR, infotype_child x){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    address_child a,P,R;
    address_relasi b,Q,Q2;

    P=findElmById(LC, x);
    if (P != NULL){
        while (findElm_child(LR, P) != NULL){
            Q = findElm_child(LR, P);
            delete_relasi(LR,Q,Q2);
        }
    }else{
        delete_child(LC,P,R);
    }

}

void deleteParent(infotype_parent x){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    address_parent a,T;
    address_child b,Q;
    address_relasi P,R,S;
    bool d;

    if(first(LC)!=NULL&&first(LR)!=NULL&&first(LP)!=NULL){
        a=findElmParent_byID(LP,x);
        if(a!=NULL){
            P=first(LR);
            while(P!=NULL){
                d=false;
                if(parent(P)==a){
                    b=findElmById(LC,info(child(P)));
                    if(b!=NULL){
                        delete_child(LC, b, Q);
                        R=P;
                        P=next(P);
                        delete_relasi(LR,R,S);
                        d=true;
                    }else{
                        P=next(P);
                    }
                }else{
                    P=next(P);
                }
            }if(d==true){
                delete_parent(LP, a, T);
                SP.push(info(T).id_kategori);
                cout<<"Kategori berhasil dihapus!!"<<endl;
            }else{
                cout<<"Kategori TIDAK berhasil dihapus!!"<<endl;
            }
        }else{cout<<"Kategori tidak ditemukan"<<endl;}
    }else{cout<<"list kosong"<<endl;return;}
}

/**=========================================Tambahan==============================================================================================*/
void cariDiChild_byName(){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    address_child a;
    infotype_child anak;
    int i=1;
    cout<<"=============================Cari Barang by Name=================================="<<endl;
    cout<<"= 1. Nama barang = ";
    cin>>anak.nama_brg;
    cout<<"=================================================================================="<<endl;

    if(first(LC)!=NULL){
        a=findElmByName(LC,anak);
        if(a!=NULL){
            system("cls");
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t------------------Hasil Pencarian----------------------"<<endl;
            cout<<"\t\t\t\t\t- "<<i<<". id barang = "<<info(a).id_brg<<endl;
            cout<<"\t\t\t\t\t-     nama barang = "<<info(a).nama_brg<<endl;
            cout<<"\t\t\t\t\t-     stok = "<<info(a).stok<<endl;
            cout<<"\t\t\t\t\t-------------------------------------------------------"<<endl;
        }else{
            system("cls");
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t-------------------NOTICE---------------------"<<endl;
            cout<<"\t\t\t\t\t-         data tidak ditemukan               -"<<endl;
            cout<<"\t\t\t\t\t----------------------------------------------"<<endl;}
    }else{
        system("cls");
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t-------------------NOTICE---------------------"<<endl;
        cout<<"\t\t\t\t\t-              list kosong                   -"<<endl;
        cout<<"\t\t\t\t\t----------------------------------------------"<<endl;}
}

void cariDiChild_byID(){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    address_child a;
    infotype_child anak;
    int i=1;
    cout<<"================================Cari barang by ID====================================="<<endl;
    cout<<"= 1. ID barang = ";
    cin>>anak.id_brg;
    cout<<"=================================================================================="<<endl;

    if(first(LC)!=NULL){
        a=findElmById(LC,anak);
        if(a!=NULL){
            system("cls");
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t------------------Hasil Pencarian----------------------"<<endl;
            cout<<"\t\t\t\t- "<<i<<". id barang = "<<info(a).id_brg<<endl;
            cout<<"\t\t\t\t-    nama barang = "<<info(a).nama_brg<<endl;
            cout<<"\t\t\t\t-    stok = "<<info(a).stok<<endl;
            cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
        }else{
            system("cls");
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t-------------------NOTICE---------------------"<<endl;
            cout<<"\t\t\t\t\t-          Data tidak ditemukan              -"<<endl;
            cout<<"\t\t\t\t\t----------------------------------------------"<<endl;}
    }else{
        system("cls");
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t-------------------NOTICE---------------------"<<endl;
        cout<<"\t\t\t\t\t-              list kosong                   -"<<endl;
        cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
    }
}

void cariDiParent_byID(){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    address_parent a;
    infotype_parent anak;
    int i=1;
    cout<<"============================Cari Kategori by ID==================================="<<endl;
    cout<<"= 1. ID kategori = ";
    cin>>anak.id_kategori;
    cout<<"=================================================================================="<<endl;
//    cout<<"asdfghjkl"<<endl;

    if(first(LC)!=NULL){
        a=findElmParent_byID(LP,anak);
        if(a!=NULL){
            system("cls");
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t------------------Hasil Pencarian----------------------"<<endl;
            cout<<"\t\t\t\t\t- "<<i<<". id kategori = "<<info(a).id_kategori<<endl;
            cout<<"\t\t\t\t\t-     nama kategori = "<<info(a).kategori<<endl;
            cout<<"\t\t\t\t\t-------------------------------------------------------"<<endl;

        }else {system("cls");
               cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
               cout<<"\t\t\t\t\t-------------------NOTICE---------------------"<<endl;
               cout<<"\t\t\t\t\t-          Data tidak ditemukan              -"<<endl;
               cout<<"\t\t\t\t\t----------------------------------------------"<<endl;}
    }else{
        system("cls");
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t-------------------NOTICE---------------------"<<endl;
        cout<<"\t\t\t\t\t-              list kosong                   -"<<endl;
        cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
    }
}

void StokLihat(){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    address_child P;
    bool a=false;

    if(first(LC)==NULL){
        system("cls");
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t-------------------NOTICE---------------------"<<endl;
        cout<<"\t\t\t\t-              list kosong                   -"<<endl;
        cout<<"\t\t\t\t----------------------------------------------"<<endl;
    }else{
        P=first(LC);
        int i=1;
        do{
            if(info(P).stok<=10){
                cout<<i<<". ID barang = "<<info(P).id_brg<<endl;
                cout<<"   Nama barang = "<<info(P).nama_brg<<endl;
                cout<<"   Stok barang = "<<info(P).stok<<endl;
                cout<<"---------------------------------------------"<<endl;
                a=true;
                i++;
            }P=next(P);
        }while(P!=first(LC));
         if(a==false){
            cout<<"-------------------NOTICE---------------------"<<endl;
            cout<<"-  Tidak ada barang yang memiliki stok <=10  -"<<endl;
            cout<<"----------------------------------------------"<<endl;
         }
    }
}

