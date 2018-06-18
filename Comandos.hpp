#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <limits>
#include <list>

#include "Dominios.hpp"
#include "Entidades.cpp"
#include "Interface.hpp"

//--------------------------------------------------------------------------- 
/**
* Declaração das structs Stermo, Sdefin e Vocabulario que irão formar a estrutura de dados.
*/

struct Stermo {
	Termo termo;
	list<Definicao> definicao;
};
typedef struct Stermo Stermo;

struct Sdefin {
	Definicao defin;
	Nome preferedT;
};
typedef struct Ctermo Ctermo;

struct Vocabulario {
	Vocabulario_controlado vocabulario;
	Definicao definicao;
	Email administrador;
	list<Email> desenvolvedor;
	list<Stermo> termo; 
};
typedef struct Vocabulario Vocabulario;

//--------------------------------------------------------------------------- 
/**
* Classe CmdBase.
* Essa classe abstrata fornece a estrutura de dados base para as demais classes de comando.
*/
class CmdBase: public InterCMD{
protected:
	// usuario.
	static list<Leitor>			userLer;
	static list<Desenvolvedor>	userDev;
	static list<Administrador>	userAdm;
	static list<Leitor>::iterator			itLer;
	static list<Desenvolvedor>::iterator	itDev;
	static list<Administrador>::iterator	itAdm;
	// vocabulario.
	static list<Vocabulario>				listVocab;
	static list<Vocabulario>::iterator		itVocab;
	static list<Email>::iterator			itMail;
	static list<Stermo>::iterator			itTermo;
	static list<Definicao>::iterator		itDef;
};

// definicao das variaveis estaticas de CmdBase.
list<Leitor>			CmdBase::userLer;
list<Desenvolvedor>		CmdBase::userDev;
list<Administrador>		CmdBase::userAdm;
list<Leitor>::iterator			CmdBase::itLer;
list<Desenvolvedor>::iterator	CmdBase::itDev;
list<Administrador>::iterator	CmdBase::itAdm;

list<Vocabulario>				CmdBase::listVocab;
list<Vocabulario>::iterator		CmdBase::itVocab;
list<Email>::iterator			CmdBase::itMail;
list<Stermo>::iterator			CmdBase::itTermo;
list<Definicao>::iterator		CmdBase::itDef;

//--------------------------------------------------------------------------- 
/**
* Classe CmdSULeitor.
* Essa classe realiza o servico de cadastro de leitor.
*/
class CmdSULeitor: public CmdBase{
private:
	Nome nome, sobrenome;
	Email email;
	Senha senha;
public:
	CmdSULeitor(Nome, Nome, Email, Senha);
	void execute() throw (invalid_argument);
};

//--------------------------------------------------------------------------- 
/**
* Classe CmdSUDev.
* Essa classe realiza o servico de cadastro de desenvolvedor.
*/
class CmdSUDev: public CmdBase{
private:
	Nome nome, sobrenome;
	Email email;
	Senha senha;
	Data nascimento;
public:
	CmdSUDev(Nome, Nome, Email, Senha, Data);
	void execute() throw (invalid_argument);
};

//--------------------------------------------------------------------------- 
/**
* Classe CmdSUAdmin.
* Essa classe realiza o servico de cadastro de administrador.
*/
class CmdSUAdmin: public CmdBase{
private:
	Nome nome, sobrenome;
	Email email;
	Senha senha;
	Data nascimento;
	Telefone telefone;
	Endereco endereco;
public:
	CmdSUAdmin(Nome, Nome, Email, Senha, Data, Telefone, Endereco);
	void execute() throw (invalid_argument);
};

//--------------------------------------------------------------------------- 
/**
* Classe CmdLogin.
* Essa classe realiza o servico de login do usuario.
*/
class CmdLogin: public CmdBase{
private:
	Email email;
	Senha senha;
	int result;
public:
	static const unsigned int LG_LEITOR		= 1;
	static const unsigned int LG_DEV		= 2;
	static const unsigned int LG_ADMIN		= 3;
	static const unsigned int LG_ERROR		= 404;

	CmdLogin(Email, Senha);
	void execute() throw (invalid_argument);
	int getResult(){ return result; }
};



//##############################################################################################
//############################### Acoes de usuario #############################################
//##############################################################################################

//--------------------------------------------------------------------------- 
/**
* Classe CmdNewVocab.
* Essa classe realiza o servico de criacao de vocabulario.
*/
class CmdNewVocab: public CmdBase{
private:
	Email user;
	Vocabulario_controlado vocab;
	Definicao defin;

public:
	CmdNewVocab(Vocabulario_controlado, Definicao, Email);
	void execute() throw (invalid_argument);
};

//--------------------------------------------------------------------------- 
/**
* Classe CmdEditVocab.
* Essa classe realiza o servico de edicao de vocabulario.
*/
class CmdEditVocab: public CmdBase{
private:
	Email user;
	Vocabulario_controlado vocab;
	Definicao defin;

public:
	CmdEditVocab(Vocabulario_controlado, Definicao, Email);
	void execute() throw (invalid_argument);
};

//--------------------------------------------------------------------------- 
/**
* Classe CmdDeleteVocab.
* Essa classe realiza o servico de exclusao de vocabulario.
*/
class CmdDeleteVocab: public CmdBase{
private:
	Email user;
	Nome vocab;

public:
	CmdDeleteVocab(Nome, Email);
	void execute() throw (invalid_argument);
};


//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
/**
* Classe CmdNewTermo.
* Essa classe realiza o servico de criacao de termo.
*/
class CmdNewTermo: public CmdBase{
private:
	Email user;
	Nome vocab;
	Termo termo;

public:
	CmdNewTermo(Termo, Nome, Email);
	void execute() throw (invalid_argument);
};

//--------------------------------------------------------------------------- 
/**
* Classe CmdEditTermo.
* Essa classe realiza o servico de edicao de termo.
*/
class CmdEditTermo: public CmdBase{
private:
	Email user;
	Nome vocab;
	Termo termo;

public:
	CmdEditTermo(Termo, Nome, Email);
	void execute() throw (invalid_argument);
};

//--------------------------------------------------------------------------- 
/**
* Classe CmdDeleteTermo.
* Essa classe realiza o servico de exclusao de termo.
*/
class CmdDeleteTermo: public CmdBase{
private:
	Email user;
	Nome vocab;
	Nome termo;

public:
	CmdDeleteTermo(Nome, Nome, Email);
	void execute() throw (invalid_argument);
};


#endif // COMANDOS_H_INCLUDED