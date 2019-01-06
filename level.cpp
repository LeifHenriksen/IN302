#include "level.h"

Level::Level(){

}
Level::Level(int l,int L,int resistance,int nb_briques,int nb_lines,int padding){
    int posY = 1;
    int posX = 1;
    for(int line = 0; line < nb_lines ; line++) {
        posX = 1;
        for(int brick = 0 ;brick < nb_briques ; brick++) {
            tabBriques.add(' ',posY,posX,L,l,resistance);
            posX += l+padding;
            
        }
        posY += L+1;
    }
}

tableauBriques Level::get_tabBriques() const{
    return tabBriques;
}