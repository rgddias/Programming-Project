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

char ask_command()
{
    char input[50];
    printf(">");
    gets(input);

    if(strcmp(input, "back") == 0){
        //go back one screen
    }
    else{
        return input;
    }

}

void execute_login()
{
    char blank[2] = " ";
    char senha_temp[30];
    char login_temp[30];

    //
    login_screen_print(blank, blank, 1, 0);
    printf("> ");

    gets(login_temp);
    login_screen_print(login_temp, blank, 0, 1);
    printf("> ");
    gets(senha_temp);
    login_screen_print(login_temp, senha_temp, 0, 0);
}
//




int main()
{
    execute_login();

    //login
    //


    return 0;

}
