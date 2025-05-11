#pragma once
#include "Items.h"
#include <vector>

using namespace System::Drawing;

class CBomba {
private:
    int row, col;                  // Posici�n en la matriz de la cancha
    int radioExplosion;            // Radio de la explosi�n en bloques
    float tiempoVida;              // Tiempo en segundos antes de detonar
    float tiempoCreacion;          // Marca de tiempo cuando se coloc�
    bool detonada;                 // Estado de detonaci�n
public:
    CBomba(int row, int col, int radio, float tiempoCreacion);
    void actualizar(float tiempoActual);
    void dibujar(Graphics^ g, Bitmap^ bmpBomba, int anchoImg, int altoImg);
    std::vector<std::pair<int, int>> calcularExplosion() const;
    bool estaDetonada() const;
};