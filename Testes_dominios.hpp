#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>

class Testes{
private:

public:
	int resultado_teste;

	void iniciar();
	
	static const int SUCESSO = 	0;
	static const int FALHA = 	1;
};

//--------------------------------------------------------------------------- 
//Teste Classe Nome.

class Teste_Nome : private Testes{	//Teste valido para sobrenome
private:
	Nome nome;

	// Casos de sucesso.
	void nomeValido();
	// Casos de falha.
	void nomeVazio();
	void nomeGrande();
	void nomeIniciaMinusculo();
	void nomeComNumero();
	void nomeNaoAlfanum();

public:
	void run();
};

//--------------------------------------------------------------------------- 
//Teste Classe Telefone.

class Teste_Telefone : private Testes{
private:
	Telefone telefone;

	// Casos de sucesso.
	void telefoneValido();
	// Casos de falha.
	void telefonePequeno();
	void telefoneGrande();
	void telefoneAlfa();
	void telefoneNaoAlfanum();

public:
	void run();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Endereco.

class Teste_Endereco : private Testes{
private:
	Endereco endereco;

	// Casos de sucesso.
	void enderecoValido();
	// Casos de falha.
	void enderecoVazio();
	void enderecoGrande();
	void enderecoIniciaEspaco();
	void enderecoTerminaEspaco();
	void enderecoEspacoSeguido();
	void enderecoNum();
	void enderecoNaoAlfanum();

public:
	void run();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Data.

class Teste_Data : private Testes{
private:
	Data data;

	// Casos de sucesso.
	void dataValido();
	void dataBissexto();
	// Casos de falha.
	void dataAnoPequeno();
	void dataAnoGrande();
	void dataMesPequeno();
	void dataMesGrande();
	void dataDiaPequeno();
	void dataDiaGrande();
	void dataNaoBissexto();

public:
	void run();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Email.

class Teste_Email : private Testes{
private:
	Email email;

	// Casos de sucesso.
	void emailValido();
	// Casos de falha.
	void emailLocalIniciaPonto();
	void emailLocalTerminaPonto();
	void emailLocalCaracterInvalido();
	void emailDominioIniciaHifem();
	void emailDominioTerminaHifem();
	void emailDominioOnlyNum();
	void emailDominioNaoHifemAlfanum();

public:
	void run();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Senha.

class Teste_Senha : private Testes{
private:
	Senha senha;
	Nome nome;

	void iniciar();

	// Casos de sucesso.
	void senhaValido();
	// Casos de falha.
	void senhaPequeno();
	void senhaGrande();
	void senhaNoNum();
	void senhaNoMaiusculo();
	void senhaNoMinusculo();
	void senhaContemUsuario();
	void senhaNaoAlfanum();

public:
	void run();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Texto.

class Teste_Texto : private Testes{
private:
	Texto texto;

	// Casos de sucesso.
	void textoValido();
	// Casos de falha.
	void textoPequeno();
	void textoGrande();

public:
	void run();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Idioma.

class Teste_Idioma : private Testes{
private:
	Idioma idioma;

	// Casos de sucesso.
	void idiomaEng();
	void idiomaFra();
	void idiomaGer();
	void idiomaIta();
	void idiomaPor();
	void idiomaSpa();
	// Casos de falha.
	void idiomaInvalido();

public:
	void run();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Termo.

class Teste_Classe_de_termo : private Testes{
private:
	Classe_de_termo classe;

	// Casos de sucesso.
	void classePT();
	void classeNP();
	// Casos de falha.
	void classeInvalido();

public:
	void run();
	
};


#endif // TESTES_H_INCLUDED