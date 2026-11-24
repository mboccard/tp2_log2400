#include "Configuration.h"

const The* Configuration::getTheCourant() const
{
    return theCourant_;
}

void Configuration::setTheCourant(const The* the)
{
    theCourant_ = the;
}

int Configuration::getNPortions() const
{
    return nPortions_;
}

bool Configuration::setNPortions(int nPortions)
{
    if (nPortions <= 0) {
        return false;
    }
    nPortions_ = nPortions;
    return true;
}
