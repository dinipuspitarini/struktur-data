##include <iostream>
#include <string>
#include "listParent.h"
#include "listRelasi.h"
#include "listChild.h"
#include <cstdlib>
#include <conio.h>

using namespace std;
/// KOK DINI CANTIK SIH?
/// KOK DINI CANTIK SIH?
/// KOK DINI CANTIK SIH?
int main()
{
    listChild LC;
    listParent LP;
    listRelasi LR;
    createListChild(LC);
    createListParent(LP);
    createListRelasi(LR);
    int choose = 0;
    char answer;

    while (choose == 0){
        system("CLS");
        cout << "================================================================================" << endl;
        cout << "=================================DATA AKTOR DAN FILM============================" << endl;
        cout << "================================================================================" << endl;
        cout << "=====================================MENU=======================================" << endl;
        cout << "1. Tambah data aktor/aktris." <<endl;
        cout << "2. Tambah data film baru." << endl;
        cout << "3. Tambah data aktor ke film(membuat relasi)"<< endl;
        cout << "4. Hapus data aktor/aktirs " << endl;
        cout << "5. Hapus data film tertentu." << endl;
        cout << "6. Tampilkan seluruh data film yang pernah diperankan oleh aktirs/aktor tertentu" << endl;
        cout << "7. Tampilkan 2 aktor yang bermain di 2 film yang sama" << endl; /// BELUM ADA SOALNYA PROSEDURNYA BELUM ADA
        cout << "8. Tampilkan judul film yang melibatkan banyak aktor" << endl;
        cout << "9. Tampilkan aktor/aktirs yang paling sering ngejob"<<endl;
        cout << endl;
        cout <<"Silahkan pilih: ";
        cin >> choose;
        system("CLS");
        switch(choose){
            case 1:{
               infotype_parent A;
                cout << "=======================================" << endl;
                cout << "|           INPUT DATA AKTOR           |" << endl;
                cout << "=======================================" << endl;
                int d;
                int i=1;
                cout << "masukan banyak aktor yang ingin di input : ";
                cin >> d;
                while (i <= d){
                    cout<<i<<endl;
                    cout << "= Nama aktor                  : ";
                    cin >> A.namaAktor;
                    cout << endl;
                    addressParent P;
                    P = findParent(LP, A);
                    if (P == NULL){
                        insertLastParent(LP,alokasiParent(A));
                        cout << "aktor berhasil ditambahkan "<< endl;
                        printinfoP(LP);
                    } else {
                        cout << "aktor sudah terdaftar! " << endl;
                    }
                i++;
                }
                cout<<endl;
                cout<<"Apakah anda ingin memasukan data lagi? [y/Y]"<<endl;
                cin>>answer;
                cout<<endl;
                if ((answer!='Y') || (answer!='y')){
                    choose=0;
                }
            }break;
            case 2:{
                infotype_child B;
                cout << "=======================================" << endl;
                cout << "|           JUDUL FILM                 |" << endl;
                cout << "=======================================" << endl;
                cout << "masukan banyak film  yang ingin input : ";
                int x;
                int y = 1;
                cin >> x;
                while (y <= x){
                    cout << "= Judul FIlm                        : ";
                    cin >> B.judulFilm;
                    addressChild C = findChild(LC, B);
                    if (C == NULL){
                        insertLastChild(LC,alokasiChild(B));
                        cout << "film berhasil ditambahkan "<< endl;
                        printinfoC(LC);
                    } else {
                        cout << "film sudah terdaftar! " << endl;
                    }
                    y++;
                }
                cout<<endl;
                cout<<"Apakah anda ingin memasukan data lagi? [y/Y]"<<endl;
                cin>>answer;
                cout<<endl;
                if ((answer!='Y') || (answer!='y')){
                    system("CLS");
                    answer=0;
                }
            }break;
            case 3:{
                infotype_parent X;
                infotype_child Y;
                if ((firstP(LP)!= NULL)&&(firstC(LC)!= NULL)){
                    cout<<"Apakah anda ingin mendaftarkan artis ke sebuah film?[y/Y]"<<endl;
                    cin>>answer;
                    system("CLS");
                    while ((answer=='y')||(answer=='Y')){
                        cout<<"============NAMA AKTOR ============"<<endl;
                        printinfoP(LP);
                        cout<<endl;
                        cout<<"===== DAFTAR FILM YANG ADA ========"<<endl;
                        printinfoC(LC);
                        cout<<endl;
                        cout<<"================================================="<<endl;
                        cout<<"Pilih nama artis yang akan dimasukan ke film :"<<endl;
                        cin>>X.namaAktor;
                        cout<<"Pilih judul film  yang diinginkan:"<<endl;
                        cin>>Y.judulFilm;
                        addressParent A=findParent(LP, X);
                        addressChild B=findChild(LC, Y);
                        if (A==NULL){
                            cout<<"artis tersebut tidak ada dalam data."<<endl<<endl;
                        }
                        if (B==NULL){
                            cout<<"judul film tersebut tidak ada dalam data."<<endl<<endl;
                        }
                        if ((A!=NULL)&&(B!=NULL)){
                            addressRelasi C = findElmRel(LR, A, B);
                            if (C!=NULL){
                                cout <<"artis dengan nama tersebut sudah didaftarkan pada film ini."<<endl;
                            }else{
                                addressRelasi D = alokasiRelasi(A,B);
                                insertLastRelasi(LR,D);
                                cout<<"Proses sukses."<<endl;
                                cout<<endl;
                                system("CLS");
                                showAllData(LR);
                                cout<<"=============================================================="<<endl;
                            }
                        }
                        cout<<"apakah anda ingin memasukan lagi artis ke film yang diinginkan?[Y/y]"<<endl;
                        cin>>answer;
                        system("CLS");
                    }
                    choose=0;
                }else{
                    choose=0;
                    cout<<"silahkan isi data artis atau judul film  terlebih dahulu."<<endl;
                }
            }break;
            case 4:{
                infotype_parent P;
                cout<<"Hapus data artis? serius? [y/t]" << endl;
                cin>>answer;
                while ((answer =='y')|| (answer =='Y')){
                    cout<<"==================================================="<<endl;
                    cout<<" Data keseluruhan aktor dan film yang dimainkan  " <<endl;
                    showAllData(LR);
                    cout<<" Input nama aktor yang akan dihapus datanya" <<endl;
                    cin>>P.namaAktor;
                    addressParent Q = findParent(LP , P);
                    if ((Q != NULL)){
                        deleteRelasiAktor(LR,Q);
                        deleteParent(LP,Q);
                        cout<<"Delete Sukses!"<<endl;
                        if(firstR(LR)!= NULL){
                            showAllData(LR);
                        } else {
                            choose = 0;
                        }
                    } else {
                        cout << "Relasi ga ada" << endl;
                    }
                cout<<"Ingin hapus yang lain?"<<endl;
                cin>>answer;
            }
            choose = 0;
            }break;
            case 5:{
                infotype_child C;
                cout<<"Hapus data film? serius? [y/t]" << endl;
                cin>>answer;
                while ((answer =='y')|| (answer =='Y')){
                    cout<<"=================================================="<<endl;
                    cout<<" Data keseluruhan artis dan film yang dimainkan " <<endl;
                    showAllData(LR);
                    cout<<" Input judul film yang akan dihapus datanya" <<endl;
                    cin>>C.judulFilm;
                    addressChild Q = findChild(LC , C);
                    if ((Q != NULL)){
                        deleteRelasiFilm(LR,Q);
                        deleteChild(LC,Q);
                        cout<<"Delete Sukses!"<<endl;
                        if(firstR(LR)!= NULL){
                            showAllData(LR);
                        } else {
                            choose = 0;
                        }
                    } else {
                        cout << "Relasi ga ada" << endl;
                    }
                cout<<"Ingin hapus yang lain?"<<endl;
                cin>>answer;
            }
            choose = 0;
            }break;
            case 6:{
                string aktor;
                cout<<"============================================================"<<endl;
                cout<<"===  Data judul film yang dimainkan oleh artis  tertentu ==="<<endl;
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"Masukkan nama aktor yang ingin ditampilkan bermain di film mana"<<endl;
                cin>>aktor;
                filmAktorTertentu(LR,aktor);
                cout<<"============================================================="<<endl;
                cout<<"Kembali ke menu apa tidak?[y/Y]"<<endl;
                cin>>answer;
                while ((answer != 'y') && (answer != 'Y')){
                    cout<<"Kembali ke menu apa tidak? [Press y/Y] : "<<endl;
                    cin>>answer;
                }
                if ((answer == 'y')&&(answer == 'Y'))
                    choose = 0;
            }break;
            case 7:{ /// BELUM ADA SOALNYA PROSEDURNYA BELUM ADA

                /// BELUM ADA SOALNYA PROSEDURNYA BELUM ADA
                /// BELUM ADA SOALNYA PROSEDURNYA BELUM ADA
                /// BELUM ADA SOALNYA PROSEDURNYA BELUM ADA
                /// BELUM ADA SOALNYA PROSEDURNYA BELUM ADA
                /// BELUM ADA SOALNYA PROSEDURNYA BELUM ADA
                /// BELUM ADA SOALNYA PROSEDURNYA BELUM ADA

            }break;
            case 8:{ ///Tampilkan judul film yang melibatkan banyak aktor
                cout<<"================================================================="<<endl;
                cout<<"             judul film yang melibatkan banyak aktor             "<<endl;
                cout<<"================================================================="<<endl;
                cout<<endl;
                string temp = filmBanyakAktor(LP,LC,LR)
                cout<<"filmnya adalah :" <<temp<<endl;
                cout<<"================================================================="<<endl;
                cout<<"================================================================="<<endl;
                cout<<"Kembali kemenu apa tidak? [y/Y]?"<<endl;
                cin>>answer;
                while ((answer != 'y') && (answer != 'Y')){
                    cout<<"Kembali ke menu apa tidak? [Press y/Y] : "<<endl;
                    cin>>answer;
                }
                if ((answer == 'y')&&(answer == 'Y'))
                    choose = 0;
            }break;
            case 9:{ /// aktor/aktirs yang paling sering ngejob
                cout<<"================================================================="<<endl;
                cout<<"               Artis yang memerankan banyak film                 "<<endl;
                cout<<"================================================================="<<endl;
                cout<<endl;
                string temp = aktorSeringNgeJob(LP,LC,LR);
                cout<<"aktornya adalah :" <<temp<<endl;
                cout<<"================================================================="<<endl;
                cout<<"================================================================="<<endl;
                cout<<"Kembali kemenu apa tidak? [y/Y]?"<<endl;
                cin>>answer;
                while ((answer != 'y') && (answer != 'Y')){
                    cout<<"Kembali ke menu apa tidak? [Press y/Y] : "<<endl;
                    cin>>answer;
                }
                if ((answer == 'y')&&(answer == 'Y'))
                    choose = 0;
            }break;
        }///endchoose (dont move this bracket)
    }///endwhile before choose (dont move this bracket)
}///endprogram (dont move this bracket)
