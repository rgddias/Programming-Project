#include <stdio.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>


int num_contas = 0;

// STRUCTS

typedef struct{
    char login[20];
    char email[30];
    char password[20];
    char question[30];//pergunta esqueci senha
    char answer[30];//reposta
    int status; //1 se a conta pode logar e 0 se a conta nao pode logar
}Account;

// PROTOTIPOS

void main_menu(Account contas[]);//menu inicial (primeira tela)

int login_window(Account contas[]);//tela de login retorna o indice da conta logada

void line_start();

void line_end();

void nfgets(char put_array[], int max_size); //nfgets function

void new_password(Account logged[],int index); // funcao para mudanca de senha (opcao - esqueci senha)

 int register_window(Account create[], int acc_number); // funcao para cadastro

int check_at(char get_string[]); //verificaçao de email valido

//Main

int main ()
{

 Account acc_database[10];

//Variables

  int option;
  int acc_count = 0;

  //Operation

  do
  {
    system("cls");

    line_end();

    printf("\n--Bem ao aplicativo Spotify--");
    printf("\n\n(1)-> Entrar");
    printf("\n(2)-> Cadastrar\n");
    line_end();
    printf("\nDigite a opcao: ");
    scanf("%d",&option);
    getchar();
    switch(option)
    {
      case 1 :
        login_window(acc_database);
        break;

      case 2:
       if(register_window(acc_database, acc_count) == 1){//se conta criada com sucesso
            acc_count++;
            system("cls");
            printf("Cadastro feito com sucesso.\nEncaminhando para a aba de login");
            getchar();
            getchar();
            login_window(acc_database);
        }else {
          printf("\nO cadastro foi cancelado!");
        }
        break;

      default:
        printf("\n\n Digite um opcao valida");
    }


  }while ( option != 2 && option != 1);

}



//FUNCOES

void line_start()
{
  int i;
   printf("\n\n");
  for ( i = 0; i < 45; i++)
  printf("*");
}

void line_end()
{
  int i;
  printf("\n");
  for ( i = 0; i < 45; i++)
  printf("=");
}


int  login_window(Account acc_database[])
{

  //Variables
  char char_temp_info[5][30];
  int email_confirm = 0;
  int password_confirm = 0;
  int tryAgain;
  int i;

  //Operation

  do
  {

    system("cls");

    line_end();
    printf("\n\n--Login--");
    printf("\n\nDigite o email: ");
    nfgets(char_temp_info[0],30);


    for (i = 0; i < 10; i++)
    {
      if( strcmp(acc_database[i].email,char_temp_info[0]) == 0) //comparando o email com os cadastrados
      {
        email_confirm = 1; // confirmação de email compativel

        do
        {

          printf("\nDigite a senha: ");
          nfgets(char_temp_info[1],30);


          if( strcmp(char_temp_info[1],acc_database[i].password) == 0)//comparando as senhas com os cadastrados
          {
            password_confirm = 1;  // confirmação de senha compativel
            printf("\n\n Login feito");
            return i;
          }

          else
          {
            printf("\nSenha incorreta: (1-Tentar de novo / 2- Esqueci minha senha)");
            scanf("%d",&tryAgain);
            getchar();
            if (tryAgain == 2){
                new_password(acc_database,i);
            }

          }

        }while(password_confirm == 0);

      }
    }

    if (email_confirm == 0 || num_contas == 0) //caso nao haja email compativel com o digitado
    {
      printf("\nEmail nao cadastrado. \n(1-Tente novamente / 2- Cadastre-se)");
      scanf("%d",&tryAgain);
      getchar();
      if (tryAgain == 2){
        register_window(acc_database,i);
      }
    }


  }while(email_confirm == 0 || password_confirm == 0);

}

void nfgets(char put_array[], int max_size)
 {
     fgets(put_array, max_size, stdin);
     size_t length = strlen(put_array);
     if (put_array[length - 1] == '\n'){
         put_array[length - 1] = '\0';
     }
 }

void new_password(Account logged[],int index)
{

  char char_temp_info[3][30];
  int password_change = 0;
  int answer_confirm = 0;

  system("cls");

  line_start();
  printf("\n\nPara sabemos que voce e realmente o dono dessa conta. Por favor responda a pergunta de confirmacao");

  do {

    getchar();
    printf("\n->%s ? ",logged[index].question); // Apresenta a pergunta de confirmacao
    nfgets(char_temp_info[0],30);

    if(strcmp(char_temp_info[0],logged[index].answer)==0)// comparando a informacao dada com a resposta armazenada
    {
      answer_confirm = 1; // confirmacao de acerto da resposta

      do {
        printf("\n\n Digite sua nova senha: ");
        nfgets(char_temp_info[1],30);

        printf("\n\n Digite novamente: ");
        nfgets(char_temp_info[2],30);

        if (strcmp(char_temp_info[1],char_temp_info[2]) == 0) // comparando se as senhas sao iguais
        {
          strcpy(logged[index].password,char_temp_info[2]);

          password_change = 1; // confirmacao de mudança de senha

          printf("A sua senha foi alterada com sucesso!! Volte para o login");

        }
        else
        {
          printf("\nAs senhas nao sao iguais");
        }

      }while(password_change == 0);
    }

    else
    {
      printf("\nA resposta nao corresponde. Tente novamente");
    }

  }while(answer_confirm == 0);


}


int register_window(Account create[], int acc_number)
{
    char char_temp_info[7][30];
    int flag = 0;
    system("cls");

    line_start();
    printf("\n--Cadastro--\n\n");

    do
    {

        printf("email: ");

        nfgets(char_temp_info[0], 30);
        //se usuario digitar cancel cancela criacao de conta
        if(strcmp(char_temp_info[0], "cancel") == 0){
            return 0;
        }
        //se nao tiver @ manda digitar denovo "email invalido digite novamente"
        if( ( check_at(char_temp_info[0]) ) != 1){
            printf("email invalido, digite novamente\n");
        }
        else{
            //se tiver correto
            strcpy(create[acc_number].email, char_temp_info[0]);
            flag = 1;
        }
    }while(flag != 1);
    //
    printf("login: ");
    nfgets(char_temp_info[1], 30);
    //
    if(strcmp(char_temp_info[1], "cancel") == 0){
        return 0;
    }
    //
    strcpy(create[acc_number].login, char_temp_info[1]);

    flag = 0;
    do{
        printf("senha: ");
        nfgets(char_temp_info[2], 30);
        //
        if(strcmp(char_temp_info[2], "cancel") == 0){
            return 0;
        }
        //
        printf("confirme a senha: ");
        nfgets(char_temp_info[3], 30);
        if(strcmp(char_temp_info[3], "cancel") == 0){
            return 0;
        }
        //se estiverem iguais
        if(strcmp(char_temp_info[2], char_temp_info[3]) == 0){
            strcpy(create[acc_number].password, char_temp_info[3]);
            flag = 1;
        }
        else{
            printf("senhas nao estao diferentes, digite novamente\n");
        }
    }while(flag != 1);

    printf("pergunta de seguranca: ");
    nfgets(char_temp_info[4], 30);
    //
    if(strcmp(char_temp_info[4], "cancel") == 0){
        return 0;
    }
    strcpy(create[acc_number].question, char_temp_info[4]);

    printf("resposta de seguranca: ");
    nfgets(char_temp_info[5], 30);
    //
    if(strcmp(char_temp_info[5], "cancel") == 0){
        return 0;
    }
    strcpy(create[acc_number].answer, char_temp_info[5]);

    //se conta criada
    create[acc_number].status = 1;
    return 1;
}

int check_at(char get_string[])
{
    int size = strlen(get_string);
    int found = 0;
    int i = 0;
    for(i = 0; i < size; i++){
        if(get_string[i] == '@'){
            found++;
        }
    }
    if(found == 1){
        return 1;
    }
    else{
        return -1;
    }
}
