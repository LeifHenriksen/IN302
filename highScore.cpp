#include "highScore.h"
#include "window.h"
#include <string>
#include <fstream>
#include <ncurses.h>
#include<stdio.h>// remove rename
highScore::highScore(){
  std::ifstream input("highScore.txt");

  if(!input.is_open())
    {
      //creation du fichier highScore
      std::ofstream input("highScore.txt");
      if(input.is_open())
	{
	  input <<"#nom--------score \n#NE PAS MODIFIER \nuser 1 : 0\nuser 2 : 0\nuser 3 : 0\nuser 4 : 0\nuser 5 : 0";

	  //creation de tab
	  
	  unsigned int *tab = new unsigned int[5]; 
	  TabDeScores = tab;
	  TabDeScores[0]=0;
	  TabDeScores[1]=0;
	  TabDeScores[2]=0;
	  TabDeScores[3]=0;
	  TabDeScores[4]=0;
	}
      else
	{
	  Window w(20, 20, 0 , 0 , 0 );
	  w.popup("ERREUR avec le fichier de HighScore, TERMINATE");
	  stopProgramX();
	  std::terminate();
	}
      
    }
  else
    {
      //creation du tab
      unsigned int *tab = new unsigned int[5];
      TabDeScores = tab;
      
      
      //variables
      std::string line;
      int indiceLine = 0;
      int indiceTab = 0;
      int end;
      int score;

      while(!input.eof())
	{
	  getline(input , line);
	  end = line.size()-1;

	  if(!(line[0] == '#') && indiceTab<5)
	  {
	    //trouver le ':'
	    while(line[indiceLine]!=':')
	      indiceLine++;
	    //elever l'espace
	    indiceLine++;
	    //creer l'int
	    line = line.substr(indiceLine , end);
	    score = atoi(line.c_str());
	    //mettre le score dans le tab
	    TabDeScores[indiceTab] = score;

	    indiceTab++;
	    indiceLine = 0;
	    
	  }
	}
    }
  

  
  input.close();
}

bool highScore::estUnHighScore(unsigned int x)const{
  bool estSup = false;
  for(int i = 0 ; i<5 ; i++ )
    if(TabDeScores[i]<x)
      estSup = true;

  return estSup;
}

void highScore::mettreNouveauHighScore(unsigned int score , std::string nom)
{
  std::ifstream input("highScore.txt");
  std::ofstream output("highScore2.txt");

  if(!input.is_open())
    {
      Window win(20, 50, 0 , 0 , 0 );
      win.popup("ERREUR avec le fichier de HighScore, TERMINATE");
      stopProgramX();
      std::terminate();
    }
  else
    {
      std::string str;
      std::string line;
      int indiceTab = 0;
      bool insertion = false;
      while(!input.eof())
	{
	  getline(input , line);
	  if(line[0] == '#')
	    {
	      output << line + '\n';
	    }
	  else
	    {
	      if(TabDeScores[indiceTab] < score && insertion == false)
		{
		  insertion = true;
		  //-1 car boucle et affichage decales
		  str = nom + " : " + std::to_string(score-1) + '\n'; 
		  output << str; 
		}
	      else
		{
		  output << line + '\n';
		}
	    }
	}
    }
  input.close();
  output.close();
  
  //solo poner 1
  //si el que voy a meter es el numero uno , eliminar
  //el ultimo y meter decalar los otros
  //cambiar de nombre
  //eliminar el high
}
void highScore::pop(const Window &w)const{

  std::ifstream input("highScore.txt");
  if(!input.is_open())
    {
      Window win(20, 50, 0 , 0 , 0 );
      win.popup("ERREUR avec le fichier de HighScore, TERMINATE");
      stopProgramX();
      std::terminate();
    }
  else
    {
     
      std::string message = "-----HighScores-----\n";
      std::string line;

      while(!input.eof())
	{
	  getline(input , line);
	  
	  if(line[0] != '#')
	    {
	      message = message + line + '\n';
	    }

	}


      
      w.popup(message);
    }
}
