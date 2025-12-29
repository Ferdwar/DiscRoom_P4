#pragma once
using namespace System::Drawing;

class Enemigo1 {
private:
	int x, y;
	int dy;
	int indiceW, indiceH;
	int W, H;
	bool visibilidad;
	int limiteSuperior, limiteInferior;

public:
	Enemigo1(int W, int H, int startX, int startY, int limiteSup, int limiteInf) {
		this->W = W;
		this->H = H;
		this->x = startX;
		this->y = startY;
		this->dy = 6;
		this->indiceW = 0;
		this->indiceH = 1;
		this->visibilidad = true;
		this->limiteSuperior = limiteSup;
		this->limiteInferior = limiteInf;
	}

	void dibujar(Graphics^ gr, Bitmap^ bmp) {
		Rectangle src = Rectangle(indiceW * W, indiceH * H, W, H);
		Rectangle dst = Rectangle(x, y, W, H);
		gr->DrawImage(bmp, dst, src, GraphicsUnit::Pixel);
	}

	void mover() {
		y += dy;
		if (y <= limiteSuperior || y + H >= limiteInferior) {
			dy *= -1;
		}
		indiceW++;
		if (indiceW > 3) indiceW = 0;
	}
};
