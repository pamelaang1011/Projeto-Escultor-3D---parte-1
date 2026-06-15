#include "sculptor.h"
#include <fstream>
#include <cmath>
#include <iostream>

Sculptor::Sculptor(int _nx, int _ny, int _nz) 
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];

    for (int i = 0; i < nx; i++) {
        v[i] = new Voxel*[ny];

        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];

            for (int k = 0; k < nz; k++) {
                v[i][j][k].r = 0.0;
                v[i][j][k].g = 0.0;
                v[i][j][k].b = 0.0;
                v[i][j][k].a = 0.0;
                v[i][j][k].show = false;
            }
        }
    }
}

Sculptor::~Sculptor() {
    /*Para liberar a memória, fazemos o caminho inverso da alocação!
    */
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            /* apaga os blocos do eixo Z
            */
            delete[] v[i][j];
        }
        /* apaga as linhas do eixo Y
        */
        delete[] v[i];
    }
    /*apaga as fatias do eixo X
    */
    delete[] v;
}

void Sculptor::writeOFF(const char* filename) {
    std::ofstream fout(filename);

    if (!fout.is_open()) {
        std::cout << "Erro ao abrir o arquivo " << filename << std::endl;
        return;
    }

    int activeVoxels = 0;

    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].show) {
                    activeVoxels++;
                }
            }
        }
    }

    fout << "OFF" << std::endl;
    fout << activeVoxels * 8 << " " << activeVoxels * 6 << " 0" << std::endl; 

    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].show) {
                    fout << x - 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl; // P0
                    fout << x - 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl; // P1
                    fout << x + 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl; // P2
                    fout << x + 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl; // P3
                    fout << x - 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl; // P4
                    fout << x - 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl; // P5
                    fout << x + 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl; // P6
                    fout << x + 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl; // P7
                }
            }
        }
    }

    int currentVoxel = 0;
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].show) {
                    int offset = currentVoxel * 8;
                    
                    float r = v[x][y][z].r;
                    float g = v[x][y][z].g;
                    float b = v[x][y][z].b;
                    float a = v[x][y][z].a;

                    fout << "4 " << offset + 0 << " " << offset + 3 << " " << offset + 2 << " " << offset + 1 << " " << r << " " << g << " " << b << " " << a << std::endl; // Traseira
                    fout << "4 " << offset + 4 << " " << offset + 5 << " " << offset + 6 << " " << offset + 7 << " " << r << " " << g << " " << b << " " << a << std::endl; // Frontal
                    fout << "4 " << offset + 0 << " " << offset + 1 << " " << offset + 5 << " " << offset + 4 << " " << r << " " << g << " " << b << " " << a << std::endl; // Esquerda
                    fout << "4 " << offset + 0 << " " << offset + 4 << " " << offset + 7 << " " << offset + 3 << " " << r << " " << g << " " << b << " " << a << std::endl; // Superior
                    fout << "4 " << offset + 3 << " " << offset + 7 << " " << offset + 6 << " " << offset + 2 << " " << r << " " << g << " " << b << " " << a << std::endl; // Direita
                    fout << "4 " << offset + 1 << " " << offset + 2 << " " << offset + 6 << " " << offset + 5 << " " << r << " " << g << " " << b << " " << a << std::endl; // Inferior

                    currentVoxel++;
                }
            }
        }
    }

    fout.close();
    std::cout << "Arquivo " << filename << " salvo com sucesso!" << std::endl;
}

void Sculptor::setColor(float r, float g, float b, float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z) {
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z) {
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = false; 
        
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            for (int z = z0; z <= z1; z++) {
                putVoxel(x, y, z); 
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            for (int z = z0; z <= z1; z++) {
                cutVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
    double r2 = radius * radius;
    
    for (int x = xcenter - radius; x <= xcenter + radius; x++) {
        for (int y = ycenter - radius; y <= ycenter + radius; y++) {
            for (int z = zcenter - radius; z <= zcenter + radius; z++) {
                
                double dist = ((x - xcenter) * (x - xcenter)) + 
                              ((y - ycenter) * (y - ycenter)) + 
                              ((z - zcenter) * (z - zcenter));
                
                if (dist <= r2) {
                    putVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    double r2 = radius * radius;
    
    for (int x = xcenter - radius; x <= xcenter + radius; x++) {
        for (int y = ycenter - radius; y <= ycenter + radius; y++) {
            for (int z = zcenter - radius; z <= zcenter + radius; z++) {
                
                double dist = ((x - xcenter) * (x - xcenter)) + 
                              ((y - ycenter) * (y - ycenter)) + 
                              ((z - zcenter) * (z - zcenter));
                
                if (dist <= r2) {
                    cutVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    double dist;
    for (int x = xcenter - rx; x <= xcenter + rx; x++) {
        for (int y = ycenter - ry; y <= ycenter + ry; y++) {
            for (int z = zcenter - rz; z <= zcenter + rz; z++) {
                if (rx != 0 && ry != 0 && rz != 0) {
                    dist = (pow(x - xcenter, 2) / pow(rx, 2)) + 
                           (pow(y - ycenter, 2) / pow(ry, 2)) + 
                           (pow(z - zcenter, 2) / pow(rz, 2));
                    
                    if (dist <= 1.0) {
                        putVoxel(x, y, z);
                    }
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    double dist;
    for (int x = xcenter - rx; x <= xcenter + rx; x++) {
        for (int y = ycenter - ry; y <= ycenter + ry; y++) {
            for (int z = zcenter - rz; z <= zcenter + rz; z++) {
                if (rx != 0 && ry != 0 && rz != 0) {
                    dist = (pow(x - xcenter, 2) / pow(rx, 2)) + 
                           (pow(y - ycenter, 2) / pow(ry, 2)) + 
                           (pow(z - zcenter, 2) / pow(rz, 2));
                    
                    if (dist <= 1.0) {
                        cutVoxel(x, y, z);
                    }
                }
            }
        }
    }
}