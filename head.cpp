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
void createListRelasiClass(list_relasi_class &C) {
    C.first = NULL;
    C.last = NULL;
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
adr_relasi_ke_stud allocate_relationDua(adr_stud x) {
    adr_relasi_ke_stud P = new relasi_ke_stud;
    P -> next = NULL;
    P -> prev = NULL;
    P -> next_stud = x;
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
void deleteIni(list_stud &S, adr_stud P) {
    adr_stud A,B;
    A = P->prev;
    B = P->next;
    P->prev = NULL;
    P->next = NULL;
    A->next = B;
    B->prev = A;
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
            cout << "#" << i << ". " << P->info.id << " " << P->info.nama << endl;
            P = P -> next;
            i++;
        }
    };
};
    // Akhir function untuk print stud

// Function untuk menghitung total data
int banyakStud(list_stud &S) {
    int total = 0;
    if(S.first != NULL && S.last != NULL) {
        adr_stud P = S.first;
        while(P != NULL) {
            P = P->next;
            total++;
        }
    }
    return total;
};

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
void deleteIniDua(list_class &C, adr_class P) {
    if (C.first == NULL) {
        cout << "Empty" << endl;
    } else if (C.first == P) {
        C.first = NULL;
    } else if (P->next == NULL) {
        adr_class entah;
        deleteLastClass(C, entah);
    } else {
        adr_class A = C.first;
        while (A->next != P){
            A = A->next;
        };
        A->next = P->next;
        P = NULL;
    }
};
    // Akhir Function untuk delete


    // Function untuk searching class
adr_class search_class(list_class &L, string id){
    adr_class Q = L.first;
    while (Q != NULL && Q->info.id != id) {
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
        int i = 1;
        while (P != NULL) {
            cout << "#" << i << ". "<< P->info.id << "    " << P -> info.nama << endl;
            P = P -> next;
            i++;
        }
    };
};
    // Akhir function untuk print class

// Function untuk menghitung total class
int banyakClass(list_class &C) {
    int total = 0;
    if(C.first != NULL) {
        adr_class P = C.first;
        while(P != NULL) {
            P = P->next;
            total++;
        }
    }
    return total;
};


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
void insertLastRelasiStud(list_relasi_stud &L, adr_relasi_ke_kelas P) {
    if (L.first == NULL && L.last == NULL) {
        L.first = P;
        L.last = P;
    } 
    else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    };
};
    // Akhir Function untuk insert


    // Function untuk delete
void deleteFirstRelasiStud(list_relasi_stud &L) {
    if(L.first == NULL && L.last == NULL) {
        cout << "Empty" << endl;
    } else if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        adr_relasi_ke_kelas P = L.first;
        L.first = P->next;
        P->next = NULL;
        L.first->prev = NULL;
    }
};
void deleteLastRelasiStud(list_relasi_stud &L) {
    if(L.first == NULL && L.last == NULL) {
        cout << "Empty" << endl;
    } else if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        adr_relasi_ke_kelas P = L.last;
        L.last = P->prev;
        P->prev = NULL;
        L.last->next = NULL;
    }
};
void deleteIniRelasiStud(list_relasi_stud &L, adr_relasi_ke_kelas P) {
    adr_relasi_ke_kelas A,B;
    A = P->prev;
    B = P->next;
    P->next = NULL;
    P->prev = NULL;
    A->next = B;
    B->prev = A;
};
    // Akhir Function untuk delete


adr_relasi_ke_kelas searchRelasiStud(list_relasi_stud &L, adr_relasi_ke_kelas P) {

};
void printRelasiStud(list_relasi_stud &L) {
    if (L.first != NULL && L.last != NULL) {
        adr_relasi_ke_kelas P = L.first;
        int i = 1;
        while(P != NULL) {
            cout << "#" << i << ". " << P->next_class->info.id << "     "  << P->next_class->info.nama << endl;
            P = P->next;
            i++;
        };
    } else {
        cout << "Empty List" << endl;
    }
};
// Akhir Kumpulan Function untuk relasi ke kelas


// Kumpulan Function untuk relasi ke Stud

    // Function insert
void insertFirstRelasiClass(list_relasi_class &L, adr_relasi_ke_stud P) {
    if(L.first == NULL && L.last == NULL) {
        L.first = NULL;
        L.last = NULL;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
};
void insertLastRelasiClass(list_relasi_class &L, adr_relasi_ke_stud P) {
    if(L.first == NULL && L.last == NULL) {
        L.first = NULL;
        L.last = NULL;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
};
    // Akhir function insert

    // Function Delete
void deleteFirstRelasiClass(list_relasi_class &L) {
    if(L.first == NULL && L.last == NULL) {
        cout << "Empty" << endl;
    } else if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        adr_relasi_ke_stud P = L.first;
        L.first = P->next;
        P->next = NULL;
        L.first->prev = NULL;
    }
};
void deleteLastRelasCilass(list_relasi_class &L) {
    if(L.first == NULL && L.last == NULL) {
        cout << "Empty" << endl;
    } else if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        adr_relasi_ke_stud P = L.last;
        L.last = P->prev;
        P->prev = NULL;
        L.last->next = NULL;
    }
};
void deleteIniRelasiClass(list_relasi_class &L, adr_relasi_ke_stud P) {
    adr_relasi_ke_stud A,B;
    A = P->prev;
    B = P->next;
    P->next = NULL;
    P->prev = NULL;
    A->next = B;
    B->prev = A;
};
    // Akhir Function Delete

    
adr_relasi_ke_stud searchRelasiClass(list_relasi_class &L, adr_relasi_ke_stud P);

void printRelasiClass(list_relasi_class &L) {
    if (L.first != NULL && L.last != NULL) {
        adr_relasi_ke_stud P = L.first;
        int i = 1;
        while(P != NULL) {
            cout << "#" << i << ". " << P->next_stud->info.id << "     "  << P->next_stud->info.nama << endl;
            P = P->next;
            i++;
        };
    } else {
        cout << "Empty List" << endl;
    }
};
// Akhir Kumpulan Function untuk relasi ke Stud