#ifndef FORMES_H
#define FORMES_H

#include "../Geometrie/Point2D.h"
#include "../Geometrie/Vecteur2D.h"
#include "../InterfacesGraphiques/InterfaceGraphique.h"
#include "../Sauvegardeur/SauvegardeurTxt.h"
#include <string>

class Forme {
public:
  /// Couleurs disponibles
  class Couleur {
    const char *content;

  public:
    /// liste des couleurs connues
    /// -> le serveur choisi une couleur par défaut si inconnue
    static constexpr const char *BLACK = "black", *BLUE = "blue", *RED = "red",
                                *GREEN = "green", *YELLOW = "yellow",
                                *CYAN = "cyan";
    Couleur(const char *content) : content(content) {}

    /// retourne la couleur choisie à la création de l'objet
    const char *getContent() const { return content; }
  };

public:
  Couleur color;
  /// Une forme est définie par une couleur
  Forme(Couleur color) : color(color){};

  virtual ~Forme() = default;

  /// La translation est une operation de décalage dans le plan. Elle s'applique
  /// sur l'objet implicite.
  /// @param translation Le vecteur de translation
  virtual void translation(const Vecteur2D &translation) = 0;

  /// L'homotetie est une operation de zoom. Elle s'applique sur l'objet
  /// implicite.
  /// @param point_invariant le point sur lequel va se baser l'homotetie
  /// @param rapport le rapport d'homothetie, il va définir le zoom ou le
  /// dézoom.
  virtual void homotetie(const Point2D &point_invariant,
                         const double &rapport) = 0;

  /// La rotation s'applique sur l'objet implicite.
  /// @param point_invariant le point sur lequel va se baser la rotation
  /// @param point_invariant l'angle sur lequel va se baser la rotation
  virtual void rotation(const Point2D &point_invariant,
                        const double &theta) = 0;

  /// retourne l'aire totale de la forme
  virtual double aire() const = 0;

  /**
   * Dessine la forme sur l'interface graphique donnée.
   * @param ig : l'interface graphique
   */
  virtual void dessiner(const InterfaceGraphique &ig) const = 0;

  /**
   * Sauvegarde la forme dans le fichier dont le chemin est donné.
   * @param sauvegardeur : l'instance de sauvegarde
   * @param chemin : le chemin du fichier de sauvegarde, vide si la fonction ne doit pas écrire dans le fichier
   * @return le contenu du fichier de sauvegarde
   */
  virtual const string &sauvegarder(const SauvegardeurTxt &sauvegardeur, const string &chemin) const = 0;

  /// cacalcule l'égalité entre deux forme sans prendre en compte leur couleur
  virtual bool operator==(const Forme &) const = 0;

  /// transformation de la forme en string.
  virtual explicit operator string() const = 0;
};

#endif // !FORMES_H
