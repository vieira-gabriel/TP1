#include <string>
#include <stdio.h>

class Leitor{ //Dados requeridos para leitor (usuário mais básico)
private:
	string nome;
	string sobrenome;
	string email;
	string senha;

public:
	Leitor();
	void setNome(string nome);
	void setSobrenome(string sobrenome);
	void setEmail(string email);
	void setSenha(string senha);	
};

class Desenvolvedor{
private:
	string nascimento;

public:
	Desenvolvedor();
	void setNascimento(string nascimento);
}

class Administrador{
public:
	int telefone;
	string endereco;
private:
	Administrador();
	
};