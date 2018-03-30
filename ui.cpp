#include "ui.h"

void anyKey() {
    cout << " " << endl;
    cout << "   [PRESS ANY KEY TO CONTINUE]" << endl;
    cin.ignore();
    cin.get();
};


// menu utama
int menuUtama() {
    cout << "==    Menu Utama Program ==" << endl;
    cout << " " << endl;
    cout << "#1  Tambah Manager" << endl;
    cout << "#2  Tambah Karyawan" << endl;
    cout << "#3  Manager Memilih Karyawan" << endl;
    cout << "#4  Karyawan Memilih Manager" << endl;
    cout << "#5  Hapus Karyawan" << endl;
    cout << "#6  Hapus Manager" << endl;
    cout << "#7  Update Data Karyawan" << endl;
    cout << "#8  Update Data Manager" << endl;
    cout << "#9  Lihat Manager" << endl;
    cout << "#10 Lihat Karyawan" << endl;
    cout << "#11 Lihat Jumlah Karyawan dan Manager" << endl;
    cout << "#12 Keluar" << endl;
    cout << "" << endl;
    cout << "Pilih [ Dengan mengisi angka ] : ";
    int x;
    cin >> x;
    return x;
};


// Function untuk tambah Manager
void tambahManager(list_stud &list_manager) {
    // variable yang dibutuhkan
    infotype_stud manager;
    // proses input
    cout << "== Tambah Manager ==" << endl;
    cout << " " << endl;
    cout << "ID     : ";cin >> manager.id;
    cout << "Nama   : ";cin >> manager.name;
    adr_stud P = allocate_stud(manager);
    insertFirstStud(list_manager, P);
    anyKey();
}
void tambahKaryawan(list_class &list_karyawan) {
    // variable yang dibutuhkan
    infotype_class karyawan;
    // proses input
    cout << "== Tambah karyawan ==" << endl;
    cout << " " << endl;
    // cout << "ID     : ";cin >> karyawan.id;
    cout << "Nama   : ";cin >> karyawan.nama;
    adr_class P = allocate_class(karyawan);
    insertFirstClass(list_karyawan, P);
    anyKey();
}


// Function untuk Lihat Data
void lihatManager(list_stud &list_manager) {
    cout << "== Daftar Manager ==" << endl;
    cout << " " << endl;
    printStud(list_manager);
    cout << " " << endl;
}
void lihatKaryawan(list_class &list_karyawan) {
    cout << "== Daftar Karyawan ==" << endl;
    cout << " " << endl;
    printClass(list_karyawan);
    cout << " " << endl;
}