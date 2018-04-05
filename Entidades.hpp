#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominios.hpp"


class Leitor{ //Dados requeridos para leitor (usuário mais básico)
private:
	Nome nome, sobrenome;
	Email email;
	Senha senha;

	void validarNome(Nome);	//Essa classe também vale para validar o sobrenome
	void validarEmail(Email);
	void validarSenha(Senha);

public:
	Leitor();

	void setNome(const Nome &nome);	//O argumento que esta sendo passado é uma referência do objeto nome. "const" é para que não seja possível alterar o conteúdo da referência
	Nome getNome() const{
		return nome;
	}

	void setSobrenome(const Nome &sobrenome);
	Nome getSobrenome() const{
		return sobrenome;
	}

	void setEmail(const Email &email);
	Email getEmail() const{
		return email;
	}

	void setSenha(const Senha &senha);	
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

class Data{  //data de criação das entidades abaixo
private:
	Data nascimento;

	void validarData(Data);

public:
	Data();

	void setData(const Data &nascimento);
	Data getData() const{
		return nascimento;
	}
};

class Vocabilario : public Data{
private:
	Nome nome;
	Idioma idioma;

	void validarNome(Nome);
	void validarIdioma(Idioma);

public:
	Vocabilario();

	void setData(const Data &nascimento);
	Data getData() const{
		return nascimento;
	}

	void setData(const Data &nascimento);
	Data getData() const{
		return nascimento;
	}

};

class Termo : public Data{
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

class Definição : public Data{
private:	
	Texto texto;

	void validarTexto(Texto);

public:
	Definição();

	void setTexto(const Texto &texto);
	Texto getTexto() const{
		return texto;
	}
};

#endif // ENTIDADES_H_INCLUDED