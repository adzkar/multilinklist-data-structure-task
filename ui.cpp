#include "ui.h"

// menu utama
int menuUtama() {
    cout << "== Menu Utama Program ==" << endl;
    cout << " " << endl;
    cout << "#1 Tambah Manager" << endl;
    cout << "#2 Tambah Karyawan" << endl;
    cout << "#3 Manager Memilih Karyawan" << endl;
    cout << "#4 Karyawan Memilih Manager" << endl;
    cout << "#5 Lihat Jumlah Karyawan dan Manager" << endl;
    cout << "#6 Keluar" << endl;
    cout << "" << endl;
    cout << "Pilih [ Dengan mengisi angka ] : ";
    int x;
    cin >> x;
    return x;
};