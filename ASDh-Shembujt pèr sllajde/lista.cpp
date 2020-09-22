//#include <iostream>
//using namespace std;
//struct nyja {
//	int vlera;
//	nyja* tjetra;
//};
//class lista {
//private:
//	nyja* fillimi = NULL, * fundi = NULL;
//	int numri_vlerave = 0;
//public:
//	void shto_ne_fillim(int _vlera);
//	void shto_ne_fund(int _vlera);
//	void shto_pas_nje_vlere(int _vlera_aktuale, int _vlera);
//	void terheqe_ne_fillim();
//	void terheqe_ne_fund();
//	void terheqe_nje_vlere(int _vlera);
//	int vlera_ne_fillim();
//	int vlera_ne_fund();
//	void pershko();
//	int madhesia();
//	bool e_zbrazte();
//	nyja* nyja_ne_fillim();
//	nyja* nyja_ne_fund();
//};
//void main() {
//	lista L;
//	int vlera,veprimi;
//	char perserite = 'p';
//	while (perserite=='p')
//	{
//		cout << "Llojet e veprimeve ne liste:\n"
//			<< "1. Shto ne fillim \n"
//			<< "2. Shto ne fund\n"
//			<< "3. Shto pas nje vlere\n"
//			<< "4. Largo ne fillim\n"
//			<< "5. Largo ne fund\n"
//			<< "6. Largo nje vlere te caktuar\n"
//			<< "7. Trego numrin e anetareve\n"
//			<< "8. Trego vleren ne fillim\n"
//			<< "9. Trego vleren ne fund\n"
//			<< "10. Trego a eshte lista e zbrazte\n"
//			<< "11. Trego permbajtjen e liste\n"
//			<< "Zgjedh veprimin: ";
//		cin >> veprimi;
//		if (veprimi == 1 || veprimi == 2 || veprimi == 3) {
//			cout << "Cakto vleren per t'u shtuar ne liste: ";
//			cin >> vlera;
//			if (veprimi == 1) {
//				L.shto_ne_fillim(vlera);
//				cout << "Vlera " << vlera << " eshte shtuar ne fillim.\n";
//			}
//			else if (veprimi == 2) {
//				L.shto_ne_fund(vlera);
//				cout << "Vlera " << vlera << " eshte shtuar ne fund.\n";
//			}
//			else {
//				int vlera_aktuale;
//				cout << "Cakto pas ciles vlere te shtohet vlera: "
//					<< vlera << " :";
//				cin >> vlera_aktuale;
//				L.shto_pas_nje_vlere(vlera_aktuale, vlera);
//			}
//		}
//		else if (veprimi == 4) {
//			L.terheqe_ne_fillim();
//		}
//		else if (veprimi == 5)
//			L.terheqe_ne_fund();
//		else if (veprimi == 6) {
//			int vlera_per_largim;
//			cout << "Cila vlere duhet te largohet: ";
//			cin >> vlera_per_largim;
//			L.terheqe_nje_vlere(vlera_per_largim);
//		}
//		else if (veprimi == 7)
//			cout << "Numri anetareve ne liste eshte: "
//			<< L.madhesia() << endl;
//		else if (veprimi == 8)
//			cout << "Vlera ne fillim eshte: "
//			<< L.vlera_ne_fillim() << endl;
//		else if (veprimi == 9)
//			cout << "Vlera ne fund eshte: "
//			<< L.vlera_ne_fund() << endl;
//		else if (veprimi == 10)
//			if (L.e_zbrazte())
//				cout << "Lista eshte e zbrazte.\n";
//			else
//				cout << "Lista nuk eshte e zbrazte\n";
//		else if (veprimi == 11) {
//			cout << "Permbatja e listes eshte: ";
//			L.pershko();
//		}
//		else
//			cout << "Veprimi i zgjedhur nuk ekziston!\n";
//		cout << "\nA te perseritet programi (p-po ose j-jo): ";
//		cin >> perserite;
//	}
//}
//void lista::shto_ne_fillim(int _vlera) {
//	nyja * nyja_re = new nyja();
//	nyja_re->vlera = _vlera;
//	nyja_re->tjetra = NULL;
//	if (fillimi == NULL) {
//		fillimi = nyja_re;
//		fundi = nyja_re;
//	}
//	else
//	{
//		nyja_re->tjetra = fillimi;
//		fillimi = nyja_re;
//	}
//	numri_vlerave = numri_vlerave + 1;
//}
//void lista::shto_ne_fund(int _vlera) {
//	nyja* nyja_re = new nyja();
//	nyja_re->vlera = _vlera;
//	nyja_re->tjetra = NULL;
//	if (fillimi == NULL) {
//		fillimi = nyja_re;
//		fundi = nyja_re;
//	}
//	else
//	{
//		fundi->tjetra = nyja_re;
//		fundi = nyja_re;
//	}
//	numri_vlerave = numri_vlerave + 1;
//}
//void lista::shto_pas_nje_vlere(int _vlera_aktuale, int _vlera) {
//	nyja* indeksi=fillimi;
//	while (indeksi!=NULL)
//	{
//		if (indeksi->vlera== _vlera_aktuale)
//		{
//			if (indeksi == fundi)
//				this->shto_ne_fund(_vlera);
//			else {
//				nyja* nyja_re = new nyja();
//				nyja_re->vlera = _vlera;
//				nyja_re->tjetra = indeksi->tjetra;
//				indeksi->tjetra = nyja_re;
//			}
//			numri_vlerave = numri_vlerave + 1;
//			cout << "Vlera " << _vlera << " eshte shtuar pas vleres "
//				<< _vlera_aktuale << endl;
//			break;
//		}
//		indeksi = indeksi->tjetra;
//	}
//	if (indeksi == NULL)
//		cout << "Vlera aktuale " << _vlera_aktuale << " nuk ekziston!\n";
//}
//void lista::terheqe_ne_fillim() {
//	if (fillimi == NULL) {
//		cout << "Lista eshte e zbrazte: " << endl;
//		return;
//	}
//	else if(fillimi==fundi){
//		fillimi = NULL; fundi = NULL;
//	}
//	else{
//		fillimi = fillimi->tjetra;
//	}
//	numri_vlerave = numri_vlerave - 1;
//}
//void lista::terheqe_ne_fund() {
//	if (fillimi == NULL) {
//		cout << "Lista eshte e zbrazte: " << endl;
//		return;
//	}
//	else if (fillimi == fundi) {
//		fillimi = NULL; fundi = NULL;
//	}
//	else {
//		nyja* indeksi = fillimi;
//		nyja* paraprake = indeksi;
//		while (indeksi != fundi)
//		{
//			paraprake = indeksi;
//			indeksi = indeksi->tjetra;
//		}
//		paraprake->tjetra = NULL;
//		fundi = paraprake;
//	}
//	numri_vlerave = numri_vlerave -1;
//}
//void lista::terheqe_nje_vlere(int _vlera) {
//	if (fillimi == NULL) {
//		cout << "Lista eshte e zbrazte: " << endl;
//		return;
//	}
//	nyja* indeksi = fillimi;
//	nyja* paraprake = NULL;
//	while (indeksi != NULL)
//	{
//		if (indeksi->vlera == _vlera)
//		{
//			if (indeksi == fillimi && indeksi == fundi) {
//				fillimi = NULL; fundi = NULL;
//			}
//			else if (indeksi == fillimi)
//				this->terheqe_ne_fillim();
//			else if (indeksi == fundi)
//				this->terheqe_ne_fund();
//			else
//				paraprake->tjetra = indeksi->tjetra;
//
//			numri_vlerave = numri_vlerave - 1;
//			break;
//		}
//		paraprake = indeksi;
//		indeksi = indeksi->tjetra;
//	}
//	if (indeksi == NULL)
//		cout << "Vlera " << _vlera << " nuk ekziston!\n";
//}
//void lista::pershko() {
//	nyja* indeksi = fillimi;
//	while (indeksi!=NULL)
//	{
//		cout << indeksi->vlera << " ";
//		indeksi = indeksi->tjetra;
//	}
//	cout << endl;
//}
//int lista::vlera_ne_fillim() {
//	return fillimi->vlera;
//}
//int lista::vlera_ne_fund() {
//	return fundi->vlera;
//}
//bool lista::e_zbrazte() {
//	return fillimi==NULL;
//}
//int lista::madhesia() {
//	return numri_vlerave;
//}
//nyja* lista::nyja_ne_fillim() {
//	return fillimi;
//}
//nyja* lista::nyja_ne_fund() {
//	return fundi;
//}