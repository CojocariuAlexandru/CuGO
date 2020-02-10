#ifndef JOCCALCULATORHARD_H_INCLUDED
#define JOCCALCULATORHARD_H_INCLUDED


void urmatoareaMutareHARD(){
    int i, j;
    pieseAlbe = pieseNegre = 0;
    pozitiePieseAlbe[0].clear();
    pozitiePieseAlbe[1].clear();
    pozitiePieseNegre[0].clear();
    pozitiePieseNegre[1].clear();
    for(i=1; i<=8; i++)
        for(j=1; j<=8; j++){
            if(TablaDeJoc[i][j] == 1){
                pieseAlbe++;
                pozitiePieseAlbe[0].push_back(i);
                pozitiePieseAlbe[1].push_back(j);
                }
                else if(TablaDeJoc[i][j] == 2){
                    pieseNegre++;
                    pozitiePieseNegre[0].push_back(i);
                    pozitiePieseNegre[1].push_back(j);
                    }
            }
    if(pieseNegre < 8)
        FazaI(1);
}

int FazaI(int adancimeInArbore){
    int i, j;
    double scor, scormaxim, scorminim;
    if(pieseNegre == 0){
        pozFinI = rand() % 2;
        pozFinJ = rand() % 2;
        while(TablaDeJoc[pozFinI][pozFinJ] != 1){
            pozFinI = rand() % 2;
            pozFinJ = rand() % 2;
            }
        pozFinI+=4; pozFinJ+=4;
        return 0;
        }
    if(adancimeInArbore == 1){
       scormaxim = -2;
       for(i=1; i<=8; i++)
            for(j=1; j<=8; j++){
                if(TablaDeJoc[i][j] == 0){
                    TablaDeJoc[i][j] = 2;
                    scor = scorTabla();
                    if(scor == INF){
                        pozFinI = i;
                        pozFinJ = j;
                        goto loop;
                        }
                        else if(scor == -1){
                            TablaDeJoc[i][j] = 0;
                            continue;
                            }
                    pozitiePieseNegre[0].push_back(i);
                    pozitiePieseNegre[1].push_back(j);
                    scor = FazaI(adancimeInArbore+1);
                    if(scor > scormaxim){
                        scormaxim = scor;
                        pozFinI = i;
                        pozFinJ = j;
                        }
                    TablaDeJoc[i][j] = 0;
                    pozitiePieseNegre[0].pop_back();
                    pozitiePieseNegre[1].pop_back();
                    }
                }
        loop:
        return 0;
        }
    if(adancimeInArbore == 2){
        scorminim = INF+1;
        for(i=1; i<=8; i++){
            for(j=1; j<=8; j++){
                if(TablaDeJoc[i][j] == 0){
                    TablaDeJoc[i][j] = 1;
                    scor = scorTabla();
                    if(scor == -1){
                        TablaDeJoc[i][j] = 0;
                        return -1;
                        }
                        else if(scor == INF){
                            TablaDeJoc[i][j] = 0;
                            return INF;
                            }
                    pozitiePieseAlbe[0].push_back(i);
                    pozitiePieseAlbe[1].push_back(j);
                    scor = FazaI(adancimeInArbore+1);
                    if(scor < scorminim)
                        scorminim = scor;
                    TablaDeJoc[i][j] = 0;
                    pozitiePieseAlbe[0].pop_back();
                    pozitiePieseAlbe[1].pop_back();
                    if(scorminim == -1)
                        return -1;
                    }
                }
            }
        return scorminim;
        }
    if(adancimeInArbore == 3){
        scormaxim = -2;
        scor = scorTabla();
        if(scor == -1)
            return -1;
            else if(scor == INF)
                return INF;
        for(i=1; i<=8; i++)
            for(j=1; j<=8; j++){
                if(TablaDeJoc[i][j] == 0){
                    TablaDeJoc[i][j] = 2;
                    pozitiePieseNegre[0].push_back(i);
                    pozitiePieseNegre[1].push_back(j);
                    scor = scorTabla();
                    if(scor > scormaxim)
                        scormaxim = scor;
                    TablaDeJoc[i][j] = 0;
                    pozitiePieseNegre[0].pop_back();
                    pozitiePieseNegre[1].pop_back();
                    }
                }
        return scormaxim;
        }
        else
        return 0;
}

int FazaII(int adancimeInArbore){
    int i, j, k;
    sus = (inaltimeEcranJoc - latimeTablaJoc) / 2;
    stanga = 50;
    double scor, scormaxim, scorminim;
    if(adancimeInArbore == 1){
       scormaxim = -2;
       for(i=1; i<=8; i++)
            for(j=1; j<=8; j++){
                if(TablaDeJoc[i][j] == 2){
                    for(k=0; k<=3; k++)
                        if(TablaDeJoc[i+dl[k]][j+dc[k]] == 0){
                            TablaDeJoc[i+dl[k]][j+dc[k]] = 2;
                            TablaDeJoc[i][j] = 0;
                            scor = scorTabla2();
                            if(scor == -1){
                                TablaDeJoc[i][j] = 2;
                                TablaDeJoc[i+dl[k]][j+dc[k]] = 0;
                                continue;
                                }
                            else if(scor == INF){
                                pozFinI = i;
                                pozFinJ = j;
                                goto loop2;
                                }
                            scor = FazaII(adancimeInArbore+1);
                            if(scor > scormaxim){
                                scormaxim = scor;
                                pozFinI = i;
                                pozFinJ = j;
                                mutareFin = k;
                                }
                            TablaDeJoc[i+dl[k]][j+dc[k]] = 0;
                            TablaDeJoc[i][j] = 2;
                            }
                    }
                }
        loop2:
        return 0;
        }
    if(adancimeInArbore == 2){
        scorminim = INF+1;
        scor = scorTabla();
        if(scor == -1)
            return -1;
            else if(scor == INF)
                return INF;
      for(i=1; i<=8; i++)
            for(j=1; j<=8; j++){
                if(TablaDeJoc[i][j] == 1){
                    for(k=0; k<=3; k++)
                        if(TablaDeJoc[i+dl[k]][j+dc[k]] == 0){
                            TablaDeJoc[i+dl[k]][j+dc[k]] = 1;
                            TablaDeJoc[i][j] = 0;
                            scor = FazaII(adancimeInArbore+1);
                            if(scor  < scorminim)
                                scorminim = scor;
                            TablaDeJoc[i+dl[k]][j+dc[k]] = 0;
                            TablaDeJoc[i][j] = 1;
                            if(scorminim == -1)
                                return -1;
                            }
                    }
                }
        return scorminim;
        }
    if(adancimeInArbore == 3){
        scormaxim = -2;
        scor = scorTabla();
        if(scor == -1)
            return -1;
            else if(scor == INF)
                return INF;
        for(i=1; i<=8; i++)
            for(j=1; j<=8; j++){
                if(TablaDeJoc[i][j] == 2){
                    for(k=0; k<=3; k++)
                        if(TablaDeJoc[i+dl[k]][j+dc[k]] == 0){
                            TablaDeJoc[i+dl[k]][j+dc[k]] = 2;
                            TablaDeJoc[i][j] = 0;
                            scor = scorTabla2();
                            if(scor > scormaxim)
                                scormaxim = scor;
                            TablaDeJoc[i+dl[k]][j+dc[k]] = 0;
                            TablaDeJoc[i][j] = 2;
                            }
                    }
                }
        return scormaxim;
        }
        else
        return 0;
}


double scorTabla(){
    unsigned int i, j, k;
    int threatMe=0, threatMeAux=0, safeMe=0, threatHim=0, threatHimAux=0, safeHim=0;
    for(i=1; i<=8; i++)
        for(j=1; j<=8; j++){
            if(TablaDeJoc[i][j] == 1)
                if(isTrapped(i, j))
                    return INF;
            if(TablaDeJoc[i][j] == 2)
                if(isTrapped(i, j))
                    return -1;
            }
    for(i=0; i<pozitiePieseNegre[0].size(); i++){
        threatMeAux = threatMe;
        for(k=0; k<=3; k++)
             if(TablaDeJoc[pozitiePieseNegre[0][i]+dl[k]][pozitiePieseNegre[1][i]+dc[k]] == 1)
                threatMe++;
                else if(TablaDeJoc[pozitiePieseNegre[0][i]+dl[k]][pozitiePieseNegre[1][i]+dc[k]] == 2)
                    safeMe++;
        if(pozitiePieseNegre[0][i]+1>8 || pozitiePieseNegre[0][i]-1<1)
            threatMe++;
        if(pozitiePieseNegre[1][i]+1>8 || pozitiePieseNegre[1][i]-1<1)
            threatMe++;
        if(threatMe - threatMeAux == 1)
            threatMe = threatMeAux+1;
            else if(threatMe - threatMeAux == 2)
                threatMe = threatMeAux+5;
                 else if(threatMe - threatMeAux == 3)
                    threatMe = threatMeAux + 20;
        }
    for(i=0; i<pozitiePieseAlbe[0].size(); i++){
        threatHimAux = threatHim;
        for(k=0; k<=3; k++)
            if(TablaDeJoc[pozitiePieseAlbe[0][i]+dl[k]][pozitiePieseAlbe[1][i]+dc[k]] == 2)
                threatHim++;
                else if(TablaDeJoc[pozitiePieseAlbe[0][i]+dl[k]][pozitiePieseAlbe[1][i]+dc[k]] == 1)
                    safeHim++;
        if(pozitiePieseAlbe[0][i]+1>8 || pozitiePieseAlbe[0][i]-1<1)
            threatHim++;
        if(pozitiePieseAlbe[1][i]+1>8 || pozitiePieseAlbe[1][i]-1<1)
            threatHim++;
        if(threatHim - threatHimAux == 1)
            threatHim = threatHimAux+1;
            else if(threatHim - threatHimAux == 2)
                threatHim = threatHimAux+5;
                 else if(threatHim - threatHimAux == 3)
                    threatHim = threatHimAux + 20;

        }
    return 100 - threatMe + 2*threatHim + safeMe - safeHim;
}

double scorTabla2(){
    int i, j, k, pericol=0, pericolaux=0, castig=0, castigaux=0;
    for(i=1; i<=8; i++)
        for(j=1; j<=8; j++){
            if(TablaDeJoc[i][j] == 1)
                if(isTrapped(i, j))
                    return INF;
            if(TablaDeJoc[i][j] == 2)
                if(isTrapped(i, j))
                    return -1;
            }
    for(i=1; i<=8; i++)
        for(j=1; j<=8; j++){
            if(TablaDeJoc[i][j] == 2){
                pericolaux = pericol;
                for(k=0; k<=3; k++)
                     if(TablaDeJoc[i+dl[k]][j+dc[k]] == 1)
                        pericol++;
                if(i+1>8 || i-1<1)
                    pericol++;
                if(j+1>8 || j-1<1)
                    pericol++;
                if(pericol - pericolaux == 1)
                    pericol = pericolaux+1;
                    else if(pericol - pericolaux == 2)
                        pericol = pericolaux+3;
                         else if(pericol - pericolaux == 3)
                            pericol = pericolaux + 5;
                }
            if(TablaDeJoc[i][j] == 1){
                castigaux = castig;
                for(k=0; k<=3; k++)
                    if(TablaDeJoc[i+dl[k]][j+dc[k]] == 2)
                        castig++;
                if(i+1>8 || i-1<1)
                    castig++;
                if(j+1>8 || j-1<1)
                    castig++;
                 if(castig - castigaux == 1)
                    castig = castigaux+1;
                    else if(castig - castigaux == 2)
                        castig = castigaux+3;
                         else if(castig - castigaux == 3)
                            castig = castigaux + 5;
                }
            }
    return 100 - pericol + castig/2;
}


void mutarePiesaCalculatorHARD(int jucator, int culoare)
{

    int k;
    int linia, coloana, sus, stanga;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;

    FazaII(1);

    cout<<pozFinI<<" "<<pozFinJ<<" "<<mutareFin<<endl;

    sus = (inaltimeEcranJoc - latimeTablaJoc) / 2;
    stanga = 50;

    linia = pozFinI;
    coloana = pozFinJ;

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
    delay(1000);

    pozFinI+=dl[mutareFin];
    pozFinJ+=dc[mutareFin];


    TablaDeJoc[pozFinI][pozFinJ] = jucator;
    x1 = stanga + lungimeLatura * (pozFinJ - 1);
    y1 = sus + lungimeLatura * (pozFinI - 1);
    x2 = x1 + lungimeLatura;
    y2 = y1 + lungimeLatura;
    xmijloc = (x1 + x2) / 2;
    ymijloc = (y1 + y2) / 2;
    setcolor(culoare);
    setfillstyle(SOLID_FILL, culoare);
    fillellipse(xmijloc, ymijloc, dimensiuneCerc, dimensiuneCerc);

    TablaDeJoc[linia][coloana] = 0;
    x1 = stanga + lungimeLatura * (coloana - 1);
    y1 = sus + lungimeLatura * (linia - 1);
    x2 = x1 + lungimeLatura;
    y2 = y1 + lungimeLatura;
    xmijloc = (x1 + x2) / 2;
    ymijloc = (y1 + y2) / 2;
    setcolor(FUNDAL);
    setfillstyle(SOLID_FILL, FUNDAL);
    fillellipse(xmijloc, ymijloc, dimensiuneCerc, dimensiuneCerc);

    for (k = 0; k <= 3; k++) {
        if (TablaDeJoc[linia + dl[k]][coloana + dc[k]] == 3) {
            TablaDeJoc[linia + dl[k]][coloana + dc[k]] = 0;
            x1 = stanga + lungimeLatura * (coloana + dc[k] - 1);
            y1 = sus + lungimeLatura * (linia + dl[k] - 1);
            x2 = x1 + lungimeLatura;
            y2 = y1 + lungimeLatura;
            xmijloc = (x1 + x2) / 2;
            ymijloc = (y1 + y2) / 2;
            setcolor(FUNDAL);
            setfillstyle(SOLID_FILL, FUNDAL);
            fillellipse(xmijloc, ymijloc, dimensiuneCerc/2, dimensiuneCerc/2);
        }
    }
}


#endif // JOCCALCULATORHARD_H_INCLUDED
