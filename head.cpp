#include "head.h"

// CreateList Function
void createListStud(list_stud &S){
    S.first = NULL;
    S.last = NULL;
};
void createListClass(list_class &C){
    C.first = NULL;
};
void createListRelasiStud(list_relasi_stud &R) {
    R.first = NULL;
    R.last  = NULL;
};
// End CreateList Function

// Allocate Function
adr_stud allocate_stud(infotype_stud x) {
    adr_stud P = new elm_stud;
    P -> info = x;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
};
adr_class allocate_class(infotype_class x) {
    adr_class P = new elm_class;
    P -> info = x;
    P -> next = NULL;
    return P;
};
adr_relasi_ke_kelas allocate_relationSatu(adr_class x) {
    adr_relasi_ke_kelas P = new relasi_ke_kelas;
    P -> next = NULL;
    P -> prev = NULL;
    P -> next_class = x;
    return P;
};
// End Allocate Function



// Kumpulan Function untuk student

    // Function Insert 
void insertFirstStud(list_stud &S, adr_stud P) {
    if (S.first == NULL && S.last == NULL) {
        S.first = P;
        S.last = P;
    } 
    else {
        P->next = S.first;
        S.first->prev = P;
        S.first = P;
    };
};
void insertLastStud(list_stud &S, adr_stud P) {
    if (S.first == NULL && S.last == NULL) {
        S.first = P;
        S.last = P;
    } 
    else {
        P->prev = S.last;
        S.last->next = P;
        S.last = P;
    };
};
    // Akhir Function Insert


    // Function Delete Stud
void deleteFirstStud(list_stud &S) {
    if(S.first == NULL && S.last == NULL) {
        cout << "Empty" << endl;
    } else if (S.first == S.last) {
        S.first = NULL;
        S.last = NULL;
    } else {
        adr_stud P = S.first;
        S.first = P->next;
        P->next = NULL;
        S.first->prev = NULL;
    }
};
void deleteLastStud(list_stud &S) {
    if(S.first == NULL && S.last == NULL) {
        cout << "Empty" << endl;
    } else if (S.first == S.last) {
        S.first = NULL;
        S.last = NULL;
    } else {
        adr_stud P = S.last;
        S.last = P->prev;
        P->prev = NULL;
        S.last->next = NULL;
    }
};
    // Akhir Function Delete Stud


    // Function Searching untuk stud
adr_stud search_stud(list_stud &S, string id){
    adr_stud Q = S.first;
    while (Q != NULL && Q->info.id != id) {
        Q = Q->next;
    };
    if (Q != NULL){
        return Q;
    } else {
        return NULL;
    }
};
    // Akhir Function Searching untuk stud

    // Function untuk print stud
void printStud(list_stud &S){
    if (S.first == NULL){
        cout << "Empty List" << endl;
    } else {
        adr_stud P = S.first;
        int i = 1;
        while (P != NULL) {
            cout << "#" << i << ". " << P->info.id << " " << P->info.name << endl;
            P = P -> next;
        }
    };
};
    // Akhir function untuk print stud

// Akhir kumpulan Function untuk student







// Kumpulan Function untuk Class

    // Function untuk insert
void insertFirstClass(list_class &C, adr_class P) {
    if (C.first == NULL) {
        C.first = P;
    } else {
        P->next = C.first;
        C.first = P;
    }
};
void insertLastClass(list_class &C, adr_class P){
    if (C.first == NULL) {
        C.first = P;
    } else {
        adr_class Q = C.first;
        while (Q != NULL) {
            Q = Q -> next;
        };
        Q -> next = P;
    };
};
    // Akhir Function Insert


    // Function untuk delete
void deleteFirstClass(list_class &C, adr_class P) {
    if (C.first == NULL) {
        cout << "Empty" << endl;
    } else if (C.first == P) {
        C.first = NULL;
    } else {
        adr_class P = C.first;
        C.first = P->next;
    }
};
void deleteLastClass(list_class &C, adr_class P) {
    if (C.first == NULL) {
        cout << "Empty" << endl;
    } else if (C.first == P) {
        C.first = NULL;
    } else {
        adr_class P = C.first;
        adr_class Q = P->next;
        while(Q != NULL) {
            P = P->next;
            Q = Q->next;
        }
        P->next = NULL;
    }
};
    // Akhir Function untuk delete


    // Function untuk searching class
adr_class search_class(list_class &L, string kelas){
    adr_class Q = L.first;
    while (Q != NULL && Q->info.nama != kelas) {
        Q = Q -> next;
    };
    if (Q == NULL){
        return NULL;
    }
    else {
        return Q;
    }
};
    // Akhir Function untuk searching


    // Function untuk print class
void printClass(list_class &C){
    if (C.first == NULL){
        cout << "Empty List" << endl;
    } else {
        adr_class P = C.first;
        while (P != NULL) {
            cout << P -> info.nama << endl;
            P = P -> next;
        }
    };
};
    // Akhir function untuk print class

// Akhir Kumpulan Function untuk Class


// Kumpulan Function untuk relasi ke Kelas

// Function untuk insert
void insertFirstRelasiStud(list_relasi_stud &L, adr_relasi_ke_kelas P) {
    if (L.first == NULL && L.last == NULL) {
        L.first = P;
        L.last = P;
    } 
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    };
};
void insertLastRelasiStud(list_relasi_stud &L, adr_relasi_ke_kelas P);
// Akhir Function untuk insert

// Function untuk delete
void deleteLastRelasiStud(list_relasi_stud &L);
void deleteFirstRelasiStud(list_relasi_stud &L);
// Akhir Function untuk delete
adr_relasi_ke_kelas searchRelasiStud(list_relasi_stud &L, adr_relasi_ke_kelas P);
void printRelasiStud(list_relasi_stud &L);
// Akhir Kumpulan Function untuk relasi ke kelas