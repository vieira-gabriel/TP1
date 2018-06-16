#ifndef NAVEGACAO_H_INCLUDED
#define NAVEGACAO_H_INCLUDED

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
#include "Comandos.cpp"

//--------------------------------------------------------------------------- 
/**
* Classe FrontPage.
* Essa classe é a primeira tela de interação com o usuário, perguntando se deseja fazer login ou se cadastrar na plataforma.
*/
class NavFrontPage: public InterUI {
private:
	static const unsigned int OP_LOGIN		= 1;
	static const unsigned int OP_SIGNUP		= 2;
	static const unsigned int OP_EXIT		= 3;
	void showOption();

public:
	NavFrontPage(){}
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe Login.
* Essa classe é responsável pela janela de login.
*/
class NavLogin: public InterUI {
private:
	void showOption();

public:
	NavLogin(){}
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe SignUp.
* Essa classe é responsável pela janela de cadastro.
*/
class NavSignUp: public InterUI {
private:
	static const unsigned int SU_LEITOR		= 1;
	static const unsigned int SU_DEV		= 2;
	static const unsigned int SU_ADMIN		= 3;
	static const unsigned int SU_EXIT		= 4;
	void showOption();

public:
	NavSignUp(){}
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe SULeitor.
* Essa classe é responsável pela janela de cadastro de leitor.
*/
class NavSULeitor: public InterUI {
private:
	void showOption();

public:
	NavSULeitor(){}
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe SUDev.
* Essa classe é responsável pela janela de cadastro de desenvolvedor.
*/
class NavSUDev: public InterUI {
private:
	void showOption();

public:
	NavSUDev(){}
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe SUAdmin.
* Essa classe é responsável pela janela de cadastro de administrador.
*/
class NavSUAdmin: public InterUI {
private:
	void showOption();

public:
	NavSUAdmin(){}
	void execute();
};

#endif // NAVEGACAO_H_INCLUDED