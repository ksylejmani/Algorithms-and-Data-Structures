//#include <iostream>
//using namespace std;
//class kerkimi_perzgjedhja {
//private:
//	int* vlerat;
//	int numri_vlerave;
//public:
//	kerkimi_perzgjedhja(int _vlerat[], int _numri_vlerave);
//	int kerkimi_sekuencial(int _vlera_kerkuar);
//	int kerkimi_binare(int _vlera_kerkuar);
//	int vlera_maksimale();
//	int vlera_k_maksimale(int k);
//	int vlera_k_maksimale_me_rekurzion(int fillimi, int fundi, int k);
//	void shtyp_vlerat();
//};
//void main() {
//	int m = 10, A[] = { 5,2,7,6,9,8,4,3,12,-1 }, vlera_kerkuar = 4;
//	kerkimi_perzgjedhja kp1(A, m);
//	kp1.shtyp_vlerat();
//	int indeksi1 = kp1.kerkimi_sekuencial(vlera_kerkuar);
//	if (indeksi1 != -1)
//		cout << "Vlera e kerkuar '" << vlera_kerkuar
//		<< "' gjendet ne poziten " << indeksi1 + 1 << endl;
//	else
//		cout << "Vlera e kerkuar nuk gjendet ne vargun e vlerave.\n";
//	int B[] = { 2,4,6,9, 10, 11, 16, 15,18, 21 }; vlera_kerkuar = 11;
//	kerkimi_perzgjedhja kp2(B, m);
//	kp2.shtyp_vlerat();
//	int indeksi2 = kp2.kerkimi_binare(vlera_kerkuar);
//	if (indeksi2 != -1)
//		cout << "Vlera e kerkuar '" << vlera_kerkuar
//		<< "' gjendet ne poziten " << indeksi2 + 1 << endl;
//	else
//		cout << "Vlera e kerkuar nuk gjendet ne vargun e vlerave.\n";
//	kp1.shtyp_vlerat();
//	cout << "Vlera maksimale: " << kp1.vlera_maksimale() << endl;
//	int k = 3;
//	kp1.shtyp_vlerat();
//	cout << "Vlera e "<<k<<"-te me e madhe: " << kp1.vlera_k_maksimale(k) << endl;
//	cout << "Vlera e " << k << "-te me e madhe: " 
//		<< kp1.vlera_k_maksimale_me_rekurzion(0,m-1,k-1) << endl;//Indeksi i bazuar ne zero
//}
//kerkimi_perzgjedhja::kerkimi_perzgjedhja(int _vlerat[], int _numri_vlerave) {
//	numri_vlerave = _numri_vlerave;
//	vlerat = new int[numri_vlerave];
//	for (int i = 0; i < numri_vlerave; i++)
//		vlerat[i] = _vlerat[i];
//}
//int kerkimi_perzgjedhja::kerkimi_sekuencial(int _vlera_kerkuar) {
//	int indeksi = -1;
//	for (int i = 0; i < numri_vlerave; i++)
//		if (vlerat[i] == _vlera_kerkuar) {
//			indeksi = i;
//			break;
//		}
//	return indeksi;
//}
//void kerkimi_perzgjedhja::shtyp_vlerat() {
//	cout << "Vlerat: ";
//	for (int i = 0; i < numri_vlerave; i++)
//		cout << vlerat[i] << " ";
//	cout << endl;
//}
//int kerkimi_perzgjedhja::kerkimi_binare(int _vlera_kerkuar) {
//	int indeksi = -1;
//	int fillimi = 0, fundi = numri_vlerave - 1,mesi;
//	while (fillimi<=fundi)
//	{
//		mesi = (fillimi + fundi) / 2;
//		if (_vlera_kerkuar > vlerat[mesi])
//			fillimi = mesi + 1;
//		else if (_vlera_kerkuar < vlerat[mesi])
//			fundi = mesi - 1;
//		else {
//			indeksi = mesi;
//			break;
//		}
//	}
//	return indeksi;
//}
//int kerkimi_perzgjedhja::vlera_maksimale() {
//	int max = vlerat[0];
//	for (int i = 1; i < numri_vlerave; i++)
//		if (vlerat[i] > max) {
//			max = vlerat[i];
//		}
//	return max;
//}
//int kerkimi_perzgjedhja::vlera_k_maksimale(int k) {
//	for (int i = 0; i < k; i++) {
//		int max = vlerat[i];
//		int indeksi_max = i;
//		for(int j=i+1;j<numri_vlerave;j++)
//			if (vlerat[j] > max) {
//				max = vlerat[j];
//				indeksi_max = j;
//			}
//		vlerat[indeksi_max] = vlerat[i];
//		vlerat[i] = max;
//	}
//	return vlerat[k-1];
//}
//int kerkimi_perzgjedhja::vlera_k_maksimale_me_rekurzion(int fillimi, int fundi, int k) {
//	if (fillimi < fundi) {
//		int vlera_qendrore = vlerat[fundi];
//		int i = fillimi - 1;
//		for (int j = fillimi; j <= fundi - 1; j++)
//			if (vlerat[j] >= vlera_qendrore) {
//				i++;
//				int perkohshme1 = vlerat[i];
//				vlerat[i] = vlerat[j];
//				vlerat[j] = perkohshme1;
//			}
//		int perkohshme2 = vlerat[i + 1];
//		vlerat[i + 1] = vlerat[fundi];
//		vlerat[fundi] = perkohshme2;
//		int indeksi_ndarjes = i + 1;
//		if (indeksi_ndarjes == k)
//			return vlerat[indeksi_ndarjes];
//		else if (indeksi_ndarjes > k)
//			return vlera_k_maksimale_me_rekurzion(fillimi, indeksi_ndarjes - 1, k);
//		else
//			return vlera_k_maksimale_me_rekurzion(indeksi_ndarjes + 1, fundi, k);
//	}
//	else
//		return vlerat[fillimi]; // ne kete rast fillimi dhe fundi jane te barabarte
//}