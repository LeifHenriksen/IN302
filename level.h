#ifndef LEVEL_H
#define LEVEL_H

#include "briques.h"
#include "tableauBriques.h"

class Level {
private:
    tableauBriques tabBriques;
public:
    Level();
    Level(int l,int L,int resistance,int nb_briques,int nb_lines,int padding);

    tableauBriques get_tabBriques() const;
    
};

#endif