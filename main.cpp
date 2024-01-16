#include <iostream>
#include "kopiantubes.h"
using namespace std;

int main()
{
   int pilih;
   RumahSakit RS;
   adr_dokter q,prec;
   adr_pasien p,precPasien;
   infotypeD inDk;
   infotypeP inPs;
   int kode_dokter, kode_pasien;

    createListDokter(RS);

   pilih = selectMenu();
   while(pilih != 0){
    switch(pilih){
    case 1:
        adr_dokter cari;
        cout << "Masukkan Kode Dokter (Dalam bentuk Angka): ";
        cin >> inDk.kode_dokter;
        cari = findDokter(RS, inDk.kode_dokter);
        if (cari == NULL){
            cout << "Masukkan Nama Dokter: ";
            cin >> inDk.nama_dokter;
            cout << "Masukkan Spesialisasi: ";
            cin >> inDk.spesialisasi;
            cout << "Masukkan Nomor Telepon (Dalam bentuk Angka): ";
            cin >> inDk.no_telepon;
            q = createElementDokter(inDk);
            insertDataDokter(RS,q);

        }else{
            cout << "Kode Dokter Tidak Boleh sama!!" << endl;
        }
        cout << endl;
        break;
    case 2:
       adr_dokter dk;
       adr_pasien ps;
        cout << "Masukkan Kode Dokter (Dalam Bentuk Angka): ";
        cin >> kode_dokter;
        dk = findDokter(RS,kode_dokter);
        if (dk != NULL ) {
            cout << "Masukkan Kode Pasien (Dalam Bentuk Angka): ";
            cin >> inPs.kode_pasien;
            ps = findPasien(RS,inPs.kode_pasien);
            if (ps == NULL){
                cout << "Masukkan Nama Pasien: ";
                cin >> inPs.nama;
                cout << "Masukkan Umur Pasien (Dalam Bentuk Angka): ";
                cin >> inPs.umur;
                cout << "Masukkan Riwayat Penyakit: ";
                cin >> inPs.riwayat_penyakit;
                p = createElementPasien(inPs);
                insertDataPasien(RS, p, dk);
            }else {
                cout << "Kode pasien tidak boleh sama." << endl;
            }
    }else{
        cout << "Data Dokter Tidak Ditemukan!!!" << endl;
        }
        cout << endl;
        break;
    case 3 :
        cout << "Masukkan Kode Dokter (Dalam Bentuk Angka): ";
        cin >> kode_dokter;
        deleteDataDokter(RS,q,prec,kode_dokter);
        break;
    case 4 :
        cout << "Masukkan Kode Pasien (Dalam Bentuk Angka): ";
        cin >> kode_pasien;
        deleteDataPasien(RS,precPasien,p,q,kode_pasien);
        break;
    case 5:
        cout << "Masukkan Kode Dokter (Dalam Bentuk Angka): ";
        cin >> kode_dokter;
        q = findDokter(RS,kode_dokter);
        if (q != NULL){
            cout << "Data Dokter Di Temukan!!" << endl;
            cout <<endl;
            cout << "Kode dokter: " << infoPr (q).kode_dokter << endl;
            cout << "Nama dokter:" << infoPr(q).nama_dokter << endl;
            cout << "Spesialisasi: " << infoPr(q).spesialisasi << endl;
            cout << "Nomor Telepon: " << infoPr(q).no_telepon << endl;
        }else{
             cout << "Data Dokter Di Tidak di Temukan!!" << endl;
        }
        cout << endl;
        break;
    case 6:
        cout << "Masukkan Kode Pasien (Dalam Bentuk Angka): ";
        cin >> kode_pasien;
        q = findDokterbyPasien(RS,kode_pasien);
        if (q != NULL){
            cout << "Data Dokter Di Temukan!!" << endl;
            cout <<endl;
            showDokterByPasien(RS,kode_pasien);
        }else{
             cout << "Data Dokter Di Tidak di Temukan!!" << endl;
        }
        cout << endl;
        break;
    case 7 :
        showAllDokter(RS);
        cout << endl;
        break;
    case 8:
        cout << "Masukkan Kode Dokter (Dalam Bentuk Angka): ";
        cin >> kode_dokter;
        cout << endl;
        showPasienOfDokter(RS,kode_dokter);
        cout << endl;
        break;
    case 9:
        showDokterWithPasien(RS);
        cout << endl;
        break;
    case 10:
        cout << "Masukkan Kode Pasien (Dalam Bentuk Angka): ";
        cin >> kode_pasien;
        cout << endl;
        showDokterByPasien(RS, kode_pasien);
        cout << endl;
        break;
    case 11:
        int countPS ;
        cout << "Masukkan Kode Dokter (Dalam Bentuk Angka): ";
        cin >> kode_dokter;
        cout << endl;
        countPS = countPasienOfDokter(RS,kode_dokter);
        cout << "Jumlah Pasien: " << countPS << endl;
        break;
    case 12:
        countPasienAllDokter(RS);
        cout << endl;
        break;
    case 13:
        cout << "Masukkan Kode Pasien (Dalam Bentuk Angka): ";
        cin >> kode_pasien;
        cout << endl;
        countPasien(RS,kode_pasien);
        cout << endl;
        break;
     case 14:
        cout << "Masukkan Kode Pasien (Dalam Bentuk Angka): ";
        cin >> kode_pasien;
        cout << endl;
        countDokterofPasien(RS,kode_pasien);
        cout << endl;
        break;
    case 15:
        int kode_dokterA;
        int kode_dokterB;
        cout << "Masukkan Kode Dokter Asal (Dalam Bentuk Angka): ";
        cin >> kode_dokterA;
        cout << "Masukkan Kode Dokter Tujuan (Dalam Bentuk Angka): ";
        cin >> kode_dokterB;
        cout << "Masukkan Kode Pasien yang Ingin Dipindah: ";
        cin >> kode_pasien;
        editPasienDariDokterTertentu(RS,kode_dokterA,kode_dokterB,kode_pasien);
        cout << endl;
        break;
    default:
        cout << endl;
        cout << "SILAHKAN PILIH MENU YANG TELAH DISEDIAKAN!!!" <<endl;
        cout << endl;
    }
    pilih = selectMenu();
   }
   if (pilih == 0){
    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
   }
    return 0;
}
