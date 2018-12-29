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
#include "save.h"



Save::Save(Window uneWindow, tableauBriques unTab, joueur unJoueur, Bille uneBille, options desOptions, platf unePlatf, highScore unHighScore, std::String nom): maWindow(uneWindow), monTabBriques(unTab), monJoueur(unJoueur), maBille(uneBille), mesOptions(desOptions), maPlateforme(unePlatf), monHighScore(unHighScore), monNom(nom){
}


Window Save::getWindow() const{
    return(maWindow);
}
tableauBriques Save::getTabBriques() const{
    return(monTabBriques);
}
joueur Save::getJoueur() const{
    return(monJoueur);
}
Bille Save::getBille() const{
    return(maBille);
}
options Save::getOptions() const{
    return(mesOptions);
}
platf Save::getPlateforme() const{
    return(maPlateforme);
}
highscore Save::getHighScore() const{
    return(monHighScore);
}
std::string Save::getNom() const{
    return(monNom);
}



void Save::setWindow(Window uneWindow){
    maWindow=uneWindow;
}
void Save::setTab(tableauBriques unTab){
    monTabBriques=unTab;
}
void Save::Joueur(joueur unJoueur){
    monJoueur=unJoueur;
}
void Save::setBille(Bille uneBille){
    maBille=uneBille;
}
void Save::setOptions(options desOptions){
    mesOptions=desOptions;
}
void Save::setPlatf(platf unePlateforme){
    maPlateforme=unePlateforme;
}
void Save::setHighScore(highScore unHighScore){
    monHighScore=unHighScore;
}
void Save::setNom(std::string nom){
    monNom=nom;
}



/*void Save::saveFile(){
    
}*/








