#ifndef LISTA_H
#define LISTA_H

using namespace std;

typedef struct
{
    string modelo;
    string marca;
    string tipo;
    int ano;
    int km;
    float potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    int portas;
    string placa;
    float valor;  
}Tveiculo;

typedef struct no_ {
    Tveiculo *veiculo; 
    struct no_ * prox;  
} no;

typedef struct {
	int tam;            
	struct no_ * lista; 
} tLista;


tLista* inicia_lista();
tLista * encerra_lista(tLista * ptlista);
no * busca(tLista * ptlista, string placa);
void imprime(tLista * ptlista);
void remove(tLista *ptlista, no *rem);
void insere(tLista *ptlista, string placa);
no *noIns(string placa);
void ordena_lista(tLista *BD);

void insere_inicio(tLista * ptlista, no *ins);
no * remove_inicio(tLista * ptlista);
void insere_fim(tLista * ptlista, no *ins);
no * remove_fim(tLista * ptlista);


#endif /* LISTA_H */
