#ifndef JOCCALCULATOREASY_H_INCLUDED
#define JOCCALCULATOREASY_H_INCLUDED

void urmatoareaMutareEASY(int numarPiese) {
    int i, j, k, pericol, liber;
    int dl[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    int pericolmaxim = -1;
    int liberminim = 4;
    int liniaLibera, coloanaLibera;
    if (numarPiese > 2) {
        for (i = 1; i <= 8; i++)
            for (j = 1; j <= 8; j++) {
                if (TablaDeJoc[i][j] == 2) {
                    pericol = 0;
                    liber = 0;
                    for (k = 0; k <= 3; k++)
                        if (TablaDeJoc[i + dl[k]][j + dc[k]] == 1)
                            pericol++;
                        else
                            if (TablaDeJoc[i + dl[k]][j + dc[k]] == 0) {
                                liber++;
                                liniaLibera = i + dl[k];
                                coloanaLibera = j + dc[k];
                        }

                    if (pericol > pericolmaxim && liber <= liberminim && liber > 0) {
                        pozFinI = liniaLibera;
                        pozFinJ = coloanaLibera;
                        pericolmaxim = pericol;
                        liberminim = liber;
                    }
                }
            }
    } else
        mutareRandom();

}


void mutarePiesaCalculatorEASY(int jucator, int culoare, int coordonatePiese[8][2]) {

    int piesaAleasa;

    int linia, coloana, sus, stanga;
    int x1, y1, x2, y2, k;
    int xmijloc, ymijloc;

    sus = (inaltimeEcranJoc - latimeTablaJoc) / 2;
    stanga = 50;

    do{
        piesaAleasa = rand()%8;
    }while(TablaDeJoc[coordonatePiese[piesaAleasa][0]+1][coordonatePiese[piesaAleasa][1]]!=0
           &&TablaDeJoc[coordonatePiese[piesaAleasa][0]][coordonatePiese[piesaAleasa][1]+1]!=0
           &&TablaDeJoc[coordonatePiese[piesaAleasa][0]][coordonatePiese[piesaAleasa][1]-1]!=0
           &&TablaDeJoc[coordonatePiese[piesaAleasa][0]-1][coordonatePiese[piesaAleasa][1]]!=0
           );

    linia = coordonatePiese[piesaAleasa][0];
    coloana = coordonatePiese[piesaAleasa][1];

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

    int v[4],nr=0;
    delay(700);
    for (k = 0; k <= 3; k++)
        if (TablaDeJoc[linia + dl[k]][coloana + dc[k]] == 3)
        {
            v[nr++]=k;
        }
    int mutareAleasa = rand()%nr;

    coordonatePiese[piesaAleasa][0]+=dl[v[mutareAleasa]];
    coordonatePiese[piesaAleasa][1]+=dc[v[mutareAleasa]];


    TablaDeJoc[coordonatePiese[piesaAleasa][0]][coordonatePiese[piesaAleasa][1]] = jucator;
    x1 = stanga + lungimeLatura * (coordonatePiese[piesaAleasa][1] - 1);
    y1 = sus + lungimeLatura * (coordonatePiese[piesaAleasa][0] - 1);
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


void mutareRandom() {
    do {
        pozFinI = rand() % 5 + 2;
        pozFinJ = rand() % 5 + 2;
    } while (TablaDeJoc[pozFinI][pozFinJ] != 0);
}


#endif // JOCCALCULATOREASY_H_INCLUDED
