#pragma once

#include "AlerteTexte.h"
 
class NotificationDistante : public AlerteTexte {
protected:
    std::string getEtiquette() const override;
};