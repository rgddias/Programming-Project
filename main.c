#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs

//functions
char f_cursor(int o_f)
{
    if(o_f == 1)
    {
        return '>';
    }
    else if(o_f == 0)
    {
        return ;
    }
}

void line_print()
{
    int i = 0;
    printf("\n");
    for(i = 0; i < 40; i++){
        printf("=");
    }
    printf("\n");

}

void login_screen_print(char login_temp_inlogin[], char senha_temp_inlogin[], int c_of1, int c_of2)
{

    line_print();
    printf("\nlogin:%c%s", f_cursor(c_of1), login_temp_inlogin);
    printf("\n\nsenha:%c%s", f_cursor(c_of2), senha_temp_inlogin);
    printf("\n");
    line_print();

}

char ask_command(char out_command[])
{
    char input[50];
    printf(">");
    gets(input);
    strcpy(out_command, input);
}

void execute_login()
{
    char blank[2] = " ";
    char senha_temp[30];
    char login_temp[30];

    //
    login_screen_print(blank, blank, 1, 0);
    ask_command(login_temp);
    login_screen_print(login_temp, blank, 0, 1);
    ask_command(senha_temp);
    login_screen_print(login_temp, senha_temp, 0, 0);
}

void execute_register()
{
    printf("register");
}
//




int main()
{
    char home_command[50];
    ask_command(home_command);

    if(strcmp(home_command, "login") == 0){
        execute_login();
    }
    else if(strcmp(home_command, "register") == 0)
    {
        execute_register();
    }
    //login
    //


    return 0;

}
