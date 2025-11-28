# 📡 Uai-Fi Project

&emsp; Nessa atividade, o intuito foi entender como a **conexão Wi-Fi** ocorre dentro de diferentes ambientes, entendendo a oscilação da rede ou até mesmo a desconexão.

Vale ressaltar a existência do fenômeno **Gaiola de Faraday**, onde a eletricidade estática é bloqueada por um condutor em equilíbrio eletrostático. Em nosso teste, a **estrutura metálica de um elevador** atua como uma **gaiola imperfeita**, atenuando (bloqueando ou enfraquecendo) drasticamente o sinal de **rádio frequência (RF)**, como o Wi-Fi. Isso causa uma **queda abrupta** na potência do sinal medida. 

---

## 📉 Metodologia e Objetivo

O objetivo principal do projeto é registrar e visualizar a **potência do sinal Wi-Fi (dBm)** em diferentes cenários, destacando a variação causada por barreiras físicas e o efeito de blindagem do elevador.


### Dashboard (Adafruit IO)

O dashboard foi configurado com um **Gráfico de Linha** (Tempo vs. dBm) para monitorar a variação do sinal em tempo real.

| Potência (dBm) | Qualidade do Sinal |
| :---: | :---: |
| -30 a -50 | Excelente |
| -50 a -70 | Boa |
| -70 a -80 | Fraca/Aceitável |
| Abaixo de -80 | Muito Fraca/Ruim |

---

## 💻 Código pode ser conferido [aqui](code.ino)

## Vídeo de todo experimento está [aqui](https://drive.google.com/file/d/1gEEeg02h9Rw_omRznExT0nFogPlm244e/view?usp=sharing)