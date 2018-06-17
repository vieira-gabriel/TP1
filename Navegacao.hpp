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
* Classe NavFrontPage.
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
* Classe NavLogin.
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
* Classe NavSignUp.
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
* Classe NavSULeitor.
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
* Classe NavSUDev.
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
* Classe NavSUAdmin.
* Essa classe é responsável pela janela de cadastro de administrador.
*/
class NavSUAdmin: public InterUI {
private:
	void showOption();

public:
	NavSUAdmin(){}
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavUserLeitor.
* Essa classe é responsável pela janela de usario nivel Leitor.
*/
class NavUserLeitor: public InterUI {
private:
	static const unsigned int US_SHOW_USER		= 1;
	static const unsigned int US_EDIT_USER		= 2;
	static const unsigned int US_DELETE_USER	= 3;
	static const unsigned int US_LIST_VOCAB		= 4;
	static const unsigned int US_SHOW_VOCAB		= 5;
	static const unsigned int US_SHOW_TERMO		= 6;
	static const unsigned int US_SHOW_DEFIN		= 7;
	static const unsigned int US_EXIT			= 8;
	Email email;
	void showOption();

public:
	NavUserLeitor(Email e){ email = e; }
	void execute();
};

#endif // NAVEGACAO_H_INCLUDED