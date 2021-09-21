#ifndef LISTCHILD_H_INCLUDED
#define LISTCHILD_H_INCLUDED
#include <string>
#include <iostream>
#define firstC(L) L.firstC
#define lastC(L) L.lastC
#define nextC(P) P->nextC
#define info(P) P->info
#define prevC(P) P->prevC

using namespace std;

struct film {
    string judulFilm;
};

typedef film infotype_child;
typedef struct elmListChild *addressChild;

struct elmListChild{
    infotype_child info;
    addressChild nextC;
    addressChild prevC;
};

struct listChild{
    addressChild firstC;
    addressChild lastC;
};

void createListChild(listChild &L);
addressChild alokasiChild(infotype_child X);
bool isEmpty(listChild L);
void insertLastChild(listChild &L, addressChild P);
void dealokasiChild(addressChild &P);
addressChild findChild(listChild L, infotype_child X);
void printinfoC(listChild &L);
void deletefirstC(listChild &L, addressChild &P);
void deletelastC(listChild &L, addressChild &P);
void deleteChild(listChild &L, addressChild &P);

#endif // LISTCHILD_H_INCLUDED
