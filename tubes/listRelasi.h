#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED
#include <string>
#include <iostream>
#include "listChild.h"
#include "listParent.h"
#define toParent(P) P->toParent ///aktor
#define toChild(P) P->toChild   ///film
#define firstR(L) L.firstR
#define lastR(L) L.lastR
#define nextR(P) P->nextR
#define info(P) P->info
#define prevR(P) P->prevR

using namespace std;

typedef struct elmListRelasi *addressRelasi;
struct elmListRelasi{
    addressParent toParent;
    addressChild toChild;
    addressRelasi nextR;
    addressRelasi prevR;
};

struct listRelasi{
    addressRelasi firstR;
    addressRelasi lastR;
};

void createListRelasi(listRelasi &L);
addressRelasi alokasiRelasi(addressParent P, addressChild C);
bool isEmpty(listRelasi L);
void insertLastRelasi(listRelasi &L, addressRelasi P);
void findElmRel(listRelasi LR, addressParent P, addressChild C);
void deletelastR(listRelasi L, addressParent &P);
void deletefirstR(listRelasi L, addressParent &P);
void deleteRelasiAktor(listRelasi L, addressParent &P);
void deleteRelasiFilm(listRelasi L,addressChild &P);
void showAllData(listRelasi L);
void filmAktorTertentu(listRelasi &L, string aktor);
void show2aktor(listRelasi LR, listChild LC, listParent LP);
string filmBanyakAktor(listParent LP, listChild LC, listRelasi LR);
string aktorSeringNgejob(listParent LP, listChild LC, listRelasi LR);

#endif // LISTRELASI_H_INCLUDED
