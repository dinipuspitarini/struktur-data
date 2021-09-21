#ifndef LISTPARENT_H_INCLUDED
#define LISTPARENT_H_INCLUDED
#include <iostream>
#define firstP(L) L.firstP
#define lastP(L) L.lastP
#define nextP(P) P->nextP
#define info(P) P->info
#define prevP(P) P->prevP

using namespace std;

struct aktor{
    string namaAktor;
};

typedef aktor infotype_parent;
typedef struct elmListParent *addressParent;

struct elmListParent{
    infotype_parent info;
    addressParent nextP;
    addressParent prevP;
};

struct listParent{
    addressParent firstP;
    addressParent lastP;
};

void createListParent(listParent &L);
addressParent alokasiParent(infotype_parent X);
bool isEmpty(listParent L);
void insertLastParent(listParent &L, addressParent P);
void dealokasiParent(addressParent &P);
addressParent findParent(listParent L, infotype_parent X);
void printinfoP(listParent &L);
void deletelastP(listParent &L, addressParent &P);
void deletefirstP(listParent &L, addressParent &P);
void deleteParent(listParent &L,addressParent &P);

#endif // LISTPARENT_H_INCLUDED
