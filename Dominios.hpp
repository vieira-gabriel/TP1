#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <stdio.h>

using namespace std;

class Nome{ //Essa classe servirá tanto para o primeiro nome quanto para o sobrenome
private:
	string nome;
	void validar(string) throw (invalid_argument);
public:
	Nome();
	void setNome(string nome) throw (invalid_argument);
	void callNome(Nome objeto);
};

class Telefone{
private:
	int telefone[13]; //O numero será armazenado no formato AANNNNNNNNN, mas será aprensentado no fomrato AA NNNNN-NNNN
	void validar(int) throw (invalid_argument);
public:
	Telefone();
	void setTelefone(int telefone[]) throw (invalid_argument);
	void callTelefone(Telefone objeto);
};

class Edereco{
private:
	string endereco;
	void validar(string) throw (invalid_argument);
public:
	Edereco();
	void setEndereco(string endereco) throw (invalid_argument);
	void callEndereco(Endereco objeto);
};

class Data{
private:
	int dia, mes, ano;
	void validar(int, int, int) throw (invalid_argument);
public:
	Data();
	void setData(int dia, int mes, int ano) throw (invalid_argument);
	void callData(Data objeto);	
};

class Email{
private:
	string email;
	void validar(string) throw (invalid_argument);
public:
	Email();
	void setEmail(string email) throw (invalid_argument);
	void callEmail(Email objeto);	
};

class Senha{
private:
	string senha;
	void validar(string) throw (invalid_argument);
public:
	Senha();
	void setSenha(string senha) throw (invalid_argument);
	void callSenha(Senha objeto);
};

class Texto{
private:
	string texto;
	void validar(string, Nome) throw (invalid_argument);
public:
	Texto();
	void setTexto(string texto) throw (invalid_argument);
	void callTexto(Texto objeto);	
};

class Idioma{
private:
	char idioma[3];
	void validar(int) throw (invalid_argument);
public:
	Idioma();
	void setIdioma(char idioma[]) throw (invalid_argument);
	void callIdioma(Idioma objeto);
	
};

#endif // DOMINIOS_H_INCLUDED