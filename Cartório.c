#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função respovavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string string= conjunto de variaveis
	char arquivo[40];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //printf = armazenar / coletando informação do usuário
	scanf("%s", cpf); //%s = string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string (str = string, cpy = copy)
	
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
		printf("Não foi possível localizar este cpf!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[11];

	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);

	FILE *file;
	file = fopen(cpf,"r"); // r = read

	if (file == NULL)
	{
		printf("O usuário não está cadastrado\n");
		system("pause");
	}
	
	if (file != NULL)
	{
		printf("O usuário foi deletado!\n");
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
	
	system("cls"); //limpar a tela após comando
	
	printf("### Cartório ###\n\n"); //Inicio do menu //printf = armazenar
	printf("Escolha a opção desejada do menu: \n\n"); //printf = armazenar
	printf("\t1 - Registrar nomes\n"); //printf = armazenar 
	printf("\t2 - Consultar nomes\n"); //printf = armazenar
	printf("\t3 - Deletar nomes\n\n");  //printf = armazenar
	printf("Opção: "); //Fim do menu //printf = armazenar
	
	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	system("cls");
	
		switch(opcao) // inicio da selação do menu
		{
			case 1:
			registro(); // chamada de funções
			break;
			
			case 2:
	        consultar(); 
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system("Pause");
			break;
			//fim da seleção
			
		}
	    
	}

}
