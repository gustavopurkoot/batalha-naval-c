# 🚢 Batalha Naval em C

Jogo de Batalha Naval (*Battleship*) desenvolvido em C, jogável no terminal, no modo dois jogadores (passa e joga no mesmo computador).

## 📌 Sobre o projeto

Este projeto simula o clássico jogo de Batalha Naval, com posicionamento de navios validado, sistema de tiros, ocultação da frota do oponente e detecção de vitória.

Foi desenvolvido como projeto pessoal, com foco em lógica de programação, manipulação de arrays bidimensionais e ponteiros em C.

## 🎮 Como jogar

1. Cada jogador posiciona sua frota de 5 navios no próprio tabuleiro (10x10), informando linha, coluna e orientação (horizontal ou vertical).
2. Os jogadores se alternam atirando em coordenadas do tabuleiro do oponente.
3. Cada tiro resulta em **água** ou **acerto**.
4. O jogo termina quando um dos jogadores afunda toda a frota do adversário.

### Frota de cada jogador

| Navio | Tamanho (casas) |
|-------|-----------------|
| Porta-aviões | 5        |
| Encouraçado  | 4        |
| Cruzador     | 3        |
| Submarino    | 3        |
| Destróier    | 2        |

## ✅ Funcionalidades implementadas

- Posicionamento de navios com validação de limites do tabuleiro
- Validação de sobreposição entre navios
- Repetição automática da pergunta em caso de entrada inválida
- Ocultação da frota do oponente durante a fase de tiros
- Validação de tiros (dentro do tabuleiro e sem repetir a mesma posição)
- Detecção automática de vitória

## 🛠️ Tecnologias

- C (padrão C99 ou superior)
- Compilador GCC (ou qualquer compilador C compatível)

## ▶️ Como compilar e executar

```bash
gcc main.c -o batalha
./batalha
```

No Windows (sem WSL/MinGW configurado como acima):

```bash
gcc main.c -o batalha.exe
batalha.exe
```

> Substitua `main.c` pelo nome real do arquivo-fonte do projeto, caso seja diferente.

## 📐 Estrutura do código

| Função | Responsabilidade                                                             |
|--------|------------------------------------------------------------------------------|
| `inicializarTabuleiro` | Zera um tabuleiro (água em todas as posições)                |
| `imprimirtabuleiro`    | Exibe um tabuleiro no terminal                               |
| `posicionarNavios`     | Lê e valida a posição de cada navio da frota                 |
| `lerTiro`              | Lê e valida a coordenada de um tiro                          |
| `processarTiro`        | Verifica se o tiro acertou um navio e atualiza os tabuleiros |
| `aindaTemNavios`       | Verifica se um jogador ainda possui navios não afundados     |
| `main`                 | Controla o fluxo geral do jogo (posicionamento + turnos)     |

## 📈 Possíveis melhorias futuras

- Identificar e anunciar quando um navio específico é afundado (não só "acertou")
- Modo contra o computador (CPU posiciona e atira automaticamente)
- Interface gráfica

## 👨‍💻 Autor

Gustavo Purkoot Ferreira
[github.com/gustavopurkoot](https://github.com/gustavopurkoot)

## 📄 Licença

Este projeto é apenas para fins educacionais.
