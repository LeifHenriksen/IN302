#ifndef __BILLE_H
#define __BILLE_H
#include <ncurses.h>
#include "window.h"

class Bille{

public:
    
    enum DirectionDepart {
    GAUCHE,
    DROITE,
    };
    
private:
    
    int posX;
    int posY;
    int directionX;
    int directionY;
    char icone;
    DirectionDepart maDirection;
    
    
public:
    
    Bille();
    Bille(int positionX, int positionY, int dirX, int dirY, char icon, DirectionDepart dirDebut);
    
    
    int getX() const;
    int getY() const;
    int getDirX() const;
    int getDirY() const;
    char getIcone() const;
    int getDirDepart() const;
    
    void setX(int x);
    void setY(int y);
    void setDirX(int dirX);
    void setDirY(int dirY);
    void setIcone(char icon);
    void setDirDepart(DirectionDepart dir);
    
    
    void changerTrajectoire();
    void print(WINDOW* w) const;
    
};
#endif
