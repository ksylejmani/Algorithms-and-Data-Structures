//#include <iostream>
//#include<queue>
//#include<stack>
//using namespace std;
//struct nyja {
//	int vlera;
//	nyja* majtas;
//	nyja* djathtas;
//};
//class pema_binare_e_kerkimit {
//public:
//	nyja* rrenja=NULL;
//	int numri_vlerava;
//	nyja* nyje_e_re(int _vlera);
//	nyja* shto(nyja* _nyja_fillestare, int _vlera);
//	nyja* largo(nyja* _nyja_fillestare, int _vlera);
//	nyja* kerko(nyja* _nyja_fillestare, int _vlera);
//	nyja* minimalja(nyja* _nyja_fillestare);
//	nyja* maksimalja(nyja* _nyja_fillestare);
//	void pershko_gjeresia_se_pari();
//	void pershko_thelesia_se_pari();
//	void pershko_pre_order(nyja* _nyja_fillestare);
//	void pershko_in_order(nyja* _nyja_fillestare);
//	void pershko_post_order(nyja* _nyja_fillestare);
//};
//void main() {
//	pema_binare_e_kerkimit p;
//	
//	p.rrenja=p.shto(p.rrenja,6);
//	p.rrenja=p.shto(p.rrenja, 5);
//	p.rrenja = p.shto(p.rrenja, 9);
//	p.rrenja = p.shto(p.rrenja, 4);
//	p.rrenja = p.shto(p.rrenja, 12);
//	p.rrenja = p.shto(p.rrenja, 8);
//	p.rrenja = p.shto(p.rrenja, 11);
//	p.rrenja = p.shto(p.rrenja, 15);
//	p.rrenja = p.shto(p.rrenja, 5);
//
//	p.rrenja=p.largo(p.rrenja, 6);
//	p.rrenja = p.largo(p.rrenja, 1);
//
//	nyja* ekziston = p.kerko(p.rrenja, 7);
//	if (ekziston != NULL) 
//		cout << "\nVlera " 
//		<< ekziston->vlera << " gjendet ne peme.";
//	else 
//		cout << "\nVlera e kerkuar nuk gjendet ne peme.";
//
//	p.pershko_gjeresia_se_pari();
//	p.pershko_thelesia_se_pari();
//
//	cout << "\nPershkimi pre order: ";
//	p.pershko_pre_order(p.rrenja);
//	cout << "\nPershkimi in order: ";
//	p.pershko_in_order(p.rrenja);
//	cout << "\nPershkimi post order: ";
//	p.pershko_post_order(p.rrenja);
//
//	nyja* min = p.minimalja(p.rrenja);
//	cout << "\nMinimalja: " << min->vlera;
//	nyja* max = p.maksimalja(p.rrenja);
//	cout << "\nMaksimalja: " << max->vlera << endl;
//	cout << "Numri i vlerave ne peme: " << p.numri_vlerava<<endl;
//}
//nyja* pema_binare_e_kerkimit::nyje_e_re(int _Vlera) {
//	nyja* n = new nyja();
//	n->vlera = _Vlera;
//	n->majtas = NULL;
//	n->djathtas = NULL;
//	numri_vlerava = numri_vlerava + 1;
//	return n;
//}
//nyja* pema_binare_e_kerkimit::shto(nyja* _nyja_fillestare, int _vlera)
//{
//	if (_nyja_fillestare == NULL)
//	{
//		_nyja_fillestare = this->nyje_e_re(_vlera);
//	}
//	else if (_nyja_fillestare->vlera == _vlera) {
//		cout << "Vlera " << _vlera << " nuk mund te shtohet, pasi ajo gjendet ne peme.\n";
//	}
//	else if (_vlera <= _nyja_fillestare->vlera)
//	{
//		_nyja_fillestare->majtas = shto(_nyja_fillestare->majtas, _vlera);
//	}
//	else
//	{
//		_nyja_fillestare->djathtas = shto(_nyja_fillestare->djathtas, _vlera);
//
//	}
//	return _nyja_fillestare;
//}
//
//nyja* pema_binare_e_kerkimit::kerko(nyja* _nyja_fillestare, int _vlera)
//{
//	nyja* rezultati;
//	if (_nyja_fillestare == NULL)
//		rezultati = NULL;
//	else if (_nyja_fillestare->vlera == _vlera)
//		rezultati = _nyja_fillestare;
//	else if (_vlera < _nyja_fillestare->vlera)
//		rezultati = kerko(_nyja_fillestare->majtas, _vlera);
//	else
//		rezultati = kerko(_nyja_fillestare->djathtas, _vlera);
//	return rezultati;
//}
//void pema_binare_e_kerkimit::pershko_gjeresia_se_pari() {
//	cout << "\nPershkimi gjeresia se pari: ";
//	queue<nyja*> rreshti;
//	rreshti.push(rrenja);
//	while (!rreshti.empty())
//	{
//		nyja* n = rreshti.front();
//		cout << n->vlera << " ";
//		rreshti.pop();
//		if (n->majtas!=NULL)
//			rreshti.push(n->majtas);
//		if (n->djathtas!=NULL)
//			rreshti.push(n->djathtas);
//	}
//}
//void pema_binare_e_kerkimit::pershko_thelesia_se_pari() {
//	cout << "\nPershkimi thellesia se pari: ";
//	stack<nyja*> steku;
//	steku.push(rrenja);
//	while (!steku.empty())
//	{
//		nyja* n = steku.top();
//		cout << n->vlera << " ";
//		steku.pop();
//		if (n->djathtas != NULL)
//			steku.push(n->djathtas);
//		if (n->majtas != NULL)
//			steku.push(n->majtas);
//	}
//}
//void pema_binare_e_kerkimit::pershko_pre_order(nyja* _nyja_fillestare) {
//	if (_nyja_fillestare != NULL)
//	{
//		cout << _nyja_fillestare->vlera << " "; 
//		pershko_pre_order(_nyja_fillestare->majtas);
//		pershko_pre_order(_nyja_fillestare->djathtas);
//	}
//
//}
//void pema_binare_e_kerkimit::pershko_in_order(nyja* _nyja_fillestare){
//	if (_nyja_fillestare != NULL)
//	{
//		pershko_in_order(_nyja_fillestare->majtas);
//		cout << _nyja_fillestare->vlera << " ";
//		pershko_in_order(_nyja_fillestare->djathtas);
//	}
//}
//void pema_binare_e_kerkimit::pershko_post_order(nyja* _nyja_fillestare) {
//	if (_nyja_fillestare != NULL)
//	{
//		pershko_post_order(_nyja_fillestare->majtas);
//		pershko_post_order(_nyja_fillestare->djathtas);
//		cout << _nyja_fillestare->vlera << " ";
//	}
//}
//nyja* pema_binare_e_kerkimit::minimalja(nyja* _nyja_fillestare) {
//	if (_nyja_fillestare->majtas != NULL)
//		minimalja(_nyja_fillestare->majtas);
//	else
//		return _nyja_fillestare;
//}
//nyja* pema_binare_e_kerkimit::maksimalja(nyja* _nyja_fillestare) {
//	if (_nyja_fillestare->djathtas != NULL)
//		maksimalja(_nyja_fillestare->djathtas);
//	else
//		return _nyja_fillestare;
//}
//nyja* pema_binare_e_kerkimit::largo(nyja* _nyja_fillestare, int _vlera) {
//	if (_nyja_fillestare == NULL) {
//		cout << "Vlera " << _vlera << " nuk gjendet ne peme. Asnje vlere nuk eshte larguar.";
//	}
//	else if (_vlera == _nyja_fillestare->vlera) {
//		if (_nyja_fillestare->majtas == NULL && _nyja_fillestare->djathtas == NULL) {
//			_nyja_fillestare = NULL;
//			numri_vlerava = numri_vlerava - 1;
//		}
//		else if (_nyja_fillestare->majtas == NULL) {
//			numri_vlerava = numri_vlerava - 1;
//			return _nyja_fillestare->djathtas;
//		}
//		else if (_nyja_fillestare->djathtas == NULL) {
//			numri_vlerava = numri_vlerava - 1;
//			return _nyja_fillestare->majtas;
//		}
//		else {
//			nyja* nyja_max = maksimalja(_nyja_fillestare->majtas);
//			nyja* zevendesuesja = this->nyje_e_re(nyja_max->vlera);
//			zevendesuesja->djathtas = _nyja_fillestare->djathtas;
//			zevendesuesja->majtas = largo(_nyja_fillestare->majtas, nyja_max->vlera);
//			numri_vlerava = numri_vlerava - 1;
//			return zevendesuesja;
//		}
//	}
//	else if (_vlera <= _nyja_fillestare->vlera)
//	{
//		_nyja_fillestare->majtas = largo(_nyja_fillestare->majtas, _vlera);
//	}
//	else
//	{
//		_nyja_fillestare->djathtas = largo(_nyja_fillestare->djathtas, _vlera);
//	
//	}
//	return _nyja_fillestare;
//}