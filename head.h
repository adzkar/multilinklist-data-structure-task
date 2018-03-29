#include <iostream>
#include <string>

using namespace std;

struct infotype_stud {
    string id;
    string name;
};
struct infotype_class {
    string nama;
};
typedef struct elm_stud*adr_stud;
typedef struct elm_class*adr_class;
typedef struct relasi_ke_kelas*adr_relasi_ke_kelas;

struct list_relasi_stud {
    adr_relasi_ke_kelas first;
    adr_relasi_ke_kelas last;
};
struct elm_stud {
    infotype_stud info;
    adr_stud next;
    adr_stud prev;
    list_relasi_stud relasi_class;
};
struct elm_class {
    infotype_class info;
    adr_class next;
};
struct relasi_ke_kelas {
    adr_class next_class;
    adr_relasi_ke_kelas next;
    adr_relasi_ke_kelas prev;
};

struct list_stud {
    adr_stud first;
    adr_stud last;
};
struct list_class {
    adr_class first;
};

// Create List
void createListStud(list_stud &S);
void createListClass(list_class &C);
void createListRelasiStud(list_relasi_stud &R);

// Allocate function
adr_stud allocate_stud(infotype_stud x);
adr_class allocate_class(infotype_class x);
adr_relasi_ke_kelas allocate_relationSatu(adr_class x);
// end Allocate function


// Kumpulan Funtion untuk student
void insertLastStud(list_stud &S, adr_stud P);
void insertFirstStud(list_stud &S, adr_stud P);
void deleteFirstStud(list_stud &S);
void deleteLastStud(list_stud &S);
adr_stud search_stud(list_stud &S, string id);
void printStud(list_stud &S);
// Akhir kumpulan Function untuk student

// Kumpulan Function untuk Class
void insertFirstClass(list_class &C, adr_class P);
void insertLastClass(list_class &C, adr_class P);
void deleteFirstClass(list_class &C, adr_class P);
void deleteLastClass(list_class &C, adr_class P);
adr_class search_class(list_class &L, string nama);
void printClass(list_class &C);
// Akhir Kumpulan Function untuk Class


// Kumpulan Function untuk relasi ke Kelas
void insertFirstRelasiStud(list_relasi_stud &L, adr_relasi_ke_kelas P);
void insertLastRelasiStud(list_relasi_stud &L, adr_relasi_ke_kelas P);
void deleteLastRelasiStud(list_relasi_stud &L);
void deleteFirstRelasiStud(list_relasi_stud &L);
adr_relasi_ke_kelas searchRelasiStud(list_relasi_stud &L, adr_relasi_ke_kelas P);
void printRelasiStud(list_relasi_stud &L);
// Akhir Kumpulan Function untuk relasi ke kelas


void setClass(list_stud L1, list_class L2, string id, string kelas);
void del_class(list_stud L1, list_class L2, string kelas);
