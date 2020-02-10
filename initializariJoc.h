#ifndef INITIALIZARIJOC_H_INCLUDED
#define INITIALIZARIJOC_H_INCLUDED


void initializareEcran() {
    initwindow(lungimeEcranJoc, inaltimeEcranJoc, "CuGO");
}

void afisareBackgroundMeniu() {
    const char * title = BackgroundMeniu;
    readimagefile(title, 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
}


void desen() {
    int i, j, sus, stanga;
    setcolor(DESENE);
    latimeTablaJoc = lungimeTablaJoc = inaltimeEcranJoc - 100;
    lungimeLatura = latimeTablaJoc / patrateLatura;
    dimensiuneCerc = lungimeLatura/3.5;
    sus = (inaltimeEcranJoc - latimeTablaJoc) / 2;
    stanga = 50;
    for (i = 1; i <= patrateLatura; i++)
        for (j = 1; j <= patrateLatura; j++)
            rectangle(stanga + lungimeLatura * (i - 1), sus + lungimeLatura * (j - 1), stanga + lungimeLatura * i, sus + lungimeLatura * j);
}


void initializareTablaJoc() {
    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)
            TablaDeJoc[i][j] = 0;
}

void precalculari() {
    int i;

    topSingleplayer = inaltimeEcranJoc / 2 - inaltimeCaracter;
    bottomSingleplayer = inaltimeEcranJoc / 2;
    if(strlen(SINGLEPLAYER)%2==1)
    {
        leftSingleplayer = lungimeEcranJoc / 2 - (strlen(SINGLEPLAYER)/2+1) * latimeCaracter;
        rightSingleplayer = lungimeEcranJoc / 2 + (strlen(SINGLEPLAYER)/2+1) * latimeCaracter;
    }
    else
    {
        leftSingleplayer = lungimeEcranJoc / 2 - strlen(SINGLEPLAYER)/2 * latimeCaracter;
        rightSingleplayer = lungimeEcranJoc / 2 + strlen(SINGLEPLAYER)/2 * latimeCaracter;

    }

    topMultiplayer = inaltimeEcranJoc / 2 + spatiulDintreButoane - inaltimeCaracter;
    bottomMultiplayer = inaltimeEcranJoc / 2 + spatiulDintreButoane;
    if(strlen(MULTIPLAYER)%2==1)
    {
        leftMultiplayer = lungimeEcranJoc / 2 - (strlen(MULTIPLAYER)/2+1) * latimeCaracter;
        rightMultiplayer = lungimeEcranJoc / 2 + (strlen(MULTIPLAYER)/2+1) * latimeCaracter;
    }
    else
    {
        leftMultiplayer = lungimeEcranJoc / 2 - strlen(MULTIPLAYER)/2 * latimeCaracter;
        rightMultiplayer = lungimeEcranJoc / 2 + strlen(MULTIPLAYER)/2 * latimeCaracter;

    }

    topOPTIUNI = inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane - inaltimeCaracter;
    bottomOPTIUNI = inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane;
    if(strlen(OPTIONS)%2==1)
    {
        leftOPTIUNI = lungimeEcranJoc / 2 - (strlen(OPTIONS)/2+1) * latimeCaracter;
        rightOPTIUNI = lungimeEcranJoc / 2 + (strlen(OPTIONS)/2+1) * latimeCaracter;
    }
    else
    {
        leftOPTIUNI = lungimeEcranJoc / 2 - strlen(OPTIONS)/2 * latimeCaracter;
        rightOPTIUNI = lungimeEcranJoc / 2 + strlen(OPTIONS)/2 * latimeCaracter;

    }

    topExit = inaltimeEcranJoc / 2 + 3 * spatiulDintreButoane - inaltimeCaracter;
    bottomExit = inaltimeEcranJoc / 2 + 3 * spatiulDintreButoane;
    if(strlen(IESIRE)%2==1)
    {
        leftExit = lungimeEcranJoc / 2 - (strlen(IESIRE)/2+1) * latimeCaracter;
        rightExit = lungimeEcranJoc / 2 + (strlen(IESIRE)/2+1) * latimeCaracter;
    }
    else
    {
        leftExit = lungimeEcranJoc / 2 - strlen(IESIRE)/2 * latimeCaracter;
        rightExit = lungimeEcranJoc / 2 + strlen(IESIRE)/2 * latimeCaracter;

    }

    topDarkMode = inaltimeEcranJoc / 2 - inaltimeCaracter;
    bottomDarkMode = inaltimeEcranJoc / 2;
    if(strlen(DarkMode)%2==1)
    {
        leftDarkMode = lungimeEcranJoc / 2 - (strlen(DarkMode)/2+1) * latimeCaracter;
        rightDarkMode = lungimeEcranJoc / 2 + (strlen(DarkMode)/2+1) * latimeCaracter;
    }
    else
    {
        leftDarkMode = lungimeEcranJoc / 2 - strlen(DarkMode)/2 * latimeCaracter;
        rightDarkMode = lungimeEcranJoc / 2 + strlen(DarkMode)/2 * latimeCaracter;
    }

    topCuloriPiese = inaltimeEcranJoc / 2 + spatiulDintreButoane - inaltimeCaracter;
    bottomCuloriPiese = inaltimeEcranJoc / 2 + spatiulDintreButoane;
    if(strlen(CULORIPIESE)%2==1)
    {
        leftCuloriPiese = lungimeEcranJoc / 2 - (strlen(CULORIPIESE)/2+1) * latimeCaracter;
        rightCuloriPiese = lungimeEcranJoc / 2 + (strlen(CULORIPIESE)/2+1) * latimeCaracter;
    }
    else
    {
        leftCuloriPiese = lungimeEcranJoc / 2 - strlen(CULORIPIESE)/2 * latimeCaracter;
        rightCuloriPiese = lungimeEcranJoc / 2 + strlen(CULORIPIESE)/2 * latimeCaracter;
    }

    topDificultate = inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane - inaltimeCaracter;
    bottomDificultate = inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane;
    if(strlen(DIFICULTATE)%2==1)
    {
        leftDificultate = lungimeEcranJoc / 2 - (strlen(DIFICULTATE)/2+1) * latimeCaracter;
        rightDificultate = lungimeEcranJoc / 2 + (strlen(DIFICULTATE)/2+1) * latimeCaracter;
    }
    else
    {
        leftDificultate = lungimeEcranJoc / 2 - strlen(DIFICULTATE)/2 * latimeCaracter;
        rightDificultate = lungimeEcranJoc / 2 + strlen(DIFICULTATE)/2 * latimeCaracter;
    }

    topLimba = inaltimeEcranJoc / 2 + 3 * spatiulDintreButoane - inaltimeCaracter;
    bottomLimba = inaltimeEcranJoc / 2 + 3 * spatiulDintreButoane;
    if(strlen(LIMBA)%2==1)
    {
        leftLimba = lungimeEcranJoc / 2 - (strlen(LIMBA)/2+1) * latimeCaracter;
        rightLimba = lungimeEcranJoc / 2 + (strlen(LIMBA)/2+1) * latimeCaracter;
    }
    else
    {
        leftLimba = lungimeEcranJoc / 2 - strlen(LIMBA)/2 * latimeCaracter;
        rightLimba = lungimeEcranJoc / 2 + strlen(LIMBA)/2 * latimeCaracter;
    }

    topBack = inaltimeEcranJoc / 2 + 4 * spatiulDintreButoane - inaltimeCaracter;
    bottomBack = inaltimeEcranJoc / 2 + 4 * spatiulDintreButoane;
    if(strlen(INAPOI)%2==1)
    {
        leftBack = lungimeEcranJoc / 2 - (strlen(INAPOI)/2+1) * latimeCaracter;
        rightBack = lungimeEcranJoc / 2 + (strlen(INAPOI)/2+1) * latimeCaracter;
    }
    else
    {
        leftBack = lungimeEcranJoc / 2 - strlen(INAPOI)/2 * latimeCaracter;
        rightBack = lungimeEcranJoc / 2 + strlen(INAPOI)/2 * latimeCaracter;
    }

    //MouseLeftClickX > lungimeEcranJoc / 2 - 2.5 * lungimeEcranJoc / 35 && MouseLeftClickX < lungimeEcranJoc / 2 + 2.5 * lungimeEcranJoc / 35 &&
      //  MouseLeftClickY > inaltimeEcranJoc / 2 + 2 * inaltimeEcranJoc / 12 - inaltimeEcranJoc / 40 && MouseLeftClickY < inaltimeEcranJoc / 2 + 2 * inaltimeEcranJoc / 12 + inaltimeEcranJoc / 40)

    topMeniu = inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane - inaltimeCaracterMic;
    bottomMeniu = inaltimeEcranJoc / 2 + 2 * spatiulDintreButoane;
    if(strlen(MENIU)%2==1)
    {
        leftMeniu = lungimeEcranJoc / 2 - (strlen(MENIU)/2+1) * latimeCaracter;
        rightMeniu = lungimeEcranJoc / 2 + (strlen(MENIU)/2+1) * latimeCaracter;
    }
    else
    {
        leftMeniu = lungimeEcranJoc / 2 - strlen(MENIU)/2 * latimeCaracter;
        rightMeniu = lungimeEcranJoc / 2 + strlen(MENIU)/2 * latimeCaracter;
    }

    topRestart = inaltimeEcranJoc / 2 + spatiulDintreButoane - inaltimeCaracterMic;
    bottomRestart = inaltimeEcranJoc / 2 + spatiulDintreButoane;
    if(strlen("RESTART")%2==1)
    {
        leftRestart = lungimeEcranJoc / 2 - (strlen("RESTART")/2+1) * latimeCaracter;
        rightRestart = lungimeEcranJoc / 2 + (strlen("RESTART")/2+1) * latimeCaracter;
    }
    else
    {
        leftRestart = lungimeEcranJoc / 2 - strlen("RESTART")/2 * latimeCaracter;
        rightRestart = lungimeEcranJoc / 2 + strlen("RESTART")/2 * latimeCaracter;
    }

    topTutorial = inaltimeEcranJoc - inaltimeEcranJoc/4;
    bottomTutorial = inaltimeEcranJoc - inaltimeEcranJoc/20;
    leftTutorial = lungimeEcranJoc/26;
    rightTutorial = lungimeEcranJoc/8;

    topInapoi = inaltimeEcranJoc - inaltimeEcranJoc/3.9;
    bottomInapoi = inaltimeEcranJoc - inaltimeEcranJoc/20;
    leftInapoi = lungimeEcranJoc/18;
    rightInapoi = lungimeEcranJoc/3.5;

    topUrmatorul = inaltimeEcranJoc - inaltimeEcranJoc/3.9;
    bottomUrmatorul = inaltimeEcranJoc - inaltimeEcranJoc/20;
    leftUrmatorul = lungimeEcranJoc - lungimeEcranJoc/3.9;
    rightUrmatorul = lungimeEcranJoc - lungimeEcranJoc/20;

    topSunet = inaltimeEcranJoc-inaltimeEcranJoc/5;
    bottomSunet = inaltimeEcranJoc-inaltimeEcranJoc/20;
    leftSunet = lungimeEcranJoc-lungimeEcranJoc/6;
    rightSunet = lungimeEcranJoc-lungimeEcranJoc/25;

    for(i=0; i<=9; i++)
        TablaDeJoc[0][i] = TablaDeJoc[i][0] = TablaDeJoc[9][i] = TablaDeJoc[i][9] = 1;
}

#endif // INITIALIZARIJOC_H_INCLUDED
