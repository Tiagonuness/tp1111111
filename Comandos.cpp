#include "Comandos.h"
#include "Camada de Servi�o/Banco de Dados/ConexaoBD.h"
#include "Camada de Servi�o/ControladorasServico.h"

void ComandoIAContaCriar::executar() {
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;

    string cpfValue;
    string nomeValue;
    string senhaValue;

    cout << "--- Criacao de Conta ---" << endl;
    cout << "Digite o CPF: ";
    cin >> cpfValue;
    cout << "Digite seu Nome: ";
    cin >> nomeValue;
    cout << "Digite sua senha: ";
    cin >> senhaValue;

    try {
        cpf.setValor(cpfValue);
        nome.setValor(nomeValue);
        senha.setValor(senhaValue);

        conta.setCpf(cpf);
        conta.setNome(nome);
        conta.setSenha(senha);

        CntrlSConta cntrlSConta;
        if (cntrlSConta.criar(conta)) {
            cout << "Sucesso na criacao da Conta." << endl;
        } else {
            cout << "Falha na criacao da conta." << endl;
        }
    } catch (const invalid_argument& e) {
        cout << "Erro na criacao da conta: " << e.what() << endl;
    } catch (const EErroPersistencia& e) {
        cout << "Erro de persist�ncia: " << e.what() << endl;
    }
};

void ComandoIAContaAtualizar::atualizar() {
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;

    string cpfValue;
    string nomeValue;
    string senhaValue;

    cout << "--- Atualizacao de Conta ---" << endl;
    cout << "Digite o CPF: ";
    cin >> cpfValue;
    cout << "Digite o Nome que deseja Atualizar: ";
    cin >> nomeValue;
    cout << "Digite a senha que deseja Atualizar: ";
    cin >> senhaValue;

    try {
        cpf.setValor(cpfValue);
        nome.setValor(nomeValue);
        senha.setValor(senhaValue);

        conta.setCpf(cpf);
        conta.setNome(nome);
        conta.setSenha(senha);

        CntrlSConta cntrlSConta;
        if (cntrlSConta.atualizar(conta)) {
            cout << "Sucesso na atualizacao da Conta." << endl;
        } else {
            cout << "Falha na atualizacao da conta." << endl;
        }
    } catch (const invalid_argument& e) {
        cout << "Erro na atualizacao da conta: " << e.what() << endl;
    } catch (const EErroPersistencia& e) {
        cout << "Erro de persist�ncia: " << e.what() << endl;
    }
}

void ComandoIAContaAtualizar::excluir() {
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;

    string cpfValue;
    string nomeValue;
    string senhaValue;

    cout << "--- Excluir de Conta ---" << endl;
    cout << "Digite o CPF: ";
    cin >> cpfValue;
    cout << "Digite o Nome: ";
    cin >> nomeValue;
    cout << "Digite a senha: ";
    cin >> senhaValue;

    try {
        cpf.setValor(cpfValue);
        nome.setValor(nomeValue);
        senha.setValor(senhaValue);

        conta.setCpf(cpf);
        conta.setNome(nome);
        conta.setSenha(senha);

        CntrlSConta cntrlSConta;
        if (cntrlSConta.excluir(conta)) {
            cout << "Sucesso na atualizacao da Conta." << endl;
        } else {
            cout << "Falha na atualizacao da conta." << endl;
        }
    } catch (const invalid_argument& e) {
        cout << "Erro na atualizacao da conta: " << e.what() << endl;
    } catch (const EErroPersistencia& e) {
        cout << "Erro de persist�ncia: " << e.what() << endl;
    }
}

void ComandoIAContaListar::executar() {
    try {
        CntrlSConta cntrlSConta;
        vector<Conta> contas = cntrlSConta.listarTodasContas();

        // Verifica se h� contas para mostrar
        if (contas.empty()) {
            cout << "Nenhuma conta encontrada." << endl;
            return;
        }

        // Imprime os dados de forma bonita
        cout << "--- Listagem de Contas ---" << endl;
        cout << "-----------------------------------" << endl;
        cout << "| CPF                | Nome          | Senha         |" << endl;
        cout << "-----------------------------------" << endl;

        for (const auto& conta : contas) {
            cout << "| " << conta.getCpf().getValor()
                 << " | " << conta.getNome().getValor()
                 << " | " << conta.getSenha().getValor()
                 << " |" << endl;
        }

        cout << "-----------------------------------" << endl;
    } catch (const EErroPersistencia& e) {
        cout << "Erro ao listar contas: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Erro inesperado: " << e.what() << endl;
    }
}

