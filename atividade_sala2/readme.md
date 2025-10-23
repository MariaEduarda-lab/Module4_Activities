# Atividade em Sala: Circuito RC / Prática

## 📘 Descrição da Atividade

Nesta atividade, o objetivo foi **analisar o comportamento de um circuito RC (Resistor–Capacitor)** utilizando o **Arduino** como ferramenta de aquisição de dados. O experimento foi realizado para observar a **curva de carga e descarga** do capacitor e comparar os resultados obtidos em ambas as etapas.

O circuito foi montado em **protoboard**, utilizando o **Arduino UNO** e componentes eletrônicos simples, permitindo a leitura e o registro das tensões no resistor e no capacitor ao longo do tempo.

---

## ⚙️ Etapas Realizadas

### 1. Código Fonte Utilizado

O seguinte código foi utilizado para realizar as medições de tensão durante os processos de carga e descarga do capacitor:

[codigo.ino](codigo.ino)


O código lê a tensão no pino analógico, calcula as tensões sobre o resistor e o capacitor, e envia os valores para o **Monitor Serial**, permitindo análise posterior e geração dos gráficos de comportamento do circuito.

---

### 2. Componentes Utilizados

- **Resistor de carga (Re)** = 1 MΩ  
- **Resistor de descarga (Rd)** = 100 Ω  
- **Capacitor** = 10 µF / 25 V  
- **Chave** = 1 unidade (para alternar entre carga e descarga)  
- **Arduino UNO + Protoboard + Jumpers**
- **Luz led + resistor de carga (Re)** = 250 Ω

---

### 3. Explicação do Funcionamento

- Quando a **chave é fechada**, o capacitor começa a **carregar-se** através do resistor de 1 MΩ.  
- A tensão no **capacitor aumenta exponencialmente**, enquanto a tensão no resistor diminui com o tempo.  
- Ao **abrir a chave**, o led acende, o capacitor **descarga-se** através do resistor de 100 Ω, fazendo com que ambas as tensões decaiam exponencialmente,
- O **Arduino** acompanha essas variações ao longo do tempo, permitindo comparar as curvas de **carga e descarga**.

O comportamento teórico segue as equações de um circuito RC:

\[
V_C(t) = V_{max}(1 - e^{-t/RC})
\]

\[
V_C(t) = V_{max} \cdot e^{-t/RC}
\]

Essas fórmulas descrevem respectivamente os processos de **carga** e **descarga** do capacitor.

---

### 4. Evidências de Execução

#### 📈 Gráficos Obtidos

Os gráficos a seguir mostram o comportamento da **tensão do capacitor** durante a **carga e a descarga**:

<div align="center">

*Gráfico 1 - Carga do Capacitor*  
<img src="grafico_carga_capacitor" width="100%"><br>

*Gráfico 2 - Descarga do Capacitor*  
<img src="grafico_descarga.png" width="100%"><br>

<sup>Fonte: Maria Eduarda, 2025</sup>

</div>

---

### 5. Análise Comparativa

- Na **carga**, a tensão no capacitor partiu de **0 V** e tendeu a **5 V**, demonstrando o comportamento exponencial de acúmulo de carga.  
- Na **descarga**, a tensão decaiu de aproximadamente **5 V** a **0 V** rapidamente, devido ao resistor de menor valor (100 Ω), evidenciando **menor constante de tempo (τ = RC)**.  
- Os dados obtidos pelo **Monitor Serial** validaram as curvas teóricas esperadas para o circuito RC.

---

### 6. Link TinkerCad

O circuito foi simulado no **Tinkercad**, utilizando os mesmos componentes e o código acima.

[Link para o TinkerCad](https://www.tinkercad.com/things/hY6mBnw7wzw-magnificent-tumelo-snaget/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=2sUsnQRqQUEkUGcIPZHeP3cgR3qaYye-u2wUhpDkMzU)

---

### 💡 Arduino em Funcionamento

<div align="center">

*GIF 1 - Circuito RC em execução (simulação)*  
<img src="rc_pratica.gif" width="100%"><br>  

<sup>Fonte: Maria Eduarda, 2025</sup>

</div>
