//#include <iostream>
//using namespace std;
//int numri_krahasimeve_bubble_sort = 0;
//int numri_krahasimeve_selection_sort = 0;
//int numri_krahasimeve_insertion_sort = 0;
//void bubble_sort(int A[], int m) {
//    int indeksi_elementit_te_fundit_te_pasortuar = m - 1;
//    bool shkembyer;
//    do {
//        shkembyer = false;
//        for (int i = 0; i < indeksi_elementit_te_fundit_te_pasortuar; i++) {
//            numri_krahasimeve_bubble_sort += 1;
//            if (A[i] > A[i + 1]) {
//                int perkohshme = A[i];
//                A[i] = A[i + 1];
//                A[i + 1] = perkohshme;
//                shkembyer = true;
//            }
//        }
//        indeksi_elementit_te_fundit_te_pasortuar--;
//    } while (shkembyer);
//}
//void selection_sort(int A[], int m) {
//    for (int i = 0; i < m - 1; i++) {
//        int min = A[i], indeksi_min = i;
//        for (int j = i + 1; j < m; j++) {
//            numri_krahasimeve_selection_sort += 1;
//            if (A[j] < min) {
//                min = A[j];
//                indeksi_min = j;
//            }
//        }
//        int perkohshme = A[i];;
//        A[i] = min;
//        A[indeksi_min] = perkohshme;
//    }
//}
//void insertion_sort(int A[], int m) {
//    for (int i = 0; i < m; i++) {
//        int e = A[i]; int j = i;
//        while (j > 0) {
//            numri_krahasimeve_insertion_sort++;
//            if (A[j - 1] > e)
//                A[j] = A[j - 1];
//            else
//                break;
//            j--;
//        }
//        A[j] = e;
//    }
//}
//void shtyp(int A[], int m) {
//    for (int i = 0; i < m; i++)
//        cout << A[i] << " ";
//    cout << endl;
//}
//void main() {
//    const int m = 6;
//    int A[m] = { 6, 1, 0, 9, 4, 2 };
//    cout << "Vargu i pasortuar: ";
//    shtyp(A, m);
//    bubble_sort(A, m);
//    cout << "Vargu i sortuar me metoden bubble sort: ";
//    shtyp(A, m);
//    cout << "Numri i krahasimeve me metoden bubble sort: "
//        << numri_krahasimeve_bubble_sort << endl;
//    int B[m] = { 6, 1, 0, 9, 4, 2 };
//    cout << "Vargu i pasortuar: ";
//    shtyp(B, m);
//    selection_sort(B, m);
//    cout << "Vargu i sortuar me metoden selection sort: ";
//    shtyp(B, m);
//    cout << "Numri i krahasimeve me metoden selection sort: "
//        << numri_krahasimeve_selection_sort << endl;
//    int C[m] = { 8, 6, 0, 12,14, 2 };
//    cout << "Vargu i pasortuar: ";
//    shtyp(C, m);
//    insertion_sort(C, m);
//    cout << "Vargu i sortuar me metoden insertion sort: ";
//    shtyp(C, m);
//    cout << "Numri i krahasimeve me metoden insertion sort: "
//        << numri_krahasimeve_insertion_sort << endl;
//}