#include "ui.h"
#include "clrscr.h"

void anyKey(void) {
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
    cout << "#11 Lihat Karyawan berdasarkan Manager" << endl;
    cout << "#13 Lihat Jumlah Karyawan dan Manager" << endl;
    cout << "#14 Keluar" << endl;
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
    cout << "Nama   : ";cin >> manager.nama;
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
    cout << "ID     : ";cin >> karyawan.id;
    cout << "Nama   : ";cin >> karyawan.nama;
    adr_class P = allocate_class(karyawan);
    insertFirstClass(list_karyawan, P);
    anyKey();
}


// Function untuk Lihat Data
void lihatManager(list_stud &list_manager) {
    cout << "== Daftar Manager ==" << endl;
    cout << " " << endl;
    if(banyakStud(list_manager) > 0) {
        printStud(list_manager);
    } else {
        cout << "Belum ada Manager yang ditambahkan" << endl;    
    }
    cout << " " << endl;
    anyKey();
}
void lihatKaryawan(list_class &list_karyawan) {
    cout << "== Daftar Karyawan ==" << endl;
    cout << " " << endl;
    if(banyakClass(list_karyawan) > 0) {
        printClass(list_karyawan);
    } else {
        cout << "Belum ada Karyawan yang ditambahkan" << endl;
    }    
    cout << " " << endl;
    anyKey();
}
void karyawanByManager(list_stud &list_manager) {
    string id_manager;
    cout << "==  Lihat Karyawan berdasarkan Manager ==" << endl;
    cout << " " << endl;
    lihatManager(list_manager);
    cout << "Pilih Manager [ Input ID ] : ";
    cin >> id_manager;
    adr_stud cariManager = search_stud(list_manager, id_manager);    
    if(cariManager != 0) {
        printRelasiStud(cariManager->relasi_stud);
    } else {
        cout << "ID Tidak Ditemukan" << endl;
    }
    anyKey();
};
// Akhir Function untuk Lihat Data


// Function untuk melihat banyak karyawan dan manager
void banyakManagerKaryawan(list_stud &list_manager, list_class &list_karyawan) {
    cout << " " << endl;
    cout << "== Banyak Manager ==" << endl;
    cout << " " << endl;
    cout << "Total Manager : " << banyakStud(list_manager) << endl;
    cout << " " << endl;
    cout << "== Banyak Karyawan == " << endl;
    cout << " " << endl;
    cout << "Total Karyawan : " << banyakClass(list_karyawan) << endl;
    cout << " " << endl;
    anyKey();
}


// function untuk mengatur relasi
void managerPilihKaryawan(list_stud list_manager, list_class list_karyawan) {
    if(banyakStud(list_manager) > 0 && banyakClass(list_karyawan) > 0) {
        // proses input data
        string id_karyawan, id_manager;
        cout << "== Daftar Karyawan ==" << endl;
        cout << " " << endl;
        printStud(list_manager);
        cout << "Pilih Manager [ Input ID ] : ";
        cin >> id_manager;
        cout << " " << endl;
        cout << "== Daftar Karyawan ==" << endl;
        cout << " " << endl;
        printClass(list_karyawan);    
        cout << "Pilih Karyawan [ Input ID ] : ";
        cin >> id_karyawan; 
        // proses searching berdasarkan id_karyawan dan id_manager
        adr_stud cariManager = search_stud(list_manager, id_manager);
        adr_class cariKaryawan = search_class(list_karyawan, id_karyawan);
        if(cariKaryawan != 0 && cariManager != 0) {
            adr_relasi_ke_kelas P = allocate_relationSatu(cariKaryawan);
            if (cariManager->relasi_stud.first == 0) {
                createListRelasiStud(cariManager->relasi_stud);
            }
            insertFirstRelasiStud(cariManager->relasi_stud, P);
        } else {
            cout << "ID tidak ditemukan" << endl;
        }
    } else {
        cout << "Input Manager dan Karyawan terlebih dahulu" << endl;
    }
    anyKey();
};


void karyawanPilihManager(list_class list_karyawan, list_stud list_manager);
