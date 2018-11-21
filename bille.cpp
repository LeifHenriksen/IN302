#include "bille.h"
#include <stdio.h>


Bille::Bille() : posX(0), posY(0), directionX(0), directionY(0), maDirection(DROITE){
}

Bille::Bille(int x, int y, int dirX, int dirY, DirectionDepart dirDebut): posX(x), posY(y), directionX(dirX), directionY(dirY), maDirection(dirDebut){
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
    void Bille::setDirDepart(DirectionDepart dir){
        maDirection=dir;
    }
