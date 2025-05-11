#include "Bomba.h"
#include <algorithm>

using namespace System::Drawing;


CBomba::CBomba(int row, int col, int radio, float tiempoCreacion)
    : row(row), col(col), radioExplosion(radio), tiempoVida(3.0f), tiempoCreacion(tiempoCreacion), detonada(false) {
}

void CBomba::actualizar(float tiempoActual) {
    if (!detonada && tiempoActual - tiempoCreacion >= tiempoVida) {
        detonada = true;
    }
}

void CBomba::dibujar(Graphics^ g, Bitmap^ bmpBomba, int anchoImg, int altoImg) {
    int x = col * anchoImg;
    int y = row * altoImg;
    g->DrawImage(bmpBomba, x, y, anchoImg, altoImg);
}

std::vector<std::pair<int, int>> CBomba::calcularExplosion() const {
    std::vector<std::pair<int, int>> celdas;
    // Celda central
    celdas.emplace_back(row, col);
    // Explosión en cuatro direcciones
    for (int d = 1; d <= radioExplosion; ++d) {
        celdas.emplace_back(row + d, col);
        celdas.emplace_back(row - d, col);
        celdas.emplace_back(row, col + d);
        celdas.emplace_back(row, col - d);
    }
    return celdas;
}

bool CBomba::estaDetonada() const {
    return detonada;
}