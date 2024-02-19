import argparse
import re


def quitar_tildes(texto):
    tildes = {"á": "a", "é": "e", "í": "i", "ó": "o", "ú": "u", "ü": "u"}
    resultado = "".join(tildes.get(caracter, caracter) for caracter in texto)
    return resultado


# Recibe como argumento o numero do problema resolto e o nome do problema
# e engade unha nova fila a táboa de problemas resoltos na posicion correspondente
# do problema cos enlaces correspondentes
def engadir_fila_taboa(arquivo_md, numero, nome):
    with open(arquivo_md, "r", encoding="utf-8") as file:
        linhas = file.readlines()

        for linha in linhas:
            # Comprobamos se a linea é unha fila da taboa e se a primeira palabra é un numero
            if linha.startswith("|") and linha.split(" ")[1].strip().isdigit():
                if int(linha.split(" ")[1].strip()) == numero:
                    print(f"O problema {numero} xa está na táboa")
                    return
                elif int(linha.split(" ")[1].strip()) > numero:
                    # Contruimos a parte do nome do problema na url (quitamos tildes e colocamos os '%20' en lugar dos espazos)
                    nome_en_url = quitar_tildes(nome).replace(" ", "%20")
                    # Contruimos a nova fila da taboa
                    nova_linha = f"| {numero}      | [{nome}](https://aceptaelreto.com/problem/statement.php?id={numero})              | [{numero}.cpp](https://github.com/antongomez/acepta-el-reto/blob/main/{numero}%20{nome_en_url}/{numero}.cpp)                        |"
                    linhas.insert(linhas.index(linha), nova_linha + "\n")
                    break

    with open(arquivo_md, "w", encoding="utf-8") as file:
        file.writelines(linhas)


# Recibe como argumento o arquivo README.md e devolve o numero de filas da taboa
# de problemas resoltos
def contar_filas_taboa(arquivo_md):
    with open(arquivo_md, "r", encoding="utf-8") as file:
        contenido = file.read()

        # Obtener todas las filas de la tabla
        filas = re.findall(r"^\|(.+?)\|$", contenido, re.MULTILINE)

        # Contar el número de filas
        num_filas = len(filas)

        filas_a_restar = 0

        for fila in filas:
            # Comprobo que a primera 'palabra' sexa un numero
            if not fila.split(" ")[1].strip().isdigit():
                filas_a_restar += 1

        return num_filas - filas_a_restar


# Recibe como argumento o arquivo README.md e a ultima frase do arquivo
# e actualiza o numero de problemas resoltos no README.md
def actualizar_numero_problemas_resoltos(arquivo_md, ultima_frase):
    with open(arquivo_md, "r+", encoding="utf-8") as file:
        linhas = file.readlines()

    if linhas:
        # Atopamos a ultima linha con contido e eliminamos todas incluida esa
        ultima_linea = linhas[-1].strip()
        while ultima_linea == "":
            linhas.pop()
            ultima_linea = linhas[-1].strip()
        linhas.pop()

        # Engadimos a nova ultima linea
        linhas.append(ultima_frase)

    # Escribimos no arquivo o contido actualizado
    with open(arquivo_md, "w", encoding="utf-8") as file:
        file.writelines(linhas)


# Lemos o numero de problema e o nome do problema
parser = argparse.ArgumentParser(
    description="Script que actualiza o README.md. Engade unha nova fila a táboa de problemas resoltos e actualiza o número de problemas resoltos."
)

parser.add_argument("numero", type=int, help="Número de problema")
parser.add_argument("nome", type=str, help="Nome do problema")

args = parser.parse_args()

numero = args.numero
nome = args.nome

arquivo_md = "./README.md"

# Engadimos a nova fila a táboa de problemas resoltos cos enlaces correspondentes
engadir_fila_taboa(arquivo_md, numero, nome)
# Obtemos o numero de problemas resoltos
num_filas = contar_filas_taboa(arquivo_md)
ultima_frase = f"Número de problemas resueltos: {num_filas}"
# Actualizamos o numero de problemas resoltos
actualizar_numero_problemas_resoltos(arquivo_md, ultima_frase)

print(ultima_frase)
