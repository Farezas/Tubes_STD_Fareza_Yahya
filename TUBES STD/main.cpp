#include <iostream>
#include <conio.h>
#include "primitif_penilaian.h"

using namespace std;
void tambahBarang(List_child &LC){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    infotype_child anak;
    bool c;
    system("cls");
    cout<<"================================Tambah Barang====================================="<<endl;
    cout<<"= 1. Nama barang = ";
    cin>>anak.nama_brg;
    cout<<"= 2. Banyak barang yang dimasukkan = ";
    cin>>anak.stok;
    cout<<"=================================================================================="<<endl;
    insertChild(anak,c);
    getch();
}
void tambahKategori(){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    infotype_parent isi;
    system("cls");
    cout<<"===============================Tambah Kategori===================================="<<endl;
    cout<<"= 1. Nama kategori = ";
    cin>>isi.kategori;
    cout<<"=================================================================================="<<endl;
    insertParent(isi);
    getch();
}

void cekKoneksi(){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    infotype_child b;
    infotype_parent a;
    system("cls");
    cout<<"==================================Cek koneksi====================================="<<endl;
    cout<<"= 1. ID barang = ";
    cin>>b.id_brg;
    cout<<"= 2. ID Kategori = ";
    cin>>a.id_kategori;
    cout<<"=================================================================================="<<endl;
    checkConnection(a,b);
    getch();
}
void cariBarangById(){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    system("cls");
    cariDiChild_byID();
    getch();
}
void cariKategoriById(){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    system("cls");
    cariDiParent_byID();
    getch();
}
void lihatStok(){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    system("cls");
    StokLihat();
    getch();
}
void lihatKategori(){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    system("cls");
    displayListParentOnly();
    getch();
}
void lihatBarang(){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    system("cls");
    displayListChildOnly();
    getch();
}
void hapusBarang(){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    List_child LC;
    List_relasi LR;
    infotype_child anak;
    system("cls");
    cout<<"=================================Hapus Barang====================================="<<endl;
    cout<<"= 1. ID Barang = ";
    cin>>anak.id_brg;
    cout<<"=================================================================================="<<endl;
    deleteChild(LC,LR,anak);
    getch();
}
void hapusKategori(){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    infotype_parent isi;
    system("cls");
    cout<<"===============================Hapus Kategori===================================="<<endl;
    cout<<"= 1. ID kategori = ";
    cin>>isi.id_kategori;
    cout<<"=================================================================================="<<endl;
    deleteParent(isi);
    getch();
}
void lihatbarangKategoriPilihan(){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    system("cls");
    infotype_parent isi;
    cout<<"===============================Pilih kategori====================================="<<endl;
    cout<<"= 1. ID kategori = ";
    cin>>isi.id_kategori;
    cout<<"=================================================================================="<<endl;
    printChildOfAParent(isi);
    getch();
}
void lihatbarangSemuaKategori(){
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    system("cls");
    printAll();
    getch();
}
void tambahkanRelasi(){
    /** Penyusun:
            Nama : Fareza Adityanto
            NIM  : 1301174228
            Kelas: IF 41-08
    */
    system("cls");
    infotype_child b;
    infotype_parent a;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t============================Tambahkan list relasi================================="<<endl;
    cout<<"\t\t= 1. ID barang = ";
    cin>>b.id_brg;
    cout<<"\t\t= 2. ID Kategori = ";
    cin>>a.id_kategori;
    cout<<"\t\t=================================================================================="<<endl;
    Connect(a,b);
    getch();
}

void header(){
        cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~PROGRAM KONTROL GUDANG~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
        cout<<"\t\t==================================MainMenu===================================="<<endl;
        cout<<"\t\t=  1.  PANDUAN PENGGUNAAN PROGRAM                                            ="<<endl;
        cout<<"\t\t=  A.  Tambah barang                                                         ="<<endl;
        cout<<"\t\t=  B.  Tambah kategori                                                       ="<<endl;
        cout<<"\t\t=  C.  Connect ke relasi                                                     ="<<endl;
        cout<<"\t\t=  E.  Check connection                                                      ="<<endl;//yahya
        cout<<"\t\t=  F.  Cari barang by id                                                     ="<<endl;//yahya
        cout<<"\t\t=  G.  Cari kategori by id                                                   ="<<endl;//yahya
        cout<<"\t\t=  H.  lihat semua barang                                                    ="<<endl;//yahya
        cout<<"\t\t=  I.  lihat semua kategori                                                  ="<<endl;//yahya
        cout<<"\t\t=  J.  Lihat barang dengan stok <10                                          ="<<endl;//yahya
        cout<<"\t\t=  K.  Lihat barang sesuai kategori pilihan                                  ="<<endl;//yahya
        cout<<"\t\t=  L.  Lihat barang sesuai kategori (semua kategori ditampilkan)             ="<<endl;//yahya
        cout<<"\t\t=  M.  Hapus barang                                                          ="<<endl;
        cout<<"\t\t=  N.  Hapus kategori                                                        ="<<endl;
        cout<<"\t\t=  0.  Keluar                                                                ="<<endl;
        cout<<"\t\t=============================================================================="<<endl;

}
int main()
{
    /** Penyusun:
            Nama : Muchtarom Yahya
            NIM  : 1301174052
            Kelas: IF 41-08
    */
    List_parent LP;
    List_child LC;
    List_relasi LR;
    createList(LC);
    createList(LP);
    createList(LR);

    char pilih;
    do
    {
        system("cls");
        header();
        cout<<"\t\t Pilihan: ";
        cin>>pilih;
        switch(pilih)
        {
            case '1':
                {
                    /** Penyusun:
                            Nama : Fareza Adityanto
                            NIM  : 1301174228
                            Kelas: IF 41-08
                    */

                    system("cls");
                    cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~PANDUAN PENGGUNAAN PROGRAM~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                    cout<<"\t\t=  1.  Tambahkan kategori dahulu sebelum tambahkan barang lalu               ="<<endl;
                    cout<<"\t\t=      klik menu connect untuk memasukkan barang ke suatu kategori           ="<<endl;
                    cout<<"\t\t=  2.  ID barang dan kategori sudah otomatis terisi oleh sistem              ="<<endl;
                    cout<<"\t\t=  3.  Apabila ingin menambahkan 2 barang atau lebih ke kategori yang sama,  ="<<endl;
                    cout<<"\t\t=      silahkan pilih menu connect setelah anda menambahkan barang.          ="<<endl;
                    cout<<"\t\t=  4.  Di setiap menu pencarian, menggunakan ID sebagai parameter pencarian  ="<<endl;
                    cout<<"\t\t=============================================================================="<<endl;
                    getch();
                    break;
                }
            case 'A':
                tambahBarang(LC);
                break;
            case 'B':
                tambahKategori();
                break;
            case 'C':
                tambahkanRelasi();
                break;
            case 'E':
                cekKoneksi();
                break;
            case 'F':
                cariBarangById();
                break;
            case 'G':
                cariKategoriById();
                break;
            case 'H':
                lihatBarang();
                break;
            case 'I':
                lihatKategori();
                break;
            case 'J':
                lihatStok();
                break;
            case 'K':
                lihatbarangKategoriPilihan();
                break;
            case 'L':
                lihatbarangSemuaKategori();
                break;
            case 'M':
                hapusBarang();
                break;
            case 'N':
                hapusKategori();
                break;
            case '0':
                cout<<"\t\t\t\t\t\t------------------"<<endl;
                cout<<"\t\t\t\t\t\t- Terima kasih!! -"<<endl;
                cout<<"\t\t\t\t\t\t------------------"<<endl;
                exit(0);

            default :
                {
                    cout<<"\t\t\t\t--------------------------------------"<<endl;
                    cout<<"\t\t\t\t- Maaf inputan anda salah, coba lagi -"<<endl;
                    cout<<"\t\t\t\t--------------------------------------"<<endl;
                    getch();
                    break;
                }

        }
    }
    while(pilih!='0');
    cout<<endl<<"Tekan Enter"<<endl;
    getch();
}
