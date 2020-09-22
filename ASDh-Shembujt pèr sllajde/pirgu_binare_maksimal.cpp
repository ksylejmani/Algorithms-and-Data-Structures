//#include<iostream>
//#include<math.h>
//using namespace std;
//class pirgu_binare_maksimal {
//private:
//	int* vlerat, kapaciteti, numri_vlerave, lartesia_pemes;
//	void zmadho_kapacitetin(int _lartesia_pemes);
//public:
//	pirgu_binare_maksimal(int _lartesia_pemes = 3) {
//		numri_vlerave = 0;
//		lartesia_pemes = _lartesia_pemes;
//		// Numri maksimal i nyjeve sipas shprehjes n=2^(h+1)-1
//		kapaciteti = pow(2, lartesia_pemes + 1) - 1;
//		vlerat = new int[kapaciteti];
//	}
//	void shto(int vlera);
//	void krijo_prej_vargu_nlogn(int vargu[], int m);
//	void krijo_prej_vargu_n(int vargu[], int m);
//	void largo_max();
//	int trego_max();
//	void shtyp_pirgun();
//	int madhesia();
//	bool i_zbrazet();
//};
//void main() {
//	pirgu_binare_maksimal pbm1, pbm2, pbm3;
//	pbm1.shto(10); pbm1.shto(12);
//	pbm1.shto(34); pbm1.shto(7);
//	pbm1.shto(48);
//	pbm1.shtyp_pirgun();
//	cout << "Maksimalja: " << pbm1.trego_max() << endl;
//
//	const int m = 10; int A[m] = {2,7,26,25,19,17,1,90,3,36 };
//	pbm2.krijo_prej_vargu_nlogn(A, m);
//	pbm2.shtyp_pirgun();
//	cout << "Maksimalja: " << pbm2.trego_max() << endl;
//
//	pbm3.krijo_prej_vargu_n(A, m);
//	pbm3.shtyp_pirgun();
//	cout << "Maksimalja: " << pbm3.trego_max() << endl;
//
//	pbm3.largo_max();
//	pbm3.largo_max();
//	pbm3.shtyp_pirgun();
//	cout << "Maksimalja: " << pbm3.trego_max() << endl;
//}
//void pirgu_binare_maksimal::zmadho_kapacitetin(int _lartesia_pemes) {
//	kapaciteti = pow(2, lartesia_pemes + 1) - 1;
//	int* vlerat_reja = new int[kapaciteti];
//	for (int i = 0; i < numri_vlerave; i++)
//		vlerat_reja[i] = vlerat[i];
//	delete[] vlerat;
//	vlerat = vlerat_reja;
//}
//void pirgu_binare_maksimal::shto(int vlera) {
//	if (numri_vlerave == kapaciteti - 1) {
//		lartesia_pemes += 1;
//		this->zmadho_kapacitetin(lartesia_pemes);
//	}
//	vlerat[numri_vlerave] = vlera;
//	int indeksi = numri_vlerave;
//	while (indeksi > 0)
//	{
//		int indeksi_prindit = (indeksi - 1) / 2;
//		if (vlerat[indeksi] > vlerat[indeksi_prindit]) {
//			int perkohshme = vlerat[indeksi];
//			vlerat[indeksi] = vlerat[indeksi_prindit];
//			vlerat[indeksi_prindit] = perkohshme;
//		}
//		else
//			break;
//		indeksi = indeksi_prindit;
//	}
//	numri_vlerave += 1;
//}
//void pirgu_binare_maksimal::krijo_prej_vargu_nlogn(int vargu[], int m) {
//	for (int i = 0; i < m; i++)
//		this->shto(vargu[i]);
//}
//void pirgu_binare_maksimal::krijo_prej_vargu_n(int vargu[], int m) {
//	if (kapaciteti < m) {
//		int lartesia_pemes = ceil(log2(m + 1) - 1); // lartesia e pemes e rrumbullaksuar lart
//		this->zmadho_kapacitetin(lartesia_pemes);
//	}
//
//	for (int i = 0; i < m; i++) {
//		vlerat[i] = vargu[i];
//		numri_vlerave += 1;
//	}
//	for (int i = m / 2 - 1; i >= 0; i--) {
//		int indeksi = i;
//		while (indeksi <= m / 2 - 1)
//		{
//			int indeksi_max;
//			if (2 * indeksi + 2 == numri_vlerave) {
//				indeksi_max = 2 * indeksi + 1;
//			}
//			else {
//				int majtas = vlerat[2 * indeksi + 1], djathtas = vlerat[2 * indeksi + 2];
//				indeksi_max = (majtas > djathtas) ? (2 * indeksi + 1) : (2 * indeksi + 2);
//			}
//			if (vlerat[indeksi] < vlerat[indeksi_max]) {
//				int perkohshme = vlerat[indeksi];
//				vlerat[indeksi] = vlerat[indeksi_max];
//				vlerat[indeksi_max] = perkohshme;
//			}
//			else
//				break;
//			indeksi = indeksi_max;
//		}
//	}
//}
//void pirgu_binare_maksimal::largo_max() {
//	if (numri_vlerave == 0) {
//		cout << "Pirgu eshte i zbrazte.\n";
//		return;
//	}
//	vlerat[0] = vlerat[numri_vlerave - 1];
//	int indeksi = 0;
//	while (indeksi <= numri_vlerave / 2 - 1)
//	{
//		int indeksi_max;
//		if (2 * indeksi + 2 == numri_vlerave) {
//			indeksi_max = 2 * indeksi + 1;
//		}
//		else {
//			int majtas = vlerat[2 * indeksi + 1], djathtas = vlerat[2 * indeksi + 2];
//			indeksi_max = (majtas > djathtas) ? (2 * indeksi + 1) : (2 * indeksi + 2);
//		}
//		if (vlerat[indeksi] < vlerat[indeksi_max]) {
//			int perkohshme = vlerat[indeksi];
//			vlerat[indeksi] = vlerat[indeksi_max];
//			vlerat[indeksi_max] = perkohshme;
//		}
//		else
//			break;
//		indeksi = indeksi_max;
//	}
//	numri_vlerave -= 1;
//}
//void pirgu_binare_maksimal::shtyp_pirgun() {
//	cout << "Pirgu maksimal: ";
//	for (int i = 0; i < numri_vlerave; i++)
//		cout << vlerat[i] << " ";
//	cout << endl;
//}
//int pirgu_binare_maksimal::trego_max() {
//	return vlerat[0];
//}
//int pirgu_binare_maksimal::madhesia() {
//	return numri_vlerave;
//}
//bool pirgu_binare_maksimal::i_zbrazet() {
//	return numri_vlerave == 0;
//}