# Gerenciamento-de-Vans-Carros-e-Utilitarios-II
Segundo trabalho feito em C++ para a matéria de Algoritmo e Estrutura de Dados II, onde a nota foi 95 de 100. Esse repositório está com correções feitas no código para atingir a nota máxima.

**Obs:** Como esse trabalho foi feito no NetBeans, pode ocorrer erro ao zipar e tentar abrir em outras IDEs. Caso aconteça, uma possibilidade é baixar separadamente os arquivos .cpp, .h e o banco de dados com os veículos.


**Objetivo:** adquirir conhecimentos de manipulação de listas com alocação dinâmica (lista ligada ou encadeada) numa aplicação que cria listas, pilhas e filas como resultado de buscas numa lista principal de carros, vans e utilitários.

**Descrição:** o aplicativo desenvolvido no projeto deve criar uma lista ligada principal com os dados lidos de um arquivo de entrada, na ordem apresentada pelo arquivo. Cada linha do arquivo deve ser armazenada numa struct (em C++) que será apontada por um nó da lista. Então o aplicativo deve construir outras listas, pilhas ou filas a partir de buscas realizadas na lista principal, sem realocar
ou duplicar as structs da lista principal.

**Arquivo de Dados:** conterá um número ilimitado de linhas, onde cada linha conterá os dados de um veículo: modelo, marca, tipo, ano, quilometragem, potência do motor, combustível, câmbio, direção, cor, número de portas, placa e preço de venda.

**Requisitos:** o aplicativo deverá:

- implementar as opções de inclusão, busca (com opção de exclusão) e relatório;

- construir uma segunda lista de nós que apontem para os veículos ordenados pelas placas;

- realizar buscas na lista principal, construindo uma estrutura com as seguintes características abaixo, e ao final retire
os veículos da estrutura e imprima as placas na tela;

- **pilha:** inserir quando este tiver direção hidráulica e remover um veículo quando for direção mecânica;

- **fila:** inserir o veículo quando este tiver câmbio automático e remover um veículo quando for câmbio manual;

ao final da execução todas as estruturas devem ser desalocadas.
