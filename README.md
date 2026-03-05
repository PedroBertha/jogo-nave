# 🚀 Jogo da Nave Espacial (Terminal)

Este projeto foi desenvolvido como trabalho para a disciplina de **Paradigmas da Computação**.
O objetivo foi criar um jogo utilizando **programação estruturada em C**, respeitando as restrições da atividade.

O jogo é executado diretamente no **terminal** e consiste em controlar uma nave que precisa desviar de obstáculos que caem do topo da tela.

---

# 🎮 Como funciona o jogo

O jogador controla uma nave localizada na parte inferior da tela.
Obstáculos aparecem aleatoriamente no topo e descem a cada atualização do jogo.

O objetivo é **sobreviver o maior tempo possível sem colidir**.

A pontuação aumenta com o tempo e o jogo fica **progressivamente mais rápido**, aumentando a dificuldade.

---

# 🕹️ Controles

| Tecla | Ação                     |
| ----- | ------------------------ |
| A     | mover nave para esquerda |
| D     | mover nave para direita  |
| Q     | sair do jogo             |

---

# 🖥️ Exemplo do jogo no terminal

```
################################
#                              #
#            O                 #
#                              #
#               O              #
#          ^                   #
################################

Pontuação: 25
Recorde: 40
```

---

# ⚙️ Como compilar

É necessário ter o **GCC** instalado.

No terminal, execute:

```
gcc main.c -o jogo
```

Isso irá gerar o executável:

```
jogo.exe
```

---

# ▶️ Como executar

No Windows PowerShell:

```
.\jogo.exe
```

No Prompt de Comando:

```
jogo.exe
```

---

# 📚 Conceitos utilizados

O projeto foi desenvolvido utilizando apenas conceitos de **programação estruturada**, incluindo:

* Matrizes
* Struct
* Loops (`for`, `while`)
* Condicionais (`if`, `switch`)
* Números aleatórios (`rand`)
* Entrada e saída no terminal

Não foram utilizados:

* Classes
* Objetos
* Bibliotecas gráficas
* Instanciação de objetos

---

# 📂 Estrutura do projeto

```
jogo-nave/
│
├── main.c
├── jogo.exe
├── HELP.txt
├── ALGORITMO.txt
└── README.md
```

---

# 👨‍💻 Autor

**Pedro Henrique Likoski Bertha**
**Guilherme Possenti**

* GitHub: https://github.com/PedroBertha
* Curso: Ciência da Computação
* Disciplina: Paradigmas da Computação

---
