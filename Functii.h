#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include "animatieInceput.h"
#include "tutorial.h"
#include "initializariJoc.h"
#include "mouseAndClicks.h"
#include "jocCalculatorEasy.h"
#include "jocCalculatorHard.h"



void punerePiesaCalculator(int & numarPiese, int culoare, int coordonatePiese[8][2]) {
    int sus, stanga;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    if(soundOn == 1)
        PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);

    TablaDeJoc[pozFinI][pozFinJ] = 2;
    sus = (inaltimeEcranJoc - latimeTablaJoc) / 2;
    stanga = 50;
    x1 = stanga + lungimeLatura * (pozFinJ - 1);
    y1 = sus + lungimeLatura * (pozFinI - 1);
    x2 = x1 + lungimeLatura;
    y2 = y1 + lungimeLatura;
    xmijloc = (x1 + x2) / 2;
    ymijloc = (y1 + y2) / 2;
    setcolor(culoare);
    setfillstyle(SOLID_FILL, culoare);
    fillellipse(xmijloc, ymijloc, dimensiuneCerc, dimensiuneCerc);
    numarPiese++;
    coordonatePiese[numarPiese/2-1][0]=pozFinI;
    coordonatePiese[numarPiese/2-1][1]=pozFinJ;
}

int verificareColt()
{
    if(TablaDeJoc[1][1]==1)
        return 1;
    else
        if(TablaDeJoc[8][1]==1)
            return 2;
        else
            if(TablaDeJoc[8][8]==1)
                return 3;
            else
                if(TablaDeJoc[1][8]==1)
                    return 4;
    return 0;
}

void strategieColt(int&numarPiese, int colt)
{
    if(colt==1&&numarPiese==1)
    {
        pozFinI=2;
        pozFinJ=1;
    }
    else
        if(colt==1)
        {
            for(int i=2;i<=8;i++)
                if(TablaDeJoc[1][i]==0&&TablaDeJoc[1][i-1]==1&&TablaDeJoc[2][i-1]==2)
                {
                    pozFinI=1;
                    pozFinJ=i;
                    break;
                }
                else
                    if(TablaDeJoc[1][i]==1&&TablaDeJoc[2][i]==0)
                    {
                        pozFinI=2;
                        pozFinJ=i;
                        break;
                    }
        }
    else
        if(colt==2&&numarPiese==1)
    {
        pozFinI=8;
        pozFinJ=2;
    }
    else
        if(colt==2)
        {
            for(int i=7;i>=1;i--)
                if(TablaDeJoc[i][1]==0&&TablaDeJoc[i+1][1]==1&&TablaDeJoc[i+1][2]==2)
                {
                    pozFinI=i;
                    pozFinJ=1;
                    break;
                }
                else
                    if(TablaDeJoc[i][1]==1&&TablaDeJoc[i][2]==0)
                    {
                        pozFinI=i;
                        pozFinJ=2;
                        break;
                    }
        }
    else
    if(colt==3&&numarPiese==1)
    {
        pozFinI=7;
        pozFinJ=8;
    }
    else
        if(colt==3)
        {
            for(int i=7;i>=1;i--)
                if(TablaDeJoc[8][i]==0&&TablaDeJoc[8][i+1]==1&&TablaDeJoc[7][i+1]==2)
                {
                    pozFinI=8;
                    pozFinJ=i;
                    break;
                }
                else
                    if(TablaDeJoc[8][i]==1&&TablaDeJoc[7][i]==0)
                    {
                        pozFinI=7;
                        pozFinJ=i;
                        break;
                    }
        }
    else
        if(colt==4&&numarPiese==1)
    {
        pozFinI=1;
        pozFinJ=7;
    }
    else
        if(colt==4)
        {
            for(int i=2;i<=8;i++)
                if(TablaDeJoc[i][8]==0&&TablaDeJoc[i-1][8]==1&&TablaDeJoc[i-1][7]==2)
                {
                    pozFinI=i;
                    pozFinJ=8;
                    break;
                }
                else
                    if(TablaDeJoc[i][8]==1&&TablaDeJoc[i][7]==0)
                    {
                        pozFinI=i;
                        pozFinJ=7;
                        break;
                    }
        }
}


void afisareRundaJucator1() {
    char ascunde[] = "         ";
    setbkcolor(FUNDAL);
    setcolor(DESENE);
    settextstyle(FONT, 0, 3);

    outtextxy(lungimeEcranJoc-lungimeEcranJoc/6, inaltimeEcranJoc/6, JUCATOR1);
    outtextxy(lungimeEcranJoc-lungimeEcranJoc/6, inaltimeEcranJoc /1.3, ascunde);
}

void afisareRundaJucator2() {
    char ascunde[] = "         ";
    setbkcolor(FUNDAL);
    setcolor(DESENE);
    settextstyle(FONT, 0, 3);

    outtextxy(lungimeEcranJoc-lungimeEcranJoc/6, inaltimeEcranJoc/6, ascunde);
    outtextxy(lungimeEcranJoc-lungimeEcranJoc/6, inaltimeEcranJoc /1.3, JUCATOR2);
}


#endif // FUNCTII_H_INCLUDED
