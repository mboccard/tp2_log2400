#pragma once

class Besoins {
public:
    Besoins(double eau, double the) : eau_(eau), the_(the) {};
    Besoins ajouter(const Besoins& autre) const;
    double getEau() const;
    double getThe() const;
private:
    double eau_;
    double the_;
};
