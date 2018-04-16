#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>

#define FALHA = 0;
#define SUCESSO = 1;

class Testes{
private:

	int resultado_teste;

	void Criar();
	void Destruir();
	void FoiArmazenado();
public:
	Testes();
	void run();
	
};

class TesteNome : public Testes{	//Teste valido para sobrenome
private:
	Nome *nome;

public:
	TesteNome();
	
};

class TesteTelefone : public Testes{
private:
	Telefone *telefone;

public:
	TesteTelefone();
	
};

class TesteEndereco : public Testes{
private:
	Endereco *endereco;

public:
	TesteEndereco();
	
};

class TesteEndereco : public Testes{
private:
	Endereco *endereco;

public:
	TesteEndereco();
	
};

class TesteData : public Testes{
private:
	Data *data;

public:
	TesteData();
	
};

class TesteEmail : public Testes{
private:
	Email *email;

public:
	TesteEmail();
	
};

class TesteSenha : public Testes{
private:
	Senha *senha;

public:
	TesteSenha();
	
};

class TesteTexto : public Testes{
private:
	Texto *texto;

public:
	TesteTexto();
	
};

class TesteIdioma : public Testes{
private:
	Idioma *idioma;

public:
	TesteIdioma();
	
};

class TesteClasse_de_termo : public Testes{
private:
	Classe_de_termo *classe;

public:
	TesteClasse_de_termo();
	
};

#endif // TESTES_H_INCLUDED