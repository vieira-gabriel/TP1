#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

//--------------------------------------------------------------------------- 
//Classe Nome.

class Nome{ //Essa classe servirá tanto para o primeiro nome quanto para o sobrenome
private:
	string nome;
	void validar(string) throw (invalid_argument);
public:
	Nome() {};
	void setNome(string) throw (invalid_argument);
	string getNome();
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
	string getTelefone();
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
	string getEndereco();
};

//--------------------------------------------------------------------------- 
//Classe Data.

class Data{
private:
	int dia, mes, ano;
	void validar(int, int, int) throw (invalid_argument);
public:
	Data() {};
	void setData(int, int, int) throw (invalid_argument);
	void getData(int*);	
};

//--------------------------------------------------------------------------- 
//Classe Email.

class Email{
private:
	string email;
	void validar(string) throw (invalid_argument);
public:
	Email() {};
	void setEmail(string) throw (invalid_argument);
	string getEmail();	
};

//--------------------------------------------------------------------------- 
//Classe Senha.

class Senha{
private:
	string senha;
	void validar(string, string) throw (invalid_argument);
public:
	Senha() {};
	void setSenha(string, string) throw (invalid_argument);
	string getSenha();
};

//--------------------------------------------------------------------------- 
//Classe Texto.

class Texto{
private:
	string texto;
	void validar(string) throw (invalid_argument);
public:
	Texto() {};
	void setTexto(string) throw (invalid_argument);
	string getTexto();	
};

//--------------------------------------------------------------------------- 
//Classe Idioma.

class Idioma{
private:
	string idioma;
	void validar(string) throw (invalid_argument);
public:
	Idioma() {};
	void setIdioma(string) throw (invalid_argument);
	string getIdioma();
	
};

//--------------------------------------------------------------------------- 
//Classe Termo.

class Classe_de_termo{
private:
	string classe;
	void validar(string) throw (invalid_argument);

public:
	Classe_de_termo() {};
	void setClasse(string) throw (invalid_argument);
	string getClasse();	
};

#endif // DOMINIOS_H_INCLUDED