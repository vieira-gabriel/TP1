#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include "Interfaces.hpp"

//-----------------------------------------------------------------------------------------------
//Stub de Autenticação

class StubAutenticacao:public ILNAutenticacao{
public:

	const static int TRIGGER_FALHA		= 1234;
	const static int TRIGGER_ERRO		= 9876;

	int autenticar(string, string) throw(runtime_error) = 0;
	StubAutenticacao();
};

//-----------------------------------------------------------------------------------------------
//Stub de Administrador



//-----------------------------------------------------------------------------------------------
//Stub de Desenvolvedor



//-----------------------------------------------------------------------------------------------
//Stub de Leitor




//-----------------------------------------------------------------------------------------------
//Stub de Vocabulário

#endif // STUBS_H_INCLUDED