#include "Dominios.hpp"
#include<iostream>
#include "TestesDominios.hpp"
#include <iostream>

/*-------------------------------------------- Teste de Unidade Nome -----------------------------------------------------------*/

void TUNome::setUp()
{
    nome = new Nome();
    resultado = SUCESSO;
}

void TUNome::tearDown()
{
    delete nome;
}
// Teste de um nome válido
void TUNome::nomeValido()
{
    try
    {
        nome->setNome("Joao");
        if(nome->getNome()!="Joao")
        {
            resultado = FALHA;
        }
    }
    catch(invalid_argument)
    {
        resultado = FALHA;
    }
}

void TUNome::nomeComDigito()
{
    try
    {
        nome->setNome("matheu2");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUNome::nomeGrande()
{
    try
    {
        nome->setNome("Joao lucas matheus barbosinha picles e azeitona sao nojentos");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUNome::nomeMinusculo()
{
    try
    {
        nome->setNome("matheus");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUNome::nomeDuasMaiusculas()
{
    try
    {
        nome->setNome("MatHeus");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUNome:: run()
{
    cout<<"Teste de unidade Nome: ";
    setUp();
    nomeValido();
    nomeComDigito();
    nomeGrande();
    nomeMinusculo();
    nomeDuasMaiusculas();
    if(resultado == SUCESSO)
    {
        cout<<"BEM SUCEDIDO"<<endl;
    }
    else
    {
        cout<<"FACASSOU"<<endl;
    }
    tearDown();
}

/*-------------------------------------------- Teste de Unidade Email-------------------------------------------------------*/

void TUEmail::setUp()
{
    email = new Email();
    resultado = SUCESSO;
}

void TUEmail::tearDown()
{
    delete email;
}

void TUEmail::emailValido()
{
    try
    {
        email->setEmail("joaolucas.cruz411@gmail");
        if(email->getEmail() != "joaolucas.cruz411@gmail")
        {
            resultado=FALHA;
        }
    }
    catch(invalid_argument)
    {
        resultado=FALHA;
    }
}

void TUEmail::emailDomNumerico()
{
    try
    {
        email->setEmail("barboso@991929");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUEmail::emailHifenDominio()
{
    try
    {
        email->setEmail("joaolucas@-hotmail");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUEmail::emailSemArroba()
{
    try
    {
        email->setEmail("joaolucasyahoo");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUEmail::emailPontoLocal()
{
    try
    {
        email->setEmail(".barbosBarboso@matheus");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUEmail::run()
{
    cout<<"Teste de Unidade Email: ";
    setUp();
    emailValido();
    emailDomNumerico();
    emailHifenDominio();
    emailPontoLocal();
    emailSemArroba();
    if(resultado==SUCESSO)
    {
        cout<<"BEM SUCEDIDO"<<endl;
    }
    else
    {
        cout<<"FRACASSOU"<<endl;
    }
    tearDown();
}
/*-------------------------------------------------------Teste de unidade Data--------------------------------------------------*/

void TUData::setUp()
{
    data = new Data();
    resultado=SUCESSO;
}

void TUData::tearDown()
{
    delete data;
}

void TUData::dataValida()
{
    try
    {
        data->setData("29/02/2016");
        if(data->getData()!="29/02/2016")
        {
            resultado=FALHA;
        }
    }
    catch (invalid_argument)
    {
        resultado=FALHA;
    }

}

void TUData::dataAnoInval()
{
    try
    {
        data->setData("01/01/2100");
        resultado=FALHA;
    }
    catch (invalid_argument)
    {
        return;
    }
}

void TUData::dataMesInval()
{
    try
    {
        data->setData("01/13/2010");
        resultado=FALHA;
    }
    catch (invalid_argument)
    {
        return;
    }
}

void TUData::dataDiaInval()
{
    try
    {
        data->setData("32/01/2010");
        resultado=FALHA;
    }
    catch (invalid_argument)
    {
        return;
    }
}

void TUData::dataNaoBisex()
{
    try
    {
        data->setData("29/02/2009");
        resultado=FALHA;
    }
    catch (invalid_argument)
    {
        return;
    }
}

void TUData::dataComChar()
{
    try
    {
        data->setData("0a/01/2000");
        resultado=FALHA;
    }
    catch (invalid_argument)
    {
        return;
    }
}

void TUData::dataSemBarra()
{
    try
    {
        data->setData("0101210099");
        resultado=FALHA;
    }
    catch (invalid_argument)
    {
        return;
    }
}

void TUData::run()
{
    cout<<"teste de unidade Data: ";
    setUp();
    dataValida();
    dataAnoInval();
    dataMesInval();
    dataComChar();
    dataNaoBisex();
    dataSemBarra();
    if(resultado==SUCESSO)
    {
       cout<<"BEM SUCEDIDO"<<endl;
    }
    else
    {
        cout<<"FRACASSOU"<<endl;
    }
    tearDown();
}
/*-------------------------------------------------------Teste de Unidade de Senha----------------------------------------------*/

void TUSenha::setUp()
{
    senha = new Senha();
    resultado = SUCESSO;
}

void TUSenha::tearDown()
{
    delete senha;
}

void TUSenha::SenhaValida()
{
    try
    {
        senha->setSenha("Piccolo9");
        if(senha->getSenha() != "Piccolo9")
        {
            resultado=FALHA;
        }
    }
    catch(invalid_argument)
    {
        resultado=FALHA;
    }
}

void TUSenha::senhaSemMai()
{
    try
    {
        senha->setSenha("piccolo9");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUSenha::senhaSemMin()
{
    try
    {
        senha->setSenha("PICCOLO9");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUSenha::senhaSemDig()
{
    try
    {
        senha->setSenha("piccoloo");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUSenha::senhaCharEsp()
{
    try
    {
        senha->setSenha("piccolo*");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUSenha::senhaGrande()
{
    try
    {
        senha->setSenha("piccoloooooooooo");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUSenha::run()
{
    cout<<"teste de unidade Senha: ";
    setUp();
    SenhaValida();
    senhaSemMai();
    senhaSemMin();
    senhaSemDig();
    senhaCharEsp();
    senhaGrande();
    if(resultado==SUCESSO)
    {
        cout<<"BEM SUCEDIDO"<<endl;
    }
    else
    {
        cout<<"FRACASSOU"<<endl;
    }
}
/*-----------------------------------------------------Testes Classe de Termo---------------------------------------------------*/

void TUClasseDeTermo::setUp()
{
    classe = new ClasseDeTermo();
    resultado = SUCESSO;
}

void TUClasseDeTermo::tearDown()
{
    delete classe;
}

void TUClasseDeTermo::classeValida()
{
    try
    {
        classe->setClasse("PT");
        if(classe->getClasse() != "PT")
        {
            resultado = FALHA;
        }
    }
    catch(invalid_argument)
    {
        resultado=FALHA;
    }
}

void TUClasseDeTermo::classeInexistente()
{
    try
    {
        classe->setClasse("naoEX");
        resultado=FALHA;
    }
    catch(invalid_argument)
    {
        return;
    }
}

void TUClasseDeTermo::run()
{
    cout<<"Teste de unidade CasseDeTermo: ";
    setUp();
    classeValida();
    classeInexistente();
    if(resultado==SUCESSO)
    {
        cout<<"BEM SUCEDIDO"<< endl;
    }
    else
    {
        cout<<"FRACASSOU"<<endl;
    }
}


