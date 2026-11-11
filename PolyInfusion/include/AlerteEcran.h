#pragma once

#include "AlerteTexte.h"
 
class AlerteEcran : public AlerteTexte {
protected:
    std::string getEtiquette() const override;
};
