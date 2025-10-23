import pandas as pd
import matplotlib.pyplot as plt
import sys

arquivo = "output.txt"

# tentativa de leitura robusta: aceita espaços e vírgulas como separador
try:
    dados = pd.read_csv(arquivo, sep=r'[,\s]+', engine='python',
                        names=["tempo_ms", "tensao_R", "tensao_C"],
                        header=None, comment='#')
except Exception as e:
    print("Erro ao ler o arquivo:", e)
    sys.exit(1)

# converte colunas para numéricas (vai transformar valores inválidos em NaN)
for col in ["tempo_ms", "tensao_R", "tensao_C"]:
    dados[col] = pd.to_numeric(dados[col], errors='coerce')

# remove linhas que não têm valores nas colunas essenciais
dados = dados.dropna(subset=["tempo_ms", "tensao_R", "tensao_C"])

if dados.empty:
    print("Nenhum dado numérico válido encontrado em", arquivo)
    print("Verifique o formato do arquivo (ex.: 'tempo tensao_R tensao_C' por linha).")
    sys.exit(1)

# ordena por tempo (caso não esteja ordenado)
dados = dados.sort_values("tempo_ms").reset_index(drop=True)

# converte tempo para segundos
dados["tempo_s"] = dados["tempo_ms"] / 1000.0

# imprime um resumo rápido para diagnóstico
print("Linhas lidas:", len(dados))
print(dados[["tempo_ms", "tensao_R", "tensao_C"]].head())

# --- GRÁFICO 1: Tensão no Capacitor (Carga) ---
plt.figure(figsize=(8,5))
plt.plot(dados["tempo_s"], dados["tensao_C"], marker='o', linestyle='-', linewidth=2, markersize=4, label='Tensão no Capacitor (C)')
plt.title("Carga do Capacitor")
plt.xlabel("Tempo (s)")
plt.ylabel("Tensão (V)")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("grafico_carga_capacitor.png", dpi=300, bbox_inches='tight')
plt.close()

# --- GRÁFICO 2: Tensão no Resistor (Descarga) ---
plt.figure(figsize=(8,5))
plt.plot(dados["tempo_s"], dados["tensao_R"], marker='o', linestyle='-', linewidth=2, markersize=4, label='Tensão no Resistor (R)')
plt.title("Descarga pelo Resistor")
plt.xlabel("Tempo (s)")
plt.ylabel("Tensão (V)")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("grafico_descarga_resistor.png", dpi=300, bbox_inches='tight')
plt.close()

# --- GRÁFICO 3: Comparação ---
plt.figure(figsize=(8,5))
plt.plot(dados["tempo_s"], dados["tensao_C"], marker='o', linestyle='-', linewidth=2, markersize=4, label='Capacitor (C)')
plt.plot(dados["tempo_s"], dados["tensao_R"], marker='o', linestyle='-', linewidth=2, markersize=4, label='Resistor (R)')
plt.title("Comparação entre carga e descarga")
plt.xlabel("Tempo (s)")
plt.ylabel("Tensão (V)")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("grafico_comparacao.png", dpi=300, bbox_inches='tight')
plt.close()

print("Gráficos salvos no diretório atual como:")
print(" - grafico_carga_capacitor.png")
print(" - grafico_descarga_resistor.png")
print(" - grafico_comparacao.png")
