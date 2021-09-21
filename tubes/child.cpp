#include "listChild.h"
#include <iostream>

using namespace std;

void createListChild(listChild &L){
    firstC(L) = NULL;
    lastC(L) = NULL;
}

addressChild alokasiChild(infotype_child X){
    addressChild P = new elmListChild;
    info(P).judulFilm = X.judulFilm;
    nextC(P) = NULL;
    prevC(P) = NULL;

    return P;
}

bool isEmpty(listChild L){
    bool status;
    if (firstC(L) == NULL && lastC(L) == NULL ){
        status = true;
    } else {
        status = false;
    }
    return status;
}

void insertLastChild(listChild &L, addressChild P){
    if(isEmpty(L)){
        firstC(L) = P;
        lastC(L) = P;
    } else {
        prevC(P) = lastC(L);
        nextC(lastC(L)) = P;
        lastC(L) = P;
    }
}

void dealokasiChild(addressChild &P) {
    delete(P);
    P = NULL;
}

addressChild findChild(listChild L, infotype_child X) {
    addressChild P = firstC(L);
    if (firstC(L) == NULL ){
        P = NULL;
    } else {
        while ( nextC(P) != firstC(L) && info(P).judulFilm != X.judulFilm){
            P = nextC(P);
        }
        if (info(P).judulFilm != X.judulFilm ){
            P = NULL;
        } while (P != NULL ){
            if ( info(P).judulFilm == X.judulFilm){
                return P;
            }
            P = nextC(P);
        }
    }
    return P;
}

void printinfoC(listChild &L) {
    addressChild P = firstC(L);
    if (firstC(L) == NULL && lastC(L) == NULL){
        cout << " < Data tidak ada > " << endl;
    } else {
        P = firstC(L);
        int i = 1;
        while (P != firstC(L)){
            cout << "Judul Film : " << info(P).judulFilm << endl;
            P = nextC(P);
            i++;
        }
    }
}

void deletefirstC(listChild &L, addressChild &P) {
    if(isEmpty(L)){
        cout << "< list kosong >" << endl;
    }else if(nextC(firstC(L))== NULL ){
        P = firstC(L);
        firstC(L) = NULL;
        lastC(L) = NULL;
        dealokasiChild(P);
    } else {
        P = firstC(L);
        firstC(L) = nextC(P);
        prevC(firstC(L)) = NULL;
        nextC(P) = NULL;
        prevC(P) = NULL;
        dealokasiChild(P);
    }
}

void deletelastC(listChild &L, addressChild &P) {
    if (isEmpty(L)){
        cout << "< list kosong > " << endl;
    } else if (nextC(firstC(L)) == NULL ){
        P = firstC(L);
        firstC(L) = NULL;
        lastC(L) = NULL;
        dealokasiChild(P);
    } else {
        P = lastC(L);
        lastC(L) = prevC(P);
        nextC(P) = NULL;
        prevC(P) = NULL;
        dealokasiChild(P);
    }
}

void deleteChild(listChild &L, addressChild &P) {
    if (P != NULL ){
        if (P == firstC(L)){
            deletefirstC(L,P);
        } else if (P == lastC(L)){
            deletelastC(L,P);
        } else {
            nextC(prevC(P)) = nextC(P);
            prevC(nextC(P)) = prevC(P);
            nextC(P) = NULL;
            prevC(P) = NULL;
            dealokasiChild(P);
        }
    }
}
