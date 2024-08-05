#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED
#include "Camada de Apresentação/ControladorasApr.h"
#include "Camada de Serviço/Banco de Dados/ConexaoBD.h"

using namespace std;

class ComandoIAConta {
public:
    virtual ~ComandoIAConta() = default;
    virtual void executar() = 0;             // Método por meio do qual é solicitada a execução do comando.
};

class ComandoIAContaCriar : public ComandoIAConta {
private:
    InterfaceSConta* ISConta;
    string cpfValue, nomeValue, senhaValue;
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;
public:
    ComandoIAContaCriar() : ISConta(nullptr) {};
    void executar() override;
};

class ComandoIAContaAtualizar : public ComandoIAConta {
private:
    InterfaceSConta* ISConta;
    string cpfValue, nomeValue, senhaValue;
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;
public:
    ComandoIAContaAtualizar() : ISConta(nullptr) {};
    void executar() override;
};

class ComandoIAContaExcluir : public ComandoIAConta {
private:
    InterfaceSConta* ISConta;
    string cpfValue, nomeValue, senhaValue;
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;
public:
    ComandoIAContaExcluir() : ISConta(nullptr) {};
    void executar() override;
};

class ComandoIAContaListar : public ComandoIAConta {
private:
    InterfaceSConta* ISConta;
    string cpfValue, nomeValue, senhaValue;
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;
public:
    ComandoIAContaListar() : ISConta(nullptr) {};
    void executar() override;  // Implementa o método virtual puro
};


#endif // COMANDOS_H_INCLUDED
