#ifndef _USUARIO_H_
#define _USUARIO_H_

#include "Lista.h"

typedef struct {
    int user_id;
    double jaccard;
    Lista *assistidos;
} Usuario;

/**
 * Aloca a memória e inicializa os elementos de um novo usuário. Inicializa a
 * lista de filmes assistidos (vazia).
 * @param  user_id    ID do usuário.
 * @param  jaccard    Coeficiente de jaccard do usuário com outro usuário
 * @param  assistidos Endereço da lista de filmes assistidos (ou NULL, caso se
 *                    queira criar uma lista vazia.
 * @return            Endereço do novo usuário.
 */
Usuario *Usuario_Inicializar(int user_id, double jaccard, Lista *assistidos);

/**
 * Libera a memória do usuário e da lista de filmes.
 * @param usuario Usuário a ser destruído
 */
void Usuario_Destruir(Usuario *usuario);

/**
 * Função auxiliar para destruir usuário. Construída para ser usada em conjunto
 * com as funções de destruir lista.
 * @param dados Endereço do usuário.
 */
void Usuario_DestruirAux(void *dados);

/**
 * Retorna o ID do usuário.
 * @param  usuario Usuário a ser lido.
 * @return         ID do usuário.
 */
int Usuario_ObterID(Usuario *usuario);

/**
 * Retorna o coeficiente de Jaccard do usuário com outro usuário.
 * @param  usuario Usuário do qual se quer o valor.
 * @return         Coeficiente de Jaccard.
 */
double Usuario_ObterJaccard(Usuario *usuario);

/**
 * Retorna o endereço da lista de filmes assistidos.
 * @param  usuario Usuário a ser lido.
 * @return         Endereço da lista de filmes assistidos.
 */
Lista *Usuario_ObterAssistidos(Usuario *usuario);

#endif