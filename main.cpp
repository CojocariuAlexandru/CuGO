#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <graphics.h>
#include <winbgim.h>
#include <queue>
#include <windows.h>
#include <mmsystem.h>
#include "InitializariVariabile.h"
#include "Functii.h"


int main() {
    if(soundOn == 1){
        PlaySound(TEXT("door.wav"), NULL, SND_SYNC);
        delay(2000);
        }
    initializareEcran();
    animatieInceput(); delay(100);
    precalculari();
    DarkModeOnOff(darkMode);
    joc();
    closegraph();
    return 0;
}

void DarkModeOnOff(int&darkMode){
    if(darkMode==0)
    {
        darkMode=1;
        strcpy(textDarkMode, "ON");
        strcpy(BackgroundMeniu, "MeniuDark.jpg");
        strcpy(BackgroundJoc, "JocDark.jpg");
        FUNDAL = BLACK;
        DESENE = WHITE;
    }
    else
    {
        darkMode=0;
        strcpy(textDarkMode, "OFF");
        strcpy(BackgroundMeniu, "Meniu.jpg");
        strcpy(BackgroundJoc, "Joc.jpg");
        FUNDAL = WHITE;
        DESENE = BLACK;
    }
}



int piesaPeMargineaTablei()
{
    for(int i=1;i<=8;++i)
        if(TablaDeJoc[i][1]==1)
            return 3;
        else
            if(TablaDeJoc[i][8]==1)
                return 4;
            else
                if(TablaDeJoc[1][i]==1)
                    return 1;
                else
                    if(TablaDeJoc[8][i]==1)
                        return 2;
    return 0;
}

void joc() {
    initializareTablaJoc();
    while(1){
        if (undeSunt == 1)
            Meniu();
            else if (undeSunt == 2)
                OPTIUNI();
                else if (undeSunt == 3)
                    CuGOsingleplayer();
                    else if (undeSunt == 4)
                        CuGOmultiplayer();
                        else if (undeSunt == 5)
                            Tutorial();
        }
}

void afisareSunet(){
    const char* titluSunet;
    if(darkMode==1 && soundOn==1)
        titluSunet = "sunetOnDark.jpg";
        else if(darkMode==1 && soundOn==0)
            titluSunet = "sunetOffDark.jpg";
            else if(darkMode==0 && soundOn==1)
                titluSunet = "sunetOn.jpg";
                else
                titluSunet = "sunetOff.jpg";
    readimagefile(titluSunet, leftSunet, topSunet, rightSunet, bottomSunet);
}

void Meniu() {
    afisareBackgroundMeniu();
    undeCursor = 0; ok = 0;
    cursorPesteNimic();
    while (1) {
        delay(50);
        preluareInput();
        undeCursor =0;
        //Tratez cazurile in care cursorul se poate afla peste unul dintre butoane
        cursorPesteSingleplayer();
        cursorPesteMultiplayer();
        cursorPesteOptiuni();
        cursorPesteExit();
        cursorPesteNimic();
        afisareSunet();
        //cursorPesteDarkMode();

        //Tratez cazurile in care se apasa click pe unul dintre butoane
        if (clickTutorial()) {
            if(soundOn == 1)
                PlaySound(TEXT("Button.wav"), NULL, SND_SYNC);
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            undeSunt = 5;
            break;
        }
        if (clickMultiplayer()) {
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            undeSunt = 4;
            break;
        }
        if (clickSingleplayer()) {
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            undeSunt = 3;
            break;
        }
        if (clickOPTIUNI()) {
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            MouseX = MouseY = 0;
            undeSunt = 2;
            break;
        }
        if (clickExit()){
            if(soundOn == 1)
                PlaySound(TEXT("doorClose.wav"), NULL, SND_SYNC);
            exit(0);
            }
        if(clickSunet()){
            if(soundOn == 1)
                PlaySound(TEXT("Button.wav"), NULL, SND_SYNC);
            soundOn = 1-soundOn;
            MouseLeftClickX = MouseLeftClickY = 0;
            }
    }
    joc();

}

void OPTIUNI() {
    const char * title = BackgroundMeniu;
    ok = 0;
    readimagefile(title, 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
    setfillstyle(SOLID_FILL, FUNDAL);
    bar(leftTutorial,topTutorial,rightTutorial,bottomTutorial);
    cursorPesteNimicOPTIUNI();
    while(1)
    {
        delay(50);
        preluareInput();
        ok = 0;
        //Tratez cazurile in care cursorul se poate afla peste unul dintre butoane
        cursorPesteDarkMode();
        cursorPesteCuloriPiese();
        cursorPesteDificultate();
        cursorPesteLimba();
        cursorPesteInapoi();
        //cursorPesteDarkMode();
        cursorPesteNimicOPTIUNI();
        ok = 0;

        if (clickDarkMode()) {
            DarkModeOnOff(darkMode);
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            undeSunt = 2;
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            break;
        }

        if (clickCuloriPiese()) {
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            if(contorCulori==5)
                contorCulori=0;
            else
                contorCulori++;
            culoareJucator1 = culoriJucator1[contorCulori];
            culoareJucator2 = culoriJucator2[contorCulori];
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            undeSunt = 2;
            break;
        }

        if (clickDificultate()) {
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            if(Dificultate==2)
                Dificultate=0;
            else
                Dificultate++;
            if(Dificultate==0&&Limba==0)
                strcpy(textDificultate,"USOR");
                else
            if(Dificultate==0&&Limba==1)
                strcpy(textDificultate,"EASY");
                else
            if(Dificultate==1&&Limba==0)
                strcpy(textDificultate,"NORMAL");
                else
            if(Dificultate==1&&Limba==1)
                strcpy(textDificultate,"NORMAL");
                else
            if(Dificultate==2&&Limba==0)
                strcpy(textDificultate,"GREU");
                else
                strcpy(textDificultate,"HARD");

            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            undeSunt = 2;
            break;
        }

        if (clickLimba()) {
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            Limba = 1 - Limba;
            if(Limba==0)
            {
                strcpy(JUCATOR1,"JUCATOR 1");
                strcpy(JUCATOR2,"JUCATOR 2");

            strcpy(SINGLEPLAYER,"SINGLEPLAYER");
            strcpy(MULTIPLAYER,"MULTIPLAYER");
            strcpy(OPTIONS,"OPTIUNI");
            strcpy(IESIRE,"IESIRE");
            strcpy(CULORIPIESE,"CULORI");
            strcpy(DIFICULTATE,"DIFICULTATE");
            strcpy(LIMBA,"LIMBA");
            strcpy(INAPOI,"INAPOI");
            strcpy(textLimba,"ROMANA");

            strcpy(MENIU,"MENIU");

            if(Dificultate==0)
                strcpy(textDificultate, "USOR");
            else
                if(Dificultate==1)
                    strcpy(textDificultate,"NORMAL");
                else
                    strcpy(textDificultate,"GREU");
            }
            else
            {
                strcpy(JUCATOR1,"PLAYER 1");
                strcpy(JUCATOR2,"PLAYER 2");

            strcpy(SINGLEPLAYER,"SINGLEPLAYER");
            strcpy(MULTIPLAYER,"MULTIPLAYER");
            strcpy(OPTIONS,"OPTIONS");
            strcpy(IESIRE,"EXIT");
            strcpy(CULORIPIESE,"COLORS");
            strcpy(DIFICULTATE,"DIFFICULTY");
            strcpy(LIMBA,"LANGUAGE");
            strcpy(INAPOI,"BACK");
            strcpy(textLimba,"ENGLISH");

            strcpy(MENIU,"MENU");

            if(Dificultate==0)
                strcpy(textDificultate, "EASY");
            else
                if(Dificultate==1)
                    strcpy(textDificultate,"NORMAL");
                else
                    strcpy(textDificultate,"HARD");

            }

            precalculari();

            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            undeSunt = 2;
            break;
        }

        if (clickInapoiMeniu()) {
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            undeSunt = 1;
            break;
        }
    }
    joc();
}

void CuGOsingleplayer() {
    const char * title = BackgroundJoc;
    readimagefile(title, 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
    desen();
    int numarPiese = 0;

    ok = 1;
    int colt = 0;
    do {
        afisareRundaJucator1();
        punerePiesaJucator(numarPiese, 1, culoareJucator1);
        if(soundOn == 1)
            PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
        if (detectTrapped() == 1) {
            afisareCastigator(1);
            ok = 0;
        } else
        if (detectTrapped() == 2) {
            afisareCastigator(2);
            ok = 0;
        } else
        if (detectTrapped() == 3) {
            afisareCastigator(3);
            ok = 0;
        }

        if(numarPiese==1&&verificareColt())
        {
            colt=verificareColt();
        }
        if(colt)
        {
            afisareRundaJucator2();
            delay(500);
            strategieColt(numarPiese,colt);
            punerePiesaCalculator(numarPiese,culoareJucator2,coordonatePiese);

            if (detectTrapped() == 1) {
                afisareCastigator(1);
                ok = 0;
            } else
            if (detectTrapped() == 2) {
                afisareCastigator(2);
                ok = 0;
            } else
            if (detectTrapped() == 3) {
                afisareCastigator(3);
                ok = 0;
            }
        }
        else
            if (ok) {
            afisareRundaJucator2();
            delay(500);
            if(Dificultate==0)
                mutareRandom();
            else
                if(Dificultate==1)
                    urmatoareaMutareEASY(numarPiese);
                else
                    urmatoareaMutareHARD();
            punerePiesaCalculator(numarPiese, culoareJucator2,coordonatePiese);
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            if (detectTrapped() == 1) {
                afisareCastigator(1);
                ok = 0;
            } else
            if (detectTrapped() == 2) {
                afisareCastigator(2);
                ok = 0;
            } else
            if (detectTrapped() == 3) {
                afisareCastigator(3);
                ok = 0;
            }
        }
    }
    while (numarPiese < 15 && ok);
    while (ok) {

        afisareRundaJucator1();
        mutarePiesaJucator(1, culoareJucator1);

        if (detectTrapped() == 1) {
            afisareCastigator(1);
            ok = 0;
        } else
        if (detectTrapped() == 2) {
            afisareCastigator(2);
            ok = 0;
        } else
        if (detectTrapped() == 3) {
            afisareCastigator(3);
            ok = 0;
        }
        if (ok) {

            afisareRundaJucator2();

            if(Dificultate==0||Dificultate==1)
                mutarePiesaCalculatorEASY(2,culoareJucator2, coordonatePiese);
            else
                mutarePiesaCalculatorHARD(2,culoareJucator2);

            if (detectTrapped() == 1) {
                afisareCastigator(1);
                ok = 0;
            } else
            if (detectTrapped() == 2) {
                afisareCastigator(2);
                ok = 0;
            } else
            if (detectTrapped() == 3) {
                afisareCastigator(3);
                ok = 0;
            }
        }
    }
    butonRestart(1);
    joc();

}

void butonRestart(int mod) {
    char butonTextRestart[] = "RESTART";
    settextstyle(FONT, 0, 3);
    outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + spatiulDintreButoane, butonTextRestart);
    outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane, MENIU);
    int ok = 1;
    MouseLeftClickX = 0;
    MouseLeftClickY = 0;
    while (ok) {
        int x = mousex();
        int y = mousey();

        cursorAfisareCastigator(x,y);

        preluareInput();
        //Alex, comenteaza if-ul urmator daca apare vreo eroare la restart..
        //poate iti dai seama tu ce are
        if(clickRestart()&&mod==1){
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            undeSunt = 3;
            PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            ok = 0;
        }
        else
            if(clickRestart()&&mod==2){
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            undeSunt = 4;
            PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            ok = 0;
        }

        if (clickMeniu()) {
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            undeSunt = 1;
            PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            ok = 0;
        }
    }
}

void cerculetePierzator(){
    int i, j, k;
    if(darkMode == 1)
        setcolor(YELLOW);
        else
        setcolor(RED);
    for(i=1; i<=8; i++)
        for(j=1; j<=8; j++)
            if((TablaDeJoc[i][j] == 1 || TablaDeJoc[i][j] == 2) && isTrapped(i, j)){
                for(k=dimensiuneCerc; k<=dimensiuneCerc+7; k++)
                    circle((sus+lungimeLatura *j+sus+lungimeLatura*(j+1))/2, (stanga+lungimeLatura *i+stanga+lungimeLatura*(i+1))/2,k);
                }
    delay(600);
    if(darkMode == 1)
        setcolor(BLACK);
        else
        setcolor(WHITE);
    for(i=1; i<=8; i++)
        for(j=1; j<=8; j++)
            if((TablaDeJoc[i][j] == 1 || TablaDeJoc[i][j] == 2) && isTrapped(i, j)){
                for(k=dimensiuneCerc; k<=dimensiuneCerc+7; k++)
                    circle((sus+lungimeLatura *j+sus+lungimeLatura*(j+1))/2, (stanga+lungimeLatura *i+stanga+lungimeLatura*(i+1))/2,k);
                }
    delay(600);
}

void afisareCastigator(int jucator) {
    cerculetePierzator();
    cerculetePierzator();
    cerculetePierzator();
    setfillstyle(SOLID_FILL, DESENE);
    setcolor(DESENE);
    bar(lungimeEcranJoc / 2 - lungimeEcranJoc / 4, inaltimeEcranJoc / 2 - inaltimeEcranJoc / 4, lungimeEcranJoc / 2 + lungimeEcranJoc / 4, inaltimeEcranJoc / 2 + inaltimeEcranJoc / 4);

    setfillstyle(SOLID_FILL, FUNDAL);
    setcolor(FUNDAL);
    bar(lungimeEcranJoc / 2 - lungimeEcranJoc / 4 + 10, inaltimeEcranJoc / 2 - inaltimeEcranJoc / 4 + 10, lungimeEcranJoc / 2 + lungimeEcranJoc / 4 - 10, inaltimeEcranJoc / 2 + inaltimeEcranJoc / 4 - 10);
    setbkcolor(FUNDAL);
    setcolor(DESENE);
    settextstyle(FONT, 0, 3);
    settextjustify(1, 1);
    if (jucator == 1&&Limba==0)
        strcpy(CASTIGATOR,"A CASTIGAT JUCATORUL 1");
    else
    if (jucator == 1&&Limba==1)
        strcpy(CASTIGATOR,"PLAYER 1 WON");
    else
    if (jucator == 2&&Limba==0)
        strcpy(CASTIGATOR,"A CASTIGAT JUCATORUL 2");
    else
    if (jucator == 2&&Limba==1)
        strcpy(CASTIGATOR,"PLAYER 2 WON");
    else
    if (jucator == 3&&Limba==0)
        strcpy(CASTIGATOR,"REMIZA");
    else
        strcpy(CASTIGATOR,"DRAW");
    outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2, CASTIGATOR);
}

void CuGOmultiplayer() {
    const char * title = BackgroundJoc;
    readimagefile(title, 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
    desen();
    int numarPiese = 0;
    ok = 1;
    do {
        afisareRundaJucator1();
        punerePiesaJucator(numarPiese, 1, culoareJucator1);
        if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
        if (detectTrapped() == 1) {
            afisareCastigator(1);
            ok = 0;
        } else
        if (detectTrapped() == 2) {
            afisareCastigator(2);
            ok = 0;
        } else
        if (detectTrapped() == 3) {
            afisareCastigator(3);
            ok = 0;
        }
        if (ok) {
            afisareRundaJucator2();
            punerePiesaJucator(numarPiese, 2, culoareJucator2);
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            if (detectTrapped() == 1) {
                afisareCastigator(1);
                ok = 0;
            } else
            if (detectTrapped() == 2) {
                afisareCastigator(2);
                ok = 0;
            } else
            if (detectTrapped() == 3) {
                afisareCastigator(3);
                ok = 0;
            }
        }
    }while (numarPiese < 15 && ok);

    while (ok) {
        afisareRundaJucator1();
        mutarePiesaJucator(1, culoareJucator1);
        if(soundOn == 1)
            PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
        if (detectTrapped() == 1) {
            afisareCastigator(1);
            ok = 0;
        } else
        if (detectTrapped() == 2) {
            afisareCastigator(2);
            ok = 0;
        } else
        if (detectTrapped() == 3) {
            afisareCastigator(3);
            ok = 0;
        }
        if (ok) {

            afisareRundaJucator2();
            mutarePiesaJucator(2, culoareJucator2);
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            if (detectTrapped() == 1) {
                afisareCastigator(1);
                ok = 0;
            } else
            if (detectTrapped() == 2) {
                afisareCastigator(2);
                ok = 0;
            } else
            if (detectTrapped() == 3) {
                afisareCastigator(3);
                ok = 0;
            }
        }
    }
    butonRestart(2);
    joc();
}

void punerePiesaJucator(int & numarPiese, int jucator, int culoare) {
    int linia, coloana, x, y, sus, stanga;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    int ok = 0;
    sus = (inaltimeEcranJoc - latimeTablaJoc) / 2;
    stanga = 50;
    while (ok == 0) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            linia = (y - sus) / lungimeLatura + 1;
            coloana = (x - stanga) / lungimeLatura + 1;
            if (TablaDeJoc[linia][coloana] == 0 && linia > 0 && linia < 9 && coloana > 0 && coloana < 9) {
                TablaDeJoc[linia][coloana] = jucator;
                x1 = stanga + lungimeLatura * (coloana - 1);
                y1 = sus + lungimeLatura * (linia - 1);
                x2 = x1 + lungimeLatura;
                y2 = y1 + lungimeLatura;
                xmijloc = (x1 + x2) / 2;
                ymijloc = (y1 + y2) / 2;
                setcolor(culoare);
                setfillstyle(SOLID_FILL, culoare);
                fillellipse(xmijloc, ymijloc, dimensiuneCerc, dimensiuneCerc);
                ok = 1;
                numarPiese++;
            }
        }
    }
}

void mutarePiesaJucator(int jucator, int culoare) {
    int linia, coloana, x, y, sus, stanga;
    int x1, y1, x2, y2, k;
    int xmijloc, ymijloc;
    int ok = 0;
    int liniaPiesaDeMutat, coloanaPiesaDeMutat;
    sus = (inaltimeEcranJoc - latimeTablaJoc) / 2;
    stanga = 50;
    while (ok == 0) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            linia = (y - sus) / lungimeLatura + 1;
            coloana = (x - stanga) / lungimeLatura + 1;
            if (TablaDeJoc[linia][coloana] == jucator) {
                liniaPiesaDeMutat = linia;
                coloanaPiesaDeMutat = coloana;
                ok = 1;
                for (k = 0; k <= 3; k++) {
                    if (TablaDeJoc[linia + dl[k]][coloana + dc[k]] == 0 && linia + dl[k] > 0 && linia + dl[k] < 9 && coloana + dc[k] > 0 && coloana + dc[k] < 9) {
                        TablaDeJoc[linia + dl[k]][coloana + dc[k]] = 3;
                        x1 = stanga + lungimeLatura * (coloana + dc[k] - 1);
                        y1 = sus + lungimeLatura * (linia + dl[k] - 1);
                        x2 = x1 + lungimeLatura;
                        y2 = y1 + lungimeLatura;
                        xmijloc = (x1 + x2) / 2;
                        ymijloc = (y1 + y2) / 2;
                        setcolor(GREEN);
                        setfillstyle(SOLID_FILL, GREEN);
                        fillellipse(xmijloc, ymijloc, dimensiuneCerc/2, dimensiuneCerc/2);
                    }
                }
            }
        }
    }
    ok = 0;
    while (ok == 0) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            linia = (y - sus) / lungimeLatura + 1;
            coloana = (x - stanga) / lungimeLatura + 1;
            if (TablaDeJoc[linia][coloana] == 3) {
                ok = 1;

                TablaDeJoc[linia][coloana] = jucator;
                x1 = stanga + lungimeLatura * (coloana - 1);
                y1 = sus + lungimeLatura * (linia - 1);
                x2 = x1 + lungimeLatura;
                y2 = y1 + lungimeLatura;
                xmijloc = (x1 + x2) / 2;
                ymijloc = (y1 + y2) / 2;
                setcolor(culoare);
                setfillstyle(SOLID_FILL, culoare);
                fillellipse(xmijloc, ymijloc, dimensiuneCerc, dimensiuneCerc);

                TablaDeJoc[liniaPiesaDeMutat][coloanaPiesaDeMutat] = 0;
                x1 = stanga + lungimeLatura * (coloanaPiesaDeMutat - 1);
                y1 = sus + lungimeLatura * (liniaPiesaDeMutat - 1);
                x2 = x1 + lungimeLatura;
                y2 = y1 + lungimeLatura;
                xmijloc = (x1 + x2) / 2;
                ymijloc = (y1 + y2) / 2;
                setcolor(FUNDAL);
                setfillstyle(SOLID_FILL, FUNDAL);
                fillellipse(xmijloc, ymijloc, dimensiuneCerc, dimensiuneCerc);
                for (k = 0; k <= 3; k++) {
                    if (TablaDeJoc[liniaPiesaDeMutat + dl[k]][coloanaPiesaDeMutat + dc[k]] == 3) {
                        TablaDeJoc[liniaPiesaDeMutat + dl[k]][coloanaPiesaDeMutat + dc[k]] = 0;
                        x1 = stanga + lungimeLatura * (coloanaPiesaDeMutat + dc[k] - 1);
                        y1 = sus + lungimeLatura * (liniaPiesaDeMutat + dl[k] - 1);
                        x2 = x1 + lungimeLatura;
                        y2 = y1 + lungimeLatura;
                        xmijloc = (x1 + x2) / 2;
                        ymijloc = (y1 + y2) / 2;
                        setcolor(FUNDAL);
                        setfillstyle(SOLID_FILL, FUNDAL);
                        fillellipse(xmijloc, ymijloc, dimensiuneCerc/2, dimensiuneCerc/2);
                    }
                }
                //mutarePiesaJucator1();
                break;
            } else {
                for (k = 0; k <= 3; k++) {
                    if (TablaDeJoc[liniaPiesaDeMutat + dl[k]][coloanaPiesaDeMutat + dc[k]] == 3 && liniaPiesaDeMutat + dl[k] > 0 && liniaPiesaDeMutat + dl[k] < 9 && coloanaPiesaDeMutat + dc[k] > 0 && coloanaPiesaDeMutat + dc[k] < 9) {
                        TablaDeJoc[liniaPiesaDeMutat + dl[k]][coloanaPiesaDeMutat + dc[k]] = 0;
                        x1 = stanga + lungimeLatura * (coloanaPiesaDeMutat + dc[k] - 1);
                        y1 = sus + lungimeLatura * (liniaPiesaDeMutat + dl[k] - 1);
                        x2 = x1 + lungimeLatura;
                        y2 = y1 + lungimeLatura;
                        xmijloc = (x1 + x2) / 2;
                        ymijloc = (y1 + y2) / 2;
                        setcolor(FUNDAL);
                        setfillstyle(SOLID_FILL, FUNDAL);
                        fillellipse(xmijloc, ymijloc, dimensiuneCerc/2, dimensiuneCerc/2);
                    }
                }
                mutarePiesaJucator(jucator, culoare);
                break;
            }
        }
    }
}

int detectTrapped() {
    int i, j, albe = 0, negre = 0;
    for (i = 1; i <= 8; i++)
        for (j = 1; j <= 8; j++) {
            if (TablaDeJoc[i][j] == 1 && isTrapped(i, j) == 1)
                albe++;
            else if (TablaDeJoc[i][j] == 2 && isTrapped(i, j) == 1)
                negre++;
        }
    if (albe > negre)
        return 2; //cout << "Player 2 wins\n";
    else if (negre > albe)
        return 1; //afisareCastigator(1);//cout << "Player 1 wins\n";
    else if (negre == albe && albe > 0)
        return 3; //afisareCastigator(3);//cout << "Remiza!\n";
    else return 0;

    /*if(albe>0 || negre>0)
        exit(0);*/
}

int isTrapped(int i, int j) {
    int k, i1, j1;
    for (i1 = 1; i1 <= 8; i1++)
        for (j1 = 1; j1 <= 8; j1++)
            Vizitat[i1][j1] = 0;
    queue < int > QLinie;
    queue < int > QColoana;
    QLinie.push(i);
    QColoana.push(j);
    Vizitat[i][j] = 1;
    while (!QLinie.empty()) {
        for (k = 0; k <= 3; k++)
            if (TablaDeJoc[QLinie.front() + dl[k]][QColoana.front() + dc[k]] == TablaDeJoc[QLinie.front()][QColoana.front()] && Vizitat[QLinie.front() + dl[k]][QColoana.front() + dc[k]] == 0) {
                QLinie.push(QLinie.front() + dl[k]);
                QColoana.push(QColoana.front() + dc[k]);
                Vizitat[QLinie.front() + dl[k]][QColoana.front() + dc[k]] = 1;
            }
        for (k = 0; k <= 3; k++)
            if (TablaDeJoc[QLinie.front() + dl[k]][QColoana.front() + dc[k]] == 0)
                return 0;
        QLinie.pop();
        QColoana.pop();
    }
    return 1;
}
