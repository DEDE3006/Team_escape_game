#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct {
	char nome[50];
  char descricao[200];
}item;

typedef struct Aresta {
  int vertice;
  struct Aresta *proxima_aresta;
} aresta;

typedef struct {
  char nome[50];
  char descricao[500];
  aresta *proxima_aresta;
  item *chave;
} vertice;

typedef struct Grafo {
  int numero_vertices;
  vertice *vertices; // vetor de vertices [0..n-1]
} grafo;

grafo *inicializarGrafo(int numero_vertices) {
	int i =0;
  grafo *g = malloc(sizeof(grafo));
  g->numero_vertices = numero_vertices;
  g->vertices = malloc(numero_vertices *sizeof(vertice));
  if(g != NULL) {
    // para cada vertice, inicializa as adjacencias (arestas) com null
    for(i = 0; i < numero_vertices; i++) {
      g->vertices[i].proxima_aresta = NULL;
      g->vertices[i].chave = NULL;
    }
  }
  return g;
}
// aresta (v1 -> v2)
void addAresta(grafo *g, int v1, int v2) {
  if(v1 >= 0 && v1 < g->numero_vertices && v2 >= 0 && v2 < g->numero_vertices) {
    aresta *nova_aresta = malloc(sizeof(aresta));
    nova_aresta->vertice = v2;
    nova_aresta->proxima_aresta = NULL;
    if(nova_aresta != NULL) {
      if(g->vertices[v1].proxima_aresta == NULL) {
        g->vertices[v1].proxima_aresta = nova_aresta;
        }

        else {
          aresta *a = g->vertices[v1].proxima_aresta;
          while(a->proxima_aresta != NULL) {
            a = a->proxima_aresta;
          }
          a->proxima_aresta = nova_aresta;
        }
    }
  }
}

void imbutir_item (grafo *g, int v){
	item *item_imbutido = malloc(sizeof(item));
	g->vertices[v].chave = item_imbutido;
}

void escrever(grafo *g, int k){
	printf("\n");
  printf ("%s", g->vertices[k].nome);
  printf("\n");
  printf ("%s", g->vertices[k].descricao);
  printf("\n");
  printf("\n");
}

void escrever_so_nome(grafo *g, int k){
	int i;

  printf (" %s", g->vertices[k].nome);
  printf("\n");
}

void listarArestas(grafo *g, int v) {
  if(v >= 0 && v < g->numero_vertices) {

    aresta *a = g->vertices[v].proxima_aresta;

    while(a != NULL) {
      printf("(%d)->", a->vertice);

      escrever_so_nome(g, a->vertice);

	  printf("\n");
      a = a->proxima_aresta;
    }
  }
}

int checar_arestas(grafo *g, int v_atual, int v_checar) {
  if(v_atual >= 0 && v_atual < g->numero_vertices) {

    aresta *a = g->vertices[v_atual].proxima_aresta;

    while(a != NULL) {
    	if( a->vertice==v_checar ){

		return 1;

	  }
      a = a->proxima_aresta;
    }
  }

  return 0;
}

int main(void) {

  int start = 0;
  printf("Se quiser jogar, digite 1.\nCaso contrário, digite qualquer coisa.\n");
  scanf("%d", &start);
  if(start == 1){
    int atual=0,x,i,aux=26,proximo,chave_1=0,chave_2=0,chave_1_aux=1,chave_2_aux=1,chave_3_aux=1,chave_aux_4=1,chave_aux=1,chave_3=0,chave_4=0;
    setlocale(LC_ALL,"Portuguese");
    printf("-------------------------------\n");
    grafo *g = inicializarGrafo(aux);

    printf("Você acorda, um incomodo de uma luz forte em seus olhos, após se levantar e seus olhos se ajustarem ao brilho,\nvocê percebe que esté em um lugar que não reconhece.");
    printf("Você se encontra em um escritório que nunca viu em sua vida,\n uma sensação de desconforto sobre lentamente pelas suas costas enquanto pensamentos começam aparecer em sua cabeça:\n'Onde estou?'' 'Como cheguei aqui?'' 'O que esté acontecendo?'' ");
    printf("Pânico toma seu corpo,\n e mesmo sem ter nenhum sinal aparente de perigo,\n você tem certeza que precisa sair de onde esté o mais rápido possível.");
    printf("\n-------------------------------");

    strcpy(g->vertices[0].nome, "Escritório");
    strcpy(g->vertices[0].descricao, "Olhando melhor a sua volta, consegue ver que é um simples escritório com uma mesa de escritório,\n um sofá apoiado contra a parede e um quadro pendurado na parede acima do sofá,\n um relógio de pêndulo, uma lixeira ao lado da mesa, estande de livros e uma porta.");
    strcpy(g->vertices[1].nome, "Mesa");
    strcpy(g->vertices[1].descricao, "Uma mesa de madeira sem muitos entalhes, tem várias marcas de desgastes e de objetos afiados\n que retiraram partes da madeira, não parece que o tempo e quem a utilizava não foram muito bons. \nNela você consegue ver uma caneca, um porta-retrato,\n alguns papeis e 3 gavetas no canto direito. ");
    addAresta(g, 0, 1);
    addAresta(g, 1, 0);
    strcpy(g->vertices[8].nome, "Gavetas");
    strcpy(g->vertices[8].descricao, "Três gavetas com detalhes ornamentais, a de cima e de baixo estéo em bom estado, \n mas a do meio parece que foi forçada, talvez você consiga forçá-la a abrir.");
    addAresta(g,1,8);
    addAresta(g,8,1);
    strcpy(g->vertices[9].nome, "De cima");
    strcpy(g->vertices[9].descricao, "Você abre, mas não há nada dentro.");
    addAresta(g,8,9);
    addAresta(g,9,8);
    strcpy(g->vertices[10].nome, "Do meio");
    strcpy(g->vertices[10].descricao, "Com um pouco de força você consegue abrir a gaveta e \n encontra o que parece um amuleto em forma de estrela, você pega o amuleto e guarda ");
    addAresta(g,8,10);
    addAresta(g,10,8);
    imbutir_item(g,10);
    strcpy(g->vertices[10].chave->nome, "Amuleto em forma de estrela");
    strcpy(g->vertices[10].chave->descricao, "Um amuleto que possui a forma de uma estrela\n e também uma pedra no meio, parece um olho, quanto mais você olha para o amuleto\n, mais desconfortável você se sente");

    strcpy(g->vertices[11].nome, "De baixo");
    strcpy(g->vertices[11].descricao, "Trancada");
    addAresta(g,8,11);
    addAresta(g,11,8);
    imbutir_item(g,11);
    strcpy(g->vertices[11].chave->nome, "Chave Grande");
    strcpy(g->vertices[11].chave->descricao, "Uma chave com a ponta deformada,\n parece que a ponta tem o mesmo formato que a porta neste escritório,\n há também a gravura de um cadeado na chave");

    strcpy(g->vertices[12].nome, "Papéis");
    strcpy(g->vertices[12].descricao, "Apenas documentos de negociações, é alguns rabiscos em algumas das folhas,\n mas todos eles são de palavras bem fortes e de gestos obscenos,\n alguém realmente parece que ficou furioso com essas negociações.\n Mas é nada que vá ajudar sua situação atual.");
    addAresta(g,1,12);
    addAresta(g,12,1);
    strcpy(g->vertices[13].nome, "Porta-Retratos");
    strcpy(g->vertices[13].descricao, "Um porta-retrato sem um retrato, uma pena que não é a porta para sua liberdade. \n Não é útil para sua situação");
    addAresta(g,1,13);
    addAresta(g,13,1);
    strcpy(g->vertices[14].nome, "Caneca");
    strcpy(g->vertices[14].descricao, "Uma caneca a decoração de 'Melhor Chefe do Mundo', \nde quem seja essa caneca era o chefão desse lugar. Não é útil para sua situação,\n mas agora você quer uma caneca de chocolate quente.");
    addAresta(g,1,14);
    addAresta(g,14,1);
    strcpy(g->vertices[2].nome, "Sofá");
    strcpy(g->vertices[2].descricao, "Um sofá beje, tem algumas manchas nos apoios de braço, parece vinho,\n ele aparenta ser já bem antigo, com varias marcas de desagaste\n e furos por todas as partes, você dá uma olhada em volta, mas nenhum dos furos\n parece que guardaria algo dentro, eram apenas superficiais.");
    addAresta(g, 0, 2);
    addAresta(g, 2, 0);
    strcpy(g->vertices[6].nome, "Embaixo do Sofá");
    strcpy(g->vertices[6].descricao, "Esté um pouco escuro, mas nada que impeça de identificar o que se encontra embaixo do sofá,\n restos de comida, há uma pequena chave debaixo do sofá preso em uma teia de aranha,\n você estende o braço para pegar a chave,\n rezando para que a aranha não esteja por perto. \nAssim que sentiu o metal em seus dedos, pegou a chave e retirou sue braço rapidamente,\n esfregando a chave no sofá para retirar o resto da teia e guarda em seu bolso.");
    addAresta(g,2,6);
    addAresta(g,6,2);
    imbutir_item(g,6);
    strcpy(g->vertices[6].chave->nome, "Chave Pequena");
    strcpy(g->vertices[6].chave->descricao, "Uma chave pequena com uma gravura de uma mesa, talvez seja uma dica");


    strcpy(g->vertices[7].nome, "Almofadas");
    strcpy(g->vertices[7].descricao, "O forro das almofadas já esté um pouco desgastado e descolorido.");
    addAresta(g,2,7);
    addAresta(g,7,2);
    strcpy(g->vertices[3].nome, "Lixeira");
    strcpy(g->vertices[3].descricao, "Esté vazia, comparado ao resto do escritório,\n a lixeira esté estranhamente limpa e bem cuidada, \n aparentemente as prioridades de quem é esse escritório são bem claras.\nNão é útil para sua situação, e você esté julgando \n silenciosamente o dono desse escritório.");
    addAresta(g, 0, 3);
    addAresta(g, 3, 0);
    strcpy(g->vertices[4].nome, "Relógio");
    strcpy(g->vertices[4].descricao, "Um relógio de pêndulo, não parece funcional já que seu pêndulo esté estético,\n e os ponteiros parecem quebrados.Não é útil para sua situação.");
    addAresta(g, 0, 4);
    addAresta(g, 4, 0);
    strcpy(g->vertices[5].nome, "Quadro Torto");
    strcpy(g->vertices[5].descricao, "Um quadro de relógios derretendo, você nunca foi um apreciador de artes,\n e agora sente que esté perdendo seu tempo. O quadro parece um pouco torto.\nSeu toque o impede de não endireitar o quadro, \ne assim que o endireita,\n escuta o barulho de algo se movendo na estande de livros.");
    addAresta(g, 0, 5);
    addAresta(g, 5, 0);
    strcpy(g->vertices[15].nome, "Porta");
    strcpy(g->vertices[15].descricao, "Uma porta de ferro bem robusta, você não tem a menor chance de forçá-la a abrir\n. Ao lado da porta, 3 coisas chamam seu interesse\n, um buraco, um cadeado prendendo correntes que envolvem a porta\n, e um painel eletr�nico com um teclado num�rico");
    addAresta(g, 0, 15);
    addAresta(g, 15, 0);
    strcpy(g->vertices[16].nome, "Buraco");
    strcpy(g->vertices[16].descricao, "O buraco tem o formato de estrela, como se essa parte foi retirada, \no que será que pode acontecer se conseguir encontrar e colocar algo que encaixe nesse buraco?");
    addAresta(g, 15, 16);
    addAresta(g, 16, 15);
    strcpy(g->vertices[17].nome, "Cadeado");
    strcpy(g->vertices[17].descricao, "Um cadeado bem robusto, não seria possível arrombar na sua situação atual\n, melhor procurar outra alternativa.");
    addAresta(g, 15, 17);
    addAresta(g, 17, 15);
    strcpy(g->vertices[18].nome, "Desenho");
    strcpy(g->vertices[18].descricao, "Do lado da porta há um desenho de uma moldura com uma luz vermelha saindo\n do seu centro, talvez seja algo importante.");
    addAresta(g, 15, 18);
    addAresta(g, 18, 15);
    strcpy(g->vertices[20].nome, "Abrir Porta");
    strcpy(g->vertices[20].descricao, "Não importa o quanto você tente, a porta não se desloca um centímetro.");
    addAresta(g, 15, 20);
    addAresta(g, 20, 15);

    fflush(stdin);

    //printf("\n%s", g->vertices[6].chave->nome);
    //printf("\n%s", g->vertices[6].chave->descricao);

    while(proximo!=100){

      escrever(g,atual);
      listarArestas(g,atual);

      if(atual == 6 && chave_aux_4 ==1){
          strcpy(g->vertices[6].descricao, "Não há nada mais de interesse aqui.");
          strcpy(g->vertices[11].descricao, "Você destranca a gaveta e encontra uma chave maior,\n parece ser da porta deste lugar.");
          chave_2=1;
          chave_aux_4=0;
      }

      if(atual == 11 && chave_2 == 1 && chave_2_aux==1){
          strcpy(g->vertices[11].descricao, "Nada mais de interessante aqui.");
          chave_2_aux=0;
          chave_4 = 1;
          strcpy(g->vertices[17].descricao, "Assim que você destrava o cadeado, as correntes são retraídas\n para buracos na parede, menos um obstáculo para sua liberdade");
      }


      if(atual==10 && chave_3_aux == 1){
          strcpy(g->vertices[10].descricao, "Nada mais de interessante aqui.");
          chave_3=1;
          chave_3_aux=0;
          strcpy(g->vertices[16].descricao, "O amuleto encaixa perfeitamente e você escuta um estalo vindo da porta\n, um progresso no seu caminho para sair desse lugar");
      }

      if(atual == 5 && chave_1_aux == 1){
          strcpy(g->vertices[5].nome, "Quadro Endireitado");
          strcpy(g->vertices[5].descricao, "Você ainda não entende arte.");
          chave_1=1;
          chave_1_aux=0;
          strcpy(g->vertices[18].descricao, "Do lado da porta há um desenho de uma moldura com uma luz verde saindo\n do seu centro, você sente que esté a menos um passo da liberdade");
      }


      printf("\nPara onde irá agora:\n");
      printf("Aperte 100, para sair\n");
      printf("Aperte 50, para ver Inventório\n");
      printf("Opção: ");
      scanf("%d",&proximo);

      fflush(stdin);

      if(proximo == 50){
        system("cls");
        if(chave_2 == 1){
          printf("\n%s",g->vertices[6].chave->nome);
          printf("\n%s",g->vertices[6].chave->descricao);
          printf("\n\n\n");
        }
        if(chave_3 == 1){
          printf("\n%s",g->vertices[10].chave->nome);
          printf("\n%s",g->vertices[10].chave->descricao);
          printf("\n\n\n");
        }
        if(chave_4 == 1){
          printf("\n%s",g->vertices[11].chave->nome);
          printf("\n%s",g->vertices[11].chave->descricao);
          printf("\n\n\n");
        }
        else{
          printf("\nVazio\n");
        }
        printf("\nPressione Enter Para Continuar");
        scanf("%*[^\n]%*c");
      }

      //system("cls");

      if(checar_arestas(g,atual,proximo) && proximo != 100) {

        atual = proximo;

        if(chave_1==1 && chave_2 == 1 && chave_3 == 1 && chave_4 ==1 && chave_aux == 1){
          strcpy(g->vertices[20].descricao, "Você abriu a Porta");
          chave_aux=0;
        }

        if(atual == 20 && chave_aux == 0){
          system("cls");
          escrever(g,atual);
          printf("\nSem pensar duas vezes você abra a porta e corre para fora do escritório\n, seu coração palpitando de felicidade e alivio.\nMas a comemoração seria curta, após olhar ao seu redor, \nvocê percebe que estava no mesmo escritório, tudo no mesmo lugar e do mesmo modo que tinha encontrado antes\n, mas tudo parecia um pouco mais distorcido.\nVocê cai de joelhos, confuso, irritado, triste, sem entender mais nada que esté acontecendo\n a sua volta, a única coisa que deseja é que a escuridão\n lhe consuma de forma rápida e indolor\n");
          printf("\n\n-------------Final : Preso no Loop--------------------\n\n");
          return 0;
        }

      }else{
        if(proximo != 100 && proximo != 50){
          printf("\nOpção Inválida\nPressione Enter Para Continuar");
          scanf("%*[^\n]%*c");
        }
      }

      system("cls");
    }

    return 0;
  }

  else {
    exit;
  }

}
