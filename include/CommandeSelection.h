#pragma once
#include "CommandeElementaire.h"
#include "Configuration.h"
#include <string>
#include "The.h"

class CommandeSelection : public CommandeElementaire {
public:
    CommandeSelection(Configuration& configuration, const The* the);
    bool executer() override;
    void undo() override;
    void redo() override;
    std::string decrire() const override;
private:
    Configuration& configuration_;
    const The* the_;
    const The* ancienThe_ = nullptr;
};