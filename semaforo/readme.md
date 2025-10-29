# Relatório da Atividade: Semáforo – Estágio Departamento de Engenharia de Trânsito

## Introdução

Durante meu estágio no Departamento de Engenharia de Trânsito, fui responsável por controlar o fluxo em uma via movimentada no bairro Butantã. O desafio foi construir e programar um semáforo funcional, utilizando princípios de eletrônica e lógica de programação, a fim de garantir a segurança de pedestres e veículos.

---

## Parte 1: Montagem Física do Semáforo

### Lista de Materiais Utilizados

- [2] Protoboard
- [1] LED vermelho
- [1] LED amarelo
- [1] LED verde
- [3] Resistores (330 Ω)
- [6] Jumpers/fios (macho-fêmea)
- [1] Jumper/fio (macho-macho)
- [1] Arduíno UNO
- [1] Semáforo em MDF
- [1] Cabo USB para alimentação do arduíno e upload do código

---

## Parte 2: Programação e Lógica do Semáforo

### Código do Semáforo

O funcionamento do semáforo funciona da seguinte maneira:
- 4 segundos: luz verde acesa
- 6 segundos: luz vermelha acesa
- 2 segundos: luz amarela acesa

o código solicitado pode ser conferido em [semaforo.ino](semaforo.ino)

---

## Parte 3: Vídeo de funcionamento

O semáforo foi montado de maeira com que o jumper macho-macho se conectasse com a saída GNV (polo negativo) do arduíno, onde passa energia para a protoboard. Com essa fonte, no protoboard, foi conectado um resistor para cada luz, e em sequência, na mesma linha de cada resistência, um jumper (macho-fêmea), cada um conectado ao cátodo do led, e posteriormente, cada ânodo do led, é conectado a sua respectiva saída, setada no código.

[Clique aqui](https://www.youtube.com/watch?v=Lo7x-fEkS5Y) para ter acesso ao vídeo, que motra o funcionamento do semáforo solicitado.

