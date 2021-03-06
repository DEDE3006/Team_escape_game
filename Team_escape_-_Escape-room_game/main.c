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
  printf("Se quiser jogar, digite 1.\nCaso contr??rio, digite qualquer coisa.\n");
  scanf("%d", &start);
  if(start == 1){
    int atual=0,x,i,aux=26,proximo,chave_1=0,chave_2=0,chave_1_aux=1,chave_2_aux=1,chave_3_aux=1,chave_aux_4=1,chave_aux=1,chave_3=0,chave_4=0;
    setlocale(LC_ALL,"Portuguese");
    printf("-------------------------------\n");
    grafo *g = inicializarGrafo(aux);

    printf("Voc?? acorda, um incomodo de uma luz forte em seus olhos, ap??s se levantar e seus olhos se ajustarem ao brilho,\nvoc?? percebe que est?? em um lugar que n??o reconhece.");
    printf("Voc?? se encontra em um escrit??rio que nunca viu em sua vida,\n uma sensa????o de desconforto sobre lentamente pelas suas costas enquanto pensamentos come??am aparecer em sua cabe??a:\n'Onde estou?'' 'Como cheguei aqui?'' 'O que est?? acontecendo?'' ");
    printf("P??nico toma seu corpo,\n e mesmo sem ter nenhum sinal aparente de perigo,\n voc?? tem certeza que precisa sair de onde est?? o mais r??pido poss??vel.");
    printf("\n-------------------------------");

    strcpy(g->vertices[0].nome, "Escrit??rio");
    strcpy(g->vertices[0].descricao, "Olhando melhor a sua volta, consegue ver que ?? um simples escrit??rio com uma mesa de escrit??rio,\n um sof?? apoiado contra a parede e um quadro pendurado na parede acima do sof??,\n um rel??gio de p??ndulo, uma lixeira ao lado da mesa, estande de livros e uma porta.");
    strcpy(g->vertices[1].nome, "Mesa");
    strcpy(g->vertices[1].descricao, "Uma mesa de madeira sem muitos entalhes, tem v??rias marcas de desgastes e de objetos afiados\n que retiraram partes da madeira, n??o parece que o tempo e quem a utilizava n??o foram muito bons. \nNela voc?? consegue ver uma caneca, um porta-retrato,\n alguns papeis e 3 gavetas no canto direito. ");
    addAresta(g, 0, 1);
    addAresta(g, 1, 0);
    strcpy(g->vertices[8].nome, "Gavetas");
    strcpy(g->vertices[8].descricao, "Tr??s gavetas com detalhes ornamentais, a de cima e de baixo est??o em bom estado, \n mas a do meio parece que foi for??ada, talvez voc?? consiga for????-la a abrir.");
    addAresta(g,1,8);
    addAresta(g,8,1);
    strcpy(g->vertices[9].nome, "De cima");
    strcpy(g->vertices[9].descricao, "Voc?? abre, mas n??o h?? nada dentro.");
    addAresta(g,8,9);
    addAresta(g,9,8);
    strcpy(g->vertices[10].nome, "Do meio");
    strcpy(g->vertices[10].descricao, "Com um pouco de for??a voc?? consegue abrir a gaveta e \n encontra o que parece um amuleto em forma de estrela, voc?? pega o amuleto e guarda ");
    addAresta(g,8,10);
    addAresta(g,10,8);
    imbutir_item(g,10);
    strcpy(g->vertices[10].chave->nome, "Amuleto em forma de estrela");
    strcpy(g->vertices[10].chave->descricao, "Um amuleto que possui a forma de uma estrela\n e tamb??m uma pedra no meio, parece um olho, quanto mais voc?? olha para o amuleto\n, mais desconfort??vel voc?? se sente");

    strcpy(g->vertices[11].nome, "De baixo");
    strcpy(g->vertices[11].descricao, "Trancada");
    addAresta(g,8,11);
    addAresta(g,11,8);
    imbutir_item(g,11);
    strcpy(g->vertices[11].chave->nome, "Chave Grande");
    strcpy(g->vertices[11].chave->descricao, "Uma chave com a ponta deformada,\n parece que a ponta tem o mesmo formato que a porta neste escrit??rio,\n h?? tamb??m a gravura de um cadeado na chave");

    strcpy(g->vertices[12].nome, "Pap??is");
    strcpy(g->vertices[12].descricao, "Apenas documentos de negocia????es, ?? alguns rabiscos em algumas das folhas,\n mas todos eles s??o de palavras bem fortes e de gestos obscenos,\n algu??m realmente parece que ficou furioso com essas negocia????es.\n Mas ?? nada que v?? ajudar sua situa????o atual.");
    addAresta(g,1,12);
    addAresta(g,12,1);
    strcpy(g->vertices[13].nome, "Porta-Retratos");
    strcpy(g->vertices[13].descricao, "Um porta-retrato sem um retrato, uma pena que n??o ?? a porta para sua liberdade. \n N??o ?? ??til para sua situa????o");
    addAresta(g,1,13);
    addAresta(g,13,1);
    strcpy(g->vertices[14].nome, "Caneca");
    strcpy(g->vertices[14].descricao, "Uma caneca a decora????o de 'Melhor Chefe do Mundo', \nde quem seja essa caneca era o chef??o desse lugar. N??o ?? ??til para sua situa????o,\n mas agora voc?? quer uma caneca de chocolate quente.");
    addAresta(g,1,14);
    addAresta(g,14,1);
    strcpy(g->vertices[2].nome, "Sof??");
    strcpy(g->vertices[2].descricao, "Um sof?? beje, tem algumas manchas nos apoios de bra??o, parece vinho,\n ele aparenta ser j?? bem antigo, com varias marcas de desagaste\n e furos por todas as partes, voc?? d?? uma olhada em volta, mas nenhum dos furos\n parece que guardaria algo dentro, eram apenas superficiais.");
    addAresta(g, 0, 2);
    addAresta(g, 2, 0);
    strcpy(g->vertices[6].nome, "Embaixo do Sof??");
    strcpy(g->vertices[6].descricao, "Est?? um pouco escuro, mas nada que impe??a de identificar o que se encontra embaixo do sof??,\n restos de comida, h?? uma pequena chave debaixo do sof?? preso em uma teia de aranha,\n voc?? estende o bra??o para pegar a chave,\n rezando para que a aranha n??o esteja por perto. \nAssim que sentiu o metal em seus dedos, pegou a chave e retirou sue bra??o rapidamente,\n esfregando a chave no sof?? para retirar o resto da teia e guarda em seu bolso.");
    addAresta(g,2,6);
    addAresta(g,6,2);
    imbutir_item(g,6);
    strcpy(g->vertices[6].chave->nome, "Chave Pequena");
    strcpy(g->vertices[6].chave->descricao, "Uma chave pequena com uma gravura de uma mesa, talvez seja uma dica");


    strcpy(g->vertices[7].nome, "Almofadas");
    strcpy(g->vertices[7].descricao, "O forro das almofadas j?? est?? um pouco desgastado e descolorido.");
    addAresta(g,2,7);
    addAresta(g,7,2);
    strcpy(g->vertices[3].nome, "Lixeira");
    strcpy(g->vertices[3].descricao, "Est?? vazia, comparado ao resto do escrit??rio,\n a lixeira est?? estranhamente limpa e bem cuidada, \n aparentemente as prioridades de quem ?? esse escrit??rio s??o bem claras.\nN??o ?? ??til para sua situa????o, e voc?? est?? julgando \n silenciosamente o dono desse escrit??rio.");
    addAresta(g, 0, 3);
    addAresta(g, 3, 0);
    strcpy(g->vertices[4].nome, "Rel??gio");
    strcpy(g->vertices[4].descricao, "Um rel??gio de p??ndulo, n??o parece funcional j?? que seu p??ndulo est?? est??tico,\n e os ponteiros parecem quebrados.N??o ?? ??til para sua situa????o.");
    addAresta(g, 0, 4);
    addAresta(g, 4, 0);
    strcpy(g->vertices[5].nome, "Quadro Torto");
    strcpy(g->vertices[5].descricao, "Um quadro de rel??gios derretendo, voc?? nunca foi um apreciador de artes,\n e agora sente que est?? perdendo seu tempo. O quadro parece um pouco torto.\nSeu toque o impede de n??o endireitar o quadro, \ne assim que o endireita,\n escuta o barulho de algo se movendo na estande de livros.");
    addAresta(g, 0, 5);
    addAresta(g, 5, 0);
    strcpy(g->vertices[15].nome, "Porta");
    strcpy(g->vertices[15].descricao, "Uma porta de ferro bem robusta, voc?? n??o tem a menor chance de for????-la a abrir\n. Ao lado da porta, 3 coisas chamam seu interesse\n, um buraco, um cadeado prendendo correntes que envolvem a porta\n, e um painel eletr???nico com um teclado num???rico");
    addAresta(g, 0, 15);
    addAresta(g, 15, 0);
    strcpy(g->vertices[16].nome, "Buraco");
    strcpy(g->vertices[16].descricao, "O buraco tem o formato de estrela, como se essa parte foi retirada, \no que ser?? que pode acontecer se conseguir encontrar e colocar algo que encaixe nesse buraco?");
    addAresta(g, 15, 16);
    addAresta(g, 16, 15);
    strcpy(g->vertices[17].nome, "Cadeado");
    strcpy(g->vertices[17].descricao, "Um cadeado bem robusto, n??o seria poss??vel arrombar na sua situa????o atual\n, melhor procurar outra alternativa.");
    addAresta(g, 15, 17);
    addAresta(g, 17, 15);
    strcpy(g->vertices[18].nome, "Desenho");
    strcpy(g->vertices[18].descricao, "Do lado da porta h?? um desenho de uma moldura com uma luz vermelha saindo\n do seu centro, talvez seja algo importante.");
    addAresta(g, 15, 18);
    addAresta(g, 18, 15);
    strcpy(g->vertices[20].nome, "Abrir Porta");
    strcpy(g->vertices[20].descricao, "N??o importa o quanto voc?? tente, a porta n??o se desloca um cent??metro.");
    addAresta(g, 15, 20);
    addAresta(g, 20, 15);

    fflush(stdin);

    //printf("\n%s", g->vertices[6].chave->nome);
    //printf("\n%s", g->vertices[6].chave->descricao);

    while(proximo!=100){

      escrever(g,atual);
      listarArestas(g,atual);

      if(atual == 6 && chave_aux_4 ==1){
          strcpy(g->vertices[6].descricao, "N??o h?? nada mais de interesse aqui.");
          strcpy(g->vertices[11].descricao, "Voc?? destranca a gaveta e encontra uma chave maior,\n parece ser da porta deste lugar.");
          chave_2=1;
          chave_aux_4=0;
      }

      if(atual == 11 && chave_2 == 1 && chave_2_aux==1){
          strcpy(g->vertices[11].descricao, "Nada mais de interessante aqui.");
          chave_2_aux=0;
          chave_4 = 1;
          strcpy(g->vertices[17].descricao, "Assim que voc?? destrava o cadeado, as correntes s??o retra??das\n para buracos na parede, menos um obst??culo para sua liberdade");
      }


      if(atual==10 && chave_3_aux == 1){
          strcpy(g->vertices[10].descricao, "Nada mais de interessante aqui.");
          chave_3=1;
          chave_3_aux=0;
          strcpy(g->vertices[16].descricao, "O amuleto encaixa perfeitamente e voc?? escuta um estalo vindo da porta\n, um progresso no seu caminho para sair desse lugar");
      }

      if(atual == 5 && chave_1_aux == 1){
          strcpy(g->vertices[5].nome, "Quadro Endireitado");
          strcpy(g->vertices[5].descricao, "Voc?? ainda n??o entende arte.");
          chave_1=1;
          chave_1_aux=0;
          strcpy(g->vertices[18].descricao, "Do lado da porta h?? um desenho de uma moldura com uma luz verde saindo\n do seu centro, voc?? sente que est?? a menos um passo da liberdade");
      }


      printf("\nPara onde ir?? agora:\n");
      printf("Aperte 100, para sair\n");
      printf("Aperte 50, para ver Invent??rio\n");
      printf("Op????o: ");
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
          strcpy(g->vertices[20].descricao, "Voc?? abriu a Porta");
          chave_aux=0;
        }

        if(atual == 20 && chave_aux == 0){
          system("cls");
          escrever(g,atual);
          printf("\nSem pensar duas vezes voc?? abra a porta e corre para fora do escrit??rio\n, seu cora????o palpitando de felicidade e alivio.\nMas a comemora????o seria curta, ap??s olhar ao seu redor, \nvoc?? percebe que estava no mesmo escrit??rio, tudo no mesmo lugar e do mesmo modo que tinha encontrado antes\n, mas tudo parecia um pouco mais distorcido.\nVoc?? cai de joelhos, confuso, irritado, triste, sem entender mais nada que est?? acontecendo\n a sua volta, a ??nica coisa que deseja ?? que a escurid??o\n lhe consuma de forma r??pida e indolor\n");
          printf("\n\n-------------Final : Preso no Loop--------------------\n\n");
          return 0;
        }

      }else{
        if(proximo != 100 && proximo != 50){
          printf("\nOp????o Inv??lida\nPressione Enter Para Continuar");
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
