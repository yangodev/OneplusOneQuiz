#ifndef ONEPLUS_ONE_QUIZ_HEADER_H_INCLUDED
#define ONEPLUS_ONE_QUIZ_HEADER_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

void welcomescreen();
int mainmenu();
int difficultychoice();
void Game(bool*, bool*, bool*, int, int, int, int);
void end_of_Game(bool*);
void Credits_Zeruxky();
void loading_Game(bool*, bool*, bool*);
void bye_bye();



#endif // ONEPLUS_ONE_QUIZ_HEADER_H_INCLUDED
