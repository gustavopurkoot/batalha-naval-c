# 🚢 Batalha Naval em C

Jogo de Batalha Naval para dois jogadores desenvolvido em C.

## 👤 Autor

Gustavo Purkoot Ferreira

## 📋 Descrição

Implementação do clássico jogo Batalha Naval em linguagem C, permitindo que dois jogadores posicionem seus navios manualmente e se enfrentem em turnos alternados até que todos os navios de um dos jogadores sejam destruídos.

O projeto foi desenvolvido com foco em estruturas bidimensionais, validação de entrada de dados, modularização do código e manipulação de matrizes.

## 🚀 Instruções de Execução

### Pré-requisitos

* Compilador C (GCC recomendado)

### Passos

Clone o repositório:

```bash
git clone https://github.com/gustavopurkoot/Batalha_Naval_C.git
cd Batalha_Naval_C
```

Compile o projeto:

```bash
gcc main.c -o batalhaNaval
```

Execute o programa:

Linux:

```bash
./batalhaNaval
```

Windows:

```bash
batalhaNaval.exe
```

## 🛠️ Tecnologias Utilizadas

* Linguagem C
* Matrizes bidimensionais
* Ponteiros
* Funções
* Entrada e saída padrão (`stdio.h`)

## ⚓ Funcionalidades

### Posicionamento de Navios

* Posicionamento manual
* Navios de tamanhos 5, 4, 3, 3 e 2
* Orientação vertical e horizontal
* Validação de limites do tabuleiro
* Impede sobreposição de navios

### Sistema de Tiros

* Alternância de turnos entre jogadores
* Registro de acertos e erros
* Impede tiros repetidos
* Validação das coordenadas informadas
* Exibição do histórico de disparos

### Condição de Vitória

* Verificação automática de navios restantes
* Encerramento da partida ao destruir toda a frota adversária

## 📦 Representação do Tabuleiro

| Valor | Significado   |
| ----- | ------------- |
| 0     | Água          |
| 1     | Navio         |
| 2     | Tiro na Água  |
| 3     | Tiro Acertado |

## 🗂️ Estrutura do Projeto

```text
BATALHA-NAVAL-C/
├── src/
│   └── main.c
├── .gitignore
├── README.md
└── LICENSE
```

## 📄 Licença

Este projeto está licenciado sob a licença MIT.
