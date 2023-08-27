#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respovavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string string= conjunto de variaveis
	char arquivo[40];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //printf = armazenar / coletando informa��o do usu�rio
	scanf("%s", cpf); //%s = string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string (str = string, cpy = copy)
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // w = write/escrever || criar
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // a = atualizar: 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // a = atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // a = atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[11];
	char conteudo[200];
		
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r = read
	
	if(file == NULL) // NULL = Nulo
	{
		printf("N�o foi poss�vel localizar este cpf!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[11];

	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);

	FILE *file;
	file = fopen(cpf,"r"); // r = read

	if (file == NULL)
	{
		printf("O usu�rio n�o est� cadastrado\n");
		system("pause");
	}
	
	if (file != NULL)
	{
		printf("O usu�rio foi deletado!\n");
		system("pause");
	}
	
	
}

int main()
{
	int opcao=0; //Definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	system("cls"); //limpar a tela ap�s comando
	
	printf("### Cart�rio ###\n\n"); //Inicio do menu //printf = armazenar
	printf("Escolha a op��o desejada do menu: \n\n"); //printf = armazenar
	printf("\t1 - Registrar nomes\n"); //printf = armazenar 
	printf("\t2 - Consultar nomes\n"); //printf = armazenar
	printf("\t3 - Deletar nomes\n\n");  //printf = armazenar
	printf("Op��o: "); //Fim do menu //printf = armazenar
	
	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	system("cls");
	
		switch(opcao) // inicio da sela��o do menu
		{
			case 1:
			registro(); // chamada de fun��es
			break;
			
			case 2:
	        consultar(); 
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("Pause");
			break;
			//fim da sele��o
			
		}
	    
	}

}
