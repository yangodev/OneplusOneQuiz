/*
    Author: Zeruxky
    Datum: 04/20/2014
*/

#include "Oneplus One Quiz_header.h"

int main()
{
    bool Game_ON, nextlevel, go_menu;
    int counternumber;

    welcomescreen();

    do
    {
        int choice = mainmenu();

        enum{Play_Game = 1, Credits, Load_Game, Close_Game};

        switch(choice)
        {

            case Play_Game:
                {
                    Game_ON = true;

                    do
                    {
                        int difficulty = difficultychoice();

                        enum{Easy = 1, Medium, Hard};

                        switch(difficulty)
                        {
                            case Easy:
                                {
                                    Game(&Game_ON, &nextlevel, &go_menu, difficulty, Easy, Medium, Hard);

                                }break;

                            case Medium:
                                {
                                    Game(&Game_ON, &nextlevel, &go_menu, difficulty, Easy, Medium, Hard);
                                }break;

                            case Hard:
                                {
                                   Game(&Game_ON, &nextlevel, &go_menu, difficulty, Easy, Medium, Hard);
                                    if(nextlevel == true)
                                    {
                                        end_of_Game(&go_menu);
                                    }
                                }break;

                        }

                    }while(Game_ON == true);

                }break;

            case Credits:
                {
                    Credits_Zeruxky();
                    go_menu = true;
                }break;

            case Load_Game:
                {
                   loading_Game(&Game_ON, &go_menu, &nextlevel);
                }break;

            case Close_Game:
                {
                    go_menu = false;
                }break;
        }

    }while(go_menu == true);

    bye_bye();
};
