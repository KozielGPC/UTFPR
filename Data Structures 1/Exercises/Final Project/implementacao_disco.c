#include "disco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**************************************
 * DADOS
 **************************************/

/**************************************
 *
 * AUXILIARES
 *
 * *************************/

NoArquivo *noarquivo_cria(char *nome, long int tam)
{
    NoArquivo *novo = (NoArquivo *)malloc(sizeof(NoArquivo));
    novo->setores = NULL;
    novo->ant = NULL;
    novo->prox = NULL;
    strcpy(novo->nome, nome);
    novo->tam = tam;
    return novo;
}

NoSetor *nosetor_cria(long int inicio, long int fim)
{
    NoSetor *novo = (NoSetor *)malloc(sizeof(NoSetor));
    novo->inicio = inicio;
    novo->fim = fim;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

long int getTamanhoArquivo(FILE *arq)
{
    rewind(arq);
    fseek(arq, 0, SEEK_END);
    int tamanho = ftell(arq);
    rewind(arq);
    return tamanho;
}

bool encontraArquivo(Disco *disco, char *nomeArquivo, NoArquivo *destino)
{
    NoArquivo *aux = disco->arquivos->prox;
    while (aux != disco->arquivos)
    {

        printf("nome arquivo : %s \n", nomeArquivo);
        printf("nome aux : %s \n", aux->nome);
        // if (strcmp(aux->nome, nomeArquivo) == 0)
        // {
        //     printf("Entrou no if");
        //     destino = aux;
        //     return true;
        // }
        printf("nao Entrou no if\n");
        aux = aux->prox;
    }

    return false;
}

long int getTamSetor(NoSetor *no)
{
    return no->fim - no->inicio + 1;
}

bool duplicarArquivo(char *nomeArquivoEntrada, char *nomeArquivoSaida)
{

    FILE *arqEntrada;
    FILE *arqSaida;

    // abre o arquivo de entrada no modo leitura
    arqEntrada = fopen(nomeArquivoEntrada, "rb");
    if (arqEntrada == NULL)
    {
        perror("Erro na abertura do arquivo de entrada");
        return false;
    }

    // Captura o tamanho do arquivo
    int tamanhoArquivo = getTamanhoArquivo(arqEntrada);

    // Aloca um espaço na memória para copiar o conteúdo do arquivo
    void *buffer = malloc(tamanhoArquivo);
    if (buffer == NULL)
    {
        perror("Memoria insuficiente");
        return false;
    }

    // copia o conteúdo do arquivo para a memória
    fread(buffer, tamanhoArquivo, 1, arqEntrada);

    // copia o conteúdo da memória para o arquivo
    arqSaida = fopen(nomeArquivoSaida, "wb");
    if (arqSaida == NULL)
    {
        perror("Erro na abertura do arquivo de SAIDA");
        return false;
    }
    fwrite(buffer, tamanhoArquivo, 1, arqSaida);

    // fecha os arquivos
    fclose(arqEntrada);
    fclose(arqSaida);
}

void imprimeSetoresLivres(Disco *d)
{
    printf("LIVRES: ");
    NoSetor *aux = d->livres->prox;
    while (aux != d->livres)
    {
        printf("[%ld,%ld] ", aux->inicio, aux->fim);
        aux = aux->prox;
    }
    printf("\n");
}

void disco_lista(Disco *d)
{

    printf("-----------------\n");
    imprimeSetoresLivres(d);
    printf("-----------------\n");
    printf("ARQUIVOS: \n");

    NoArquivo *arquivo = d->arquivos->prox;
    while (arquivo != d->arquivos)
    {
        printf("%-30s (%9ld) ", arquivo->nome, arquivo->tam);

        NoSetor *segmento = arquivo->setores->prox;
        while (segmento != arquivo->setores)
        {
            printf("[%ld,%ld] ", segmento->inicio, segmento->fim);
            segmento = segmento->prox;
        }
        printf("\n");
        arquivo = arquivo->prox;
    }
    printf("\n");
}

void limpaNoSetor(NoSetor *no)
{
    NoSetor *anterior = no->ant;
    NoSetor *proximo = no->prox;
    anterior->prox = proximo;
    proximo->ant = anterior;
}

void insereEsquerda(NoSetor *referencia, NoSetor *inserido)
{
    inserido->prox = referencia;
    inserido->ant = referencia->ant;
    referencia->ant->prox = inserido;
    referencia->ant = inserido;
}

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/

Disco *disco_cria(char *nome, long int tamanho)
{
    Disco *disco = (Disco *)malloc(sizeof(Disco));
    strcpy(disco->nome, nome);
    disco->tamDisco = tamanho;
    disco->qtdeArquivos = 0;
    disco->espacoLivre = tamanho;

    NoArquivo *sentinela_arquivos = noarquivo_cria("sentinela_arquivos", 0);
    sentinela_arquivos->ant = sentinela_arquivos;
    sentinela_arquivos->prox = sentinela_arquivos;
    disco->arquivos = sentinela_arquivos;

    NoSetor *livre_inicial = nosetor_cria(0, tamanho - 1);

    NoSetor *sentinela_livres = nosetor_cria(0, 0);
    sentinela_livres->ant = livre_inicial;
    sentinela_livres->prox = livre_inicial;

    livre_inicial->prox = sentinela_livres;
    livre_inicial->ant = sentinela_livres;

    disco->livres = sentinela_livres;

    void *disco_array = malloc(tamanho);
    disco->disco = disco_array;

    return disco;
}

bool disco_grava(Disco *d, char *arquivo)
{
    ///////////////////////// Abrir o arquivo físico (fopen)
    FILE *arq;

    // abre o arquivo de entrada no modo leitura
    arq = fopen(arquivo, "rb");
    if (arq == NULL)
    {
        perror("Erro na abertura do arquivo");
        return false;
    }

    // Captura o tamanho do arquivo
    long int tamanhoArquivo = getTamanhoArquivo(arq);

    if (tamanhoArquivo > d->espacoLivre)
        return false;

    /////////////////////////////////////// opcional) Carregar o conteúdo do arquivo físico em memória (fread). Pode se usar um buffer para armazenar o conteúdo do arquivo antes de transferi-lo para o disco.
    // Aloca um espaço na memória para copiar o conteúdo do arquivo
    void *buffer = malloc(tamanhoArquivo);
    if (buffer == NULL)
    {
        perror("Memoria insuficiente");
        return false;
    }

    // copia o conteúdo do arquivo para a memória
    fread(buffer, tamanhoArquivo, 1, arq);

    //////////////////////////////// Criar e inserir o nó na lista de arquivos

    NoArquivo *noarquivo = noarquivo_cria(arquivo, tamanhoArquivo);

    NoSetor *sentinela_arquivo_setor = nosetor_cria(0, 0);

    noarquivo->setores = sentinela_arquivo_setor;
    noarquivo->setores->ant = sentinela_arquivo_setor;
    noarquivo->setores->prox = sentinela_arquivo_setor;

    NoArquivo *sentinela = d->arquivos;

    noarquivo->prox = sentinela;
    noarquivo->ant = sentinela->ant;

    sentinela->ant->prox = noarquivo;
    sentinela->ant = noarquivo;

    ////////////////////////////////////// Obter os segmentos livres e armazenar o conteúdo do arquivo nas posições indicadas pelo segmento

    NoSetor *aux_livres = d->livres;
    aux_livres = aux_livres->prox;
    long int restante = tamanhoArquivo;
    long int totalCopiado = 0;
    while (restante > 0)
    {
        printf("Inicio: %ld Fim: %ld \n", aux_livres->inicio, aux_livres->fim);
        long int tamSetor = getTamSetor(aux_livres);
        NoSetor *setor_ocupado;

        if (restante < tamSetor)
        {
            printf("Entrou no if \n");
            
            printf("Total copiado: %ld \n", totalCopiado);
            printf("tamanho setor: %ld \n", tamSetor);
            printf("tamanho arquivo: %ld \n", tamanhoArquivo);
            setor_ocupado = nosetor_cria(aux_livres->inicio, aux_livres->inicio + restante - 1);
            printf("ocupado >>>> Inicio: %ld Fim: %ld \n", setor_ocupado->inicio, setor_ocupado->fim);
            aux_livres->inicio = aux_livres->inicio + restante;
            insereEsquerda(sentinela_arquivo_setor, setor_ocupado);
            memcpy(d->disco + setor_ocupado->inicio, buffer, tamanhoArquivo);
        }
        else
        {
            printf("Entrou no else \n");
            setor_ocupado = aux_livres;
            limpaNoSetor(setor_ocupado);
            insereEsquerda(sentinela_arquivo_setor, setor_ocupado);
            memcpy(d->disco + setor_ocupado->inicio, buffer, tamSetor);
            // aux_livres->ant = sentinela_arquivo_setor->ant;
            // aux_livres->prox = sentinela_arquivo_setor;
            // sentinela_arquivo_setor->ant->prox = aux_livres;
            // sentinela_arquivo_setor->ant = aux_livres;
        }

        // memcpy(d->disco + setor_ocupado->inicio, buffer + totalCopiado, tamSetor);

        totalCopiado += tamSetor;

        // setor_ocupado->ant = sentinela_arquivo_setor->ant;
        // setor_ocupado->prox = sentinela_arquivo_setor;
        // sentinela_arquivo_setor->ant->prox = setor_ocupado;
        // sentinela_arquivo_setor->ant = setor_ocupado;

        // if (restante - tamSetor < 0)
        // {
        //     restante = 0;
        // }
        // else
        // {
        //     restante -= tamSetor;
        // }

        restante -= tamSetor;
        // printf("%ld \n", restante);
        aux_livres = aux_livres->prox;
    }

    /////////////////////////////// Incrementar o número de arquivos (qtdeArquivos) e diminuir o espaço livre
    d->qtdeArquivos += 1;
    d->espacoLivre -= tamanhoArquivo;

    fclose(arq);

    return true;
}
bool disco_remove(Disco *d, char *nome)
{
    NoArquivo *noArquivo;
    bool result = encontraArquivo(d, nome, noArquivo);
    if (!result)
    {
        printf("Deu erro");
    }
    if (!result)
        return false;

    NoSetor *sentinela_livres = d->livres;

    NoSetor *aux = noArquivo->setores->prox;
    NoSetor *temp;
    while (aux != noArquivo->setores)
    {
        limpaNoSetor(aux);
        aux->ant = sentinela_livres->ant;
        sentinela_livres->ant->prox = aux;
        aux->prox = sentinela_livres;
        sentinela_livres->ant = aux;
    }

    d->qtdeArquivos -= 1;
    d->espacoLivre += noArquivo->tam;

    return true;
}
bool disco_recupera(Disco *d, char *nome, char *arquivoDestino)
{
}
