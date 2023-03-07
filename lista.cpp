#include <cstdlib>
#include <iostream>

#include "lista.h"

using namespace std;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
tLista* inicia_lista() {
	tLista* tmp = new (tLista);
	tmp->tam = 0;
	tmp->lista = NULL;

	return tmp;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 * @param ptlista ponteiro para a lista.
 * @return NULL para atualizar o ponteiro da lista.
 */
tLista * encerra_lista(tLista * ptlista) {
	no * ant = ptlista->lista;
	no * pont = ptlista->lista;
	
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(ptlista);
	
        return NULL;
}

/**
 * Busca pela placa da chave passada dentro da lista encadeada.
 * @param banco de dados utilizado.
 * @param placa a ser buscada.
 * @return verdareiro se o elemento foi encontrado.
 */
no * busca(tLista * ptlista, string placa) {
	no * ptr = ptlista->lista;
        
	while (ptr != NULL && ptr->veiculo->placa != placa)
        {
            ptr = ptr->prox;
        }
	return ptr;
}

/**
 * Realiza a insercao do no no início da lista ligada.
 * @param banco de dados utilizado.
 * @param no a ser inserido.
 */
void insere_inicio(tLista * ptlista, no *ins)
{
	no* p;
        p = new(no);
        p->veiculo = ins->veiculo;
        p->prox = ptlista->lista;
        ptlista->lista = p;
        ptlista->tam++;
}

/**
 * Realiza a insercao do no no fim da lista ligada.
 * @param banco de dados utilizado.
 * @param no a ser inserido.
 */
void insere_fim(tLista * ptlista, no *ins)
{
        if (ptlista->tam == 0)
        {
            insere_inicio(ptlista, ins);
        } else {
            no* p = ptlista->lista;
            while (p->prox != NULL)
                p = p->prox;
            p->prox = new(no);
            p->prox->veiculo = ins->veiculo;
            p->prox->prox = NULL;
            ptlista->tam++;
        }
}

/**
 * Pega o input do usuario para a insercao
 * @param placa digitada no main que veio da funcao void insere()
 * @return o no a ser inserido
 */

no *noIns(string placa)
{
    no *ins = new (no);
    ins->veiculo = new Tveiculo;
    cout << "Digite o modelo: " << endl;
    cin >> ins->veiculo->modelo;
    cout << "Digite a marca: " << endl;
    cin >> ins->veiculo->marca;
    cout << "Digite o tipo: " << endl;
    cin >> ins->veiculo->tipo;
    cout << "Digite o ano: " << endl;
    cin >> ins->veiculo->ano;
    cout << "Digite a km: " << endl;
    cin >> ins->veiculo->km;
    cout << "Digite a potencia: " << endl;
    cin >> ins->veiculo->potencia;
    cout << "Digite o combustivel: " << endl;
    cin >> ins->veiculo->combustivel;
    cout << "Digite o cambio: " << endl;
    cin >> ins->veiculo->cambio;
    cout << "Digite a direcao: " << endl;
    cin >> ins->veiculo->direcao;
    cout << "Digite a cor: " << endl;
    cin >> ins->veiculo->cor;
    cout << "Digite as portas: " << endl;
    cin >> ins->veiculo->portas;
    cout << "Digite o valor: " << endl;
    cin >> ins->veiculo->valor;
    cout << "A placa recebida será a digitada anteriormente" << endl;
    ins->veiculo->placa = placa;
    return ins;
}

/**
 * Insere o no no fim da lista
 * @param banco de dados onde sera inserido
 * @param placa digitada no main(nao sera duplicada)
 */
void insere(tLista *ptlista, string placa)
{
    no *atual = ptlista->lista;
    no *ins = noIns(placa);
    
    if(atual == NULL) // Lista vazia
    {
        atual = ins;
    } else {
        while(atual->prox != NULL)
        {
            atual = atual->prox;
        }
        
        atual->prox = ins;
    }
}

/**
 * Realiza a remocao do primeiro elemento da lista encadeada, se houver.
 * @param banco de dados a ser utilizado
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no * remove_inicio(tLista * ptlista)
{
	no * p;

	if(ptlista->tam == 0)
        {
            return NULL;
        } else {    
            p = ptlista->lista;
            ptlista->lista = p->prox;
            p->prox = NULL;
            ptlista->tam--;
            return p;
        }
}

/**
 * Realiza a remocao do último elemento da lista encadeada, se houver.
 * @param banco de dados a ser utilizado
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no * remove_fim(tLista * ptlista){
	no * p, * ant;

	if(ptlista->tam == 0)
            return NULL;

        p = ptlista->lista;
        while (p->prox != NULL){
            ant = p;
            p = p->prox;
        }
        if (p == ptlista->lista)
            ptlista->lista = NULL;
        else
            ant->prox = NULL;
        p->prox = NULL;
        ptlista->tam--;
	return p;
}

/**
 * Vai remover o no retornado da funcao busca()
 * @param banco de dados que vai ser utilizado
 * @param no a ser removido que vem da funcao busca()
 */

void remove(tLista *ptlista, no *rem)
{
    no *ant = ptlista->lista;
    if(ant == NULL)
    {
        cout << "Lista vazia." << endl;
    } else {
        while(ant->prox != NULL && ant->prox != rem)
        {
            ant = ant->prox;
        }    
        ant->prox = ant->prox->prox;
        delete(rem->veiculo);
        delete(rem);
        ptlista->tam--;
    }
}

/**
 * Imprime a lista encadeada.
 */
void imprime(tLista * ptlista){
	no * ptr = ptlista->lista;
	while(ptr != NULL){
            cout << ptr->veiculo->modelo << " ";
            cout << ptr->veiculo->marca << " ";
            cout << ptr->veiculo->tipo << " ";
            cout << ptr->veiculo->ano << " ";
            cout << ptr->veiculo->km << " ";
            cout << ptr->veiculo->potencia << " ";
            cout << ptr->veiculo->combustivel << " ";
            cout << ptr->veiculo->cambio << " ";
            cout << ptr->veiculo->direcao << " ";
            cout << ptr->veiculo->cor << " ";
            cout << ptr->veiculo->portas << " ";
            cout << ptr->veiculo->placa << " ";
            cout << ptr->veiculo->valor << ".00" << endl;
            ptr = ptr->prox;
	}
}

/**
 * Ordenacao dividida em tres if's (lembra um BubbleSort)
 * @param banco de dados que vai ser utilizado
 */
void ordena_lista(tLista *BD)
{
    tLista *BDOrd = new tLista;
    no *ptr = BD->lista; // no que vai percorrer a lista principal
    no *aux = new no; // Primeiro no a ser inserido
    
    aux->veiculo = ptr->veiculo; // Primeiro no ja tem que ter o primeiro veiculo para fazer as comparacoes
    aux->prox = NULL;
    
    BDOrd->lista = aux; // A lista Ordenada vai apontar para o primeiro no ja alocado
    BDOrd->tam = 1; 
    
    for(int i = 0; i < BD->tam-1; i++)
    {
        ptr = ptr->prox;
        aux = BDOrd->lista;
        for(int j = 0; j < BDOrd->tam; j++)
        {
            if(ptr->veiculo->placa < aux->veiculo->placa && j == 0) // Inserido logo no comeco
            {
                no *ins = new no; // Cria o no que vai ser inserido na lista ordenada
                ins->veiculo = ptr->veiculo;
                BDOrd->lista = ins;
                ins->prox = aux;
                break;
            } else if(ptr->veiculo->placa < aux->veiculo->placa) // Vai ser inserido na esquerda
            {
                no *ins = new no;
                ins->prox = aux->prox;
                ins->veiculo = aux->veiculo;
                aux->veiculo = ptr->veiculo;
                aux->prox = ins;
                break;
            } else if(aux->prox == NULL) // Ultimo
            {
                no * ins = new no;
                ins->prox = NULL;
                ins->veiculo = ptr->veiculo;
                aux->prox = ins;
                break;
            }
            aux = aux->prox;
        }
        BDOrd->tam++;
    }
    imprime(BDOrd);
}

