#pragma once

namespace id {
	class Piesti
	{
	private:
		int spalva;
	public:
		Piesti();
		~Piesti();

		void pranesimas(int spalvaf ,int spalvat, int x, int y, char* eil);
		void langas(int spalvaf, int spalvar, int dx, int dy, int x, int y, int r); 
		//fono spalva, remelio spalva, dydis(x,y), vieta(x,y), remelis(0-2).
		void tekstolangas(int spalvaf, int spalvar, int dx, int dy, int x, int y, int r, char* eil, int yx, int vy);
		void meniu(int spalvaf, int spalvar, int dx, int dy, int x, int y, int r,
			char* aeil, int ax, int ay, int aspalvaf, int aspalvat, char* beil, int bx, int by, int bspalvaf, int bspalvat,
			char* ceil, int cx, int cy, int cspalvaf, int cspalvat);
	};
}

