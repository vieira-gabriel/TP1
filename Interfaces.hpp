#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include <stdexcept>

using namespace std;

// Declarações adiantadas.

class ILNAutenticacao;
class ILNLeitor;
class ILNDesenvolvedor;
class ILNAdministrador;

// -----------------------------------------------------------------------------------------------------
// Interface entre o ḿódulo e o stub de autenticação.

class ISAutenticacao{
public:
	/// Método por meio do qual é solicitado o serviço.

    virtual void autenticar() throw(runtime_error) = 0;

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    virtual void setCntrLNAutenticacao(ILNAutenticacao *) = 0;

    /// Método destrutor virtual.

    virtual ~ISAutenticacao(){}
};

// -----------------------------------------------------------------------------------------------------
// Declaração de interface para serviço de autenticação na camada de serviço.

class ILNAutenticacao {
public:

    // Método por meio do qual é solicitado o serviço.

    virtual Leitor autenticar(const Email&, const Senha&) throw(runtime_error)= 0;

    // Método destrutor virtual.

    virtual ~ILNAutenticacao(){}
};

// -----------------------------------------------------------------------------------------------------
// Interface entre o ḿódulo e o stub de usuário.

class ISUsuario{
public:

	// Método por meio do qual é solicitado o serviço.

    virtual void executar(const Email&) throw(runtime_error) = 0;

    // Método destrutor virtual.

    virtual ~ISUsuario(){}
};

// -----------------------------------------------------------------------------------------------------
// Interface para leitor.

class ISLeitor:public ISUsuario{
public:

    // Método por meio do qual é estabelecida ligação (link) com a controladora de negócio.

    virtual void setCntrLNLeitor(ILNLeitor *) = 0;

};

// -----------------------------------------------------------------------------------------------------
// Interface para desenvolvedor.

class ISDesenvolvedor:public ISUsuario{
public:

    // Método por meio do qual é estabelecida ligação (link) com a controladora de negócio.

    virtual void setCntrLNDesenvolvedor(ILNDesenvolvedor *) = 0;

};

// -----------------------------------------------------------------------------------------------------
// Interface para Administrador.

class ISAdm:public ISUsuario{
public:

    // Método por meio do qual é estabelecida ligação (link) com a controladora de negócio.

    virtual void setCntrLNAdm(ILNAdm *) = 0;

};

// -----------------------------------------------------------------------------------------------------
// Declaração de interface da camada de negócio (leitor)

class ILNLeitor{

public:

    // Métodos por meio dos quais são solicitados os serviços.

    virtual Leitor EditarUsuário(const Email&, const Senha, const Nome&, const Nome&) throw(runtime_error) = 0;
    virtual void ExcluirConta(const Senha&) throw(runtime_error) = 0;
    virtual Vocabulario_controlado listar(const Matricula&) throw(runtime_error) = 0;
    virtual Termo consultarTermo(const Termo&) throw(runtime_error) = 0;
    virtual Definicao consultarDefinicao (const TErmo&) throw(runtime_error) = 0;


    // Método destrutor virtual.

    virtual ~ILNUsuário(){}
};

// -----------------------------------------------------------------------------------------------------
// Interface entre o ḿódulo e o stub de usuário (desenvolvedor).

class ILNDesenvolvedor:public ILNLeitor{
public:

	// Métodos por meio dos quais são solicitados os serviços.

	virtual Vocabulario_controlado Cadastrar(const Email&, const Nome&, const Nome&, const Vocabulario_controlado&)
	virtual Termo CriarTermo(const Email&, const Nome&, const Nome&) throw(runtime_error) = 0;
	virtual Termo EditarTermo(const Termo&) throw(runtime_error) = 0;
	virtual void ExcluirTermo(const Termo&) throw(runtime_error) = 0;
	virtual Definicao CriarDefinicao(const Email&, const Nome&, const Nome&) throw(runtime_error) = 0;
	virtual Definicao EditarDefinicao(const Definicao&) throw(runtime_error) = 0;
	virtual void ExcluirDefinicao(const Definicao&) throw(runtime_error) = 0;


};
// -----------------------------------------------------------------------------------------------------
// Interface entre o ḿódulo e o stub de usuário (administrador).

class ILNAdministrador:public ILNDesenvolvedor{
public:

	// Métodos por meio dos quais são solicitados os serviços.

	virtual Vocabulario_controlado EdicaoVocab(const Vocabulario_controlado&) throw(runtime_error) = 0;
	virtual Vocabulario_controlado IdiomaVocab(const Vocabulario_controlado&) throw(runtime_error) = 0;
	virtual void ExcluirVocab(const Vocabulario_controlado&) throw(runtime_error) = 0;


};

#endif // INTERFACES_H_INCLUDED