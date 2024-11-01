# Exemplos de OpenGL e GLUT

Este repositório contém dois programas de exemplo para o uso de OpenGL e GLUT, desenvolvidos para o laboratório da disciplina de Computação Gráfica na Universidade Federal do Espírito Santo (UFES).

## Descrição dos Programas

1. **Quadrado Arrastável (`make q`)**  
   Este programa exibe um quadrado na tela que pode ser arrastado com o mouse (drag and drop).

   - **Execução**: `make q`

2. **Spline com Controle de Pontos (`make l`)**  
   Este programa permite a criação de uma spline, onde cada ponto de controle pode ser arrastado com o mouse. Além disso, é possível ajustar o número de pontos usados para construir a spline, variando entre 2 e 40.
   - **Controles**:
     - **`+`**: Aumenta o número de pontos de controle (máximo de 40).
     - **`-`**: Diminui o número de pontos de controle (mínimo de 2).
   - **Execução**: `make l`

## Pré-requisitos

- **OpenGL** e **GLUT**: Certifique-se de que as bibliotecas OpenGL e GLUT estejam instaladas no sistema.

## Instalação e Execução

1. Clone o repositório:

   ```bash
   git clone <URL_do_repositório>
   cd <nome_do_repositório>
   ```

2. Compile e execute os programas com os seguintes comandos:
   - Para o programa do quadrado:
     ```bash
     make q
     ```
   - Para o programa da spline:
     ```bash
     make l
     ```

## Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo [LICENSE](./LICENSE) para mais detalhes.
