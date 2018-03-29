#include "head.h"

using namespace std;

int main(){
    list_stud daftarSiswa;
    list_class daftarKelas;
    createListStud(daftarSiswa);
    createListClass(daftarKelas);

    infotype_stud siswa;
    siswa.id = 1;
    siswa.name = "Budi";
    infotype_class kelas;
    insertLastStud(daftarSiswa,allocate_stud(siswa));
    insertLastClass(daftarKelas,allocate_class(kelas));

    cout << "List saat ini :" << endl;
    printClass(daftarKelas);
    printStud(daftarSiswa);
    cout << endl;


    return 0;
};