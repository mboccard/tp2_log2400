#pragma once

#include <string>
#include "CommandeElementaire.h"
#include "Configuration.h"

class CommandePortions : public CommandeElementaire {
public:
    CommandePortions(Configuration& configuration, int nPortions);
    bool executer() override;
    void undo() override;
    void redo() override;
    std::string decrire() const override;
private:
    Configuration& configuration_;
    int nPortions_;
    int ancienNPortions_ = 0;
};
