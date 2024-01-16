#ifndef KOPIANTUBES_H_INCLUDED
#define KOPIANTUBES_H_INCLUDED

#include <iostream>

#define first(L) L.first
#define last(L) L.last
#define infoPr(P) P->infoPr
#define infoCh(P) P->infoCh
#define nextPr(P) P->nextPr
#define nextCh(P) P->nextCh
#define pasienDk(P) P->pasienDk
#define prev(P) P->prev

using namespace std;

struct dokter{
    int kode_dokter;
    string nama_dokter;
    string spesialisasi;
    int no_telepon;
};

struct pasien{
    int kode_pasien;
    string nama;
    int umur;
    string riwayat_penyakit;
};
typedef dokter infotypeD;
typedef pasien infotypeP;
typedef struct elmDokter *adr_dokter;
typedef struct elmPasien *adr_pasien;
struct elmDokter{
    adr_dokter prev;
    infotypeD infoPr;
    adr_pasien pasienDk;
    adr_dokter nextPr;
};
struct elmPasien{
    infotypeP infoCh;
    adr_pasien nextCh;
};



struct RumahSakit{
    adr_dokter first,last;
};

void createListDokter(RumahSakit &RS);

adr_dokter createElementDokter(infotypeD x);
adr_pasien createElementPasien(infotypeP x);

void insertDataDokter(RumahSakit &RS,adr_dokter p);
void insertDataPasien(RumahSakit &RS,adr_pasien p, adr_dokter q);

void deleteFirstDokter(RumahSakit &RS,adr_dokter &p);
void deleteAfterDokter(RumahSakit &RS,adr_dokter prec, adr_dokter &p);
void deleteLastDokter(RumahSakit &RS,adr_dokter &p);
void deleteDataDokter(RumahSakit &RS, adr_dokter &P, adr_dokter Prec,int kode_dokter);


void deleteFirstPasien(RumahSakit &RS, adr_pasien &P,adr_dokter q);
void deleteAfterPasien(RumahSakit &RS,adr_pasien prec, adr_pasien &P,adr_dokter q);
void deleteLastPasien(RumahSakit &RS, adr_pasien &P,adr_dokter q);
void deleteDataPasien(RumahSakit &RS,adr_pasien prec, adr_pasien &P,adr_dokter q,int kode_pasien);

adr_dokter findDokter(RumahSakit RS, int kode_dokter);
adr_dokter findDokterbyPasien(RumahSakit RS, int kode_pasien);
adr_pasien findPasien(RumahSakit RS, int kode_pasien);
adr_dokter findDokterbyPasienDetail(RumahSakit RS, int kode_pasien, int kode_dokter);

void showAllDokter(RumahSakit RS);
void showPasienOfDokter(RumahSakit RS, int kode_dokter);
void showDokterWithPasien(RumahSakit RS);
void showDokterByPasien(RumahSakit RS, int kode_pasien);


int countPasienOfDokter(RumahSakit RS, int kode_dokter);
void countPasienAllDokter(RumahSakit RS);
void countPasien(RumahSakit RS, int kode_pasien);
void countDokterofPasien(RumahSakit RS, int kode_pasien);

void editPasienDariDokterTertentu(RumahSakit RS, int kode_dokterA,int kode_dokterB, int kode_pasien);

int selectMenu();

#endif // KOPIANTUBES_H_INCLUDED
