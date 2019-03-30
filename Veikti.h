#pragma once
#include<string>
using namespace std;

namespace ip {
	class Veikti
	{
	private:
		string a, b, c; //tekstas
		
		//lentele
		//fono spalva, remelio spalva, dydis(x,y), vieta(x,y),remelis(0-2)
		int spalvaf, spalvar, dx, dy, x, y, r;		

		//1pasirinkimas
		//tekstas1, teksto1 vieta(x,y), teksto1 spalva(fonas,tekstas),
		char* aeil;
		int ax, ay, aspalvaf, aspalvat;
		
		//2pasirinkimas
		//tekstas2, teksto2 vieta(x,y), teksto2 spalva(fonas,tekstas)
		char* beil;
		int bx, by, bspalvaf, bspalvat;
		
		//2pasirinkimas
		//tekstas3, teksto3 vieta(x,y), teksto3 spalva(fonas,tekstas)
		char* ceil;
		int cx, cy, cspalvaf, cspalvat;
		
		//vykdymas
		int pasirinkimas;
		int stadija;
		bool enter;
		bool rodykles;  //desine kaire kotroles
		int rod;
		int sspalvaf, sspalvar;

	public:
		Veikti();
		~Veikti();

		void keisti();
		void valdyti();
		void vykdyti(bool &t);
	};

}