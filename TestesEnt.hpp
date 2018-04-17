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

class Teste_Leitor : private TestesEnt{
private:
	Leitor leitor;

	void leitorValido();

public:
	void run();
};

#endif // TESTESENT_H_INCLUDED