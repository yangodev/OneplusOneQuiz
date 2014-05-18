#include "Oneplus One Quiz_header.h"

void welcomescreen()
{
    cout << "+----------------------------------------------+" << endl;
    cout << "| Welcome to the Oneplus One Quiz!             |" << endl;
    cout << "| In this quiz your knowledge is in demand.    |" << endl;
    cout << "| Will you be able to cope with the challenge? |" << endl;
    cout << "| If your answer is yes, then you can start!   |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << endl << "- Press any key to continue -" << endl;

    cin.get();

    system("cls");
}

int difficultychoice()
{
    int number;
    cout << "**************" << endl;
    cout << "* Difficulty *" << endl;
    cout << "**************" << endl;

    cout << "On what difficulty you want to try it?" << endl;

    cout << "*Easy (1)" << endl;
    cout << "*Medium (2)" << endl;
    cout << "*Heavy (3)" << endl;

    cin >> number;

    system("cls");

    return(number);
}

int mainmenu()
{
    bool repeat;
    int number;
    do
    {
        system("cls");
        repeat = false;
        number = 0;

        cout << "************" << endl;
        cout << "* Mainmenu *" << endl;
        cout << "************" << endl;

        cout << "* Play Game (1)" << endl;
        cout << "* Credits (2)" << endl;
        cout << "* Load old Game (3)" << endl;
        cout << "* Close Game (4)" << endl;

        if(!(cin >> number))
        {
            repeat = true;
            cin.clear();
            cin.sync();
            system("cls");
        }

        if(number != 1&&number != 2&&number != 3&&number != 4)
        {
            repeat = true;
        }

    }while(repeat == true);

    system("cls");

    return(number);
}

void Game(bool *p_Game_ON, bool *p_nextlevel, bool *p_go_menu, int difficulty, int Easy, int Medium, int Hard)
{
    bool falseanswer, nextquestion;
    int counternumber = 1;
    char Entry_yesORno;
    string entry;
    string Answers;
    string Question;
    string filename1;
    string filename2;

    if(difficulty == Easy)
    {
        filename1 = "Easy_Questions.txt";
        filename2 = "Easy_Answers.txt";
    }

    if(difficulty == Medium)
    {
        filename1 = "Medium_Questions.txt";
        filename2 = "Medium_Answers.txt";
    }

    if(difficulty == Hard)
    {
        filename1 = "Hard_Questions.txt";
        filename2 = "Hard_Answers.txt";
    }

    fstream Source1;
    fstream Source2;
    Source1.open(filename1.c_str(), ios::in);
    Source2.open(filename2.c_str(), ios::in);
    string filename3 = "Save_Question.txt";
    string filename4 = "Save_Answers.txt";
    fstream Target1;
    fstream Target2;
    Target1.open(filename3.c_str(), ios::out);
    Target2.open(filename4.c_str(), ios::out);

    if(Source1)
    {
        do
        {
            cout << "Enter answers as they are written normally." << endl;
            cout << "You can leave the game. You have to write only 'Exit'." << endl;
            cout << endl;
            int repeat = 0;
            *p_nextlevel = false;
            nextquestion = false;
            *p_go_menu = false;

            getline(Source1, Question);
            getline(Source2, Answers);

            do
            {
                falseanswer = false;

                if(Question.size() == 0)
                {
                    cout << "Do you want to go next level? [Y/N]" << endl;
                    cin >> Entry_yesORno;

                    if(toupper(Entry_yesORno) == 'Y')
                    {
                        *p_nextlevel = true;
                        *p_Game_ON = true;
                    }

                    else
                    {
                        *p_go_menu = true;
                    }

                }

                if(Source2)
                {
                    if(*p_nextlevel != true)
                    {
                        cout << counternumber << ". " << Question << endl;

                        cout << "Entry: ";

                        cin >> entry;

                        if(entry == Answers)
                        {
                            nextquestion = true;
                            if(counternumber%5 == 0)
                            {
                                system("cls");
                            }
                        }else
                        {
                            falseanswer = true;
                            repeat++;
                        }

                        if(repeat == 5)
                        {
                            system("cls");
                            cout << "You have not done it! Try again!" << endl;
                            repeat = 0;
                        }

                        if(entry == "Exit")
                        {
                            *p_Game_ON = false;

                            char yesORno;

                            cout << "Want to save your score to make later on there? [Y/N]" << endl;
                            cin >> yesORno;

                            if(toupper(yesORno) == 'Y')
                            {
                                Target1 << Question << endl; //Save the Question right now.
                                Target2 << Answers << endl;

                                while(getline(Source1, Question))
                                {
                                    if(!Target1.good())
                                    {
                                        Target1.clear();
                                        cout << "Dateifehler/File error";
                                    }

                                    else
                                    {
                                        Target1 << Question << endl;
                                    }
                                }
                                cout << "Saving Questions was successfully." << endl;


                                while(getline(Source2, Answers))
                                {
                                    if(!Target2.good())
                                    {
                                        Target2.clear();
                                        cout << "Dateifehler/File error";
                                    }

                                    else
                                    {
                                        Target2 << Answers << endl;
                                    }
                                }
                                cout << "Saving Answers was successfully." << endl;

                                Sleep(2000);

                            }
                            Target1.close();
                            Target2.close();
                        }
                    }
                }


                else
                {
                    if(*p_nextlevel != true)
                    {
                        cout << "Failurenumber #469" << endl;

                        cout << "Source file not found!" << endl;

                    }
                }

                if(falseanswer != true)
                {
                    counternumber++;
                }

            }while(falseanswer == true&&repeat < 5&&*p_Game_ON == true&&*p_nextlevel != true);

        }while(nextquestion == true&&*p_Game_ON == true&&*p_nextlevel != true);
        Source1.close();
        Source2.close();

    }

    else
    {
        cout << "Failurenumber #469" << endl;

        cout << "Source file not found!" << endl;
    }
}

void end_of_Game(bool *p_go_menu)
{
    cout << "Congratulation!" << endl;
    cout << "You're a good judge!" << endl;

    *p_go_menu = true;
}

void loading_Game(bool *p_Game_ON, bool *p_go_menu,  bool *p_nextlevel)
{
    bool nextquestion, falseanswer;
    int counternumber = 1, length;
    string Question;
    string entry;
    string Answers;
    string filename1 = "Save_Question.txt";
    string filename2 = "Save_Answers.txt";
    fstream Source_Target1;
    fstream Source_Target2;
    Source_Target1.open(filename1.c_str());
    Source_Target2.open(filename2.c_str());

    if(Source_Target1)
    {
        do
        {
            cout << "Enter answers as they are written normally." << endl;
            cout << "You can leave the game. You have to write only 'Exit'." << endl;
            int repeat = 0;
            *p_nextlevel = false;
            nextquestion = false;
            *p_Game_ON = true;

            getline(Source_Target1, Question);
            getline(Source_Target2, Answers);

            do
            {
                falseanswer = false;

                if(Question.size() == 0)
                {
                    *p_nextlevel = true;
                    *p_go_menu = true;
                    cout << "In the menu you can choose the next level!" << endl;
                    Sleep(2000);
                }

                if(Source_Target2)
                {
                    if(*p_nextlevel != true)
                    {

                        cout << counternumber << ". " << Question << endl;

                        cout << "Entry: ";

                        cin >> entry;

                        if(entry == Answers)
                        {
                            nextquestion = true;
                            if(counternumber%5 == 0)
                            {
                                system("cls");
                            }
                        }

                        if(entry != Answers)
                        {
                            falseanswer = true;
                            repeat++;
                        }

                        if(repeat == 5)
                        {
                            system("cls");
                            cout << "You have not done it! Try again!" << endl;
                            repeat = 0;
                        }

                        if(entry == "Exit")
                        {
                            *p_Game_ON = false;

                            char yesORno;

                            cout << "Want to save your score to make later on there? [Y/N]" << endl;
                            cin >> yesORno;

                            if(toupper(yesORno) == 'Y')
                            {
                                Source_Target1 << Question << endl; //Save the Question right now.
                                Source_Target2 << Answers << endl;

                                while(getline(Source_Target1, Question))
                                {
                                    if(!Source_Target1.good())
                                    {
                                        Source_Target1.clear();
                                        cout << "Dateifehler/File error";
                                    }

                                    else
                                    {
                                        Source_Target1 << Question << endl;
                                    }
                                }
                                cout << "Saving Questions was successfully." << endl;


                                while(getline(Source_Target2, Answers))
                                {
                                    if(!Source_Target2.good())
                                    {
                                        Source_Target2.clear();
                                        cout << "Dateifehler/File error";
                                    }

                                    else
                                    {
                                        Source_Target2 << Answers << endl;
                                    }
                                }
                                cout << "Saving Answers was successfully." << endl;

                                Source_Target1.close();
                                Source_Target2.close();
                            }
                        }
                    }
                }

                else
                {
                    cout << "Failurenumber #469" << endl;

                    cout << "Source file not found!" << endl;
                }

                if(falseanswer != true)
                {
                    counternumber++;
                }

            }while(falseanswer == true&&repeat < 5&&*p_Game_ON == true&&*p_nextlevel != true);

        }while(nextquestion == true&&*p_Game_ON == true&&*p_nextlevel != true);
        Source_Target1.close();
        Source_Target2.close();

    }

    else
    {
        cout << "Failurenumber #469" << endl;

        cout << "Source file not found!" << endl;
    }
};

void Credits_Zeruxky()
{
    cout << "Oneplus One Quiz V.1.0.2" << endl;
    cout << "Oneplus One Quiz! made by Zeruxky at 04/27/2014." << endl;
    cout << "The name 'Oneplus' and 'Oneplus One' are reserved to Oneplus." << endl;
    cout << "This program is not commercial. It's a free, open - source Game." << endl;
    cout << "Made by a proud fan of the Oneplus One!" << endl;

    cout << endl << "Contact:" << endl;
    cout << "My Github - Site: https://github.com/Zeruxky" << endl;
    cout << "In Oneplus One - Forum: Member: Zeruxky" << endl;

    Sleep(5000);

    system("cls");
}

void bye_bye()
{
    cout << "Goodbye! I hope you had fun with my little Game. :)" << endl;

    cout << endl;

    Credits_Zeruxky();
}
