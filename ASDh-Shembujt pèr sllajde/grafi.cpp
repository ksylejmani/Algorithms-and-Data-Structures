#include<iostream>
#include<queue>
#include<stack>
#include<list>
#include<string>
#include<iomanip>
#include<limits>
using namespace std;
struct nyja_fqinje
{
	int indeksi;
	int pesha;
	nyja_fqinje() {}
	nyja_fqinje(int _indeksi, int _pesha) {
		indeksi = _indeksi;
		pesha = _pesha;
	}
	bool operator == (const nyja_fqinje& nf) const { 
		bool rezultati = (indeksi == nf.indeksi) && (pesha == nf.pesha);
		return rezultati; 
	}
};
struct nyja {
	int indeksi;
	list<nyja_fqinje> fqinjet;
	nyja(){}
	nyja(int _indeksi) {
		indeksi = _indeksi;
	}
};
struct dega {
	int nyja_ne_fillim;
	int nyja_ne_fund;
	int pesha;
	dega(){}
	dega(int _nyja_ne_fillim, int _nyja_ne_fund, int _pesha) {
		nyja_ne_fillim = _nyja_ne_fillim;
		nyja_ne_fund = _nyja_ne_fund;
		pesha = _pesha;
	}
	bool operator == (const dega& d) const {
		bool rezultati1 = (nyja_ne_fillim == d.nyja_ne_fillim) && 
			(nyja_ne_fund==d.nyja_ne_fund)&&
			(pesha == d.pesha);
		bool rezultati2 = (nyja_ne_fillim == d.nyja_ne_fund) &&
			(nyja_ne_fund == d.nyja_ne_fillim) &&
			(pesha == d.pesha);
		bool rezultati = rezultati1 || rezultati2;
		return rezultati;
	}
	bool operator < (const dega& d) const {
		bool rezultati = pesha < d.pesha;
		return rezultati;
	}
	bool operator > (const dega& d) const {
		bool rezultati = pesha > d.pesha;
		return rezultati;
	}
};
class grafi {
private:
	nyja* nyjet;
	string* emertimet;
	int numri_nyjeve;
	int kapaciteti;
	void zmadho_kapacitetin(int koeficienti_zmadhimit=1);
	int gjej_indeksin(string emertimi);
	bool gjeje_nese_formohet_cikel(int indeksi_ne_fillim, int indeksi_ne_fund, list<int> nyjet_ne_peme, list<dega> deget_ne_peme);
public:
	grafi(int kapaciteti_fillestar = 8) {
		kapaciteti = kapaciteti_fillestar;
		nyjet = new nyja[kapaciteti_fillestar];
		emertimet = new string[kapaciteti_fillestar];
		numri_nyjeve = 0;
	}
	void shto_nyje(string _emertimi);
	void largo_nyje(string _emertimi);
	void shto_dege(string _emertimi_ne_fillim, string _emertimi_ne_fund, int _pesha);
	void largo_dege(string _emertimi_ne_fillim, string _emertimi_ne_fund);
	void shtyp_listen_fqinjesise();
	void shtyp_matricen_fqinjesise();
	void pershko_gjeresia_se_pari(string _nyja_startuese);
	void pershko_thellesia_se_pari(string _nyja_startuese);
	void pema_shtrirjes_minimale_Dijkstra_Prim();
	void pema_shtrirjes_minimale_Kruskal();
	void shtegu_me_shkurt(string _emertimi_ne_fillim, string _emertimi_ne_fund);
};
void main() {
	grafi g;
	g.shto_nyje("Adi"); g.shto_nyje("Jeta"); g.shto_nyje("Era"); g.shto_nyje("Lisi");
	g.shto_nyje("Guri"); g.shto_nyje("Nesa"); g.shto_nyje("Ora"); g.shto_nyje("Mali");
	g.shto_dege("Adi", "Jeta", 4); g.shto_dege("Adi", "Era", 7); g.shto_dege("Jeta", "Lisi", 6);
	g.shto_dege("Jeta", "Era", 3); g.shto_dege("Era", "Guri", 6); g.shto_dege("Era", "Lisi", 5);
	g.shto_dege("Guri", "Nesa", 2); g.shto_dege("Lisi", "Ora", 9); g.shto_dege("Nesa", "Ora", 1);
	g.shto_dege("Nesa", "Mali", 8); g.shto_dege("Ora", "Mali", 7); 
	g.shtyp_listen_fqinjesise();
	g.shtyp_matricen_fqinjesise();
	g.pershko_gjeresia_se_pari("Adi");
	g.pershko_thellesia_se_pari("Adi");
	g.pema_shtrirjes_minimale_Kruskal();
	g.pema_shtrirjes_minimale_Dijkstra_Prim();
	g.shtegu_me_shkurt("Adi", "Mali");
}

void grafi::shto_nyje(string _emertimi) {
	int indeksi = this->gjej_indeksin(_emertimi);
	if ( indeksi!= -1) {
		cout << "Nyja me emertimin " << _emertimi << " gjendet ne graf.\n";
		return;
	}
	if (numri_nyjeve == kapaciteti - 1)
		this->zmadho_kapacitetin();
	emertimet[numri_nyjeve] = _emertimi;
	nyja nyje_re(numri_nyjeve);
	nyjet[numri_nyjeve] = nyje_re;
	numri_nyjeve += 1;
}
void grafi::shto_dege(string _emertimi_ne_fillim, string _emertimi_ne_fund, int _pesha) {
	int indeksi_ne_fillim = this->gjej_indeksin(_emertimi_ne_fillim);
	int indeksi_ne_fund = this->gjej_indeksin(_emertimi_ne_fund);
	if (indeksi_ne_fillim == -1||indeksi_ne_fund==-1) {
		cout << "Dega s'mund te shtohet, pasi njera prej nyjeve te caktuara " 
			 << " nuk gjendet ne graf.\n";
		return;
	}
	list<nyja_fqinje> fqinjet_fillim = nyjet[indeksi_ne_fillim].fqinjet;
	bool dega_ekziston = false;
	for (auto f = fqinjet_fillim.begin(); f != fqinjet_fillim.end(); f++)
		if (f->indeksi == indeksi_ne_fund) {
			dega_ekziston = true;
			break;
		}
	if (dega_ekziston) {
		cout << "Ekziston nje dege ne mes te nyjeve me emertimet "
			<< _emertimi_ne_fillim << " dhe " << _emertimi_ne_fund << ".\n";
		return;
	}
	nyja_fqinje nf1(indeksi_ne_fillim, _pesha);
	nyja_fqinje nf2(indeksi_ne_fund, _pesha);
	nyjet[indeksi_ne_fillim].fqinjet.push_back(nf2);
	nyjet[indeksi_ne_fund].fqinjet.push_back(nf1);
}
void grafi::largo_nyje(string _emertimi) {
	int indeksi = this->gjej_indeksin(_emertimi);
	if (indeksi == -1) {
		cout << "Nyja me emertimin " << _emertimi << " nuk gjendet ne graf.\n";
		return;
	}
	list<nyja_fqinje> fqinjet = nyjet[indeksi].fqinjet;
	for (auto f = fqinjet.begin(); f != fqinjet.end(); f++) {
		nyja_fqinje nf(indeksi, f->pesha);
		nyjet[f->indeksi].fqinjet.remove(nf);
	}
	for (int i = indeksi; i < numri_nyjeve - 1; i++) {
		nyjet[i] = nyjet[i + 1];
		emertimet[i] = emertimet[i + 1];
		nyjet[i].indeksi -= 1;
	}
	for (int i = 0; i < numri_nyjeve - 1; i++)
		for (auto f = nyjet[i].fqinjet.begin(); f != nyjet[i].fqinjet.end(); f++)
			if (f->indeksi >indeksi) {
				f->indeksi -= 1;
			}
	numri_nyjeve -= 1;
}
void grafi::largo_dege(string _emertimi_ne_fillim, string _emertimi_ne_fund) {
	int indeksi_ne_fillim = this->gjej_indeksin(_emertimi_ne_fillim);
	int indeksi_ne_fund = this->gjej_indeksin(_emertimi_ne_fund);
	if (indeksi_ne_fillim == -1 || indeksi_ne_fund == -1) {
		cout << "Dega s'mund te largohet, pasi se paku njera prej nyjeve "
			<< " nuk gjendet ne graf.\n";
		return;
	}
	list<nyja_fqinje> fqinjet_fillim = nyjet[indeksi_ne_fillim].fqinjet;
	bool dega_ekziston = false;
	int pesha=-1;
	for (auto f = fqinjet_fillim.begin(); f != fqinjet_fillim.end(); f++)
		if (f->indeksi == indeksi_ne_fund) {
			dega_ekziston = true;
			pesha = f->pesha;
			break;
		}
	if (!dega_ekziston) {
		cout << "Nuk ekziston dege ne mes te nyjeve me emertimet "
			<< _emertimi_ne_fillim << " dhe " << _emertimi_ne_fund << ".\n";
		return;
	}
	nyja_fqinje nf1(indeksi_ne_fillim, pesha);
	nyja_fqinje nf2(indeksi_ne_fund, pesha);
	nyjet[indeksi_ne_fillim].fqinjet.remove(nf2);
	nyjet[indeksi_ne_fund].fqinjet.remove(nf1);
}
void grafi::zmadho_kapacitetin(int koeficienti_zmadhimit) {
	kapaciteti = kapaciteti*(1+koeficienti_zmadhimit);
	nyja* nyjet_reja = new nyja[kapaciteti];
	string * emertimet_reja = new string[kapaciteti];
	for (int i = 0; i < numri_nyjeve; i++) {
		nyjet_reja[i] = nyjet[i];
		emertimet_reja[i] = emertimet[i];
	}
	delete[] nyjet;
	nyjet = nyjet_reja;
	delete[] emertimet;
	emertimet = emertimet_reja;
}
int grafi::gjej_indeksin(string emertimi) {
	int indeksi = -1;
	for (int i = 0; i < numri_nyjeve; i++)
		if (emertimi == emertimet[i]) {
			indeksi = i;
			break;
		}
	return indeksi;
}
void grafi::shtyp_listen_fqinjesise() {
	cout << "Lista e fqinjesise: \n"<<left;
	for (int i = 0; i < numri_nyjeve; i++) {
		cout << setw(4)<<emertimet[i] << " : { ";
		list<nyja_fqinje> fqinjet = nyjet[i].fqinjet;
		for (auto f = fqinjet.begin(); f != fqinjet.end(); f++)
			cout << setw(4) << emertimet[f->indeksi] 
			<< "("<<f->pesha<<"),";
		cout << "\b }\n";
	}
}
void grafi::shtyp_matricen_fqinjesise() {
	cout << "Matrica e fqinjesise: \n" << left << setw(8)<<' ';
	for (int i = 0; i < numri_nyjeve; i++) 
		cout << setw(6) << emertimet[i];
	cout << endl;
	for (int i = 0; i < numri_nyjeve * numri_nyjeve + 2 * numri_nyjeve; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < numri_nyjeve; i++) {
		cout << setw(6) << emertimet[i] << "|  ";
		int* rreshti_aktual = new int[numri_nyjeve];
		for (int k = 0; k < numri_nyjeve; k++)
			rreshti_aktual[k] = 0;
		list<nyja_fqinje> fqinjet = nyjet[i].fqinjet;
		for (auto f = fqinjet.begin(); f != fqinjet.end(); f++)
			rreshti_aktual[f->indeksi] = f->pesha;
		for (int k = 0; k < numri_nyjeve; k++)
			cout << setw(6) << rreshti_aktual[k];
		cout << "\n";
	}
	for (int i = 0; i < numri_nyjeve * numri_nyjeve + 2 * numri_nyjeve; i++)
		cout << "-";
	cout << endl;
}
void grafi::pershko_gjeresia_se_pari(string _nyja_startuese) {
	int indeksi = this->gjej_indeksin(_nyja_startuese);
	if (indeksi == -1) {
		cout << "Nyja me emertimin " << _nyja_startuese << " nuk gjendet ne graf.\n";
		return;
	}
	cout << "Pershkimi gjeresia se pari: ";
	bool* vizituar = new bool[numri_nyjeve];
	for (int i = 0; i < numri_nyjeve; i++)
		vizituar[i] = false;
	queue<int> rreshti;
	rreshti.push(indeksi);
	while (!rreshti.empty())
	{
		int indeksi_aktual = rreshti.front();
		if (!vizituar[indeksi_aktual]) {
			cout << emertimet[indeksi_aktual]<<" ";
			vizituar[indeksi_aktual] = true;
		}
		rreshti.pop();
		list<nyja_fqinje> fqinjet = nyjet[indeksi_aktual].fqinjet;
		priority_queue<string, vector<string>, greater<string >> rreshti_me_prioritet;
		for (auto f = fqinjet.begin(); f != fqinjet.end(); f++)
			if (!vizituar[f->indeksi])
				rreshti_me_prioritet.push(emertimet[f->indeksi]);
		while (!rreshti_me_prioritet.empty())
		{
			string emertimi = rreshti_me_prioritet.top();
			rreshti_me_prioritet.pop();
			indeksi_aktual = this->gjej_indeksin(emertimi);
			rreshti.push(indeksi_aktual);
		}
	}
	cout << endl;
}
void grafi::pershko_thellesia_se_pari(string _nyja_startuese) {
	int indeksi = this->gjej_indeksin(_nyja_startuese);
	if (indeksi == -1) {
		cout << "Nyja me emertimin " << _nyja_startuese << " nuk gjendet ne graf.\n";
		return;
	}
	cout << "Pershkimi thellesia se pari: ";
	bool* vizituar = new bool[numri_nyjeve];
	for (int i = 0; i < numri_nyjeve; i++)
		vizituar[i] = false;
	stack<int> steku;
	steku.push(indeksi);
	while (!steku.empty())
	{
		int indeksi_aktual = steku.top();
		if (!vizituar[indeksi_aktual]) {
			cout <<emertimet[indeksi_aktual] << " ";
			vizituar[indeksi_aktual] = true;
		}
		steku.pop();
		list<nyja_fqinje> fqinjet = nyjet[indeksi_aktual].fqinjet;
		priority_queue<string> rreshti_me_prioritet;
		for (auto f = fqinjet.begin(); f != fqinjet.end(); f++)
			if (!vizituar[f->indeksi])
				rreshti_me_prioritet.push(emertimet[f->indeksi]);
		while (!rreshti_me_prioritet.empty())
		{
			string emertimi = rreshti_me_prioritet.top();
			rreshti_me_prioritet.pop();
			indeksi_aktual = this->gjej_indeksin(emertimi);
			steku.push(indeksi_aktual);
		}
	}
	cout << endl;
}
void grafi::pema_shtrirjes_minimale_Dijkstra_Prim() {
	list<int> nyjet_ne_peme;
	list<dega> deget_ne_peme;
	list<dega> deget_ne_periferi;

	//Fillo me nyjen e pare ne graf
	int indeksi_aktual = 0;
	nyjet_ne_peme.push_back(indeksi_aktual);
	list<nyja_fqinje> fqinjet=nyjet[indeksi_aktual].fqinjet;
	for (auto f = fqinjet.begin(); f != fqinjet.end(); f++) {
		dega dega_aktuale(indeksi_aktual, f->indeksi, f->pesha);
		deget_ne_periferi.push_back(dega_aktuale);
	}
	while (nyjet_ne_peme.size()<numri_nyjeve)
	{
		//Zgjedhja e deges me peshen minimale
		int pesha_min = INT_MAX;
		dega dega_min;
		for (auto d = deget_ne_periferi.begin(); d != deget_ne_periferi.end(); d++)
			if (d->pesha < pesha_min) {
				pesha_min = d->pesha;
				dega_min = *d;
			}
		nyjet_ne_peme.push_back(dega_min.nyja_ne_fund);
		deget_ne_peme.push_back(dega_min);
		
		//Azhurnimi i fqinjesise
		deget_ne_periferi.remove(dega_min);
		indeksi_aktual = dega_min.nyja_ne_fund;
		fqinjet = nyjet[indeksi_aktual].fqinjet;
		for (auto f = fqinjet.begin(); f != fqinjet.end(); f++) {
			bool gjendet_ne_peme = false;
			for (auto np = nyjet_ne_peme.begin(); np != nyjet_ne_peme.end(); np++)
				if (f->indeksi == *np) {
					gjendet_ne_peme = true;
					break;
				}
			if (gjendet_ne_peme) //Shto fqiun ne periferi vetum nese nuk eshte ne peme
				continue;
			int numruesi = 0;
			bool vendoset_ne_periferi = false;
			for (auto dp = deget_ne_periferi.begin(); dp != deget_ne_periferi.end(); dp++) {
				if (f->indeksi == dp->nyja_ne_fund) {
					if (f->pesha < dp->pesha) {//Zevendeso degen nese ka peshe me te vogel
						deget_ne_periferi.remove(*dp);
						dega dega_periferi(indeksi_aktual, f->indeksi, f->pesha);
						deget_ne_periferi.push_back(dega_periferi);
					}
					break;
				}
				if (f->indeksi != dp->nyja_ne_fund)
					numruesi++;
			}
			if (numruesi == deget_ne_periferi.size())
				vendoset_ne_periferi = true;
			if (vendoset_ne_periferi) { //Shto fqiun ne periferi vetum nese nuk eshte ne peme
				dega dega_periferi(indeksi_aktual, f->indeksi, f->pesha);
				deget_ne_periferi.push_back(dega_periferi);
			}
		}
	}
	
	// Shtypi deget dhe koston e pemes se shtrirjes minimale 
	int kostoja = 0;
	cout << "Deget e pemes se shtrirjes minimale sipas Dijkstra-Prim-it: \n";
	for (auto d = deget_ne_peme.begin(); d != deget_ne_peme.end(); d++) {
		cout << emertimet[d->nyja_ne_fillim] << " - " << emertimet[d->nyja_ne_fund] << endl;
		kostoja += d->pesha;
	}
	cout << "Kostoja e pemes se shtrirjes minimale: " << kostoja << endl;
}

void grafi::pema_shtrirjes_minimale_Kruskal() {
	list<int> nyjet_ne_peme;
	list<dega> deget_ne_peme;
	priority_queue<dega,vector<dega>,greater<dega>> deget_kandidate;

	for (int n = 0; n < numri_nyjeve; n++) {
		list<nyja_fqinje> fqinjet = nyjet[n].fqinjet;
		for (auto f = fqinjet.begin(); f != fqinjet.end(); f++) {
			dega dega_aktuale(n, f->indeksi, f->pesha);
			if(f->indeksi>n)
				deget_kandidate.push(dega_aktuale);
		}
	}
	while (deget_ne_peme.size() < numri_nyjeve-1)//Numri i degeve gjithnje eshte nje me pak se numri i nyjeve
	{
		//Zgjedhja e deges me peshen minimale
		dega dega_min = deget_kandidate.top();
		bool nyja_ne_fillim_ne_peme = false, nyja_ne_fund_ne_peme = false;
		for (auto n = nyjet_ne_peme.begin(); n != nyjet_ne_peme.end(); n++) {
			if (*n == dega_min.nyja_ne_fillim)
				nyja_ne_fillim_ne_peme = true;
			if (*n == dega_min.nyja_ne_fund)
				nyja_ne_fund_ne_peme = true;
			if (nyja_ne_fillim_ne_peme && nyja_ne_fund_ne_peme)
				break;
		}
		if (!(nyja_ne_fillim_ne_peme && nyja_ne_fund_ne_peme)){
			deget_ne_peme.push_back(dega_min);
			if (!nyja_ne_fillim_ne_peme)
				nyjet_ne_peme.push_back(dega_min.nyja_ne_fillim);
			if (!nyja_ne_fund_ne_peme)
				nyjet_ne_peme.push_back(dega_min.nyja_ne_fund);
		}
		else
		{
			bool formohet_cikel = this->gjeje_nese_formohet_cikel(dega_min.nyja_ne_fillim, dega_min.nyja_ne_fund,nyjet_ne_peme,deget_ne_peme);
			if (!formohet_cikel)
				deget_ne_peme.push_back(dega_min);
		}
		deget_kandidate.pop();
	}
	// Shtypi deget dhe koston e pemes se shtrirjes minimale 
	int kostoja = 0;
	cout << "Deget e pemes se shtrirjes minimale sipas Kruskal-it: \n";
	for (auto d = deget_ne_peme.begin(); d != deget_ne_peme.end(); d++) {
		cout << emertimet[d->nyja_ne_fillim] << " - " << emertimet[d->nyja_ne_fund] << endl;
		kostoja += d->pesha;
	}
	cout << "Kostoja e pemes se shtrirjes minimale: " << kostoja << endl;
}
bool grafi::gjeje_nese_formohet_cikel(int indeksi_ne_fillim, int indeksi_ne_fund, list<int> nyjet_ne_peme, list<dega> deget_ne_peme) {
	bool rezultati = false;
	bool* vizituar = new bool[numri_nyjeve];
	for (int i = 0; i < nyjet_ne_peme.size(); i++)
		vizituar[i] = false;
	stack<int> steku;
	steku.push(indeksi_ne_fillim);
	while (!steku.empty())
	{
		int indeksi_aktual = steku.top();
		if (!vizituar[indeksi_aktual]) {
			vizituar[indeksi_aktual] = true;
		}
		steku.pop();
		list<nyja_fqinje> fqinjet = nyjet[indeksi_aktual].fqinjet;
		priority_queue<int> rreshti_me_prioritet;
		for (auto f = fqinjet.begin(); f != fqinjet.end(); f++) {
			for (auto d = deget_ne_peme.begin(); d != deget_ne_peme.end(); d++) {
				bool dega_gjendet_ne_peme = ((indeksi_aktual == d->nyja_ne_fillim)&&(f->indeksi==d->nyja_ne_fund))||
				((indeksi_aktual==d->nyja_ne_fund)&&(f->indeksi==d->nyja_ne_fillim));
				if ((dega_gjendet_ne_peme) && (!vizituar[f->indeksi])) {
					rreshti_me_prioritet.push(f->indeksi);
					break;
				}
			}
		}
		while (!rreshti_me_prioritet.empty())
		{
			indeksi_aktual = rreshti_me_prioritet.top();
			if (indeksi_aktual == indeksi_ne_fund)
				return true;
			rreshti_me_prioritet.pop();
			steku.push(indeksi_aktual);
		}
	}
}
void grafi::shtegu_me_shkurt(string _emertimi_ne_fillim, string _emertimi_ne_fund) {
	list<int> nyjet_ne_peme;
	list<dega> deget_ne_peme;
	list<dega> deget_ne_periferi;
	int* distanca_nga_fillimi = new int[numri_nyjeve];
	int* shtegu = new int[numri_nyjeve];
	for (int i = 0; i < numri_nyjeve; i++) {
		distanca_nga_fillimi[i] = 0;
		shtegu[i] = -1;
	}

	//Fillo me nyjen ne fillim
	int nyja_ne_fillim = this->gjej_indeksin(_emertimi_ne_fillim);
	int indeksi_aktual = nyja_ne_fillim;
	nyjet_ne_peme.push_back(indeksi_aktual);
	list<nyja_fqinje> fqinjet = nyjet[indeksi_aktual].fqinjet;
	for (auto f = fqinjet.begin(); f != fqinjet.end(); f++) {
		dega dega_aktuale(indeksi_aktual, f->indeksi, f->pesha);
		deget_ne_periferi.push_back(dega_aktuale);
		distanca_nga_fillimi[f->indeksi] = f->pesha;
		shtegu[f->indeksi] = nyja_ne_fillim;
	}
	int nyja_ne_fund = this->gjej_indeksin(_emertimi_ne_fund);
	while (indeksi_aktual != nyja_ne_fund)
	{
		//Zgjedhja e deges me peshen minimale
		int distanca_min = INT_MAX;
		dega dega_min;
		for (auto d = deget_ne_periferi.begin(); d != deget_ne_periferi.end(); d++)
			if (distanca_nga_fillimi[d->nyja_ne_fund] < distanca_min) {
				distanca_min = distanca_nga_fillimi[d->nyja_ne_fund];
				dega_min = *d;
			}
		nyjet_ne_peme.push_back(dega_min.nyja_ne_fund);
		deget_ne_peme.push_back(dega_min);

		//Azhurnimi i fqinjesise
		deget_ne_periferi.remove(dega_min);
		indeksi_aktual = dega_min.nyja_ne_fund;
		fqinjet = nyjet[indeksi_aktual].fqinjet;
		for (auto f = fqinjet.begin(); f != fqinjet.end(); f++) {
			bool gjendet_ne_peme = false;
			for (auto np = nyjet_ne_peme.begin(); np != nyjet_ne_peme.end(); np++)
				if (f->indeksi == *np) {
					gjendet_ne_peme = true;
					break;
				}
			if (gjendet_ne_peme) //Shto fqiun ne periferi vetum nese nuk eshte ne peme
				continue;
			int numruesi = 0;
			bool vendoset_ne_periferi = false;
			for (auto dp = deget_ne_periferi.begin(); dp != deget_ne_periferi.end(); dp++) {
				if (f->indeksi == dp->nyja_ne_fund) {
					if (distanca_nga_fillimi[indeksi_aktual] + f->pesha < distanca_nga_fillimi[dp->nyja_ne_fund]) {//Zevendeso degen nese ka peshe me te vogel
						deget_ne_periferi.remove(*dp);
						dega dega_periferi(indeksi_aktual, f->indeksi, f->pesha);
						deget_ne_periferi.push_back(dega_periferi);
						distanca_nga_fillimi[f->indeksi] = distanca_nga_fillimi[indeksi_aktual] + f->pesha;
						shtegu[f->indeksi] = indeksi_aktual;
					}
					break;
				}
				if (f->indeksi != dp->nyja_ne_fund)
					numruesi++;
			}
			if (numruesi == deget_ne_periferi.size())
				vendoset_ne_periferi = true;
			if (vendoset_ne_periferi) { //Shto fqiun ne periferi vetum nese nuk eshte ne peme
				dega dega_periferi(indeksi_aktual, f->indeksi, f->pesha);
				deget_ne_periferi.push_back(dega_periferi);
				distanca_nga_fillimi[f->indeksi] = distanca_nga_fillimi[indeksi_aktual] + f->pesha;
				shtegu[f->indeksi] = indeksi_aktual;
			}
		}
	}

	// Shtype shtegun me te shkurte
	int nyja_aktuale = nyja_ne_fund;
	stack<int> shtegu_mbrapsht;
	shtegu_mbrapsht.push(nyja_aktuale);
	while (shtegu[nyja_aktuale] != -1)
	{
		nyja_aktuale = shtegu[nyja_aktuale];
		shtegu_mbrapsht.push(nyja_aktuale);
	}
	cout << "Nyjet e shtegut me te shkurte: ";
	while (!shtegu_mbrapsht.empty())
	{
		nyja_aktuale = shtegu_mbrapsht.top();
		cout << emertimet[nyja_aktuale] << " - ";
		shtegu_mbrapsht.pop();
	}
	cout << "\b\b \nKostoja e shtegut me te shkurte: " << distanca_nga_fillimi[nyja_ne_fund] << endl;
	cout << "Deget e pemes se krijuar gjate gjetjes se shtegut me te shkurte: \n";
	for (auto d = deget_ne_peme.begin(); d != deget_ne_peme.end(); d++) {
		cout << emertimet[d->nyja_ne_fillim] << " - " << emertimet[d->nyja_ne_fund] << endl;
	}
}