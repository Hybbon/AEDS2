import requests
from webapp.db import mongo
from flask import current_app

IMDBID_NUMDIGITOS = 7  # Usado para preencher zeros à esquerda

def obter_dados(imdb_id):
    """Obtém os dados de um filme da API do IMDB ou do cache (MongoDB).
    Adiciona dados ao cache caso ainda não estejam presentes nele.

    Argumentos:
    imdb_id -- String correspondente ao imdbID já formatado.
               Formato: tt####### (# = [0-9])
    """
    imdb_data = mongo.db.imdb_data
    query = imdb_data.find_one({"imdbID": imdb_id})
    if query is None:
        url = current_app.config['IMDB_API_URL'] + "i=" + imdb_id
        query = requests.get(url).json()
        imdb_data.insert(query)
    return query


def obter_lista_filmes(lista_filmes):
    """Obtém dados de uma lista de filmes fornecida. Retorna uma lista
    de tuplas contendo o movie_id e os dados do filme.

    Argumentos:
    lista_filmes -- Lista de tuplas correspondentes a cada filme.
                    Formato: (movie_id, imdb_id)
                                         ^-(int, ainda não formatado)
    """
    lista_imdb_ids = [
        (x[0], "tt" + str(x[1]).zfill(IMDBID_NUMDIGITOS))
        for x in lista_filmes]
    dados = []
    for filme in lista_imdb_ids:
        dados.append((filme[0], obter_dados(filme[1])))
    return dados