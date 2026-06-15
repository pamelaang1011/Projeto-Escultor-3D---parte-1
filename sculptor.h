#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"
#include <string>

/* a classe Sculptor monta uma matriz tridimensional de Voxels
 */
 
class Sculptor {
private:
    Voxel ***v;       /* matriz tridimensional dinâmica de Voxels */
    int nx, ny, nz;   /* dimensões da matriz nos eixos X, Y e Z */
    float r, g, b, a; /* cores vermelho, verde, azul e transparências atuais do desenho */

public:

    Sculptor(int _nx, int _ny, int _nz);

    /* Destrutor da classe Sculptor. Ele libera a memória alocada para a matriz tridimensional
     */
     
    ~Sculptor();

    /* define a cor e a transparência atuais para os próximos blocos a serem desenhados
     */
    void setColor(float r, float g, float b, float a);

     /* desenha um voxel na posição (x, y, z) com a cor atual
     */
    void putVoxel(int x, int y, int z);

    /* apaga um voxel na posição (x, y, z)
     */
    void cutVoxel(int x, int y, int z);

    /* ativa um bloco paralelepípedo de voxels
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

    /* desativa um bloco paralelepípedo de voxels
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

    /* ativa uma esfera maciça de voxels
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);

    /* desativa uma esfera maciça de voxels
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    /*  ativa uma elipsoide maciça de voxels
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /* desativa uma elipsoide maciça de voxels
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    void writeOFF(const char* filename);
};

#endif