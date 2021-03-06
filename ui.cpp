#include "ui.h"
#include "clrscr.h"

void anyKey(void) {
    cout << " " << endl;
    cout << "   [PRESS ANY KEY TO CONTINUE]" << endl;
    cin.get();
    cin.ignore();
    clrscr();
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
    cout << "#7  Update Data Manager" << endl;
    cout << "#8  Update Data Karyawan" << endl;
    cout << "#9  Lihat Manager" << endl;
    cout << "#10 Lihat Karyawan" << endl;
    cout << "#11 Lihat Karyawan berdasarkan Manager" << endl;
    cout << "#12 Lihat Manager berdasarkan Karyawan" << endl;
    cout << "#13 Lihat Jumlah Karyawan dan Manager" << endl;
    cout << "#14 Sorting Manager" << endl;
    cout << "#15 Keluar" << endl;
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
    cin.ignore();
    cout << "ID     : ";getline(cin, manager.id);
    // cin >> manager.id;
    cout << "Nama   : ";getline(cin, manager.nama);
    // cin >> manager.nama;
    adr_stud P = allocate_stud(manager);
    insertFirstStud(list_manager, P);
    anyKey();
    clrscr();
}
void tambahKaryawan(list_class &list_karyawan) {
    // variable yang dibutuhkan
    infotype_class karyawan;
    // proses input
    cout << "== Tambah karyawan ==" << endl;
    cout << " " << endl;
    cin.ignore();
    cout << "ID     : ";getline(cin, karyawan.id);
    // cin >> karyawan.id;
    cout << "Nama   : ";getline(cin, karyawan.nama);
    // cin >> karyawan.nama;
    adr_class P = allocate_class(karyawan);
    insertFirstClass(list_karyawan, P);
    anyKey();
    clrscr();
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
    clrscr();
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
    clrscr();
}

void karyawanByManager(list_stud &list_manager) {
    string id_manager;
    cout << "==  Lihat Karyawan berdasarkan Manager ==" << endl;
    cout << " " << endl;
    lihatManager(list_manager);
    cout << "Pilih Manager [ Input ID ] : ";
    // cin >> id_manager;
    getline(cin, id_manager);
    adr_stud cariManager = search_stud(list_manager, id_manager);    
    if(cariManager != 0) {
        printRelasiStud(cariManager->relasi_stud);
    } else {
        cout << "ID Tidak Ditemukan" << endl;
    }
    anyKey();
    clrscr();
};

void managerByKaryawan(list_class &list_karyawan) {
    string id_karyawan;
    cout << "==  Lihat Manager berdasarkan Karyawan ==" << endl;
    cout << " " << endl;
    lihatKaryawan(list_karyawan);
    cout << "Pilih Karyawan [ Input ID ] : ";
    // cin >> id_karyawan;
    getline(cin, id_karyawan);
    adr_class cariKaryawan = search_class(list_karyawan, id_karyawan);    
    if(cariKaryawan != 0) {
        printRelasiClass(cariKaryawan->relasi_class);
    } else {
        cout << "ID Tidak Ditemukan" << endl;
    }
    anyKey();
    clrscr();
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
    clrscr();
}


// function untuk mengatur relasi
void managerPilihKaryawan(list_stud list_manager, list_class list_karyawan) {
    if(banyakStud(list_manager) > 0 && banyakClass(list_karyawan) > 0) {
        // proses input data
        string id_karyawan, id_manager;
        cout << "== Daftar Manager ==" << endl;
        cout << " " << endl;
        printStud(list_manager);
        cout << "Pilih Manager [ Input ID ] : ";
        // cin >> id_manager;
        getline(cin, id_manager);
        cout << " " << endl;
        cout << "== Daftar Karyawan ==" << endl;
        cout << " " << endl;
        printClass(list_karyawan);    
        cout << "Pilih Karyawan [ Input ID ] : ";
        // cin >> id_karyawan; 
        getline(cin, id_karyawan);
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
    clrscr();
};


void karyawanPilihManager(list_class list_karyawan, list_stud list_manager) {
    if(banyakStud(list_manager) > 0 && banyakClass(list_karyawan) > 0) {
        // proses input data
        string id_karyawan, id_manager;
        cout << "== Daftar Karyawan ==" << endl;
        printClass(list_karyawan);    
        cout << " " << endl;
        cout << "Pilih Karyawan [ Input ID ] : ";
        // cin >> id_karyawan; 
        getline(cin, id_karyawan);
        cout << " " << endl;
        cout << "== Daftar Manager ==" << endl;
        cout << " " << endl;
        printStud(list_manager);
        cout << "Pilih Manager [ Input ID ] : ";
        getline(cin, id_manager);
        // cin >> id_manager;
        // proses searching berdasarkan id_karyawan dan id_manager
        adr_stud cariManager = search_stud(list_manager, id_manager);
        adr_class cariKaryawan = search_class(list_karyawan, id_karyawan);
        if(cariKaryawan != 0 && cariManager != 0) {
            adr_relasi_ke_stud P = allocate_relationDua(cariManager);
            if (cariKaryawan->relasi_class.first == 0) {
                createListRelasiClass(cariKaryawan->relasi_class);
            }
            insertFirstRelasiClass(cariKaryawan->relasi_class, P);
        } else {
            cout << "ID tidak ditemukan" << endl;
        }
    } else {
        cout << "Input Manager dan Karyawan terlebih dahulu" << endl;
    }
    anyKey();
    clrscr();
};
// Akhir function untuk mengatur relasi




// Function untuk update data
void updateDataManager(list_stud &list_manager) {
    string id_manager;
    cout << " " << endl;
    cout << "== Pilih Manager yang Ingin diupdate ==" << endl;
    cout << " " << endl;
    printStud(list_manager);
    cout << " " << endl;
    cout << " Input ID : ";
    // cin >> id_manager;
    getline(cin, id_manager);
    adr_stud cariManager = search_stud(list_manager, id_manager);
    if(cariManager != 0) {
        int opsi;
        cout << " " << endl;
        cout << "Opsi yang ingin di update : " << endl;
        cout << " " << endl;
        cout << " #1 ID" << endl;
        cout << " #2 Nama" << endl;
        cout << " " << endl;
        cout << "Input [ Input dengan Angka ] : ";cin >> opsi;
        switch(opsi) {
            case 1 : {
                cout << "Input ID Terbaru : ";
                // cin >> cariManager->info.id;
                getline(cin, cariManager->info.id);
            }
                break;
            case 2 : {
                cout << "Input Nama Terbaru : ";
                // cin >> cariManager->info.nama;
                getline(cin, cariManager->info.nama);
            }
                break;
            default: {
                cout << " Invalid Input" << endl;
            }
                break;
        }
    } else {
        cout << "ID tidak ditemukan" << endl;
    }
    anyKey();
    clrscr();
}
void updateDataKaryawan(list_class &list_karyawan) {
    string id_karyawan;
    cout << " " << endl;
    cout << "== Pilih Karyawan yang Ingin diupdate ==" << endl;
    cout << " " << endl;
    printClass(list_karyawan);
    cout << " " << endl;
    cout << " Input ID : ";getline(cin, id_karyawan);
    // cin >> id_karyawan;
    adr_class cariKaryawan = search_class(list_karyawan, id_karyawan);
    if(cariKaryawan != 0) {
        int opsi;
        cout << " " << endl;
        cout << "Opsi yang ingin di update : " << endl;
        cout << " " << endl;
        cout << " #1 ID" << endl;
        cout << " #2 Nama" << endl;
        cout << " " << endl;
        cout << "Input [ Input dengan Angka ] : ";cin >> opsi;
        switch(opsi) {
            case 1 : {
                cout << "Input ID Terbaru : ";
                // cin >> cariKaryawan->info.id;
                getline(cin, cariKaryawan->info.id);
            }
                break;
            case 2 : {
                cout << "Input Nama Terbaru : ";
                // cin >> cariKaryawan->info.nama;
                getline(cin, cariKaryawan->info.nama);
            }
                break;
            default: {
                cout << " Invalid Input" << endl;
            }
                break;
        }
    } else {
        cout << "ID tidak ditemukan" << endl;
    }
    anyKey();
    clrscr();
};
// Akhir function untuk update data


// Function untuk hapus
void hapusManager(list_stud &list_manager, list_class &list_karyawan) {
    string id_manager;
    cout << " " << endl;
    cout << "== List Manager ==" << endl;
    cout << " " << endl;
    printStud(list_manager);
    cout << " Input ID : ";getline(cin, id_manager);
    // cin >> id_manager;
    // proses pencarian data
    adr_stud cariManager = search_stud(list_manager, id_manager);
    if(cariManager != NULL) {
        // Hapus Relasi
        adr_class P = list_karyawan.first;
        while(P != NULL) {
            adr_relasi_ke_stud Q = P->relasi_class.first;
            while(Q != NULL) {
                if(Q->next_stud == cariManager) {
                   if(Q == P->relasi_class.first) {
                       deleteFirstRelasiClass(P->relasi_class);
                   } else if (Q == P->relasi_class.last) {
                       deleteLastRelasCilass(P->relasi_class);
                   } else {
                       deleteIniRelasiClass(P->relasi_class, Q);
                   }
                }
                Q = Q->next;
            }
            P = P->next;
        }
        // proses penghapus elemen
        if(cariManager == list_manager.first) {
            deleteFirstStud(list_manager);
        } else if (cariManager == list_manager.last) {
            deleteLastStud(list_manager);
        } else {
            deleteIni(list_manager, cariManager);   
        }
    }
};
void hapusKaryawan(list_class &list_karyawan, list_stud &list_manager) {
    string id_karyawan;
    cout << " " << endl;
    cout << "== List Karyawan ==" << endl;
    cout << " " << endl;
    printClass(list_karyawan);
    cout << " Input ID : ";getline(cin, id_karyawan);
    // cin >> id_karyawan;
    // proses pencarian data
    adr_class cariKaryawan = search_class(list_karyawan, id_karyawan);
    adr_class entah;
    if(cariKaryawan != NULL) {
        // Hapus Relasi
        adr_stud P = list_manager.first;
        while(P != NULL) {
            adr_relasi_ke_kelas Q = P->relasi_stud.first;
            while(Q != NULL) {
                if(Q->next_class == cariKaryawan) {
                   if(Q == P->relasi_stud.first) {
                       deleteFirstRelasiStud(P->relasi_stud);
                   } else if (Q == P->relasi_stud.last) {
                       deleteLastRelasiStud(P->relasi_stud);
                   } else {
                       deleteIniRelasiStud(P->relasi_stud, Q);
                   }
                }
                Q = Q->next;
            }
            P = P->next;
        }
        // proses penghapus elemen
        if(cariKaryawan == list_karyawan.first) {
            deleteFirstClass(list_karyawan, entah);
        } else if (cariKaryawan->next == NULL) {
            deleteLastClass(list_karyawan, entah);
        } else {
            deleteIniDua(list_karyawan, cariKaryawan);
        }
    }
};
// Akhir function untuk hapus