#include "Piesti.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

namespace id 
{
	//class Piesti
	//{
		Piesti::Piesti() {}
		Piesti::~Piesti() {}
		void Piesti::pranesimas(int spalvaf, int spalvat, int x, int y, char* eil)
		{
			string a=eil;
			for (int i = 0; i < y; i++)cout << endl;
			for (int i = 0; i < x; i++)cout << " ";
			spalva = (spalvaf * 16) + spalvat;
			SetConsoleTextAttribute(console, spalva);
			cout << a<<endl;
			SetConsoleTextAttribute(console, 0b00001111);
		}
		void Piesti::langas(int spalvaf, int spalvar, int dx, int dy, int x, int y, int r)
		{
			for (int i = 0; i < y; i++)cout << endl;
			spalva = (spalvaf * 16) + spalvar;
			SetConsoleTextAttribute(console, spalva);
			for (int i = 0; i < dy; i++)
				for (int j = 0; j < dx; j++)
				{
					if (j == 0)
					{
						SetConsoleTextAttribute(console, 0b00001111);
						for (int t = 0; t < x; t++)cout << " ";
						SetConsoleTextAttribute(console, spalva);
					}
					if (r == 0)
					{
						if (j == dx - 1)cout <<" "<< endl;
						else cout << " ";
					}
					if (r == 1)
					{
						//kampai
						if (i == 0 && j == 0)cout << (char)218;
						if (i == dy - 1 && j == 0)cout << (char)192;
						if (i == 0 && j == dx - 1)cout << (char)191 << endl;
						if (i == dy - 1 && j == dx - 1)cout << (char)217 << endl;
						//sienos
						if((i==0 || i==dy-1) && j!=0 && j!=dx-1)cout<< (char)196;
						if (j == 0 && i != 0 && i != dy - 1)cout << (char)179;
						if (j == dx-1 && i != 0 && i != dy - 1)cout << (char)179 << endl;
						//vidus
						if (i != 0 && i != dy - 1 && j != 0 && j != dx - 1)cout << " ";
					}
					if (r == 2)
					{
						//kampai
						if (i == 0 && j == 0)cout << (char)201;
						if (i == dy - 1 && j == 0)cout << (char)200;
						if (i == 0 && j == dx - 1)cout << (char)187 << endl;
						if (i == dy - 1 && j == dx - 1)cout << (char)188 << endl;
						//sienos
						if ((i == 0 || i == dy - 1) && j != 0 && j != dx - 1)cout << (char)205;
						if (j == 0 && i != 0 && i != dy - 1)cout << (char)186;
						if (j == dx - 1 && i != 0 && i != dy - 1)cout << (char)186 << endl;
						//vidus
						if (i != 0 && i != dy - 1 && j != 0 && j != dx - 1)cout << " ";
					}
				}
			SetConsoleTextAttribute(console, 0b00001111);
		}
		void Piesti::tekstolangas(int spalvaf, int spalvar, int dx, int dy, int x, int y, int r, char* eil, int vx, int vy)
		{
			string a = eil;
			int did = a.size();

			for (int i = 0; i < y; i++)cout << endl;
			spalva = (spalvaf * 16) + spalvar;
			SetConsoleTextAttribute(console, spalva);
			for (int i = 0; i < dy; i++)
				for (int j = 0; j < dx; j++)
				{
					if (j == 0)
					{
						SetConsoleTextAttribute(console, 0b00001111);
						for (int t = 0; t < x; t++)cout << " ";
						SetConsoleTextAttribute(console, spalva);
					}
					if (r == 0)
					{
						if (j == dx - 1)cout << " " << endl;
						else
						{
							if (i == vy && j == vx)
							{
								cout << a;
								j = j + did - 1;
							}
							else
								cout << " ";
						}
					}
					if (r == 1)
					{
						//kampai
						if (i == 0 && j == 0)cout << (char)218;
						if (i == dy - 1 && j == 0)cout << (char)192;
						if (i == 0 && j == dx - 1)cout << (char)191 << endl;
						if (i == dy - 1 && j == dx - 1)cout << (char)217 << endl;
						//sienos
						if ((i == 0 || i == dy - 1) && j != 0 && j != dx - 1)cout << (char)196;
						if (j == 0 && i != 0 && i != dy - 1)cout << (char)179;
						if (j == dx - 1 && i != 0 && i != dy - 1)cout << (char)179 << endl;
						//vidus
						if (i != 0 && i != dy - 1 && j != 0 && j != dx - 1)
						{
							if (i == vy && j == vx)
							{
								cout << a;
								j = j + did - 1;
							}
							else
								cout << " ";
						}
					}
					if (r == 2)
					{
						//kampai
						if (i == 0 && j == 0)cout << (char)201;
						if (i == dy - 1 && j == 0)cout << (char)200;
						if (i == 0 && j == dx - 1)cout << (char)187 << endl;
						if (i == dy - 1 && j == dx - 1)cout << (char)188 << endl;
						//sienos
						if ((i == 0 || i == dy - 1) && j != 0 && j != dx - 1)cout << (char)205;
						if (j == 0 && i != 0 && i != dy - 1)cout << (char)186;
						if (j == dx - 1 && i != 0 && i != dy - 1)cout << (char)186 << endl;
						//vidus
						if (i != 0 && i != dy - 1 && j != 0 && j != dx - 1)
						{
							if (i == vy && j == vx)
							{
								cout << a;
								j = j + did-1;
							}
							else
							cout << " ";
						}
					}
				}
			SetConsoleTextAttribute(console, 0b00001111);
		}
		void Piesti::meniu(int spalvaf, int spalvar, int dx, int dy, int x, int y, int r,
			char* aeil, int ax, int ay, int aspalvaf, int aspalvat, char* beil, int bx, int by, int bspalvaf, int bspalvat,
			char* ceil, int cx, int cy, int cspalvaf, int cspalvat)
		{
			string a = aeil;
			string b = beil;
			string c = ceil;
			int adid = a.size();
			int bdid = b.size();
			int cdid = c.size();
			int aspalva= (aspalvaf * 16) + aspalvat;
			int bspalva = (bspalvaf * 16) + bspalvat;
			int cspalva = (cspalvaf * 16) + cspalvat;

			spalva = (spalvaf * 16) + spalvar;

			for (int i = 0; i < y; i++)cout << endl;
			SetConsoleTextAttribute(console, spalva);
			for (int i = 0; i < dy; i++)
				for (int j = 0; j < dx; j++)
				{
					if (j == 0)
					{
						SetConsoleTextAttribute(console, 0b00001111);
						for (int t = 0; t < x; t++)cout << " ";
						SetConsoleTextAttribute(console, spalva);
					}
					if (r == 0)
					{
						if (j == dx - 1)cout << " " << endl;
						else
						{
							if (i == ay && j == ax)
							{
								SetConsoleTextAttribute(console, aspalva);
								cout << a;
								j = j + adid;
								SetConsoleTextAttribute(console, spalva);
							}
							if (i == by && j == bx)
							{
								SetConsoleTextAttribute(console, bspalva);
								cout << b;
								j = j + bdid;
								SetConsoleTextAttribute(console, spalva);
							}
							if (i == cy && j == cx)
							{
								SetConsoleTextAttribute(console, cspalva);
								cout << c;
								j = j + cdid - 1;
								SetConsoleTextAttribute(console, spalva);
							}
							else
								cout << " ";
						}
					}
					if (r == 1)
					{
						//kampai
						if (i == 0 && j == 0)cout << (char)218;
						if (i == dy - 1 && j == 0)cout << (char)192;
						if (i == 0 && j == dx - 1)cout << (char)191 << endl;
						if (i == dy - 1 && j == dx - 1)cout << (char)217 << endl;
						//sienos
						if ((i == 0 || i == dy - 1) && j != 0 && j != dx - 1)cout << (char)196;
						if (j == 0 && i != 0 && i != dy - 1)cout << (char)179;
						if (j == dx - 1 && i != 0 && i != dy - 1)cout << (char)179 << endl;
						//vidus
						if (i != 0 && i != dy - 1 && j != 0 && j != dx - 1)
						{
							if (i == ay && j == ax)
							{
								SetConsoleTextAttribute(console, aspalva);
								cout << a;
								j = j + adid;
								SetConsoleTextAttribute(console, spalva);
							}
							if (i == by && j == bx)
							{
								SetConsoleTextAttribute(console, bspalva);
								cout << b;
								j = j + bdid;
								SetConsoleTextAttribute(console, spalva);
							}
							if (i == cy && j == cx)
							{
								SetConsoleTextAttribute(console, cspalva);
								cout << c;
								j = j + cdid - 1;
								SetConsoleTextAttribute(console, spalva);
							}
							else
								cout << " ";
						}
					}
					if (r == 2)
					{
						//kampai
						if (i == 0 && j == 0)cout << (char)201;
						if (i == dy - 1 && j == 0)cout << (char)200;
						if (i == 0 && j == dx - 1)cout << (char)187 << endl;
						if (i == dy - 1 && j == dx - 1)cout << (char)188 << endl;
						//sienos
						if ((i == 0 || i == dy - 1) && j != 0 && j != dx - 1)cout << (char)205;
						if (j == 0 && i != 0 && i != dy - 1)cout << (char)186;
						if (j == dx - 1 && i != 0 && i != dy - 1)cout << (char)186 << endl;
						//vidus
						if (i != 0 && i != dy - 1 && j != 0 && j != dx - 1)
						{
							if (i == ay && j == ax)
							{
								SetConsoleTextAttribute(console, aspalva);
								cout << a;
								j = j + adid;
								SetConsoleTextAttribute(console, spalva);
							}
							if (i == by && j == bx)
							{
								SetConsoleTextAttribute(console, bspalva);
								cout << b;
								j = j + bdid;
								SetConsoleTextAttribute(console, spalva);
							}
							if (i == cy && j == cx)
							{
								SetConsoleTextAttribute(console, cspalva);
								cout << c;
								j = j + cdid - 1;
								SetConsoleTextAttribute(console, spalva);
							}
							else
								cout << " ";
						}
					}
				}
			SetConsoleTextAttribute(console, 0b00001111);
		}
}