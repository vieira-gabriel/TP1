#ifndef TESTES_DOMINIOS_HPP_INCLUDED
#define TESTES_DOMINIOS_HPP_INCLUDED
#include "Dominios.hpp"
#include<iostream>
#include<string>


using namespace std;


/*------------------------------------------Teste de Unidade Nome----------------------------------------------------------------*/
class TUNome
{

private:


    Nome *nome;

    int resultado;

    void setUp();
    void tearDown();
    void nomeValido();
    void nomeMinusculo();
    void nomeComDigito();
    void nomeDuasMaiusculas();
    void nomeGrande();

public:

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    void run();

};
/*------------------------------------------------- Teste de Unidade Email------------------------------------------------------*/
class TUEmail
{

private:


    Email *email;

    int resultado;

    void setUp();
    void tearDown();
//caso de Sucesso
    void emailValido();
//casos de Falha
    void emailSemArroba();
    void emailPontoLocal();
    void emailDomNumerico();
    void emailHifenDominio();

public:

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    void run();

};
/*------------------------------------------------------------Teste de Unidade Data---------------------------------------------*/
class TUData
{
private:

    Data *data;

    int resultado;

    void setUp();
    void tearDown();
//caso de sucesso
    void dataValida();
//casos de falha
    void dataComChar();
    void dataDiaInval();
    void dataMesInval();
    void dataAnoInval();
    void dataNaoBisex();
    void dataSemBarra();

public:

    const static int SUCESSO = 0;
    const static int FALHA = -1;

    void run();
};

/*-------------------------------------------------------Teste de unidade Senha-------------------------------------------------*/

class TUSenha
{
private:

    Senha *senha;

    int resultado;

    void setUp();
    void tearDown();
//caso de sucesso
    void SenhaValida();
//casos de falha
    void senhaSemMai();
    void senhaSemMin();
    void senhaSemDig();
    void senhaCharEsp();
    void senhaGrande();

public:

    const static int SUCESSO = 0;
    const static int FALHA = -1;

    void run();
};


/*------------------------------------------------------Teste de unidade Termo-------------------------------------------------*/
class TUClasseDeTermo
{
private:

    ClasseDeTermo *classe;

    int resultado;

    void setUp();
    void tearDown();
//caso de sucesso
    void classeValida();
//casos de falha
   void classeInexistente();

public:

    const static int SUCESSO = 0;
    const static int FALHA = -1;

    void run();
};
/*--------------------------------------------------TEste Definição-------------------------------------------------------------*/

#endif
