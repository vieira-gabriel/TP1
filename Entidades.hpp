#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominios.hpp"


class Leitor{ //Dados requeridos para leitor (usuário mais básico)
private:
	Nome nome, sobrenome;
	Email email;
	Senha senha;

	void validarSenha(Senha) throw (invalid_argument);

public:
	Leitor();

	void setNome(const Nome &nome){	//O argumento que esta sendo passado é uma referência do objeto nome. "const" é para que não seja possível alterar o conteúdo da referência
		this->nome = nome;
	}
	Nome getNome() const{
		return nome;
	}

	void setSobrenome(const Nome &sobrenome){
		this->sobrenome = sobrenome;
	}
	Nome getSobrenome() const{
		return sobrenome;
	}

	void setEmail(const Email &email){
		this->email = email;
	}
	Email getEmail() const{
		return email;
	}

	void setSenha(const Senha &senha) throw (invalid_argument);	//definida no arquivo .cpp
	Senha getSenha() const{
		return senha;
	}
};

class Desenvolvedor : public Leitor{
private:
	Data nascimento;

	void validarData(Data);

public:
	Desenvolvedor();

	void setData(const Data &nascimento);
	Data getData() const{
		return nascimento;
	}
	
};

class Administrador : public Desenvolvedor{
public:
	Telefone telefone;
	Endereco endereco;

	void validarTelefone(Telefone);
	void validarEndereco(Endereco);

private:
	Administrador();

	void setTelefone(const Telefone &telefone);
	Telefone getTelefone() const{
		return telefone;
	}

	void setEndereco(const Endereco &endereco);
	Endereco getEndereco() const{
		return endereco;
	}
	
};

class DataCriacao{  //data de criação das entidades abaixo
private:
	Data nascimento;

	void validarDataCriacao(DataCriacao);

public:
	DataCriacao();

	void setDataCriacao(const Data &nascimento);
	Data getDataCriacao() const{
		return nascimento;
	}
};

class Vocabilario : public DataCriacao{
private:
	Nome nome;
	Idioma idioma;

	void validarNome(Nome);
	void validarIdioma(Idioma);

public:
	Vocabilario();

	void setNome(const Nome &nome);
	Nome getNome() const{
		return nome;
	}

	void setIdioma(const Idioma &idioma);
	Idioma getIdioma() const{
		return idioma;
	}

};

class Termo : public DataCriacao{
private:
	Nome nome;
	Classe_de_termo classe;

	void validarNome(Nome);
	void validarClasse(Classe_de_termo);

public:
	Termo();

	void setNome(const Nome &nome);
	Nome getNome() const{
		return nome;
	}

	void setClasse(const Classe_de_termo &classe);
	Classe_de_termo getClasse() const{
		return classe;
	}
};

class Definicao : public DataCriacao{
private:	
	Texto texto;

	void validarTexto(Texto);

public:
	Definicao();

	void setTexto(const Texto &texto);
	Texto getTexto() const{
		return texto;
	}
};

#endif // ENTIDADES_H_INCLUDED