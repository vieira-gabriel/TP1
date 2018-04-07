#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <stdio.h>

using namespace std;

bool eh_maiusculo(char caractere);
bool eh_minusculo(char caractere);
// As três funções acima são para verificar se determinado caractere de uma string é maiúsculo, minúsculo ou numero, respectivamente
// Essas funções usam a tabela ASCII como referência.

//--------------------------------------------------------------------------- 
//Classe Nome.

class Nome{ //Essa classe servirá tanto para o primeiro nome quanto para o sobrenome
private:
	string nome;
	void validar(string) throw (invalid_argument);
public:
	Nome() {};
	void setNome(string) throw (invalid_argument);
	string callNome();
};

//--------------------------------------------------------------------------- 
//Classe Telefone.

class Telefone{
private:
	string telefone; 
	void validar(string) throw (invalid_argument);
public:
	Telefone() {}; 
	void setTelefone(string) throw (invalid_argument); 
	string callTelefone();
};

//--------------------------------------------------------------------------- 
//Classe Endereco.

class Endereco{
private:
	string endereco;
	void validar(string) throw (invalid_argument);
public:
	Endereco() {};
	void setEndereco(string endereco) throw (invalid_argument);
	string callEndereco();
};
/*
//--------------------------------------------------------------------------- 
//Classe Data.

class Data{
private:
	int dia, mes, ano;
	void validar(int, int, int) throw (invalid_argument);
public:
	Data();
	void setData(int dia, int mes, int ano) throw (invalid_argument);
	void callData(Data objeto);	
};

//--------------------------------------------------------------------------- 
//Classe Email.

class Email{
private:
	string email;
	void validar(string) throw (invalid_argument);
public:
	Email();
	void setEmail(string email) throw (invalid_argument);
	void callEmail(Email objeto);	
};

//--------------------------------------------------------------------------- 
//Classe Senha.

class Senha{
private:
	string senha;
	void validar(string) throw (invalid_argument);
public:
	Senha();
	void setSenha(string senha) throw (invalid_argument);
	void callSenha(Senha objeto);
};

//--------------------------------------------------------------------------- 
//Classe Texto.

class Texto{
private:
	string texto;
	void validar(string) throw (invalid_argument);
public:
	Texto();
	void setTexto(string texto) throw (invalid_argument);
	void callTexto(Texto objeto);	
};

//--------------------------------------------------------------------------- 
//Classe Idioma.

class Idioma{
private:
	char idioma[3];
	void validar(char) throw (invalid_argument);
public:
	Idioma();
	void setIdioma(char idioma[]) throw (invalid_argument);
	void callIdioma(Idioma objeto);
	
};

//--------------------------------------------------------------------------- 
//Classe Termo.

class Classe_de_termo{
private:
	char classe[2];
	void validar(char) throw (invalid_argument);

public:
	Classe_de_termo();
	void setClasse_de_termo(char classe[]) throw (invalid_argument);
	void callClasse_de_termo(Classe_de_termo objeto);	
};
*/
#endif // DOMINIOS_H_INCLUDED