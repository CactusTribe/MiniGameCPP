#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include "JoueurType.h"

class Joueur{
public:
  Joueur(std::string name, JoueurType type);
  ~Joueur();

  std::string getName();
  JoueurType getType();

private:
  std::string m_name;
  JoueurType m_type;

friend std::ostream& operator<<(std::ostream& out, const Joueur& j);
};

#endif
