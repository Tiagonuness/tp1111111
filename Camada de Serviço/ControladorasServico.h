#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED
#include "../Interfaces.h"

class CntrlSConta : public InterfaceSConta {
public:
    bool criar(Conta) override;
    bool recuperar(Conta*) override;
    bool atualizar(Conta) override;
    bool excluir(Cpf) override;
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
