#include "head.h"

using namespace std;

int menuUtama();

// untuk menambah data
void tambahManager(list_stud &L);
void tambahKaryawan(list_class &list_karyawan);


// untuk melihat data
void lihatManager(list_stud &list_manager); 
void lihatKaryawan(list_class &list_karyawan);
void karyawanByManager(list_stud &list_manager);
void managerByKaryawan(list_class &list_karyawan);

// Untuk melihat total data
void banyakManagerKaryawan(list_stud &list_manager, list_class &list_karyawan);


// function untuk mengatur relasi
void managerPilihKaryawan(list_stud list_manager, list_class list_karyawan);
void karyawanPilihManager(list_class list_karyawan, list_stud list_manager);


// Function untuk update data
void updateDataManager(list_stud &list_manager);
void updateDataKaryawan(list_class &list_karyawan);
// Akhir function untuk update data

// Function untuk hapus data
void hapusManager(list_stud &list_manager);
void hapusKaryawan(list_class &list_karyawan);
// akhir function untuk hapus data