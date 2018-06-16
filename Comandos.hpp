#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <limits>

#include "Dominios.hpp"
#include "Entidades.cpp"
#include "Interface.hpp"

//--------------------------------------------------------------------------- 
/**
* Classe FrontPage.
* Essa classe é a primeira tela de interação com o usuário, perguntando se deseja fazer login ou se cadastrar na plataforma.
*/
class CmdTest: public InterCMD{
public:
	void execute(){}
	void setCmd(){}
};

#endif // COMANDOS_H_INCLUDED