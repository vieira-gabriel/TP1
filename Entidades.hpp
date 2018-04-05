

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
	void setNome(Nome nome);
	void setSobrenome(Nome sobrenome);
	void setEmail(Email email);
	void setSenha(Senha senha);	
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