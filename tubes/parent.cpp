#include "listParent.h"
#include <iostream>
#include <string>

using namespace std;

void createListParent(listParent &L){
    firstP(L) = NULL;
    lastP(L) = NULL;

}

addressParent alokasiParent(infotype_parent X){
    addressParent P = new elmListParent;
    info(P).namaAktor = X.namaAktor;
    nextP(P) = NULL;
    prevP(P) = NULL;

    return P;
}

bool isEmpty(listParent L){
    bool status;
    if (firstP(L) == NULL && lastP(L) == NULL ){
        status = true;
    } else {
        status = false;
    }
    return status;
}

void insertLastParent(listParent &L, addressParent P){
    if(isEmpty(L)){
        firstP(L) = P;
        lastP(L) = P;
    } else {
        prevP(P) = lastP(L);
        nextP(lastP(L)) = P;
        lastP(L) = P;
    }
}

void dealokasiParent(addressParent &P) {
    delete(P);
    P = NULL;
}

addressParent findParent(listParent L, infotype_parent X) {
    addressParent P = firstP(L);

    if (firstP(L) == NULL ){
        P = NULL;
    } else {
        while (nextP(P) != NULL && info(P).namaAktor != X.namaAktor){
            P = nextP(P);
        }
        if (info(P).namaAktor != X.namaAktor){
            P = NULL;
        } while (P != NULL ){
            if ( info(P).namaAktor == X.namaAktor){
                return P;
            }
            P = nextP(P);
        }
    }
    return P;
}

void printinfoP(listParent &L) {
    addressParent P = firstP(L);
    if (firstP(L) == NULL && lastP(L) == NULL){
        cout << " < Data tidak ada > " << endl;
    } else {
        P = firstP(L);
        int i = 1;
        while (P != NULL ){
            cout << "Nama Aktor : " << info(P).namaAktor << endl;
            P = nextP(P);
            i++;
        }
    }
}

void deletelastP(listParent &L, addressParent &P) {
    if (isEmpty(L)){
        cout << "< list kosong > " << endl;
    } else if (nextP(firstP(L)) == NULL ){
        P = firstP(L);
        firstP(L) = NULL;
        lastP(L) = NULL;
        dealokasiParent(P);
    } else {
        P = lastP(L);
        lastP(L) = prevP(P);
        nextP(P) = NULL;
        prevP(P) = NULL;
        dealokasiParent(P);
    }
}

void deletefirstP(listParent &L, addressParent &P) {
    if(isEmpty(L)){
        cout << "< list kosong >" << endl;
    }else if(nextP(firstP(L))== NULL ){
        P = firstP(L);
        firstP(L) = NULL;
        lastP(L) = NULL;
        dealokasiParent(P);
    } else {
        P = firstP(L);
        firstP(L) = nextP(P);
        prevP(firstP(L)) = NULL;
        nextP(P) = NULL;
        prevP(P) = NULL;
        dealokasiParent(P);
    }
}

void deleteParent(listParent &L,addressParent &P){
    if (P != NULL ){
        if (P == firstP(L)){
            deletefirstP(L,P);
        } else if (P == lastP(L)){
            deletelastP(L,P);
        } else {
            nextP(prevP(P)) = nextP(P);
            prevP(nextP(P)) = prevP(P);
            nextP(P) = NULL;
            prevP(P) = NULL;
            dealokasiParent(P);
        }
    }

}
