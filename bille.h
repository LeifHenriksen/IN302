#ifndef __BILLE_H
#define __BILLE_H


class Bille{

public:
    
    enum DirectionDepart {
        GAUCHE,
        DROITE
    };
    
private:
    
    int posX;
    int posY;
    int directionX;
    int directionY;
    DirectionDepart maDirection;
    
    
public:
    
    Bille();
    Bille(int positionX, int positionY, DirectionDepart dirDebut);
    
    
    int getX() const;
    int getY() const;
    int getDirX() const;
    int getDirY() const;
    int getDirDepart() const;
    
    void setX(int x);
    void setY(int y);
    void setDirX(int dirX);
    void setDirY(int dirY);
    void setDirDepart(DirectionDepart dir);
    
    
    
#endif
