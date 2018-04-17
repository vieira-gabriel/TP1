#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>

class Testes{
private:

public:
	int resultado_teste;

	void iniciar();
	
	static const int SUCESSO = 	0;
	static const int FALHA = 	1;
};

//--------------------------------------------------------------------------- 
//Teste Classe Nome.

class Teste_Nome : private Testes{	//Teste valido para sobrenome
private:
	Nome nome;

	// Casos de sucesso.
	void nomeValido();
	// Casos de falha.
	void nomeVazio();
	void nomeGrande();
	void nomeIniciaMinusculo();
	void nomeComNumero();
	void nomeNaoAlfanum();

public:
	void run();
};

//--------------------------------------------------------------------------- 
//Teste Classe Telefone.

class Teste_Telefone : private Testes{
private:
	Telefone telefone;

	// Casos de sucesso.
	void telefoneValido();
	// Casos de falha.
	void telefonePequeno();
	void telefoneGrande();
	void telefoneAlfa();
	void telefoneNaoAlfanum();

public:
	void run();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Endereco.

class Teste_Endereco : private Testes{
private:
	Endereco endereco;

	// Casos de sucesso.
	void enderecoValido();
	// Casos de falha.
	void enderecoVazio();
	void enderecoGrande();
	void enderecoIniciaEspaco();
	void enderecoTerminaEspaco();
	void enderecoEspacoSeguido();
	void enderecoNum();
	void enderecoNaoAlfanum();

public:
	void run();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Data.

class Teste_Data : public Testes{
private:
	Data data;

	// Casos de sucesso.
	void dataValido();
	void dataBissexto();
	// Casos de falha.
	void dataAnoPequeno();
	void dataAnoGrande();
	void dataMesPequeno();
	void dataMesGrande();
	void dataDiaPequeno();
	void dataDiaGrande();
	void dataNaoBissexto();

public:
	void run();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Email.

class Teste_Email : public Testes{
private:
	Email email;

	// Caso de sucesso
	void emailValido();
	// Caso de Falha
	void emailPontoNoComeco();
	void emailPontoNoFinal();
	void emailCaractereInvalido();
	void emailDominioHifem();
	void emailDominioInvalido();
	void emailDominioSoDigito();

public:
	void run();
	
};
/*
//--------------------------------------------------------------------------- 
//Teste Classe Senha.

class TesteSenha : public Testes{
private:
	Senha *senha;

public:
	TesteSenha();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Texto.

class TesteTexto : public Testes{
private:
	Texto *texto;

public:
	TesteTexto();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Idioma.

class TesteIdioma : public Testes{
private:
	Idioma *idioma;

public:
	TesteIdioma();
	
};

//--------------------------------------------------------------------------- 
//Teste Classe Termo.

class TesteClasse_de_termo : public Testes{
private:
	Classe_de_termo *classe;

public:
	TesteClasse_de_termo();
	
};
*/

#endif // TESTES_H_INCLUDED