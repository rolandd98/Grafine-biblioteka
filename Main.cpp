#include <iostream>
#include <Windows.h>
#include <string>
#include "Piesti.h"
#include "Veikti.h"
#include <conio.h>
using namespace std;


int main()
{
	id::Piesti piesti;
	ip::Veikti veikti;
	string eil;
	bool t = true;
	bool cikl = true;
	char* txt;
	int p;
	//getline(cin, eil);

	eil = "TEKSTINIS PRANESIMAS"; //tekstas
	txt = &*eil.begin();
	
	while (cikl)
	{
		system("CLS");
		cout << "Ka norite daryti?" << endl << endl;
		cout << "1. piesti is bibliotekos pranesima" << endl;
		cout << "2. piesti is bibliotekos langa" << endl;
		cout << "3. piesti is bibliotekos teksto langa" << endl;
		cout << "4. piesti is bibliotekos meniu" << endl;
		cout << "5. paleisti animuota meniu" << endl;
		cout << "6. iseiti" << endl;
		cin >> p;
		switch (p)
		{
		case 1:
			piesti.pranesimas(15, 0, 4, 4, txt);
			//spalva(fono,teksto), vieta(x,y), tekstas.
			cout << endl;
			system("PAUSE");
			break;
		case 2:
			piesti.langas(1, 15, 16, 8, 4, 4, 1);
			//spalva(fono,remelio), dydis(x,y), vieta(x,y), remelis(0-2).
			cout << endl;
			system("PAUSE");
			break;
		case 3:
			piesti.tekstolangas(1, 15, 32, 8, 4, 4, 2, txt, 4, 4);
			//spalva(fono,remelio), dydis(x,y), vieta(x,y),
			//remelis(0-2), tekstas, teksto vieta(x,y).
			cout << endl;
			system("PAUSE");
			break;
		case 4:
			piesti.meniu(1, 15, 28, 9, 4, 4, 2, txt, 4, 2, 5, 15, txt, 4, 4, 6, 15, txt, 4, 6, 7, 15);
			//fono spalva, remelio spalva, dydis(x,y), vieta(x,y),
			//remelis(0-2), tekstas1, teksto1 vieta(x,y), teksto1 spalva(fonas,tekstas),
			//tekstas2, teksto2 vieta(x,y), teksto2 spalva(fonas,tekstas), tekstas3, teksto3 vieta(x,y), teksto3 spalva(fonas,tekstas).
			cout << endl;
			system("PAUSE");
			break;
		case 5:
			while (t)
			{
				system("CLS");
				veikti.keisti();
				veikti.valdyti();
				veikti.vykdyti(t);
			}
			t = true;
			break;
		case 6:
			cikl = false;
		}
	}
	


	return 0;
}
