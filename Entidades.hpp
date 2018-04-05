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
	

public:
	Desenvolvedor();
	
};

class Administrador : public Desenvolvedor{
public:
	

private:
	Administrador();
	
};

class Data{  //data de criação das entidades abaixo
private:
	

public:
	Data();
};

class Vocabilario : public Data{
private:

public:
	Vocabilario();
};

class Termo : public Data{
private:

public:
	Termo();
};

class Definição : public Data{
private:
public:
	Definição();
};

#endif // ENTIDADES_H_INCLUDED