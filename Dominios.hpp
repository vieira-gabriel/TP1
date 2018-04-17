#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>

using namespace std;

//--------------------------------------------------------------------------- 
/**
* Classe Nome.
* Essa classe servirá tanto para o primeiro nome quanto para o sobrenome do usuário. Ela cria um objeto com uma string que armazenará o nome.
*/
class Nome{
private:
	string nome;
	/**
	* Teste para validar a variável de acordo com as expecificações dadas no material base para o trabalho.
	*/
	void validar(string) throw (invalid_argument);
public:
	/**
	* Construtor da classe.
	*/
	Nome() {}

	/**
	* Função para setar nome.
	* Essa função armazena o nome na string nome.
	*/
	void setNome(string) throw (invalid_argument);

	/**
	* Função para retornar nome armazenado.
	*/
	string getNome();
};

//--------------------------------------------------------------------------- 
/**
* Classe Telefone.
* Essa classe cria um objeto que armazena um numero de telefone.
*/

class Telefone{
private:
	string telefone; 

	/**
	* Teste para validar a variável de acordo com as expecificações dadas no material base para o trabalho.
	*/
	void validar(string) throw (invalid_argument);
public:
	/**
	*Construtor da classe.
	*/
	Telefone() {} 

	/**
	* Função para setar telefone.
	* Essa função armazena o telefone em uma string.
	*/
	void setTelefone(string) throw (invalid_argument); 

	/**
	* Função para retornar telefone armazenado.
	*/
	string getTelefone();
};

//--------------------------------------------------------------------------- 
/**
* Classe Endereço.
* Essa classe cria um objeto que armazena o endereço do usuário.
*/

class Endereco{
private:
	string endereco;
	
	/**
	* Teste para validar a variável de acordo com as expecificações dadas no material base para o trabalho.
	*/
	void validar(string) throw (invalid_argument);
public:
	/**
	*Construtor da classe.
	*/
	Endereco() {}

	/**
	* Função para setar endereço.
	* Essa função armazena o endereço em uma string.
	*/
	void setEndereco(string endereco) throw (invalid_argument);
	/**
	* Função para retornar endereço armazenado.
	*/
	string getEndereco();
};

//--------------------------------------------------------------------------- 
/**
* Classe Data.
* Essa classe cria um objeto que armazena uma data.
*/

class Data{
private:
	int dia, mes, ano;
	void validar(int, int, int) throw (invalid_argument);
public:
	static const int JANEIRO = 		1;
	static const int FEVEREIRO = 	2;
	static const int MARCO = 		3;
	static const int ABRIL = 		4;
	static const int MAIO = 		5;
	static const int JUNHO = 		6;
	static const int JULHO = 		7;
	static const int AGOSTO = 		8;
	static const int SETEMBRO = 	9;
	static const int OUTUBRO = 		10;
	static const int NOVEMBRO = 	11;
	static const int DEZEMBRO = 	12;

	/**
	*Construtor da classe.
	*/
	Data() {}

	/**
	* Função para setar data.
	* Essa função armazena dia, mês e ano em variáveis inteiras.
	*/
	void setData(int, int, int) throw (invalid_argument);
	/**
	* Função para retornar dia armazenado.
	*/
	int getDay();
	/**
	* Função para retornar mês armazenado.
	*/
	int getMonth();
	/**
	* Função para retornar ano armazenado.
	*/
	int getYear();	
};

//--------------------------------------------------------------------------- 
/**
* Classe Email.
* Essa classe cria um objeto que armazena um endereço de email do usuário.
*/

class Email{
private:
	string email;
	
	/**
	* Teste para validar a variável de acordo com as expecificações dadas no material base para o trabalho.
	*/
	void validar(string) throw (invalid_argument);
public:
	/**
	*Construtor da classe.
	*/
	Email() {}
	void setEmail(string) throw (invalid_argument);
	string getEmail();	
};

//--------------------------------------------------------------------------- 
/**
* Classe Telefone.
* Essa classe cria um objeto que armazena uma senha do usuário.
*/

class Senha{
private:
	string senha;
	
	/**
	* Teste para validar a variável de acordo com as expecificações dadas no material base para o trabalho.
	*/
	void validar(string, string) throw (invalid_argument);
public:
	/**
	*Construtor da classe.
	*/
	Senha() {}
	void setSenha(string, string) throw (invalid_argument);
	string getSenha();
};

//--------------------------------------------------------------------------- 
/**
* Classe Texto.
* Essa classe cria um objeto que armazena em uma string um texto de, no máximo, 30 caracteres.
*/

class Texto{
private:
	string texto;
	
	/**
	* Teste para validar a variável de acordo com as expecificações dadas no material base para o trabalho.
	*/
	
	/**
	* Teste para validar a variável de acordo com as expecificações dadas no material base para o trabalho.
	*/
	void validar(string) throw (invalid_argument);
public:
	/**
	*Construtor da classe.
	*/
	Texto() {}

	/**
	* Função para setar texto.
	* Essa função armazena texto em uma string.
	*/
	void setTexto(string) throw (invalid_argument);
	string getTexto();	
};

//--------------------------------------------------------------------------- 
/**
* Classe Telefone.
* Essa classe cria um objeto que armazena um numero de telefone.
*/

class Idioma{
private:
	string idioma;
	
	/**
	* Teste para validar a variável de acordo com as expecificações dadas no material base para o trabalho.
	*/
	void validar(string) throw (invalid_argument);
public:
	/**
	*Construtor da classe.
	*/
	Idioma() {}

	/**
	* Função para setar idioma.
	* Essa função armazena idioma em uma string.
	*/
	void setIdioma(string) throw (invalid_argument);
	/**
	* Função para retornar idioma armazenado.
	*/
	string getIdioma();
	
};

//--------------------------------------------------------------------------- 
/**
* Classe Termo.
* Essa classe cria um objeto que armazena um termo de classe.
*/
class Classe_de_termo{
private:
	string classe;
	
	/**
	* Teste para validar a variável de acordo com as expecificações dadas no material base para o trabalho.
	*/
	void validar(string) throw (invalid_argument);

public:
	/**
	*Construtor da classe.
	*/
	Classe_de_termo() {}

	/**
	* Função para setar classe.
	* Essa função armazena a classe de termo em uma string.
	*/
	void setClasse(string) throw (invalid_argument);
	/**
	* Função para retornar classe de termo armazenado.
	*/
	string getClasse();	
};

#endif // DOMINIOS_H_INCLUDED