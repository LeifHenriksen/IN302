#include "bille.h"
#include "window.h"
#include <stdio.h>
#include <string>
#include "tableauBriques.h"



Bille::Bille() : posX(0), posY(0), directionX(0), directionY(0), icone('o'), maDirection(DROITE){
}

Bille::Bille(int x, int y, int dirX, int dirY, char icon, DirectionDepart dirDebut): posX(x), posY(y), directionX(dirX), directionY(dirY), icone(icon), maDirection(dirDebut){
}


//   Getters
    int Bille::getX() const{
        return posX;
    }
    int Bille::getY() const{
        return posY;
    }
    int Bille::getDirX() const{
        return directionX;
    }
    int Bille::getDirY() const{
        return directionY;
    }
    char Bille::getIcone() const{
        return icone;
    }
    Bille::DirectionDepart Bille::getDirDepart() const{
        return maDirection;
    }

    
    
//    Setters
    void Bille::setX(int x) {
        posX=x;
    }
    void Bille::setY(int y){
        posY=y;
    }
    void Bille::setDirX(int dirX){
        directionX=dirX;
    }
    void Bille::setDirY(int dirY){
        directionY=dirY;
    }
    void Bille::setIcone(char icon){
        icone=icon;
    }
    void Bille::setDirDepart(DirectionDepart dir){
        maDirection=dir;
    }
    
    
    
    
    void Bille::depart(){
        this->setDirY(-1);
        if (maDirection==Bille::GAUCHE){
            this->setDirX(-1);
        }
        if (maDirection==Bille::DROITE){
            this->setDirX(1);
        }
    }
    
    void Bille::avancer(){
        posX=posX+directionX;
        posY=posY+directionY;
    }
    
    void Bille::changerTrajectoire(int angle){
        if (angle==0){
            directionY=(-1)*(this->getDirY());
        }
        if (angle==90){
            directionX=(-1)*(this->getDirX());
        }
        if (angle==45){
            directionY=(-1)*(this->getDirY());
            directionX=(-1)*(this->getDirX());
        }
    }
    
    void Bille::contactBords(int tailleX, int tailleY){
        if ((posX+directionX==tailleX)||(posX+directionX<0)){
            (this->changerTrajectoire(90));
        }
        if ((posY+directionY==tailleY)||(posY+directionY<0)){
            (this->changerTrajectoire(0));
        }
    }
    
    void Bille::contactRaquette(int debutRaquette, int finRaquette, int yRaquette){
        if((posX+directionX<=finRaquette && posX+directionX>=debutRaquette)&&(posY+directionY==yRaquette)){
            this->changerTrajectoire(0);
        }
    }
    
    bool Bille::coinBrique(int x, int y, Brique uneBrique)const{     // renvoie ((x,y) est une case touchant un coin de brique)
        return(((x==uneBrique.getX()-1 || x==uneBrique.getX()+uneBrique.getl()) && y>=uneBrique.getY() && y<uneBrique.getY()+uneBrique.getL()) || ((y==uneBrique.getY()-1 || y==uneBrique.getY()+uneBrique.getL()) && x>=uneBrique.getX() && x<uneBrique.getX()+uneBrique.getl()));
    }
    
    bool Bille::billeDansBrique(Brique uneBrique) const{    // renvoie (bille sera dans brique)
        return(((posX+directionX>=uneBrique.getX() && posX+directionX<uneBrique.getX()+uneBrique.getl()) && (posY+directionY>=uneBrique.getY() && posY+directionY<uneBrique.getY()+uneBrique.getL())));
    }
    
    void Bille::contactCoin(tableauBriques &tabBriques){
        int nbrBriques=tabBriques.getTaille();
        for (int i=0; i<nbrBriques;i++){
            if (coinBrique(posX, posY, tabBriques.at(i)) && coinBrique(posX+directionX, posY+directionY, tabBriques.at(i))){
                tabBriques.perteResistance(i);
                if((posY==tabBriques.at(i).getY()-1 || posY==tabBriques.at(i).getY()+tabBriques.at(i).getL()) && posX>=tabBriques.at(i).getX() && posX<tabBriques.at(i).getX()+tabBriques.at(i).getl()){
                    this->changerTrajectoire(0);
                }
                else if((posX==tabBriques.at(i).getX()-1 || posX==tabBriques.at(i).getX()+tabBriques.at(i).getl()) && posY>=tabBriques.at(i).getY() && posY<tabBriques.at(i).getX()+tabBriques.at(i).getL()){
                    this->changerTrajectoire(90);
                }
            }
        }
    }
    
    void Bille::contactBrique(tableauBriques &tabBriques){
        int nbrBriques=tabBriques.getTaille();
        for(int i=0;i<nbrBriques;i++){
            if (this->billeDansBrique(tabBriques.at(i))){
                tabBriques.perteResistance(i);
                if((posY==tabBriques.at(i).getY()-1 || posY==tabBriques.at(i).getY()+tabBriques.at(i).getL()) && posX>=tabBriques.at(i).getX() && posX<tabBriques.at(i).getX()+tabBriques.at(i).getl()){
                    this->changerTrajectoire(0);
                }
                else if((posX==tabBriques.at(i).getX()-1 || posX==tabBriques.at(i).getX()+tabBriques.at(i).getl()) && posY>=tabBriques.at(i).getY() && posY<tabBriques.at(i).getX()+tabBriques.at(i).getL()){
                    this->changerTrajectoire(90);
                }
                else if((posX==tabBriques.at(i).getX()-1 || posX==tabBriques.at(i).getX()+tabBriques.at(i).getl()) && (posY==tabBriques.at(i).getY()-1 || posY==tabBriques.at(i).getY()+tabBriques.at(i).getL())){
                    this->changerTrajectoire(45);
                }
            }
        }
    }
    
    void Bille::print(WINDOW* w) const{
        std::string x(1,icone);
        mvwprintw(w,posY,posX,x.c_str());
        wrefresh(w);
        refresh();
    }
    
    void Bille::effacePrintBille(WINDOW* w) const{
        std::string x(1,' ');
        mvwprintw(w, posY, posX, x.c_str());
        wrefresh(w);
        refresh();
    }
