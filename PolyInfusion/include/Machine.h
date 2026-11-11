#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "AlerteEcran.h"
#include "Besoins.h"
#include "Chauffage.h"
#include "DistributeurEau.h"
#include "DistributeurThe.h"
#include "FabriqueComposants.h"
#include "Infuseur.h"
#include "NotificationDistante.h"
#include "Reserve.h"
#include "The.h"

class Machine {
public:
    explicit Machine(const FabriqueComposants& modele);

    void selectionner(const std::string& nomThe);
    void infuser();
    void afficherReserves() const;
    void remplirEau(double mL);
    void remplirThe(const std::string& nomThe, double grammes);
    void activerNotificationsDistantes(bool estActif);

private:
    void abonner(Reserve& reserve);
    const The* trouverThe(const std::string& nom) const;
    bool reservesSuffisantes(const Besoins& besoins, const Reserve& reserveThe) const;
    void afficherReserve(const Reserve& reserve) const;
    void afficherAjout(const Reserve& reserve, double quantite) const;
    void afficherErreurInsuffisante(const Reserve& reserve, double quantiteRequise) const;

    AlerteEcran alerteEcran_;
    NotificationDistante notificationDistante_;
    std::unique_ptr<Chauffage> chauffage_;
    std::unique_ptr<DistributeurEau> distributeurEau_;
    std::unique_ptr<DistributeurThe> distributeurThe_;
    Infuseur infuseur_;
    Reserve reserveEau_;
    std::map<std::string, Reserve> reservesThe_;
    std::vector<std::unique_ptr<The>> thes_;
    const The* theCourant_ = nullptr;
};
