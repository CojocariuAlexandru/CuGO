#ifndef MOUSEANDCLICKS_H_INCLUDED
#define MOUSEANDCLICKS_H_INCLUDED

void preluareInput() {
    MouseX = mousex();
    MouseY = mousey();
    if (kbhit())
        caracter = (char) getch();
    if (ismouseclick(WM_LBUTTONDOWN))
        getmouseclick(WM_LBUTTONDOWN, MouseLeftClickX, MouseLeftClickY);

    if (ismouseclick(WM_LBUTTONUP))
        getmouseclick(WM_LBUTTONUP, MouseLeftUpX, MouseLeftUpY);
}


void cursorPesteSingleplayer() {
    if(undeCursor != 1){
        if (MouseY >= topSingleplayer && MouseY <= bottomSingleplayer && MouseX >= leftSingleplayer && MouseX <= rightSingleplayer) {
            setbkcolor(FUNDAL);
            setcolor(LIGHTGRAY);
            settextstyle(FONT, 0, 4);
            settextjustify(1, 1);
            outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2, SINGLEPLAYER);
            ok = 1;
            undeCursor = 1;
            }
        }
        else if(undeCursor == 1 && !(MouseY >= topSingleplayer && MouseY <= bottomSingleplayer && MouseX >= leftSingleplayer && MouseX <= rightSingleplayer))
            undeCursor = 0;
}

void cursorPesteMultiplayer() {
    if(undeCursor != 2){
        if (MouseY >= topMultiplayer && MouseY <= bottomMultiplayer && MouseX >= leftMultiplayer && MouseX <= rightMultiplayer) {
            int spatiulDintreButoane = inaltimeEcranJoc / 12;
            setbkcolor(FUNDAL);
            setcolor(LIGHTGRAY);
            settextstyle(FONT, 0, 4);
            settextjustify(1, 1);
            outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + spatiulDintreButoane, MULTIPLAYER);
            ok = 1;
            undeCursor = 2;
            }
        }
        else if(undeCursor == 2 && !(MouseY >= topMultiplayer && MouseY <= bottomMultiplayer && MouseX >= leftMultiplayer && MouseX <= rightMultiplayer))
            undeCursor = 0;
}

void cursorPesteOptiuni() {
    if(undeCursor != 3){
        if (MouseY >= topOPTIUNI && MouseY <= bottomOPTIUNI && MouseX >= leftOPTIUNI && MouseX <= rightOPTIUNI) {
            int spatiulDintreButoane = inaltimeEcranJoc / 12;
            setbkcolor(FUNDAL);
            setcolor(LIGHTGRAY);
            settextstyle(FONT, 0, 4);
            settextjustify(1, 1);
            outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane, OPTIONS);
            ok = 1;
            undeCursor=3;
            }
        }
        else if(undeCursor == 3 && !(MouseY >= topOPTIUNI && MouseY <= bottomOPTIUNI && MouseX >= leftOPTIUNI && MouseX <= rightOPTIUNI))
            undeCursor = 0;
}

void cursorPesteExit() {
    if(undeCursor != 4){
        if (MouseY >= topExit && MouseY <= bottomExit && MouseX >= leftExit && MouseX <= rightExit) {
            int spatiulDintreButoane = inaltimeEcranJoc / 12;
            setbkcolor(FUNDAL);
            setcolor(LIGHTGRAY);
            settextstyle(FONT, 0, 4);
            settextjustify(1, 1);
            outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 3 * spatiulDintreButoane, IESIRE);
            ok = 1;
            undeCursor=4;
            }
        }
        else if(undeCursor == 4 && !(MouseY >= topExit && MouseY <= bottomExit && MouseX >= leftExit && MouseX <= rightExit))
            undeCursor = 0;
}


void cursorPesteNimic() {
    if(undeCursor == 0 && varAux == 1){
        int spatiulDintreButoane = inaltimeEcranJoc / 12;
        setbkcolor(FUNDAL);
        setcolor(DESENE);
        settextstyle(FONT, 0, 4);
        settextjustify(1, 1);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2, SINGLEPLAYER);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + spatiulDintreButoane, MULTIPLAYER);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane, OPTIONS);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 3 * spatiulDintreButoane, IESIRE);
        varAux = 0;
        }
        else
        varAux = 1;
}


void cursorPesteDarkMode() {
    if (MouseY >= topDarkMode && MouseY <= bottomDarkMode && MouseX >= leftDarkMode && MouseX <= rightDarkMode) {
        setbkcolor(FUNDAL);
        setcolor(LIGHTGRAY);
        settextstyle(FONT, 0, 4);
        settextjustify(1, 1);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2, DarkMode);

        setcolor(DESENE);
        outtextxy(lungimeEcranJoc / 2 + lungimeEcranJoc/4, inaltimeEcranJoc / 2, textDarkMode);

        ok = 1;
        }
}

void cursorPesteCuloriPiese() {
    if (MouseY >= topCuloriPiese && MouseY <= bottomCuloriPiese && MouseX >= leftCuloriPiese && MouseX <= rightCuloriPiese) {
        int spatiulDintreButoane = inaltimeEcranJoc / 12;

        setcolor(culoareJucator1);
        setfillstyle(SOLID_FILL, culoareJucator1);
        fillellipse(lungimeEcranJoc/2 + lungimeEcranJoc/4, inaltimeEcranJoc/2 + spatiulDintreButoane - 8, 24, 24);


        setcolor(culoareJucator2);
        setfillstyle(SOLID_FILL, culoareJucator2);
        fillellipse(lungimeEcranJoc/2 + lungimeEcranJoc/3.3, inaltimeEcranJoc/2 + spatiulDintreButoane - 8, 24, 24);

        setcolor(FUNDAL);
        setbkcolor(FUNDAL);
        setcolor(LIGHTGRAY);
        settextstyle(FONT, 0, 4);
        settextjustify(1, 1);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + spatiulDintreButoane, CULORIPIESE);
        setfillstyle(SOLID_FILL, culoareJucator1);

        ok = 1;
    }
}

void cursorPesteDificultate() {
    if (MouseY >= topDificultate && MouseY <= bottomDificultate && MouseX >= leftDificultate && MouseX <= rightDificultate) {
        int spatiulDintreButoane = inaltimeEcranJoc / 12;


        setbkcolor(FUNDAL);
        setcolor(LIGHTGRAY);
        settextstyle(FONT, 0, 4);
        settextjustify(1, 1);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane, DIFICULTATE);
        setcolor(DESENE);
        outtextxy(lungimeEcranJoc / 2 + lungimeEcranJoc/3, inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane, textDificultate);
        ok = 1;
    }
}

void cursorPesteLimba() {
    if (MouseY >= topLimba && MouseY <= bottomLimba && MouseX >= leftLimba&& MouseX <= rightLimba) {
        int spatiulDintreButoane = inaltimeEcranJoc / 12;

        setbkcolor(FUNDAL);
        setcolor(LIGHTGRAY);
        settextstyle(FONT, 0, 4);
        settextjustify(1, 1);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 3 * spatiulDintreButoane, LIMBA);
        setcolor(DESENE);
        outtextxy(lungimeEcranJoc / 2 + lungimeEcranJoc/4, inaltimeEcranJoc / 2 + 3 * spatiulDintreButoane, textLimba);
        ok = 1;
    }
}

void cursorPesteInapoi() {
    if (MouseY >= topBack && MouseY <= bottomBack && MouseX >= leftBack && MouseX <= rightBack) {
        int spatiulDintreButoane = inaltimeEcranJoc / 12;

        setbkcolor(FUNDAL);
        setcolor(LIGHTGRAY);
        settextstyle(FONT, 0, 4);
        settextjustify(1, 1);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 4 * spatiulDintreButoane, INAPOI);
        ok = 1;
    }
}

void cursorPesteNimicOPTIUNI() {
    if (ok == 0) {
        int spatiulDintreButoane = inaltimeEcranJoc / 12;

        setcolor(FUNDAL);
        setfillstyle(SOLID_FILL, FUNDAL);
        fillellipse(lungimeEcranJoc/2 + lungimeEcranJoc/4, inaltimeEcranJoc/2 + spatiulDintreButoane - 8, 24, 24);
        fillellipse(lungimeEcranJoc/2 + lungimeEcranJoc/3.3, inaltimeEcranJoc/2 + spatiulDintreButoane - 8, 24, 24);

        setbkcolor(FUNDAL);
        setcolor(DESENE);
        settextstyle(FONT, 0, 4);
        settextjustify(1, 1);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2, DarkMode);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + spatiulDintreButoane, CULORIPIESE);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane, DIFICULTATE);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 3 * spatiulDintreButoane, LIMBA);
        outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 4 * spatiulDintreButoane, INAPOI);
        setcolor(FUNDAL);
        outtextxy(lungimeEcranJoc / 2 + lungimeEcranJoc/4, inaltimeEcranJoc / 2, textDarkMode);
        outtextxy(lungimeEcranJoc / 2 + lungimeEcranJoc/3, inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane, textDificultate);
        outtextxy(lungimeEcranJoc / 2 + lungimeEcranJoc/4, inaltimeEcranJoc / 2 + 3 * spatiulDintreButoane, textLimba);

    }
}

void cursorAfisareCastigator(int x, int y) {
    char textButonRestart[] = "RESTART";
    if (x > leftRestart && x < rightRestart && y > topRestart && y < bottomRestart) {
            setcolor(LIGHTGRAY);
            outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + spatiulDintreButoane, textButonRestart);
        } else if (x > leftMeniu && x < rightMeniu && y > topMeniu && y < bottomMeniu) {
            setcolor(LIGHTGRAY);
            outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane, MENIU);
        } else {
            setcolor(DESENE);
            outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + spatiulDintreButoane, textButonRestart);
            outtextxy(lungimeEcranJoc / 2, inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane, MENIU);
        }
}

bool clickSingleplayer() {
    if (MouseLeftClickX >= leftSingleplayer && MouseLeftClickX <= rightSingleplayer && MouseLeftClickY >= topSingleplayer && MouseLeftClickY <= bottomSingleplayer)
        return 1;
    return 0;
}

bool clickMultiplayer() {
    if (MouseLeftClickX >= leftMultiplayer && MouseLeftClickX <= rightMultiplayer && MouseLeftClickY >= topMultiplayer && MouseLeftClickY <= bottomMultiplayer)
        return 1;
    return 0;
}

bool clickOPTIUNI() {
    if (MouseLeftClickX >= leftOPTIUNI && MouseLeftClickX <= rightOPTIUNI && MouseLeftClickY >= topOPTIUNI && MouseLeftClickY <= bottomOPTIUNI)
        return 1;
    return 0;
}

bool clickExit() {
    if (MouseLeftClickX >= leftExit && MouseLeftClickX <= rightExit && MouseLeftClickY >= topExit && MouseLeftClickY <= bottomExit)
        return 1;
    return 0;
}

bool clickDarkMode() {
    if (MouseLeftClickX >= leftDarkMode && MouseLeftClickX <= rightDarkMode && MouseLeftClickY >= topDarkMode && MouseLeftClickY <= bottomDarkMode)
        return 1;
    return 0;
}

bool clickCuloriPiese() {
    if (MouseLeftClickX >= leftCuloriPiese && MouseLeftClickX <= rightCuloriPiese && MouseLeftClickY >= topCuloriPiese && MouseLeftClickY <= bottomCuloriPiese)
        return 1;
    return 0;
}

bool clickDificultate() {
    if (MouseLeftClickX >= leftDificultate && MouseLeftClickX <= rightDificultate && MouseLeftClickY >= topDificultate && MouseLeftClickY <= bottomDificultate)
        return 1;
    return 0;
}

bool clickLimba() {
    if (MouseLeftClickX >= leftLimba && MouseLeftClickX <= rightLimba&& MouseLeftClickY >= topLimba && MouseLeftClickY <= bottomLimba)
        return 1;
    return 0;
}

bool clickInapoiMeniu() {
    if (MouseLeftClickX >= leftBack && MouseLeftClickX <= rightBack && MouseLeftClickY >= topBack && MouseLeftClickY <= bottomBack)
        return 1;
    return 0;
}

bool clickTutorial(){
    if(MouseLeftClickX >= leftTutorial && MouseLeftClickX <= rightTutorial && MouseLeftClickY>=topTutorial && MouseLeftClickY<=bottomTutorial)
        return 1;
    return 0;
}


bool clickMeniu() {
    if (MouseLeftClickX > leftMeniu && MouseLeftClickX < rightMeniu && MouseLeftClickY > topMeniu && MouseLeftClickY < bottomMeniu)
        return 1;
    return 0;
}

bool clickRestart() {
    if (MouseLeftClickX > leftRestart && MouseLeftClickX < rightRestart && MouseLeftClickY > topRestart && MouseLeftClickY < bottomRestart)
        return 1;
    else return 0;
}

bool clickSunet() {
    if (MouseLeftClickX > leftSunet && MouseLeftClickX < rightSunet && MouseLeftClickY > topSunet && MouseLeftClickY < bottomSunet)
        return 1;
    else return 0;
}


#endif // MOUSEANDCLICKS_H_INCLUDED
