#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// VARIAVEIS GLOBAIS
int _num_contas = 0;
int _perfil_ativo = 0;

// STRUCTS

typedef struct {

  char nome [20];
  char sobrenome[20];
  char email [30];
  char senha [20];

}Conta_perfil;

// FUNÇOES

void menu_login(Conta_perfil *contas);
void cadastrar(int numero_contas,Conta_perfil *contas);
void menu_perfil(Conta_perfil *contas);
void entrar (Conta_perfil *contas);
void pesquisar(contas);
int navegador_busca();

void linha (){
  int i;
   printf("\n\n");
  for ( i = 0; i < 45; i++)
  printf("*");
}

void linha2 (){
  int i;
  printf("\n");
  for ( i = 0; i < 45; i++)
  printf("=");
}

int navegador_busca(contas){
    char navegador[20];
    int opcao;

    printf("\n Navegador: ");
    gets(navegador);

    if(strcmp(navegador,"register")==0){
        cadastrar(_num_contas,contas);
    }
    else if ( strcmp(navegador,"login")==0){
        entrar(contas);
    }
    else{
        opcao = atoi(navegador);
        return opcao;
    }
}


pesquisar(contas){

   int opcao;

  do {
      system("cls");
      linha();
      printf("\n               O que voce deseja encontrar");
      printf("\n\n\n               1- Musicas");
      printf("\n               2- Bandas");
      printf("\n               3- Playlist");
      printf("\n               4- Voltar para o menu");
      linha2();
      opcao = navegador_busca(contas);


      switch(opcao){

        case 1 :

          printf("\n\n\n Musicas");
          break;

        case 2:

          printf("\n\n\n Bandas");
          break;

        case 3:
          printf("\n\n\n Playlist");
          break;

        case 4:
          menu_perfil(contas);
          break;



        default:
          printf("\n\n\n Digite um opcao valida");

      }
    }while ( opcao != 1 && opcao != 2 &&  opcao != 3);
}

menu_perfil(Conta_perfil *contas){

  int opcao;

  do {
      system("cls");
      linha();
      printf("\n               Ola, %s",contas[_perfil_ativo].nome);
      printf("\n\n               1- Pesquisa");
      printf("\n               2- Ver mais tocadas");
      printf("\n               3- Minha colecao");
      printf("\n               4- Comunidade");
      printf("\n               5- Sugestoes");
      printf("\n               6- Sair");
      linha2();

      opcao = navegador_busca(contas);


      switch(opcao){

        case 1 :

          pesquisar(contas);
          break;

        case 2:

          printf("\n\n\n Mais tocadas");
          break;

        case 3:
          printf("\n\n\n Minha colecao");
          break;

        case 4:
          printf("\n\n\n Comunidade");
          break;

        case 5:
          printf("\n\n\n Sugestoes");
          break;

        case 6:
          menu_login(contas);
          break;

        default:
          printf("\n\n\n Digite um opcao valida");

      }
    }while ( opcao != 1 && opcao != 2 &&  opcao != 3 &&  opcao != 4  &&  opcao != 5 );



}

entrar (Conta_perfil *contas){

  char verificacao_email[30];
  char verificacao_senha[30];
  int i;
  int confirmacao_login = 0;



  do{
    system("cls");
    printf("\n               LOGIN");
    printf("\n\n Email : ");
    gets(verificacao_email);
    printf("\n Senha: ");
    gets(verificacao_senha);

    for (i = 0; i < 4; i++){

      if ( strcmp (contas[i].email,verificacao_email) == 0)
      {

        _perfil_ativo = i;

        if (strcmp(contas[i].senha,verificacao_senha)== 0)
        {
          printf("\n\n Seu login foi feito feito com sucesso");
          printf("\n\n\n              Carregando...");
          confirmacao_login = 1;
          getchar();
          menu_perfil(contas);
          system("cls");
        }
      }

    }

    if (confirmacao_login == 0)
    {
      printf("\n\n Login ou senhas incorretos\n\n");
    }

  }while(confirmacao_login == 0);

}

cadastrar(int num_contas,Conta_perfil *contas){

  int confirmacao_cadastro;
  char senha_temp[15];
  char senha_temp2[15];

  do {
    system("cls");
    linha();
    printf("\n               CADASTRAMENTO");
    printf("\n\n Digite o seu primeiro nome: ");
    gets(contas[num_contas].nome);
    printf("\n Digite o seu sobrenome: ");
    gets(contas[num_contas].sobrenome);
    printf("\n Digite o email: ");
    gets(contas[num_contas].email);

    // VERIFICACAO DE senha

    int confirmacao_senha = 0;

    do {
      printf("\n Digite a senha: ");
      gets(senha_temp);
      printf("\n Digite a senha novamente: ");
      gets(senha_temp2);

      if ( strcmp(senha_temp2,senha_temp) == 0){
         strcpy(contas[num_contas].senha,senha_temp);
        confirmacao_senha = 1;

      }
      else {
        system("cls");
        printf("\n As senhas nao correspondem");
      }
    }while( confirmacao_senha == 0);

    system("cls");
    linha();
    printf("\n             USUARIO ");
    printf("\n      Nome: %s",contas[num_contas].nome);
    printf("\n      Sobrenome: %s",contas[num_contas].sobrenome);
    printf("\n      Email: %s",contas[num_contas].email);
    printf("\n      Senha: %s",contas[num_contas].senha);
    linha2();
    printf("\nVoce tem certeza dos seus dados ? \n( 1 - SIM / 2 - Nao ) ");
    scanf("%d",&confirmacao_cadastro);
    getchar();




    // BANCO DE DADOS


  }while(confirmacao_cadastro != 1);
    _num_contas = num_contas + 1;
    system("cls");
    printf("\n\n PARABENS, voce ja pode acessa sua conta atraves do LOGIN. Pressione enter!");
    getchar();
    entrar(contas);

}

menu_login(Conta_perfil *contas){

  int opcao;
  char navegador[20];

  do {
        system("cls");
        linha();
        printf("\n               BEM VINDO");
        printf("\n\n               1- Entrar");
        printf("\n               2- Cadastrar\n");
        linha2();

        opcao = navegador_busca(contas);

        switch(opcao){

            case 1 :

                entrar(contas);
                break;

            case 2:

                cadastrar(_num_contas,contas);
                break;

            default:
                printf("\n\n Digite um opcao valida");
        }


    }while ( opcao != 2 && opcao != 1);
}




int main () {

  // VARIAVEIS

  Conta_perfil contas[4];

 // MENU

  menu_login(contas);

  // FIM DO MENU



}
