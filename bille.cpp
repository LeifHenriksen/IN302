#include "bille.h"
#include "window.h"
#include <stdio.h>
#include <string>


Bille::Bille() : posX(0), posY(0), directionX(0), directionY(0), icone('o'), maDirection(GAUCHE){
}

Bille::Bille(int x, int y, int dirX, int dirY, char icon, DirectionDepart dirDebut): posX(x), posY(y), directionX(dirX), directionY(dirY), icone(icon), maDirection(dirDebut){
}

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
    int Bille::getDirDepart() const{
        return maDirection;
    }

    
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
    
    void Bille::print(WINDOW* w) const{
        std::string x(1,icone);
        mvwprintw(w,posY,posX,x.c_str());
        wrefresh(w);
        refresh();
    }
