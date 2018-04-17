#ifndef TESTESENT_H_INCLUDED
#define TESTESENT_H_INCLUDED

#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>

class TestesEnt{
private:

public:
	int resultado_teste;

	void iniciar();
	
	static const int SUCESSO = 	0;
	static const int FALHA = 	1;
};

//--------------------------------------------------------------------------- 
//Teste Entidade Leitor.

class Teste_Leitor : public TestesEnt{
private:
	Leitor leitor;

	void leitorValido();

public:
	void run();
};

//--------------------------------------------------------------------------- 
//Teste Entidade Desenvolvedor.

class Teste_Desenvolvedor : public Teste_Leitor{
private:
	Desenvolvedor desenvolvedor;

	void desenvolvedorValido();

public:
	void run();
};

//--------------------------------------------------------------------------- 
//Teste Entidade Administrador.

class Teste_Administrador : public Teste_Desenvolvedor{
private:
	Administrador adm;

	void admValido();

public:
	void run();
};

//--------------------------------------------------------------------------- 
//Teste Entidade DataCriacao.

class Teste_DataCriacao : public TestesEnt{
private:
	DataCriacao data;

	void dataValido();

public:
	void run();
};

//--------------------------------------------------------------------------- 
//Teste Entidade Vocabulário Controlado.

class Teste_Vocabulario : public Teste_DataCriacao{
private:
	Vocabulario_controlado vocab;

	void vocabValido();

public:
	void run();
};

//--------------------------------------------------------------------------- 
//Teste Entidade Termo.

class Teste_Termo : public Teste_DataCriacao{
private:
	Termo termo;

	void termoValido();

public:
	void run();
};

//--------------------------------------------------------------------------- 
//Teste Entidade Definicao.

class Teste_Definicao : public Teste_DataCriacao{
private:
	Definicao def;

	void defValido();

public:
	void run();
};

#endif // TESTESENT_H_INCLUDED