#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <stdio.h>

using namespace std;

bool eh_maiusculo(char caractere);
bool eh_minusculo(char caractere);
bool eh_numero(char caractere);
// As três funções acima são para verificar se determinado caractere de uma string é maiúsculo, minúsculo ou numero, respectivamente
// Essas funções usam a tabela ASCII como referência.

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
	int telefone_int; //O numero será armazenado no formato AANNNNNNNNN, mas será aprensentado no fomrato AA NNNNN-NNNN
	char telefone_char[14];
	void validar(char telefone[]) throw (invalid_argument);
public:
	Telefone();
	void setTelefone(char telefone[]) throw (invalid_argument);
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
	void validar(string) throw (invalid_argument);
public:
	Texto();
	void setTexto(string texto) throw (invalid_argument);
	void callTexto(Texto objeto);	
};

class Idioma{
private:
	char idioma[3];
	void validar(char) throw (invalid_argument);
public:
	Idioma();
	void setIdioma(char idioma[]) throw (invalid_argument);
	void callIdioma(Idioma objeto);
	
};

class Classe_de_termo{
private:
	char classe[2];
	void validar(char) throw (invalid_argument);

public:
	Classe_de_termo();
	void setClasse_de_termo(char classe[]) throw (invalid_argument);
	void callClasse_de_termo(Classe_de_termo objeto);	
};

#endif // DOMINIOS_H_INCLUDED