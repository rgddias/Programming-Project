#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs
typedef struct{
    char login[30];
    char email[30];
    char password[30];
    char question[30];//pergunta esqueci senha
    char answer[30];//reposta
    int status; //1 se a conta pode logar e 0 se a conta nao pode logar
}Account;

//functions
void nfgets(char put_array[], int max_size); //nfgets function
int register_window(Account create[], int acc_number);//tela de registro. Funcao register_window retorna 1 se teve sucesso
void line_start();
void line_end();
//
int main()
{
    Account acc_database[10]; //lista de todas as contas registradas
    int acc_count = 0; //numero de contas criadas
    //
    if(1)//se opcao registrar for selecionada
    {
        if(register_window(acc_database, acc_count) == 1){//se conta criada com sucesso
            acc_count++;
        }
    }
    return 0;
}

int register_window(Account create[], int acc_number)
{
    char char_temp_info[7][30];

    printf("email: ");
    nfgets(char_temp_info[0], 30);
    //se nao tiver @ manda digitar denovo "email invalido digite novamente"
    //
    //se tiver correto
    strcpy(create[acc_number].email, char_temp_info[0]);
    //
    printf("login: ");
    nfgets(char_temp_info[1], 30);
    strcpy(create[acc_number].login, char_temp_info[1]);

    printf("senha: ");
    nfgets(char_temp_info[2], 30);
    //
    printf("confirme a senha: ");
    nfgets(char_temp_info[3], 30);
    //se estiverem iguais
    strcpy(create[acc_number].password, char_temp_info[3]);

    printf("pergunta de seguranca: ");
    nfgets(char_temp_info[4], 30);
    strcpy(create[acc_number].question, char_temp_info[4]);

    printf("resposta de seguranca: ");
    nfgets(char_temp_info[5], 30);
    strcpy(create[acc_number].answer, char_temp_info[5]);

    //se conta criada
    create[acc_number].status = 1;
    return 1;
}

void nfgets(char put_array[], int max_size)
{
    fgets(put_array, max_size, stdin);
    size_t length = strlen(put_array);
    if (put_array[length - 1] == '\n'){
        put_array[length - 1] = '\0';
    }
}

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
