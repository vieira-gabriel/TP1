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
* Classe CmdBase.
* Essa classe abstrata fornece a estrutura de dados base para as demais classes de comando.
*/
class CmdBase: public InterCMD{
protected:
	static list<Leitor>			userLer;
	static list<Desenvolvedor>	userDev;
	static list<Administrador>	userAdm;
	static list<Leitor>::iterator			itLer;
	static list<Desenvolvedor>::iterator	itDev;
	static list<Administrador>::iterator	itAdm;
};

// definicao das variaveis estaticas de CmdBase.
list<Leitor>			CmdBase::userLer;
list<Desenvolvedor>		CmdBase::userDev;
list<Administrador>		CmdBase::userAdm;
list<Leitor>::iterator			CmdBase::itLer;
list<Desenvolvedor>::iterator	CmdBase::itDev;
list<Administrador>::iterator	CmdBase::itAdm;

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



#endif // COMANDOS_H_INCLUDED