#ifndef SAUVEGARDE_H_
#define SAUVEGARDE_H_
#include "tableauBriques.h"
#include <string>
#include "window.h"

class Sauvegarde
{
private:
  std::string nom;
  unsigned int vies;
  unsigned int score;
  tableauBriques tabBriques;
  unsigned int niveau;
public:
  Sauvegarde();
  Sauvegarde(const std::string nom,unsigned int vies,unsigned int score,unsigned int niveau,const tableauBriques &tabBriques);
  std::string getNom();
  unsigned int getVies();
  unsigned int getScore();
  unsigned int getNiveau();
  tableauBriques getTabBriques();
  void setNom(std::string nom);
  void setVies(unsigned int vies);
  void setScore(unsigned int score);
  void setNiveau(unsigned int niveau);

};
class Tabsauv
{
private:
  Sauvegarde *tabSave;
  unsigned int size;
public:
  Tabsauv(std::string namefile);
  void add(const std::string nom,unsigned int vies,unsigned int score,unsigned int niveau,const tableauBriques &tabBriques);
  void del(size_t i);
  void write(std::string namefile);
  void print(Window *w);

};




#endif
