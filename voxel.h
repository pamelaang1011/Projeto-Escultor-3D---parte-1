#ifndef VOXEL_H
#define VOXEL_H

/* armazena a cor, a transparência e o estado de visibilidade do bloco.
 */
struct Voxel {
    float r; /* intensidade da cor vermelha (0.0 a 1.0) */
    float g; /* intensidade da cor verde (0.0 a 1.0) */
    float b; /* intensidade da cor azul (0.0 a 1.0) */
    float a; /* transparência do bloco (0.0 a 1.0) */
    bool show; /* define se o bloco será desenhado (true) ou apagado (false) */
};

#endif