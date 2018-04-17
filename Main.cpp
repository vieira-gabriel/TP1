// Trabalho 1 de TP
// Autores: Bruno Takashi (12/0167263) e Gabriel Arimatéa (15/0126956)

#include "Dominios.cpp"
#include "Entidades.cpp"
#include "Testes_dominios.cpp"
#include "Testes_entidades.cpp"

int main(){

	printf("-- Teste dos dominios:\n");
	//Teste dos dominios
	Teste_Nome 				TesteA;
	Teste_Telefone 			TesteB;
	Teste_Endereco 			TesteC;
	Teste_Data 				TesteD;
	Teste_Email 			TesteE;
	Teste_Senha 			TesteF;
	Teste_Texto 			TesteG;
	Teste_Idioma 			TesteH;
	Teste_Classe_de_termo 	TesteI;

	printf("\t");
	TesteA.run();
	printf("\t");
	TesteB.run();
	printf("\t");
	TesteC.run();
	printf("\t");
	TesteD.run();
	printf("\t");
	TesteE.run();
	printf("\t");
	TesteF.run();
	printf("\t");
	TesteG.run();
	printf("\t");
	TesteH.run();
	printf("\t");
	TesteI.run();

	printf("\n-- Teste das entidades:\n");
	//Teste das entidades
	Teste_Leitor 		Teste1;
	Teste_Desenvolvedor Teste2;
	Teste_Administrador Teste3;
	Teste_DataCriacao 	Teste4;
	Teste_Vocabulario 	Teste5;
	Teste_Termo 		Teste6;
	Teste_Definicao 	Teste7;

	printf("\t");
	Teste1.run();
	printf("\t");
	Teste2.run();
	printf("\t");
	Teste3.run();
	printf("\t");
	Teste4.run();
	printf("\t");
	Teste5.run();
	printf("\t");
	Teste6.run();
	printf("\t");
	Teste7.run();

	return 0;
}