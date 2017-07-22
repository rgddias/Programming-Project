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
int check_at(char string[]);//retorna 1 se o @ esta presente e -1 se nao
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
    int flag = 0;
    printf("email: ");
    do
    {
        nfgets(char_temp_info[0], 30);
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
    strcpy(create[acc_number].login, char_temp_info[1]);

    flag = 0;
    do{
        printf("senha: ");
        nfgets(char_temp_info[2], 30);
        //
        printf("confirme a senha: ");
        nfgets(char_temp_info[3], 30);
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
    strcpy(create[acc_number].question, char_temp_info[4]);

    printf("resposta de seguranca: ");
    nfgets(char_temp_info[5], 30);
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
