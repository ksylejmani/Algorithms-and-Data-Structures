//#include <iostream>
//#include<unordered_map>
//#include<string>
//#include<queue>
//using namespace std;
//struct numrat {
//	int a, b;
//	numrat(int _a, int _b) {
//		a = _a; b = _b;
//	}
//	bool operator > (const numrat& n) const {
//		bool rezultati = a>n.a;
//		return rezultati;
//	}
//	bool operator < (const numrat& n) const {
//		bool rezultati = a < n.a;
//		return rezultati;
//	}
//};
//void main(){
//
//
//	numrat n1(4, 6), n2(1, 13);
//	if (n1 < n2)
//		cout << "E sakte" << endl;
//	else
//		cout << "E pasakte" << endl;
//
//	priority_queue<numrat, vector<numrat>, greater<numrat>> pq;
//	pq.push(n1);
//	pq.push(n2);
//	numrat t = pq.top();
//	cout << "Top: " << t.a<< endl;
//
//	unordered_map<string, int> um;
//	um["Adi"] = 10;
//	um["Jeta"] = 16;
//	um["Sadete"] = 18;
//	um["Kadri"] = 10;
//	cout << "Adi: " << um["Adi"] << endl;
//	cout << "Jeta: " << um["Jeta"] << endl;
//	cout << um.size() << endl;
//	for (auto i = um.begin(); i !=um.end(); i++)
//	{
//		cout << i->first << endl;
//		cout << i->second << endl;
//	}
//}