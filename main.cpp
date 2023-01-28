#include <iostream>
#include <ctime>    // for time
#include "World.h"
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <dos.h>
using namespace std;

int main()
{
    PlaySound(TEXT("C:\\Users\\Amos\\Desktop\\Programming Stuff\\Rodent Project\\Sound Files\\startup.wav"), NULL, SND_FILENAME | SND_ASYNC);
    system("cls");
    for (int i = 1; i <= 50; i++)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << "\n\n\n\n\t\t\t\t   Loading " << '\n' << '\t' << '\t';
        for (int j = 1; j <= i; j++)
            cout << "²";
        cout << "\n\n\t " << 2 * i << "%";
        if (i > 1 && i < 20)
            cout << "\n\n\tCreating The World";
        else if (i > 20 && i < 40)
            cout << "\n\n\tAccessing Rodent Information";
        else if (i > 40 && i < 48)
            cout << "\n\n\tAccessing main.cpp";
        else cout << "\n\n\tComplete. Press t to Continue";
        Sleep(150 - i * 3);
    }

    World myWorld(time(0));
    char ch = ' ';

    do
    {
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 't')
            {
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                cout << endl << "--------------------------------------------------------" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout << endl << "--------------------------------------------------------" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << endl << "      RODENT REPRODUCTION AND INFECTION SIMULALTION   " << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout << endl << "--------------------------------------------------------" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                cout << endl << "--------------------------------------------------------" << endl;
                PlaySound(TEXT("C:\\Users\\Amos\\Desktop\\Programming Stuff\\Rodent Project\\Sound Files\\menumusic.wav"), NULL, SND_FILENAME | SND_ASYNC);
                cout << endl << endl << endl << endl << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                cout << "                 s: Start Simulation" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "                 g: Quit the Program" << endl;
                do
                {
                    if (_kbhit())
                    {
                        ch = _getch();
                        if (ch == 's')
                        {
                            PlaySound(NULL, 0, 0);
                            myWorld.display();
                            while (ch != 'q')
                            {
                                if (_kbhit())
                                {
                                    ch = _getch();
                                    if (ch == 'i')
                                    {
                                        myWorld.InfectedRat();
                                    }
                                }
                                system("cls");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                cout << "Bryce Green";
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                                myWorld.simulateOneStep();
                                myWorld.display();
                                Sleep(1000);
                            }
                        }
                    }
                    if (_kbhit())
                    {
                        ch = _getch();
                        if (ch == 'g')
                        {
                            PlaySound(NULL, 0, 0);
                            system("cls");
                            PlaySound(TEXT("C:\\Users\\Amos\\Desktop\\Programming Stuff\\Rodent Project\\Sound Files\\shutdown.wav"), NULL, SND_FILENAME | SND_ASYNC);
                            for (int i = 1; i <= 50; i++)
                            {
                                system("cls");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                                cout << "\n\n\n\n\t\t\t\t   Qutting " << '\n' << '\t' << '\t';
                                for (int j = 1; j <= i; j++)
                                    cout << "²";
                                cout << "\n\n\t " << 2 * i << "%";
                                if (i > 1 && i < 20)
                                    cout << "\n\n\tDeleting World";
                                else if (i > 20 && i < 40)
                                    cout << "\n\n\tSaving Rodent Information";
                                else if (i > 40 && i < 48)
                                    cout << "\n\n\tClosing main.cpp";
                                else cout << "\n\n\tProgram Quit. Press q";
                                Sleep(150 - i * 3);

                            }
                        }
                    }
                } while (ch != 'q');
            
            }
        } 
    } while (ch != 'q');
} 
