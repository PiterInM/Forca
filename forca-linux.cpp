/*****************************************\
 *       Jogo de Forca no terminal       *
 *                                       *
 * Escrito por Piter Inácio (18/01/2024) *
 * MIT License                           *
 *                                       *
 * GitHub: @piterinm                     *
 * Instagram: @piterinacio               *
\*****************************************/

#include <iostream>
#include <cstdlib>
using namespace std;


#define quantPalavras 70
#define quantLetras 16

// Listagem de possíveis palavras a serem sorteadas em cada partida
// Para incluir ou modificar as palavras, dentro de um array de 16 posições, coloque
// cada letra em uma posição e complete com '_' até a 15º posição, reservando a 
// última para um número inteiro correspondente a quantidade de letras da palavra.
// Em casos de adicinar ou remover palavras da lista faz se necessário atualizar o
// define "quantPalavras" para a nova quantidade de palavras na matriz.
char dicionario[quantPalavras][quantLetras]={{'c','i','l','i','o','_','_','_','_','_','_','_','_','_','_', 5},
                                             {'b','a','n','c','o','_','_','_','_','_','_','_','_','_','_', 5},
                                             {'e','n','t','r','e','_','_','_','_','_','_','_','_','_','_', 5},
                                             {'p','a','r','d','o','_','_','_','_','_','_','_','_','_','_', 5},
                                             {'l','i','v','r','o','_','_','_','_','_','_','_','_','_','_', 5},
                                             {'t','e','m','p','o','_','_','_','_','_','_','_','_','_','_', 5},
                                             {'v','o','t','a','r','_','_','_','_','_','_','_','_','_','_', 5},
                                             {'a','c','o','r','d','o','_','_','_','_','_','_','_','_','_', 6},
                                             {'a','s','t','r','a','l','_','_','_','_','_','_','_','_','_', 6},
                                             {'b','a','l','e','i','a','_','_','_','_','_','_','_','_','_', 6},
                                             {'h','o','s','t','i','l','_','_','_','_','_','_','_','_','_', 6},
                                             {'m','o','r','t','a','l','_','_','_','_','_','_','_','_','_', 6},
                                             {'p','i','n','t','o','r','_','_','_','_','_','_','_','_','_', 6},
                                             {'s','a','l','a','d','a','_','_','_','_','_','_','_','_','_', 6},
                                             {'a','l','e','g','r','i','a','_','_','_','_','_','_','_','_', 7},
                                             {'a','m','i','z','a','d','e','_','_','_','_','_','_','_','_', 7},
                                             {'c','o','r','a','g','e','m','_','_','_','_','_','_','_','_', 7},
                                             {'c','u','l','t','u','r','a','_','_','_','_','_','_','_','_', 7},
                                             {'d','e','c','r','e','t','o','_','_','_','_','_','_','_','_', 7},
                                             {'d','e','s','a','f','i','o','_','_','_','_','_','_','_','_', 7},
                                             {'f','a','m','i','l','i','a','_','_','_','_','_','_','_','_', 7},
                                             {'l','a','c','t','o','s','e','_','_','_','_','_','_','_','_', 7},
                                             {'o','r','g','u','l','h','o','_','_','_','_','_','_','_','_', 7},
                                             {'p','o','b','r','e','s','a','_','_','_','_','_','_','_','_', 7},
                                             {'r','e','f','l','e','x','o','_','_','_','_','_','_','_','_', 7},
                                             {'s','u','c','e','s','s','o','_','_','_','_','_','_','_','_', 7},
                                             {'a','l','t','i','t','u','d','e','_','_','_','_','_','_','_', 8},
                                             {'d','e','s','t','r','u','i','r','_','_','_','_','_','_','_', 8},
                                             {'f','a','l','e','c','i','d','o','_','_','_','_','_','_','_', 8},
                                             {'g','a','n','g','o','r','r','a','_','_','_','_','_','_','_', 8},
                                             {'p','a','n','q','u','e','c','a','_','_','_','_','_','_','_', 8},
                                             {'p','o','l','i','t','i','c','o','_','_','_','_','_','_','_', 8},
                                             {'t','a','m','b','a','q','u','i','_','_','_','_','_','_','_', 8},
                                             {'c','a','p','a','c','i','t','o','r','_','_','_','_','_','_', 9},
                                             {'c','a','s','q','u','i','n','h','a','_','_','_','_','_','_', 9},
                                             {'d','i','f','u','n','d','i','r','_','_','_','_','_','_','_', 9},
                                             {'m','u','n','i','c','i','p','i','o','_','_','_','_','_','_', 9},
                                             {'p','r','e','c','a','v','i','d','o','_','_','_','_','_','_', 9},
                                             {'v','i','n','a','g','r','e','t','e','_','_','_','_','_','_', 9},
                                             {'c','o','o','r','d','e','n','a','d','a','_','_','_','_','_', 10},
                                             {'f','a','l','s','i','f','i','c','a','r','_','_','_','_','_', 10},
                                             {'f','o','r','a','s','t','e','i','r','o','_','_','_','_','_', 10},
                                             {'h','e','m','o','c','e','n','t','r','o','_','_','_','_','_', 10},
                                             {'m','a','t','r','i','m','o','n','i','o','_','_','_','_','_', 10},
                                             {'d','e','s','o','r','d','e','n','a','d','o','_','_','_','_', 11},
                                             {'e','n','l','o','u','q','u','e','c','e','r','_','_','_','_', 11},
                                             {'g','l','o','b','a','l','i','z','a','d','o','_','_','_','_', 11},
                                             {'q','u','a','d','r','i','c','i','c','l','o','_','_','_','_', 11},
                                             {'s','a','n','t','i','f','i','c','a','d','o','_','_','_','_', 11},
                                             {'a','c','h','o','c','o','l','a','t','a','d','o','_','_','_', 12},
                                             {'c','o','n','t','i','n','u','i','d','a','d','e','_','_','_', 12},
                                             {'c','r','i','s','t','i','a','n','i','s','m','o','_','_','_', 12},
                                             {'d','e','s','o','r','g','a','n','i','z','a','r','_','_','_', 12},
                                             {'p','r','e','f','e','r','e','n','c','i','a','l','_','_','_', 12},
                                             {'a','p','o','s','e','n','t','a','d','o','r','i','a','_','_', 13},
                                             {'b','i','b','l','i','o','t','e','c','a','r','i','o','_','_', 13},
                                             {'c','o','n','s','t','r','a','n','g','e','d','o','r','_','_', 13},
                                             {'p','e','r','p','e','n','d','i','c','u','l','a','r','_','_', 13},
                                             {'t','r','i','g','o','n','o','m','e','t','r','i','a','_','_', 13},
                                             {'a','n','i','v','e','r','s','a','r','i','a','n','t','e','_', 14},
                                             {'d','i','s','t','a','n','c','i','a','m','e','n','t','o','_', 14},
                                             {'d','o','c','u','m','e','n','t','a','r','i','s','t','a','_', 14},
                                             {'f','i','s','i','c','u','l','t','u','r','i','s','t','a','_', 14},
                                             {'p','r','e','s','s','e','n','t','i','m','e','n','t','o','_', 14},
                                             {'r','e','p','r','e','s','e','n','t','a','t','i','v','o','_', 14},
                                             {'c','o','m','p','e','t','i','t','i','v','i','d','a','d','e', 15},
                                             {'d','e','s','a','p','a','r','e','c','i','m','e','n','t','o', 15},
                                             {'d','e','s','c','l','a','s','s','i','f','i','c','a','d','o', 15},
                                             {'i','n','c','e','n','s','i','b','i','l','i','d','a','d','e', 15},
                                             {'o','b','r','i','g','a','t','o','r','i','e','d','a','d','e', 15}};

// Começo do jogo
int main(){
    inicio:
    
    // Declarações por partida
    int tamanhoPalavra, contErros = 0, vidas = 6;
    char palavra[quantLetras], resposta[quantLetras], tentativa, erros[6];
    for (int c = 0; c < 6; c++) erros[c] = ' ';

    // Sorteio para escolher uma das palavras aleatóriamente
	srand((unsigned) time(NULL));
    int n = rand() % quantPalavras;

    // Coletar tamanho e configurar resposta
    tamanhoPalavra = dicionario[n][quantLetras-1];
    for (int i = 0; i < tamanhoPalavra; i++){
        palavra[i] = dicionario[n][i];
        resposta[i] = '_';
    }
    
    // Loop da partida
    while (true){
        // Limpar terminal e inorimir título
        system("clear");
        cout << " Jogo da Forca\n";
        
        // Imprimir tamanho da Palavra
        cout << "\n A palavra possui " << tamanhoPalavra << " letras.\n";

        // Imprimir tentativas falhas
        if (contErros > 0){
            cout << " Letras erradas: ";
            for (int d = 0; d < contErros; d++) 
                cout << erros[d] << " ";
            cout << "\n";
        }

        // Imprimir contador de vidas
        // Baseado no jogo original de forca, onde cada erro se desenhava uma parte do corpo
        // (cabeça, corpo, braços direito e esquerdo e pernas direita e esquerda) a cada erro
        // até completar e perder o jogo, totalizando 6 vidas.
        cout << " Vidas: " << vidas << "\n";
    
        // Imprimir estado atual da resposta
        int conferencia = 0;
        cout << "\n      ";
        for (int b = 0; b < tamanhoPalavra; b++){
            cout << resposta[b];
            if (resposta[b] != '_')
                conferencia++;
        }
        cout << "\n";

        // Verificação de acerto ou morte
        if (conferencia >= tamanhoPalavra or vidas == 0)
            break;

        // Entrada de letra pelo jogador
        cout << "\n Digite uma letra ['*' para desistir]: ";
        cin >> tentativa;
        if (tentativa == '*') break;

        // Verifica acerto e escreve no array resposta
        bool acerto = false;
        for (int a = 0; a < tamanhoPalavra; a++){
            if (tentativa == palavra[a]){
                resposta[a] = tentativa;
                acerto = true;
            }
        }
        
        // Contador de vidas e erros
        if (!acerto){
            vidas--;
            erros[contErros] = tentativa;
            contErros++;
        }
    }
    // Fim do loop

    // Mensagens de fim de partida por vitória ou derrota
    if (tentativa != '*' and vidas != 0)
        cout << "\n Parabens, você venceu o jogo!";
    else{
        cout << " Que pena. A palavra era: ";
        for (int i = 0; i < tamanhoPalavra; i++)
           cout << palavra[i];
    }

    // Mensagem de reinicio ou despedida
    cout << "\n\n Jogar novamente? [s/n] ";
    char jogo;
    cin >> jogo;
    if (jogo == 's'){
        goto inicio;
    }
    system("clear");
    cout << "\n Até mais :)\n\n";

    return 0;
}