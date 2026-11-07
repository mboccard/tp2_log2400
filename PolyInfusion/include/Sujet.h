#pragma once

#include <vector>

class Reserve;
class ObservateurReserve;

class Sujet {
public:
    virtual ~Sujet() = default;
    void attacher(ObservateurReserve* observateur);
    void detacher(ObservateurReserve* observateur);

protected:
    void notifierFaible(const Reserve& reserve) const;
    void notifierRetablie(const Reserve& reserve) const;

private:
    std::vector<ObservateurReserve*> observateurs_;
};
