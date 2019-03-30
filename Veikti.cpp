#include "Veikti.h"
#include "Piesti.h"
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

id::Piesti piesti;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

namespace ip {

	Veikti::Veikti()
	{
		a = "KEISTI SPALVAS"; //tekstas
		aeil = &*a.begin();
		b = "KEISTI MENIU VIETA"; //tekstas
		beil = &*b.begin();
		c = "ISEITI"; //tekstas
		ceil = &*c.begin();

		spalvaf=1, spalvar=15, dx=28, dy=9, x=4, y=4, r=2; //lentele
		sspalvaf = 1, sspalvar = 15;
		ax=2, ay=2, aspalvaf=15, aspalvat=1; //pirmas pasirinkimas
		bx=2, by=4, bspalvaf=1, bspalvat=15; //antras pasirinkimas
		cx=2, cy=6, cspalvaf=1, cspalvat=15; //trecias pasirinkimas

		//vykdymas
		pasirinkimas = 1;
		stadija = 1;
		enter = false;
		rodykles = false;
		rod = 0;
	}
	Veikti::~Veikti() {}

	void Veikti::keisti()
	{
	//	piesti.meniu(1, 15, 28, 9, 4, 4, 2, aeil, 4, 2, 5, 15, beil, 4, 4, 6, 15, ceil, 4, 6, 7, 15);
		piesti.meniu(spalvaf, spalvar, dx, dy, x, y, r, aeil, ax, ay, aspalvaf, aspalvat, beil, bx, by, bspalvaf, bspalvat, ceil, cx, cy, cspalvaf, cspalvat);
		//cout << "stadija=" << stadija << " pasirinkimas="<<pasirinkimas <<" enter="<<enter<< endl;
		//for (int i = 0; i < 16; i++)cout << endl;
	}
	void Veikti::valdyti()
	{
		if (rodykles == false)
		{
			switch (_getch())
			{
			case KEY_UP:
				pasirinkimas--;
				break;
			case KEY_DOWN:
				pasirinkimas++;
				break;
			case KEY_ENTER:
				enter = true;
				break;
			}
		}
		else
		{
			switch (_getch())
			{
			case KEY_UP:
				pasirinkimas--;
				break;
			case KEY_DOWN:
				pasirinkimas++;
				break;
			case KEY_LEFT:
				enter = true;
				rod--;
				break;
			case KEY_RIGHT:
				enter = true;
				rod++;
				break;
			}
		}
	}
	void Veikti::vykdyti(bool &t)
	{
		if (enter == false)
		{
			if (pasirinkimas == 0)pasirinkimas = 3;
			if (pasirinkimas == 4)pasirinkimas = 1;
			if (pasirinkimas == 1)
			{
				if (rodykles == false && stadija == 3)rodykles = true;
				aspalvaf = sspalvar, aspalvat = sspalvaf;
				bspalvaf = sspalvaf, bspalvat = sspalvar;
				cspalvaf = sspalvaf, cspalvat = sspalvar;
			}
			if (pasirinkimas == 2)
			{
				if (rodykles==false && stadija == 3)rodykles = true;
				aspalvaf = sspalvaf, aspalvat = sspalvar;
				bspalvaf = sspalvar, bspalvat = sspalvaf;
				cspalvaf = sspalvaf, cspalvat = sspalvar;
			}
			if (pasirinkimas == 3)
			{
				if (rodykles==true && stadija==3)rodykles = false;
				aspalvaf = sspalvaf, aspalvat = sspalvar;
				bspalvaf = sspalvaf, bspalvat = sspalvar;
				cspalvaf = sspalvar, cspalvat = sspalvaf;
			}
		}
		else
		{
			if (pasirinkimas == 1 && stadija == 1) 
			{
				stadija = 2;
				a = "KEISTI LANGO SPALVA"; //tekstas
				aeil = &*a.begin();
				b = "TEKSTO SPALVA"; //tekstas
				beil = &*b.begin();
				c = "GRIZTI"; //tekstas
				ceil = &*c.begin();
				enter = false;
			}
			else if (pasirinkimas == 2 && stadija == 1) 
			{
				pasirinkimas = 1;
				stadija = 3;
				rodykles = true;
				a = "<HORIZONTALIAI>"; //tekstas
				aeil = &*a.begin();
				b = "<VERTIKALIAI>"; //tekstas
				beil = &*b.begin();
				c = "GRIZTI"; //tekstas
				ceil = &*c.begin();
				enter = false;
			}
			else if (pasirinkimas == 3 && stadija == 1)t = 0;
			else if (pasirinkimas == 1 && stadija == 2)
			{
				sspalvaf++;
				if (sspalvaf == 16)sspalvaf = 0;
				spalvaf = sspalvaf;
				enter = false;
			}
			else if (pasirinkimas == 2 && stadija == 2)
			{
				sspalvar++;
				if (sspalvar == 16)sspalvar = 0;
				spalvar = sspalvar;
				enter = false;
			}
			else if (pasirinkimas == 3 && stadija == 2)
			{
				stadija = 1;
				pasirinkimas = 1;	
				a = "KEISTI SPALVAS"; //tekstas
				aeil = &*a.begin();
				b = "KEISTI MENIU VIETA"; //tekstas
				beil = &*b.begin();
				c = "ISEITI"; //tekstas
				ceil = &*c.begin();
				enter = false;
			}
			else if (pasirinkimas == 1 && stadija == 3)
			{
				if (rod == 1)
				{
					x++;
				}
				if (rod == -1)
				{
					x--;
				}
				rod = 0;
				enter = false;
			}
			else if (pasirinkimas == 2 && stadija == 3)
			{
				if (rod == 1)
				{
					y++;
				}
				if (rod == -1)
				{
					y--;
				}
				rod = 0;
				enter = false;
			}
			else if (pasirinkimas == 3 && stadija == 3)
			{
				stadija = 1;
				pasirinkimas = 1;
				a = "KEISTI SPALVAS"; //tekstas
				aeil = &*a.begin();
				b = "KEISTI MENIU VIETA"; //tekstas
				beil = &*b.begin();
				c = "ISEITI"; //tekstas
				ceil = &*c.begin();
				enter = false;
			}
		}

	}

}