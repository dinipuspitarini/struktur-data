#include "listRelasi.h"
#include <iostream>

void createListRelasi(listRelasi &L){
    firstR(L) = NULL;
    lastR(L) = NULL;
}

addressRelasi alokasiRelasi(addressParent P, addressChild C){
    addressRelasi X = new elmListRelasi;
    aktor(X) = P;
    film(X) = C;
    nextR(X) = NULL;
}

bool isEmpty(listRelasi L){
    bool status;
    if (firstR(L) == NULL && lastR(L) == NULL ){
        status = true;
    } else {
        status = false;
    }
    return status;;
}

void insertLastRelasi(listRelasi &L, addressRelasi P){
    if(isEmpty(L)){
        firstR(L) = P;
        lastR(L) = P;
    } else {
        prevR(P) = lastR(L);
        nextR(lastR(L)) = P;
        lastR(L) = P;
    }
}

void findElmRel(listRelasi LR, addressParent P, addressChild C){
    addressRelasi R = firstR(L);
    while (R != NULL){
        if((toParent(R)==P)&&(toChild(R)==C)){
            return R;
        }else {
            R = nextR(R);
        }
    }
    return(R);
}
void deletelastR(listRelasi L, addressRelasi &P){
    if(isEmpty(L)){
        cout <<" <list kosong> "<<endl;
    }else if (nextR(firstR(L))== NULL){
        P = firstR(L);
        firstR(L) = NULL;
        lastR(L) = NULL;
    }else {
        P = lastR(L);
        lastR(L) = prevR(P);
        nextR(P) = NULL;
    }
}

void deletefirstR(listRelasi L, addressRelasi &P){
    if(isEmpty(L)){
        cout << "<list kosong>"<<endl;
    }else if (nextR(firstR(L)) == NULL){
        P = firstR(L);
        firstR(L)=nextR(L);
        prevR(firstR(L)) = NULL;
        nextR(P) = NULL;
        prevR(P) = NULL;
    }else {
        P = firstR(L);
        firstR(L) = nextR(P);
        prevR(firstR(L)) = NULl;
        nextR(P) = NULL;
        prevR(P) = NULL;
    }
}
void deleteRelasiAktor(listRelasi L, addressParent &P){
    addressRelasi Q = firstR(LR);
    addressRelasi R;
        while(Q!=NULL){
            R = nextR(Q);
            if(toParent(R)==P){
                nextR(Q)=nextR(R);
                delete R;
            } else if (Q == firstR(LR) && toParent(Q)==P){
                R = Q;
                firstR(LR) = nextR(R);
                nextR(R) = NULL;
                delete R;
            }
            Q = nextR(Q);
        }
}
void deleteRelasiFilm(listRelasi L,addressChild &P){
    addressRelasi Q = firstR(LR);
    addressRelasi R;
        while(Q!=NULL){
            R = nextR(Q);
            if(toChild(R)==P){
                nextR(Q)=nextR(R);
                delete R;
            } else if (Q == firstR(LR)&& toChild(Q)==P){
                R = Q;
                firstR(LR) = nextR(R);
                nextR(R) = NULL;
                delete R;
            }
            Q = nextR(Q);
        }
}
void showAllData(listRelasi L){
    addressRelasi R = firstR(L);
    if (firstR(L) == NULL){
        cout<<"  Data ga Ada"<<endl;
    }else{
        int i = 1;
        while (R != NULL) {
            cout<<endl<< i << endl;
            cout<<endl<<"  "<<info(toParent(R)).namaAktor<<" - "<<info(toChild(R)).judulFilm<<endl;
            cout<<"|========================================================================|"<<endl;
            R = nextR(R);
            i++;
        }
    }
}
void filmAktorTertentu(listRelasi &L, string aktor){
    addressRelasi R = firstR(LR);
    int i = 1;
    while (R !=NULL){
        if (info(toParent(R)).namaAktor == aktor){
            cout << "aktor ke- "<<i<<" : (" << info(toParent(R)).namaAktor << endl;
            cout << "memainkan film  : " << info(toChild(R)).judulFilm<<endl;
            i = i+1;
        }
    R = nextR(R);
    }
}
void show2aktor(listRelasi LR, listChild LC, listParent LP); /// belum ketemu coba nanti aku pikirkan

string filmBanyakAktor(listParent LP, listChild LC, listRelasi LR){
    if(firstR(LR)!= NULL ){
        addressChild C = firstC(LC);
        addressRelasi R;
        string temp;
        int x = 0;
        while (nextC(C)!= NULL) {
            int jum = 0;
            R = firstR(LR);
            while (R != NULL ){
                if (toChild(R) == C){
                    jum = jum +1;
                    if ( x < jum){
                        x = jum;
                        temp = info(toChild(R)).judulFilm;
                    }
                }
                R = nextR(R);
            }
            C = nextC(C);
        }
        if (nextC(C)== NULL){
            int jum = 0;
            R = firstR(LR);
            while (R != NULL ){
                if(toChild(R) == C){
                    jum = jum + 1;
                    if (x < jum){
                        x = jum;
                        temp = info(toChild(R)).nama;
                    }
                }
            R = nextR(R);
            }
        }
        return temp;
    }else {
        return "Tidak ada data";
    }

}

string aktorSeringNgejob(listParent LP, listChild LC, listRelasi LR){
    if(firstR(LR)!= NULL ){
        addressParent P = firstP(LP);
        addressRelasi R;
        string job;
        int x = 0;
        while (nextP(P)!= NULL) {
            int jum = 0;
            R = firstR(LR);
            while (R != NULL ){
                if (toParent(R) == P){
                    jum = jum +1;
                    if ( x < jum){
                        x = jum;
                        job = info(toParent(R)).namaAktor;
                    }
                }
                R = nextR(R);
            }
            P = nextP(P);
        }
        if (nextP(P)== NULL){
            int jum = 0;
            R = firstR(LR);
            while (R != NULL ){
                if(toParent(R) == P){
                    jum = jum + 1;
                    if (x < jum){
                        x = jum;
                        job = info(toParent(R)).namaAktor;
                    }
                }
            R = nextR(R);
            }
        }
        return job;
    }else {
        return "Tidak ada data";
    }

}
