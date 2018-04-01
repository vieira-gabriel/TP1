#include <string>
#include <stdio.h>

class Leitor{ //Dados requeridos para leitor (usuário mais básico)
private:
	string nome, sobrenome, email, senha;

public:
	Leitor();
	void setNome(string nome);
	void setSobrenome(string sobrenome);
	void setEmail(string email);
	void setSenha(string senha);	
};

class Desenvolvedor : public Leitor{
private:
	string nascimento;

public:
	Desenvolvedor();
	void setNascimento(string nascimento);
};

class Administrador : public Desenvolvedor{
public:
	int telefone;
	string endereco;

private:
	Administrador();
	void setTelefone(int telefone);
	void setEndereço(string endereco);
	
};

class Data{  //data de criação das entidades abaixo
private:
	string data;

public:
	Data();
	void setData(string data);
};

class Vocabilario : public Data{
private:
	string nome, idioma;

public:
	Vocabilario();
	void setNome(string nome);
	void setIdioma(string idioma);
};

class Termo : public Data{
private:
	string nome, classe

public:
	Termo();
	void setNome (string nome);
	void setClasse (string classe);
};

class Definição : public Data{
private:
	string texto;
public:
	Definição();
	void setTexto (string texto);	
};