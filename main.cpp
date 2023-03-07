/* Esse trabalho apresenta o gerenciamento (usando listas encadeadas) de carros, vans e utilitarios . E possivel fazer operacoes de insercao, busca, ordenacao e remocao
 * Tambem e possivel ver como seria a lista principal como uma fila e como uma pilha.
 * 
 * Nome: Barbara Silveira Rodrigues
 * RA: 2021.1.08.042
 * Curso: Ciência da Computação         Instituição: UNIFAL-MG 
 * Matéria: Algoritmo e Estrutura de Dados II (AEDsII)
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "pilha.h"
#include "fila.h"
using namespace std;

tLista *BD, *BDP, *BDF; // Lista, Pilha e Fila

int main()
{
    // Inicializa todos cabecalhos
    BD = inicia_lista();
    no *p = new (no);
    BD->lista = p;
    no *ant = p;
    
    BDP = inicia_pilha();
    
    BDF = inicia_fila();
    
    // Leitura do arquivo
    ifstream myfile("BD_veiculos.txt");
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            p->veiculo = new Tveiculo;
            myfile >> p->veiculo->modelo;
            myfile >> p->veiculo->marca;
            myfile >> p->veiculo->tipo;
            myfile >> p->veiculo->ano;
            myfile >> p->veiculo->km;
            myfile >> p->veiculo->potencia;
            myfile >> p->veiculo->combustivel;
            myfile >> p->veiculo->cambio;
            myfile >> p->veiculo->direcao;
            myfile >> p->veiculo->cor;
            myfile >> p->veiculo->portas;
            myfile >> p->veiculo->placa;
            myfile >> p->veiculo->valor;
            BD->tam++;
            p->prox = new(no);
            p = p->prox;
        }
        delete(p);
        ant->prox->prox = NULL;
        ant->prox = NULL;// com isso o ultimo nao aparece mas a busca funciona
        myfile.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }
    
    cout << "-----------------------------------------" << endl;
    cout << "Gerenciador de Carros, Vans e Utilitarios" << endl;
    cout << "-----------------------------------------" << endl; 
    
    int opc;
    
    do
    {
        cout << "Escolha a funcionalidade que deseja: " << endl;
        cout << "(1) Busca" << endl;
        cout << "(2) Inserir" << endl;
        cout << "(3) Relatorio" << endl;
        cout << "(4) Pilha" << endl;
        cout << "(5) Fila" << endl;
        cout << "(0) Sair" << endl;
        cin >> opc;
        
        switch (opc)
        {
            case 1: // Busca
            {
                string placaBus;
                no *retornoB;
                char opcB;
                
                cout << "Digite a placa do veiculo buscado: " << endl;
                cin >> placaBus;
                
                retornoB = busca(BD, placaBus);
                
                if(retornoB == NULL)
                {
                    cout << "Veiculo não encontrado." << endl;
                } else {
                    cout << "Veiculo encontrado. Deseja excluir?(s/n)" << endl;
                    cin >> opcB;
                    if(opcB == 's')
                    {
                        remove(BD, retornoB);
                        cout << "Veiculo excluido." << endl;
                    } else if(opcB == 'n')
                    {
                        cout << "Veiculo nao sera apagado." << endl;
                    } else {
                        cout << "Digito invalido." << endl;
                    }
                }
            }
            break;
            
            case 2: // Inserir
            {
                string placaIns;
                
                cout << "Digite a placa do veiculo que deseja inserir: " << endl;
                cin >> placaIns;
                
                if(busca(BD, placaIns) == NULL) // Caso seja uma placa repetida
                {
                    insere(BD, placaIns);
                    cout << "Veiculo inserido." << endl;
                } else {
                    cout << "Veiculo nao foi inserido. Placa duplicada." << endl;
                }  
            }
            break;
            
            case 3: // Relatorio
            {
                ordena_lista(BD);
            }
            break;
            
            case 4: // Pilha
            { 
                no *percorre; // Vai percorrer toda a lista principal
                percorre = BD->lista;
                
                while(percorre->prox != NULL)
                {
                    if(percorre->veiculo->direcao == "Hidráulica")
                    {
                        push(BDP, percorre); // Insere no inicio
                    } else if(percorre->veiculo->direcao == "Mecânica")
                    {
                        pop(BDP); // Remove no inicio
                    }
                    percorre = percorre->prox;
                }
                imprime(BDP);
                encerra_pilha(BDP);
            }
            break;
            
            case 5: // Fila
            {
                no *percorre2; // Vai percorrer toda a lista principal
                percorre2 = BD->lista;
                
                while(percorre2->prox != NULL)
                {
                    if(percorre2->veiculo->cambio == "Automático")
                    {
                        queue(BDF, percorre2); // Insere no fim
                    } else if(percorre2->veiculo->cambio == "Manual")
                    {
                        unqueue(BDF); // Remove no inicio
                    }
                    percorre2 = percorre2->prox;
                }
                imprime(BDF);
                encerra_fila(BDP);
            }
            break;
            
            case 0: // Sair
            {
                cout << "Obrigada por usar!" << endl;
            }
            break;
            
            default: // Usuario digita errado/invalido
            {
                cout << "Digito invalido. Digite novamente." << endl;
            }
            break;
        }
    } while(opc != 0);
       
    rename("BD_veiculos.txt", "BD_Backup.txt"); // O antigo arquivo agora sera o backup
            
    ofstream arquivo;
    arquivo.open("BD_veiculos.txt", ios::out);
    
    if(arquivo.is_open())
    {
        no *fim = BD->lista;
        while(fim->prox != NULL)
        {
            arquivo << fim->veiculo->modelo << " ";
            arquivo << fim->veiculo->marca << " ";
            arquivo << fim->veiculo->tipo << " ";
            arquivo << fim->veiculo->ano << " ";
            arquivo << fim->veiculo->km << " ";
            arquivo << fim->veiculo->potencia << " ";
            arquivo << fim->veiculo->combustivel << " ";
            arquivo << fim->veiculo->cambio << " ";
            arquivo << fim->veiculo->direcao << " ";
            arquivo << fim->veiculo->cor << " ";
            arquivo << fim->veiculo->portas << " ";
            arquivo << fim->veiculo->placa << " ";
            arquivo << fim->veiculo->valor << endl;
            fim = fim->prox;
        }
    }
    arquivo.close();
    
    encerra_lista(BD);
         
    return (EXIT_SUCCESS);
}