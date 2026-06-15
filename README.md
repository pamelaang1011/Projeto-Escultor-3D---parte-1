Projeto Escultor 3D - Parte 1

Este projeto consiste no desenvolvimento de uma ferramenta em C++ para a criação de esculturas tridimensionais representadas por matrizes digitais, utilizando o conceito de Voxels, semelhante à lógica do jogo Minecraft.

Descrição da Escultura: Campo de Futebol
Para validar a biblioteca de ferramentas, foi desenvolvido um programa de testes que gera um campo de futebol, utilizando de forma exaustiva todos os métodos de desenho e remoção disponíveis na classe. 

A escultura inclui:
*   Gramado e marcações: Criados com `putBox` e `setColor`.
*   Círculo Central: Desenhado utilizando o método `putSphere`.
*   Bolas ou detalhes ornamentais: Implementados com `putEllipsoid` e `putVoxel`.
*   Recortes e ajustes: Refinados através dos métodos `cutBox`, `cutSphere` e `cutVoxel`.

Funcionalidades Implementadas
A classe `Sculptor` permite a manipulação de uma matriz 3D alocada dinamicamente, onde cada elemento (Voxel) armazena informações de cor (RGB), transparência (Alpha) e visibilidade (show).

Os métodos disponíveis na biblioteca são:
- `putVoxel(x, y, z)` e `cutVoxel(x, y, z)`: Ativa ou desativa um voxel individual.
- `putBox` e `cutBox`: Adiciona ou remove blocos de voxels em intervalos [x_0, x_1], [y_0, y_1] e [z_0, z_1].
- `putSphere` e `cutSphere`: Cria ou apaga formas esféricas baseadas em raio e centro.
- `putEllipsoid` e `cutEllipsoid`: Cria ou apaga elipsoides com raios independentes (rx, ry, rz).
- `writeOFF`: Exporta a escultura final para o formato de arquivo OFF.

Formato de Saída (OFF)
O arquivo de saída gerado (`.off`) é um formato padrão para representação de malhas tridimensionais. Cada voxel visível é convertido em um cubo de lado 1, contendo 8 vértices e 6 faces coloridas no formato RGBA. 

Como Executar
1. Certifique-se de ter os arquivos `sculptor.h`, `sculptor.cpp` e `main.cpp` no mesmo diretório.
2. Compile o projeto utilizando um compilador C++:
   ```bash
   g++ main.cpp sculptor.cpp -o escultor
   ```
3. Execute o programa gerado:
   ```bash
   ./escultor
   ```
4. O arquivo `campo_futebol.off` (ou o nome definido no seu código) será criado e estará pronto para visualização.
