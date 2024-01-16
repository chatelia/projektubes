#ifndef KOPIANTUBES_CPP_INCLUDED
#define KOPIANTUBES_CPP_INCLUDED

#include "kopiantubes.h"

void createListDokter(RumahSakit &RS) {
    first(RS) = NULL;
    last(RS) = NULL;
}

adr_dokter createElementDokter(infotypeD x){
    adr_dokter p = new elmDokter;
    infoPr(p) = x;
    nextPr(p) = NULL;
    pasienDk(p) = NULL;
    prev(p) = NULL;
    return p;
}

adr_pasien createElementPasien(infotypeP x){
    adr_pasien p = new elmPasien;
    infoCh(p)= x;
    nextCh(p) = NULL;
    return p;

}

void insertDataDokter(RumahSakit &RS,adr_dokter p){
    if (first(RS) == NULL) {
        first(RS) = p;
        last(RS) = p;
    }else {
        nextPr(last(RS)) = p;
        prev(p) = last(RS);
        last(RS) = p;
    }

    cout << "=======================================================" << endl;
    cout << "=======================================================" << endl;
    cout << endl;
    cout << "Data Dokter Berhasil di tambahkan!!" <<endl;
    cout << endl;
}

void insertDataPasien(RumahSakit &RS,adr_pasien p, adr_dokter q){
    int kode_pasien;
    if (pasienDk(q) == NULL){
            pasienDk(q) = p;
            nextCh(p) = p;
    }else{
            adr_pasien n = pasienDk(q);
            while (nextCh(n) != pasienDk(q)){
                n = nextCh(n);
            }
            nextCh(n) = p;
            nextCh(p) = pasienDk(q);
    }
    cout << "=======================================================" << endl;
    cout << "=======================================================" << endl;
    cout << endl;
    cout << "Data Pasien Berhasil di tambahkan!!" <<endl;
    cout << endl;

}

adr_dokter findDokter(RumahSakit RS, int kode_dokter){
    adr_dokter P = first(RS);
    while (P != NULL ) {
        if (infoPr(P).kode_dokter == kode_dokter){
            return P;
        }
        P = nextPr(P);
    }
    return NULL;

}

adr_dokter findDokterbyPasien(RumahSakit RS, int kode_pasien) {
    adr_dokter P = first(RS);

    while (P != NULL) {
        adr_pasien Q = pasienDk(P);
        if (Q != NULL) {
            do {
             if (infoCh(Q).kode_pasien == kode_pasien) {
                return P;
            }
            Q = nextCh(Q);
        }
        while (Q!= pasienDk(P));
        }


        P = nextPr(P);
    }

    return NULL;
}


 adr_pasien findPasien(RumahSakit RS, int kode_pasien) {
    adr_dokter P = first(RS);

    while (P != NULL ) {
        adr_pasien Q = pasienDk(P);
        if (Q != NULL) {
            do {
             if (infoCh(Q).kode_pasien == kode_pasien){
                return Q;
            }
            Q = nextCh(Q);
        }while (Q != pasienDk(P));
        }
        P = nextPr(P);
    }
    return NULL;
}

adr_dokter findDokterbyPasienDetail(RumahSakit RS, int kode_pasien, int kode_dokter) {
    adr_dokter P = findDokter(RS,kode_dokter);
    if (P != NULL) {
        adr_pasien Q = pasienDk(P);
        if (Q != NULL) {
            do {
                if (infoCh(Q).kode_pasien == kode_pasien){
                    return P;
                }
                Q = nextCh(Q);
            }while (Q != pasienDk(P));
        }
    }
    return NULL;
}

//Delete
void deleteFirstDokter(RumahSakit &RS, adr_dokter &P) {
  if (first(RS) == NULL) {
    cout << "Data dokter Kosong!!." << endl;
  } else if (first(RS) == last(RS)){
    P = first(RS);
    first(RS) = NULL;
    last(RS) = NULL;
  }else {
    P = first(RS);
    first(RS) = nextPr(P);
    nextPr(P) = NULL;
    prev(first(RS)) = NULL;
  }
    cout << "=======================================================" << endl;
    cout << "=======================================================" << endl;
    cout << endl;
    cout << "Data Dokter Berhasil di hapus!!" <<endl;
    cout << endl;

}

void deleteLastDokter(RumahSakit &RS, adr_dokter &P) {
  if (first(RS) == NULL) {
    cout << "Data dokter Kosong !!." << endl;
  }else if (first(RS) == last(RS)){
    P = last(RS);
    first(RS) = NULL;
    last(RS) = NULL;
  }else {
    P = last(RS);
    last(RS) = prev(P);
    prev(P) = NULL;
    nextPr(last(RS)) = NULL;
  }
    cout << "=======================================================" << endl;
    cout << "=======================================================" << endl;
    cout << endl;
    cout << "Data Dokter Berhasil di hapus!!" <<endl;
    cout << endl;

}

void deleteAfterDokter(RumahSakit &RS, adr_dokter Prec, adr_dokter &P) {
  if (first(RS) == NULL) {
    cout << "Tidak ada list dokter.";
  }else if (nextPr(Prec) == NULL) {
    cout << "Tidak Ada Element Setelah Prec" << endl;
  }else if(nextPr(Prec)== last(RS)){
      deleteLastDokter(RS,P);
  }else {
    P = nextPr(Prec);
    nextPr(Prec) = nextPr(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    nextPr(P) = NULL;
  }
  cout << "=======================================================" << endl;
    cout << "=======================================================" << endl;
    cout << endl;
    cout << "Data Dokter Berhasil di hapus!!" <<endl;
    cout << endl;
}

void deleteDataDokter(RumahSakit &RS, adr_dokter &P, adr_dokter Prec, int kode_dokter) {
    adr_dokter R = findDokter(RS, kode_dokter);
    if (R != NULL) {
        if (R == first(RS)) {
            deleteFirstDokter(RS, P);
        } else if (R == last(RS)) {
            deleteLastDokter(RS, P);
        } else {
            Prec = first(RS);
            while (nextPr(Prec) != R) {
                Prec = nextPr(Prec);
            }
            deleteAfterDokter(RS,Prec,P);
        }
    } else {
        cout << "Data dokter tidak ditemukan." << endl;
    }
}


void deleteFirstPasien(RumahSakit &RS, adr_pasien &p,adr_dokter q){
    adr_pasien n = pasienDk(q);
    if (pasienDk(q) == NULL){
            cout << "Data Pasien Kosong" << endl;
    }else if (nextCh(n) ==pasienDk(q)){
            p = pasienDk(q);
            pasienDk(q) = NULL;
    }else{
            p = pasienDk(q);
            pasienDk(q) = nextCh(p);
            nextCh(p) = NULL;
    }
      cout << "=======================================================" << endl;
        cout << "=======================================================" << endl;
        cout << endl;
        cout << "Data Pasien Berhasil di hapus!!" << endl;
        cout << endl;
}

void deleteAfterPasien(RumahSakit &RS,adr_pasien prec, adr_pasien &P,adr_dokter q){
    adr_pasien n = pasienDk(q);
    if (pasienDk(q) == NULL){
        cout << "Data Pasien Kosong" << endl;
    }else if (nextCh(n) == pasienDk(q)){
        deleteFirstPasien(RS,P,q);
    }else {
        P = nextCh(prec);
        nextCh(prec) = nextCh(P);
        nextCh(P) = NULL;
    }
      cout << "=======================================================" << endl;
        cout << "=======================================================" << endl;
        cout << endl;
        cout << "Data Pasien Berhasil di hapus!!" << endl;
        cout << endl;

}
void deleteLastPasien(RumahSakit &RS, adr_pasien &P,adr_dokter q){
    adr_pasien n = pasienDk(q);
    if (pasienDk(q) == NULL){
            cout << "Data Pasien Kosong" << endl;
    }else if (nextCh(n) == pasienDk(q)){
            P = pasienDk(q);
            pasienDk(q) = NULL;
    }else{

            while (nextCh(n) != pasienDk(q)){
                n = nextCh(n);
            }
            P = nextCh(n);
            nextCh(P) = NULL;
    }
      cout << "=======================================================" << endl;
        cout << "=======================================================" << endl;
        cout << endl;
        cout << "Data Pasien Berhasil di hapus!!" << endl;
        cout << endl;
}

 void deleteDataPasien(RumahSakit &RS,adr_pasien prec, adr_pasien &P,adr_dokter q, int kode_pasien){
    adr_pasien R = findPasien(RS, kode_pasien);
    adr_pasien n = pasienDk(q);
    q = findDokterbyPasien(RS,kode_pasien);
    while (n != pasienDk(q)){
                n = nextCh(n);
    }
    if (R != NULL) {
       if (R == pasienDk(q)) {
            deleteFirstPasien(RS, P, q);
        }else if(R==n){
            deleteLastPasien(RS,P,q);
        }else {
            prec = pasienDk(q);
            while (nextCh(prec) != R) {
                prec = nextCh(prec);
            }
            deleteAfterPasien(RS, prec, P, q);
        }

    } else {
        cout << "Data pasien tidak ditemukan." << endl;
    }

}


//Show
void showAllDokter(RumahSakit RS){
    adr_dokter P = first(RS);
    if (P != NULL){
        while (P != NULL) {
            cout << "Kode dokter: " << infoPr(P).kode_dokter << endl;
            cout << "Nama dokter:" << infoPr(P).nama_dokter << endl;
            cout << "Spesialisasi: " << infoPr(P).spesialisasi << endl;
            cout << "Nomor Telepon: " << infoPr(P).no_telepon << endl;
            cout << endl;
            P = nextPr(P);
        }
    }else{
        cout << "Data Dokter Kosong!" << endl;
    }


}
void showPasienOfDokter(RumahSakit RS, int kode_dokter){
    adr_dokter q = findDokter(RS,kode_dokter);
    if (q != NULL){
        adr_pasien p = pasienDk(q);
        if (p != NULL) {
            do {
                cout << "Kode pasien: " << infoCh(p).kode_pasien << endl;
                cout << "Nama pasien:" << infoCh(p).nama << endl;
                cout << "Umur pasien: " << infoCh(p).umur << endl;
                cout << "Riwayat penyakit: " << infoCh(p).riwayat_penyakit << endl;
                cout << endl;
                p = nextCh(p);
            } while (p != pasienDk(q));
        } else {
            cout << "Dokter tidak memiliki pasien." << endl;
        }
    }else{
        cout << "Data pasien tidak ditemukan."<<endl;
    }
}
void showDokterWithPasien(RumahSakit RS){
    adr_dokter q = first(RS);
    if (q != NULL){
        while (q != NULL){
        cout << endl;
        cout << "DOKTER: " << endl;
        cout << "Kode dokter: " << infoPr (q).kode_dokter << endl;
        cout << "Nama dokter:" << infoPr(q).nama_dokter << endl;
        cout << "Spesialisasi: " << infoPr(q).spesialisasi << endl;
        cout << "Nomor Telepon: " << infoPr(q).no_telepon << endl;
        cout << endl;
        cout << "DAFTAR PASIEN: " << endl;
        cout <<endl;
        showPasienOfDokter(RS, infoPr(q).kode_dokter);
        cout << "=======================================================" << endl;
        q = nextPr(q);
        }
    }else{
         cout << "Tidak Ada Data Dokter Dan Pasien"<<endl;
    }


}
void showDokterByPasien(RumahSakit RS, int kode_pasien) {
    adr_dokter P = first(RS);
    while (P != NULL) {
        adr_pasien Q = pasienDk(P);
        adr_pasien R = findPasien(RS, kode_pasien);
        if (R != NULL){
                if(Q!= NULL){
                    do{
                        if (infoCh(Q).kode_pasien == kode_pasien) {
                        cout << "Data Dokter berdasarkan Pasien dengan Kode " << kode_pasien << ":" << endl;
                        cout << "Kode dokter: " << infoPr(P).kode_dokter << endl;
                        cout << "Nama dokter: " << infoPr(P).nama_dokter << endl;
                        cout << "Spesialisasi: " << infoPr(P).spesialisasi << endl;
                        cout << "Nomor Telepon: " << infoPr(P).no_telepon << endl;
                        cout << "=======================================================" << endl;
                        }
                        Q = nextCh(Q);
                    }while(Q != pasienDk(P));
                }

        }else{
            cout << "Data Pasien Tidak Ditemukan!!"<< endl;
        }
        P = nextPr(P);
    }


}


// count

int countPasienOfDokter(RumahSakit RS, int kode_dokter){
    int countPasien = 0;
    adr_dokter foundq = findDokter(RS,kode_dokter);
    if (foundq != NULL){
        adr_pasien p = pasienDk(foundq);
        if (pasienDk(foundq)!= NULL){
            do {
                countPasien++;
                p = nextCh(p);
            } while(p != pasienDk(foundq));
        }
    }
    return countPasien;
}
void countPasienAllDokter(RumahSakit RS){
    adr_dokter q = first(RS);
    while (q!= NULL){
        int countp = countPasienOfDokter(RS, infoPr(q).kode_dokter);
        cout << "Nama Dokter: " << infoPr(q).nama_dokter<<endl;
        cout << "Jumlah Pasien: " << countp <<endl;
        q = nextPr(q);
    }
}
void countPasien(RumahSakit RS, int kode_pasien) {
    int countPasien = 0;
    adr_dokter P = first(RS);
    while (P != NULL) {
        adr_pasien Q = pasienDk(P);
        if (Q != NULL) {
            do {
                if (infoCh(Q).kode_pasien == kode_pasien) {
                    countPasien++;
                }
                Q = nextCh(Q);
            } while (Q != pasienDk(P));
        }
        P = nextPr(P);
    }
    cout << "Jumlah pasien dengan kode " << kode_pasien << ": " << countPasien << endl;
}

void countDokterofPasien(RumahSakit RS, int kode_pasien) {
    int countDokter = 0;
    adr_dokter P = first(RS);

    while (P != NULL) {
        adr_pasien Q = pasienDk(P);
        if (Q != NULL){
            if (infoCh(Q).kode_pasien == kode_pasien) {
                countDokter++;
            }
            Q = nextCh(Q);
        }
        P = nextPr(P);
    }
    cout << "Jumlah dokter dengan kode pasien tertentu: " << countDokter << endl;
}


void editPasienDariDokterTertentu(RumahSakit RS, int kode_dokterA, int kode_dokterB, int kode_pasien) {
    adr_dokter cariDokterA = findDokter(RS, kode_dokterA);
    adr_dokter cariDokterB = findDokter(RS, kode_dokterB);

    if (cariDokterA != NULL && cariDokterB != NULL) {
        adr_pasien gantiPasien = pasienDk(cariDokterA);
        adr_pasien prec, P;
        adr_pasien newPasien;

        if (gantiPasien != NULL) {
            do {
                if (infoCh(gantiPasien).kode_pasien == kode_pasien) {
                    newPasien = gantiPasien;
                }
                gantiPasien = nextCh(gantiPasien);
            } while (gantiPasien != pasienDk(cariDokterA));

            // Delete Pasien from Dokter A
            deleteDataPasien(RS, prec, P, cariDokterA, kode_pasien);

            // Insert Pasien to Dokter B
            insertDataPasien(RS, newPasien, cariDokterB);

            cout << "Data Pasien Berhasil Diubah!" << endl;
        } else {
            cout << "Data Pasien Tidak Ditemukan!" << endl;
        }
    } else {
        cout << "Data Dokter Tidak Ditemukan!" << endl;
    }
}


int selectMenu() {
    cout << "=======================================================" << endl;
    cout << "================= SISTEM MANAJEMEN DATA ==============="<<endl;
    cout << "=================== DOKTER DAN PASIEN ================="<<endl;
    cout << "====================== RUMAH SAKIT ===================="<<endl;
    cout << "=======================================================" << endl;
    cout << "==   "<< "1. Tambah data dokter" << "                           =="<< endl;
    cout << "==   "<< "2. Tambah data pasien" << "                           =="<< endl;
    cout << "==   "<< "3. Hapus data dokter" << "                            =="<< endl;
    cout << "==   "<< "4. Hapus data pasien" << "                            =="<< endl;
    cout << "==   "<< "5. Cari data dokter" << "                             =="<< endl;
    cout << "==   "<< "6. Cari data dokter dari pasien tertentu" << "        =="<< endl;
    cout << "==   "<< "7. Tampilkan semua data dokter" << "                  =="<< endl;
    cout << "==   "<< "8. Tampilkan data pasien dari dokter tertentu" << "   =="<< endl;
    cout << "==   "<< "9. Tampilkan data dokter berserta pasiennya " << "    =="<< endl;
    cout << "==   "<< "10. Tampilkan data dokter dari pasien tertentu" << "  =="<< endl;
    cout << "==   "<< "11. Jumlah pasien dari dokter tertentu" << "          =="<< endl;
    cout << "==   "<< "12. Jumlah pasien setiap dokter" << "                 =="<< endl;
    cout << "==   "<< "13. Jumlah pasien tertentu   " << "                   =="<< endl;
    cout << "==   "<< "14. Jumlah dokter dari pasien tertentu" << "          =="<< endl;
    cout << "==   "<< "15. Edit data dokter/pasien" << "                     =="<< endl;
    cout << "==   "<< "0. Keluar" << "                                       =="<< endl;

    cout << "=======================================================" << endl;
    cout << "=======================================================" << endl;
    int input = 0;
    cout << "Pilih menu: ";
    cin >> input;

    return input;
    cout << "=======================================================" << endl;
    cout << "=======================================================" << endl;
}


#endif // KOPIANTUBES_CPP_INCLUDED
