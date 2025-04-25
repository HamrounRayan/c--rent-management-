#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "LOG_LLC_BIBLIO.h"

int readInput()
{
    int input = _getch();
    if (input == 224)
    {
        input = _getch();
    }
    return input;
}

void printMenu(int state)
{
    printf("\033[H\033[J");
    printf(state == 1 ? "==> 1- add new \n" : "  1- add new \n");
    printf(state == 2 ? "==> 2- delete  \n" : "  2- delete  \n");
    printf(state == 3 ? "==> 3- search  \n" : "  3- search  \n");
    printf(state == 4 ? "==> 4- display \n" : "  4- display \n");
    printf(state == 5 ? "==> 5- exit    \n" : "  5- exit    \n");
    printf("\nUse arrow keys to navigate and Enter to select.\n");
}

void addNew(int stateadd)
{
    printf("\033[H\033[J");
    printf(stateadd == 1 ? "==> 1- add new logement  \n" : "  1- add new logement  \n");
    printf(stateadd == 2 ? "==> 2- add new lacataire \n" : "  2- add new lacataire \n");
    printf(stateadd == 3 ? "==> 3- add new location  \n" : "  3- add new location  \n");
    printf("\nUse arrow keys to navigate and Enter to select.\n");
    printf("Press ESC to return to main menu.\n");
}

void delete(int statedelate)
{
    printf("\033[H\033[J");
    printf(statedelate == 1 ? "==> 1- delete logement  \n" : "  1- delete logement  \n");
    printf(statedelate == 2 ? "==> 2- delete lacataire \n" : "  2- delete lacataire \n");
    printf(statedelate == 3 ? "==> 3- delete location  \n" : "  3- delete location  \n");
    printf("\nUse arrow keys to navigate and Enter to select.\n");
    printf("Press ESC to return to main menu.\n");
}

void search(int statesearch)
{
    printf("\033[H\033[J");
    printf(statesearch == 1 ? "==> 1- search by date\n" : "  1- search by date \n");
    printf(statesearch == 2 ? "==> 2- list locations by type of logement\n" : "  2- list locations by type of logement\n");
    printf(statesearch == 3 ? "==> 3- list locataire by type of logement  \n" : "  3- list locataire by type of logement \n");
    printf(statesearch == 4 ? "==> 4- search the closest logement with minimal price \n" : "  4- search the closest logement with minimal price\n");
    printf(statesearch == 5 ? "==> 5- contult history by year\n" : "  5- contult history by year\n");
    printf("\nUse arrow keys to navigate and Enter to select.\n");
    printf("Press ESC to return to main menu.\n");
}

void history(int statehistory)
{
    printf("\033[H\033[J");
    printf(statehistory == 1 ? "==> 1- the number of logement rented in this year by name of street  \n" : "  1- the number of logement rented in this year\n");
    printf(statehistory == 2 ? "==> 2- the number of logement rented in this year by type of logement\n" : "  2- the number of logement rented in this year by type of logement\n");
    printf("\nUse arrow keys to navigate and Enter to select.\n");
    printf("Press ESC to return to main menu.\n");
}

void display(int statedisplay)
{
    printf("\033[H\033[J");
    printf(statedisplay == 1 ? "==> 1- display logement  \n" : "  1- display logement \n");
    printf(statedisplay == 2 ? "==> 2- display lacataire \n" : "  2- display lacataire\n");
    printf(statedisplay == 3 ? "==> 3- display location  \n" : "  3- display location \n");
    printf("\nUse arrow keys to navigate and Enter to select.\n");
    printf("Press ESC to return to main menu.\n");
}

int main()
{
    int state = 1;
    int stateadd = 1;
    int statedelate = 1;
    int statesearch = 1;
    int statehistory = 1;
    int statedisplay = 1;

    while (1)
    {
        printMenu(state);

        int key = readInput();

        if (key == 72 && state > 1)
        {
            state--;
        }
        if (key == 80 && state < 5)
        {
            state++;
        }
        if (key == 13)
        {
            if (state == 1)
            {
                stateadd = 1;
                while (1)
                {
                    addNew(stateadd);

                    int key = readInput();

                    if (key == 72 && stateadd > 1)
                    {
                        stateadd--;
                    }
                    if (key == 80 && stateadd < 3)
                    {
                        stateadd++;
                    }
                    if (key == 27)
                        break;
                    if (key == 13)
                    {
                        if (stateadd == 1)
                        {
                            printf("\033[H\033[J");
                            add_Logement();
                            printf("\nPress any key to continue...");
                            _getch();
                            break;
                        }
                        if (stateadd == 2)
                        {
                            printf("\033[H\033[J");
                            add_Locataire();
                            printf("\nPress any key to continue...");
                            _getch();
                            break;
                        }
                        if (stateadd == 3)
                        {
                            printf("\033[H\033[J");
                            add_Location();
                            printf("\nPress any key to continue...");
                            _getch();
                            break;
                        }
                    }
                }
            }
            else if (state == 2)
            {
                statedelate = 1;
                while (1)
                {
                    delete (statedelate);

                    int key = readInput();

                    if (key == 72 && statedelate > 1)
                    {
                        statedelate--;
                    }
                    if (key == 80 && statedelate < 3)
                    {
                        statedelate++;
                    }
                    if (key == 27)
                        break;
                    if (key == 13)
                    {
                        if (statedelate == 1)
                        {
                            delete_Logement();
                            printf("\nPress any key to continue...");
                            _getch();
                            break;
                        }
                        if (statedelate == 2)
                        {
                            delete_Locataire();
                            printf("\nPress any key to continue...");
                            _getch();
                            break;
                        }
                        if (statedelate == 3)
                        {
                            delete_Location();
                            printf("\nPress any key to continue...");
                            _getch();
                            break;
                        }
                    }
                }
            }
            else if (state == 3)
            {
                statesearch = 1;
                while (1)
                {
                    search(statesearch);

                    int key = readInput();

                    if (key == 72 && statesearch > 1)
                    {
                        statesearch--;
                    }
                    if (key == 80 && statesearch < 5)
                    {
                        statesearch++;
                    }
                    if (key == 27)
                        break;
                    if (key == 13)
                    {
                        if (statesearch == 1)
                        {
                            printf("\033[H\033[J");
                            searchByDate();
                            printf("\nPress any key to continue...");
                            _getch();
                            break;
                        }
                        if (statesearch == 2)
                        {
                            printf("\033[H\033[J");
                            listLocTypeLog();
                            printf("\nPress any key to continue...");
                            _getch();
                            break;
                        }
                        if (statesearch == 3)
                        {
                            printf("\033[H\033[J");
                            listLocataireTypeLog();
                            printf("\nPress any key to continue...");
                            _getch();
                            break;
                        }
                        if (statesearch == 4)
                        {
                            printf("\033[H\033[J");
                            searchPlpMoc();
                            printf("\nPress any key to continue...");
                            _getch();
                            break;
                        }
                        if (statesearch == 5)
                        {
                            statehistory = 1;
                            while (1)
                            {
                                history(statehistory);

                                int key = readInput();

                                if (key == 72 && statehistory > 1)
                                {
                                    statehistory--;
                                }
                                if (key == 80 && statehistory < 2)
                                {
                                    statehistory++;
                                }
                                if (key == 27)
                                    break;
                                if (key == 13)
                                {
                                    if (statehistory == 1)
                                    {
                                        printf("\033[H\033[J");
                                        historyNumCartier();
                                        printf("\nPress any key to continue...");
                                        _getch();
                                        break;
                                    }
                                    if (statehistory == 2)
                                    {
                                        printf("\033[H\033[J");
                                        historyNumLogement();
                                        printf("\nPress any key to continue...");
                                        _getch();
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
            }
            else if (state == 4)
            {
                statedisplay = 1;
                while (1)
                {
                    display(statedisplay);

                    int key = readInput();

                    if (key == 72 && statedisplay > 1)
                    {
                        statedisplay--;
                    }
                    if (key == 80 && statedisplay < 3)
                    {
                        statedisplay++;
                    }
                    if (key == 27)
                        break;
                    if (key == 13)
                    {
                        if (statedisplay == 1)
                        {
                            printf("\033[H\033[J");
                            loadLogement();
                            print_logement(head_logement);
                            Free_logement(head_logement);
                        }
                        if (statedisplay == 2)
                        {
                            printf("\033[H\033[J");
                            loadLocataire();
                            print_locataire(head_locataire);
                            Free_locataire(head_locataire);
                        }
                        if (statedisplay == 3)
                        {
                            printf("\033[H\033[J");
                            loadLocation();
                            print_location(head_location);
                            Free_location(head_location);
                        }
                        printf("\nPress any key to continue...");
                        _getch();
                        break;
                    }
                }
            }
            else if (state == 5)
            {
                printf("Exiting...");
                break;
            }
        }
    }
    return 0;
}