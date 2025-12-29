#pragma once
#include<iostream>
using namespace System::Drawing;
class Personaje
{
private:
	int x, y;
	int dx, dy;
	int indiceW, indiceH;
	int W, H;
	char direccion;
public:
	Personaje(int W, int H) : W(W), H(H), dx(15), dy(15), x(70), y(70), indiceW(0), indiceH(0), direccion('S') {}
	~Personaje() {}
	void dibujar(Graphics^ gr, Bitmap^ bmp) {
		Rectangle porcionMostrar = Rectangle(indiceW * W, indiceH * H, W, H);
		Rectangle zoom = Rectangle(x, y, W, H);
		gr->DrawImage(bmp, zoom, porcionMostrar, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ gr, char tecla) {
		switch (tecla)
		{
		case 'A':
			if (x > 0) {
				indiceH = 1;
				x -= dx;
				direccion = 'A';
			} break;
		case 'D':
			if (x + W < gr->VisibleClipBounds.Width) {
				indiceH = 2;
				x += dx;
				direccion = 'D';
			} break;
		case 'W':
			if (y > 0) {
				indiceH = 3;
				y -= dy;
				direccion = 'W';
			} break;
		case 'S':
			if (y + H < gr->VisibleClipBounds.Height) {
				indiceH = 0;
				y += dy;
				direccion = 'S';
			} break;

			indiceW++;
			if (indiceW > 3)indiceW = 0;
		}
	}
	char getDireccion() { return direccion; }
	int getX() { return x; }
	int getY() { return y; }



};
