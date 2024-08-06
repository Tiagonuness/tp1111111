#ifndef INTERFACES_H
#define INTERFACES_H
#include "Entidades.h"

/// @file Interfaces.h Arquivo contendo as Interfaces entre modulos.

// Declara��es de interfaces da camada de apresenta��o.

/// Interface de Apresentacao para Autenticacao.
class InterfaceAAut { // 190084499
public:
    virtual ~InterfaceAAut() = default;
    virtual bool autenticar() = 0;

};

/// Interface de Apresentacao para Contas.
class InterfaceAConta { // 190084499
public:
    virtual ~InterfaceAConta() = default;
    virtual void criar() = 0;
    virtual void executar() = 0;

};

// Declara��es de interfaces da camada de servi�o.

//---------------------------------------------------------------------------------------------------

/// Interface de Servico para Autenticacao.
class InterfaceSAut { // 190084499
public:
    virtual ~InterfaceSAut() = default;
    virtual bool autenticar(Cpf, Senha) = 0;
};

/// Interface de Servico para Contas.
class InterfaceSConta { // 190084499
public:
    virtual ~InterfaceSConta() = default;
    virtual bool criar(Conta) = 0;
    virtual bool recuperar(Conta*) = 0;
    virtual bool atualizar(Conta) = 0;
    virtual bool excluir(Cpf) = 0;
};

#endif // INTERFACES_H
