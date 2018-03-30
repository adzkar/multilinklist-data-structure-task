#include "ui.h"

using namespace std;

int main(){


    // membuat list terlebih dahulu
    list_stud list_manager;
    list_class list_karyawan;

    // membuat list
    createListStud(list_manager);
    createListClass(list_karyawan);

    int x;
    do {
        x = menuUtama();
        switch(x) {
            case 1 : {
                cout << " " << endl;
                tambahManager(list_manager);
            }
                break;
            case 2 : {
                cout << " " << endl;
                tambahKaryawan(list_karyawan);
            } 
                break;
            case 9 : {
                lihatManager(list_manager);
            }
                break;
            case 10 : {
                lihatKaryawan(list_karyawan);
            }
                break;
            default:
                break;
        }
    } while(x != 12);


    return 0;
};