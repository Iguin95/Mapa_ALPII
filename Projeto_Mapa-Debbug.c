#include <string.h> 
#include <stdio.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
#include <locale.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

//vari�veis globais
int cont = 0;
int idade = 0;

struct ingressos{
	char nome[200];
	char cpf[16];
	int ano;
};

struct ingressos ing[100]; //vari�vel global

void vender();
void vendido();
int validar();
int cpfval();


int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int op;
	
	do{
		printf("\nEscreva a op��o desejada:");
		printf("\n1) Vender ingresso\n2) Listar ingressos vendidos\n3) Validar ingresso\n4) Sair\n");
		fflush(stdin);
		scanf("%d", &op);
		system("cls");
		
		switch(op){
			case 1 : {
				vender();
				cont = cont + 1;
				break;
			}
			case 2 : {
				vendido();
				break;
			}
			case 3 : {
				validar();
				break;
			}
		}
		
	}while(op != 4);
	return 0;	
}
 /*------------------------------------------------------------------------------------------------------*/	
int cpfval(){ //verifica��o se o CPF digitado � valido
	int cpf_novo[12]; 
	int TotalDigito1 = 0, TotalDigito2 = 0, Digito_Calculado, x = 0, y = 0, tamanho, Digito_usuario;

	printf("Digite seu CPF: \n");
	scanf("%s", ing[cont].cpf);
	fflush(stdin);
	tamanho = strlen(ing[cont].cpf); /*pega o tamanho total da string cpf*/ 
	
	
	while(x < tamanho){ /*enquanto x for menor que o tamanho da string cpf, fa�a:..*/
		if(ing[cont].cpf[x]!= '.' && ing[cont].cpf[x]!= '-'){ /*se no vetor x o valor for diferente de '.' e '-',
		 atribua no cpf_novo no �ndice y o valor obtido de x*/
			cpf_novo[y] = ing[cont].cpf[x] - 48; 
			y = y + 1;
		}
		x++;
	}
	
	x = 0;
	
	while(x < 9){
		TotalDigito1 = TotalDigito1 + ((cpf_novo[x])*(10 - x));
		TotalDigito2 = TotalDigito2 + ((cpf_novo[x])*(11 - x));
		x++;
	}
	
	TotalDigito1 = (TotalDigito1 * 10) % 11;
	if(TotalDigito1 > 9){
		TotalDigito1 = 0; 
	} 
	
	
	TotalDigito2 = (TotalDigito2 + (TotalDigito1 * 2)) * 10 % 11;
	if(TotalDigito2 > 9){
		TotalDigito2 = 0;
	}

	Digito_Calculado = (TotalDigito1 * 10) + TotalDigito2; 
	x = cpf_novo[9]; 
	y = cpf_novo[10]; 
	
	Digito_usuario = ((x)*10)+(y);
	
	if(tamanho == 11 || tamanho == 14){ /*Verifica se o tamanho obtido do CPF � igual a 11 ou 14, se n�o for, ser� solicitado
	que digite o CPF novamente.*/
		if(Digito_Calculado == Digito_usuario){
			printf("CPF correto!\n");
			return 1;/*Retorna 1 se a valida��o do CPF ocorrer com �xito*/	
		}else{
			return 0;/*Retorna 0 se a valida��o do CPF der erro*/
		}
	}else{
		return 0;
	}
		
}
 /*------------------------------------------------------------------------------------------------------*/	
void vender(){ //venda e cadastro dos ingressos
	
	printf("\nVender Ingressos:\n");
/*------------------------------------------------------------------------------------------------------*/	
	printf("Escreva seu nome:\n");
	fflush(stdin);
	while(1){ /*O loop continua em execu��o at� que uma entrada n�o num�rica v�lida seja fornecida. 
	Se a entrada num�rica for detectada, ela limpa o buffer de entrada e solicita entrada novamente.*/
		if(scanf("%99[^0-9\n]",ing[cont].nome) == 1){ /*o especificador de formato %99[^0-9\n]� usado no scanf. 
		Este especificador l� os caracteres at� encontrar um d�gito num�rico (0 a 9) ou um caractere de nova linha(\n).
		Ele para de ler assim que encontra qualquer um desses caracteres, deixando os caracteres restantes no buffer de 
		entrada para a pr�xima itera��o.*/
		fflush(stdin);
			break; //para a execu��o do loop caso a entrada do nome seja n�o n�merica, ou seja, se a entrada for correta.
			}else{ //entra aqui caso os primeiros digitos do nome for n�mericos.
				int t;
				while ((t = getchar()) != '\n' && t != EOF); //limpeza do buffer
				printf("Entrada de n�meros n�o � aceita, digite o nome novamente: \n");
			}
	}
 /*------------------------------------------------------------------------------------------------------*/
 //chamada da fun��o de verificar se o CPF digitado � valido.
 	
	int cpfResult;
	do{
		cpfResult = cpfval(); /*atribui a fun��o a vari�vel inteira para que possa capturar o retorno(1 para "deu certo"
		e 0 para "deu errado")*/
		if(cpfResult == 0){/*Verifica se o valor de retorno da fun��o � igual a zero, se for, entrar� na condi��o*/
			printf("CPF incorreto! Digite novamente.\n");
		}
	}while (cpfResult == 0);/*Retornar� a fun��o enquanto o valor for zero, ou seja, enquanto a entrada do CPF for inv�lida*/
	
 /*------------------------------------------------------------------------------------------------------*/
 //inserindo o ano de nascimento caso d� tudo certo com a valida��o do CPF. 
 
	if(cpfResult != 0){ /* Esta condi��o est� verificando se cpfResult n�o � igual a zero. Ele sugere que esta 
	parte do c�digo seja executada apenas se alguma condi��o anterior (relacionada � valida��o do CPF) for 
	atendida com sucesso.*/
		printf("Escreva seu ano de nascimento:\n");
        int year; /*declara uma vari�vel inteira para armazenar a entrada do usu�rio para o ano de nascimento.*/
        while (1) { /*Este � um loop infinito que solicita repetidamente uma entrada do usu�rio at� que um ano 
		v�lido seja inserido. � 1 por causa da verifica��o do CPF*/
            if (scanf("%d", &year) == 1 && year <= 2023 && year >= 1923) { /*Esta linha tenta ler um valor inteiro da entrada do 
			usu�rio usando scanf. Ele verifica duas condi��es: primeiro, se scanf retornar 1 (indicando entrada bem-sucedida 
			verificada no retorno da verifica��o do CPF(return 1 se der certo e return 0 se der errado) e segundo, se o ano inserido 
			for menor ou igual a 2023 e maior ou igual a 1923.*/
                ing[cont].ano = year;/*Esta linha atribui o ano inserido ao ano campo (ano de nascimento) do ticket atual.*/
                break;/*Isso interrompe o loop infinito desde que um ano v�lido foi inserido com sucesso.*/
            } else { /*Se as condi��es do if n�o forem atendidas (entrada inv�lida), o c�digo dentro do else ser� executado*/
                printf("Entrada inv�lida. Por favor, insira um ano v�lido:\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF); /*Esse comando � usado para limpar o buffer de entrada consumindo quaisquer 
				caracteres restantes no buffer de entrada, incluindo o caractere de nova linha. Isso � feito para evitar que uma entrada 
				inv�lida cause um loop infinito.*/
            }
        }
        
        idade = 2023 - ing[cont].ano;
        if(idade >= 18){
        	printf("Maior de idade, passagem liberada.(Idade: %d)\n", idade);
		}else{
			printf("Menor de idade, passagem negada.(Idade: %d)\n", idade);
		}
    }
}

 /*------------------------------------------------------------------------------------------------------*/	
//lista os ingressos vendidos 

void vendido(){
	int j;
	printf("Lista de Ingressos Vendidos:\n");
	for(j = 0;j < cont; j++){
		printf("\nNome: %s\n", ing[j].nome);
		printf("CPF: %s\n", ing[j].cpf);
		if(2023 - ing[j].ano < 18){ /*Preciso subtrair novamente para adquirir a idade da pessoa*/
			printf("Menor de idade, passagem negada.(Idade: %d)\n", idade);
		}
		printf("Ano de nascimento: %d\n", ing[j].ano);
		printf("=====================================================\n");
	}
}
 /*------------------------------------------------------------------------------------------------------*/
 //busca os CPF cadastrados	

int validar() {
    int i, c, tam = 15;  
    char cpfFormatado[14];
    cpfFormatado[3] = '.';
    cpfFormatado[7] = '.';
    cpfFormatado[11] = '-';
    
    char val[30];
    printf("Digite o CPF:\n");
    scanf("%s", val);
    fflush(stdin);
    tam = strlen(val);

    if (!strcmp(ing[cont].cpf + 3, val + 3) == 0 &&
        !strcmp(ing[cont].cpf + 7, val + 7) == 0 &&
        !strcmp(ing[cont].cpf + 11, val + 11) == 0) {
        
        for (c = 0; c < tam; c++) {
            if (c >= 3 && c < 6) {
                cpfFormatado[c + 1] = ing[cont].cpf[c];
            } else if (c >= 6 && c < 9) {
                cpfFormatado[c + 2] = ing[cont].cpf[c];
            } else if (c >= 9 && c < 12) {
                cpfFormatado[c + 3] = ing[cont].cpf[c];
            } else {
                cpfFormatado[c] = ing[cont].cpf[c];
            }
        }

        strcpy(ing[cont].cpf, cpfFormatado);
    }

    for (i = 0; i < cont; i++) {
        if (strcmp(val, ing[i].cpf) == 0) {
            printf("CPF validado, entrada permitida.\n");
            return 1; // // Retorne 1 para indicar valida��o bem-sucedida; finaliza o bloco validar.
        }
    }

    printf("CPF n�o encontrado!\n");
    return 0; // Retorne 0 para indicar valida��o malsucedida; s� vai entrar nesse se o return 1 for falso.
}

