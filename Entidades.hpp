#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include <stdexcept>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdbool.h>

#include "Dominios.cpp"

//--------------------------------------------------------------------------- 
/**
* Classe Leitor.
* Essa classe cria a entidade Leitor.
*/

class Leitor{ //Dados requeridos para leitor (usuário mais básico)
private:
	Nome nome, sobrenome;
	Email email;
	Senha senha;

public:
	Leitor() {};

	void setNome(const Nome& nome){
		this->nome = nome;
	}
	Nome getNome() const{
		return nome;
	}

	void setSobrenome(const Nome& sobrenome){
		this->sobrenome = sobrenome;
	}
	Nome getSobrenome() const{
		return sobrenome;
	}

	void setEmail(const Email& email){
		this->email = email;
	}
	Email getEmail() const{
		return email;
	}

	void setSenha(const Senha& senha){
		this->senha = senha; 
	}
	void setSenha(string senha){
		this->senha.setSenha(senha, nome.getNome());
	}
	Senha getSenha() const{
		return senha;
	}
};

//--------------------------------------------------------------------------- 
/**
* Classe Desenvolvedor.
* Essa classe cria a entidade Desenvolvedor, que recebe caracteristicas de Leitor.
*/

class Desenvolvedor : public Leitor{
private:
	Data nascimento;

public:
	Desenvolvedor() {};

	void setData(const Data& nascimento){
		this->nascimento = nascimento;
	}
	Data getData() const{
		return nascimento;
	}
};

//--------------------------------------------------------------------------- 
/**
* Classe Administrador.
* Essa classe cria a entidade Administrador, que recebe caracteristicas de Desenvolvedor.
*/

class Administrador : public Desenvolvedor{
private:
	Telefone telefone;
	Endereco endereco;

public:
	Administrador() {};

	void setTelefone(const Telefone& telefone){
		this->telefone = telefone;
	}
	Telefone getTelefone() const{
		return telefone;
	}

	void setEndereco(const Endereco& endereco){
		this->endereco = endereco;
	}
	Endereco getEndereco() const{
		return endereco;
	}
};

//--------------------------------------------------------------------------- 
/**
* Classe Data de Criação.
* Essa classe cria a entidade Data de Criação.
*/

class DataCriacao{  //data de criação das entidades abaixo 
private: 
	Data criacao; 

public: 
	DataCriacao() {}; 

	void setDataCriacao(const Data& criacao){
		this->criacao = criacao;
	} 
	Data getDataCriacao() const{
		return criacao;
	}
}; 

//--------------------------------------------------------------------------- 
/**
* Classe Vocabulário Controlado.
* Essa classe cria a entidade Vocabulário Controlado, que recebe caracteristicas de DataCriacao.
*/

class Vocabulario_controlado : public DataCriacao{
private:
	Nome nome;
	Idioma idioma;

public:
	Vocabulario_controlado() {};

	void setNome(const Nome& nome){
		this->nome = nome;
	}
	Nome getNome() const{
		return nome;
	}

	void setIdioma(const Idioma& idioma){
		this->idioma = idioma;
	}
	Idioma getIdioma() const{
		return idioma;
	}
};

//--------------------------------------------------------------------------- 
/**
* Classe Termo.
* Essa classe cria a entidade Termo, que recebe caracteristicas de DataCriacao.
*/

class Termo : public DataCriacao{
private:
	Nome nome;
	Classe_de_termo classe;

public:
	Termo() {};

	void setNome(const Nome& nome){
		this->nome = nome;
	}
	Nome getNome() const{
		return nome;
	}

	void setClasse(const Classe_de_termo& classe){
		this->classe = classe;
	}
	Classe_de_termo getClasse() const{
		return classe;
	}
};

//--------------------------------------------------------------------------- 
/**
* Classe Definição.
* Essa classe cria a entidade Definição, que recebe caracteristicas de DataCriacao.
*/

class Definicao : public DataCriacao{
private:	
	Texto texto;

public:
	Definicao() {};

	void setTexto(const Texto& texto){
		this->texto = texto;
	}
	Texto getTexto() const{
		return texto;
	}
};

#endif // ENTIDADES_H_INCLUDED