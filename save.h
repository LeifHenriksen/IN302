#ifndef __SAVE_H
#define __SAVE_H
#include "window.h"
#include "briques.h"
#include "tableauBriques.h"
#include "joueur.h"
#include "bille.h"
#include "options.h"
#include "platf.h"
#include "highScore.h"
#include <iostream>
#include <fstream>
#include <string>

class Save{

private:
    
    Window maWindow;
    tableauBriques monTabBriques;
    joueur monJoueur;
    Bille maBille;
    options mesOptions;
    platf maPlateforme;
    highScore monHighScore;
    std::string monNom;
    
public:
    Save(Window uneWindow, tableauBriques unTab, joueur unJoueur, Bille uneBille, options desOptions, platf unePlatf, highScore unHighScore, std::String nom);
    
    Window getWindow() const;
    tableauBriques getTabBriques() const;
    joueur getJoueur() const;
    Bille getBille() const;
    options getOptions() const;
    platf getPlateforme() const;
    highScore getHighScore() const;
    std::string getNom() const;
    
    void setWindow(Window uneWindow);
    void setTab(tableauBriques unTab);
    void setJoueur(joueur unJoueur);
    void setBille(Bille uneBille);
    void setOptions(options desOptions);
    void setPlatf(platf unePlateforme);
    void setHighScore(highScore unHighScore);
    void setNom(std::string nom);
    
    
    //void saveFile();
    
    
};
#endif
