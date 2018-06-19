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

// Apenas para criar dados para testes.
class Premade: public InterCMD {
public:
	void execute();
};

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

//--------------------------------------------------------------------------- 
/**
* Classe NavUserDev.
* Essa classe é responsável pela janela de usario nivel Desenvolvedor.
*/
class NavUserDev: public InterUI {
private:
	static const unsigned int US_SHOW_USER		= 1;
	static const unsigned int US_EDIT_USER		= 2;
	static const unsigned int US_DELETE_USER	= 3;
	static const unsigned int US_LIST_VOCAB		= 4;
	static const unsigned int US_SHOW_VOCAB		= 5;
	static const unsigned int US_SHOW_TERMO		= 6;
	static const unsigned int US_SHOW_DEFIN		= 7;
	static const unsigned int US_SU_VOCAB		= 8;
	static const unsigned int US_NEW_TERMO		= 9;
	static const unsigned int US_EDIT_TERMO		= 10;
	static const unsigned int US_DELETE_TERMO	= 11;
	static const unsigned int US_NEW_DEFIN		= 12;
	static const unsigned int US_EDIT_DEFIN		= 13;
	static const unsigned int US_DELETE_DEFIN	= 14;
	
	static const unsigned int US_EXIT			= 15;
	Email email;
	void showOption();

public:
	NavUserDev(Email e){ email = e; }
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavUserAdmin.
* Essa classe é responsável pela janela de usario nivel Administrador.
*/
class NavUserAdmin: public InterUI {
private:
	static const unsigned int US_SHOW_USER		= 1;
	static const unsigned int US_EDIT_USER		= 2;
	static const unsigned int US_DELETE_USER	= 3;
	static const unsigned int US_LIST_VOCAB		= 4;
	static const unsigned int US_SHOW_VOCAB		= 5;
	static const unsigned int US_SHOW_TERMO		= 6;
	static const unsigned int US_SHOW_DEFIN		= 7;
	static const unsigned int US_SU_VOCAB		= 8;
	static const unsigned int US_NEW_TERMO		= 9;
	static const unsigned int US_EDIT_TERMO		= 10;
	static const unsigned int US_DELETE_TERMO	= 11;
	static const unsigned int US_NEW_DEFIN		= 12;
	static const unsigned int US_EDIT_DEFIN		= 13;
	static const unsigned int US_DELETE_DEFIN	= 14;
	static const unsigned int US_NEW_VOCAB		= 15;
	static const unsigned int US_EDIT_VOCAB		= 16;
	static const unsigned int US_DELETE_VOCAB	= 17;

	static const unsigned int US_EXIT			= 18;
	Email email;
	void showOption();

public:
	NavUserAdmin(Email e){ email = e; }
	void execute();
};



//##############################################################################################
//############################### Acoes de usuario #############################################
//##############################################################################################

//--------------------------------------------------------------------------- 
/**
* Classe NavNewVocab.
* Essa classe é responsável pela janela de criacao de vocabulario.
*/
class NavNewVocab: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavNewVocab(Email e){ user = e; }
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavEditVocab.
* Essa classe é responsável pela janela de edicao de vocabulario.
*/
class NavEditVocab: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavEditVocab(Email e){ user = e; }
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavDeleteVocab.
* Essa classe é responsável pela janela de exclusao de vocabulario.
*/
class NavDeleteVocab: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavDeleteVocab(Email e){ user = e; }
	void execute();
};

//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
/**
* Classe NavNewTermo.
* Essa classe é responsável pela janela de criacao de termo.
*/
class NavNewTermo: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavNewTermo(Email e){ user = e; }
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavEditTermo.
* Essa classe é responsável pela janela de edicao de termo.
*/
class NavEditTermo: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavEditTermo(Email e){ user = e; }
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavDeleteTermo.
* Essa classe é responsável pela janela de exclusao de termo.
*/
class NavDeleteTermo: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavDeleteTermo(Email e){ user = e; }
	void execute();
};


//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
/**
* Classe NavNewDefin.
* Essa classe é responsável pela janela de criacao de definicao de termo.
*/
class NavNewDefin: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavNewDefin(Email e){ user = e; }
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavEditDefin.
* Essa classe é responsável pela janela de edicao de definicao de termo.
*/
class NavEditDefin: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavEditDefin(Email e){ user = e; }
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavDeleteDefin.
* Essa classe é responsável pela janela de exclusao de definicao de termo.
*/
class NavDeleteDefin: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavDeleteDefin(Email e){ user = e; }
	void execute();
};


//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
/**
* Classe NavSUVocab.
* Essa classe é responsável pela janela de cadastro de desenvolvedor em vocabulario.
*/
class NavSUVocab: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavSUVocab(Email e){ user = e; }
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavListVocab.
* Essa classe é responsável pela janela de listagem de vocabulario.
*/
class NavListVocab: public InterUI {
private:
	void showOption();

public:
	NavListVocab(){}
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavShowVocab.
* Essa classe é responsável pela janela de detalhes do vocabulario.
*/
class NavShowVocab: public InterUI {
private:
	void showOption();

public:
	NavShowVocab(){}
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavShowTermo.
* Essa classe é responsável pela janela de detalhes do termo.
*/
class NavShowTermo: public InterUI {
private:
	void showOption();

public:
	NavShowTermo(){}
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavShowDefin.
* Essa classe é responsável pela janela de detalhes da definicao.
*/
class NavShowDefin: public InterUI {
private:
	void showOption();

public:
	NavShowDefin(){}
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavEditLeitor.
* Essa classe é responsável pela janela de editor de leitor.
*/
class NavEditLeitor: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavEditLeitor(Email e){ user = e; }
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavEditDev.
* Essa classe é responsável pela janela de editor de desenvolvedor.
*/
class NavEditDev: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavEditDev(Email e){ user = e; }
	void execute();
};

//--------------------------------------------------------------------------- 
/**
* Classe NavEditAdmin.
* Essa classe é responsável pela janela de editor de administrador.
*/
class NavEditAdmin: public InterUI {
private:
	Email user;
	void showOption();

public:
	NavEditAdmin(Email e){ user = e; }
	void execute();
};











#endif // NAVEGACAO_H_INCLUDED
