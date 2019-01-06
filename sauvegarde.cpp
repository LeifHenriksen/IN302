#include "sauvegarde.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

  Sauvegarde::Sauvegarde()
  :nom(""),vies(0),score(0),niveau(0),tabBriques(){

  }
  Sauvegarde::Sauvegarde(const std::string nom,unsigned int vies,unsigned int score,unsigned int niveau,const tableauBriques &tabBriques)
  :nom(nom),vies(vies) , score(score),niveau(niveau),tabBriques(tabBriques){

  }
  string Sauvegarde::getNom()
  {
      return nom;
  }
  unsigned int Sauvegarde::getVies()
  {
      return vies;
  }
  unsigned int Sauvegarde::getScore()
  {
      return score;
  }
  unsigned int Sauvegarde::getNiveau()
  {
      return niveau;
  }
  tableauBriques Sauvegarde::getTabBriques()
  {
      return tabBriques;
  }
  void Sauvegarde::setNom(std::string nom)
  {
      this->nom = nom;
  }
  void Sauvegarde::setVies(unsigned int vies)
  {
      this->vies=vies;
  }
  void Sauvegarde::setScore(unsigned int score)
  {
      this->score = score ;
  }
  void Sauvegarde::setNiveau(unsigned int niveau)
  {
      this->niveau = niveau;
  }


  Tabsauv::Tabsauv(std::string namefile):size(0),tabSave(NULL)
  {
    ifstream file(namefile.c_str());
    
    if (file)
    {
        int nb_sauv,y,x,L,l,resistance;
        unsigned int vies,score,niveau,nb_briques;
        char corp;
        int couleur;
        string nom;
        file >> nb_sauv;
        tableauBriques tab(0);
        for (int i=0; i < nb_sauv ; i++)
        {
            file >> nom >> vies >> score >> niveau >> nb_briques ;
            tab = tableauBriques(0);
            for (int j = 0 ; j < nb_briques ; j++)
            {
                do file.get(corp); while (corp == '\n' );
               file >> y >> x >> L >> l >> resistance;
               tab.add(corp,y,x,L,l,resistance);
              
            }
            add(nom,vies,score,niveau,tab);
        }
        file.close();
    }
  }
  void Tabsauv::add(const std::string nom,unsigned int vies,unsigned int score,unsigned int niveau,const tableauBriques &tabBriques)
  {
      Sauvegarde* tmp = new Sauvegarde[size+1];
      for(unsigned int i=0 ; i < size ; i++)
      {
          tmp[i]=tabSave[i];
      }
      if (tabSave != NULL) delete[] tabSave;
      tmp[size] = Sauvegarde(nom,vies,score,niveau,tabBriques);
      size++;
      tabSave=tmp;

  }
  void Tabsauv::del(size_t i)
  {
      if(i< size && i>-1){
      --size;
      
     for(int j=i;j<size;j++)
     {
         tabSave[j]=tabSave[j+1];
     }
      }
     
  }
  void Tabsauv::write(std::string namefile)
  {
      ofstream file(namefile.c_str());
    if(file)
    {

      
      tableauBriques tab;
      Brique b;
      file << size << endl;
      for (unsigned int i = 0; i < size ; i++)
      {
          file << tabSave[i].getNom() << " "<< tabSave[i].getVies() << " "<<tabSave[i].getScore()<<" "<< tabSave[i].getNiveau()<< " "<< tabSave[i].getTabBriques().getTaille()<<endl;
          tab= tabSave[i].getTabBriques();
          for(int j =0;j< tabSave[i].getTabBriques().getTaille() ; j++)
          {
              b=tab.at(j);
              file << b.getCorp() <<" "<<b.getY()<<" "<<b.getX()<<" "<<b.getL()<<" "<<b.getl()<<" "<<b.getResistance()<<endl;
          }
      }
      file.close();
    }
  }
  void Tabsauv::print(Window *w)
  {

  }