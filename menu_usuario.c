#include <stdio.h>
#include <stdlib.h>



void line_start ()
{
  int i;
  printf("\n");
  for ( i = 0; i < 45; i++)
  printf("=");
}



void menu_usuario()
{
	line_start();
	
	printf("\n--Bem vindo ao menu do usuario Spotify-- \n");	
	printf("--Escolha uma das opcoes abaixo--\n\n");
	
	printf("(1)-> Playlist  \n");
	printf("(2)-> Meus favoritos \n");
	printf("(3)-> Lista de Amigos \n");
	printf("(4)-> Recomendacoes \n");
	printf("(5)-> Mais tocadas \n");
	printf("(6)-> Pesquisa \n");
	printf("(7)-> Ajuda \n");
	
	line_start();
}





main()
{
	
	menu_usuario();
	

}
