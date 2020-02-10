#ifndef ANIMATIEINCEPUT_H_INCLUDED
#define ANIMATIEINCEPUT_H_INCLUDED
#include <cstring>

void animatieInceput(){
    int i;
    char titluri[50][50] = {"Anim5%.jpg", "Anim10%.jpg", "Anim15%.jpg", "Anim20%.jpg", "Anim25%.jpg", "Anim30%.jpg", "Anim35%.jpg", "Anim40%.jpg", "Anim45%.jpg", "Anim50%.jpg", "Anim55%.jpg", "Anim60%.jpg", "Anim65%.jpg", "Anim70%.jpg", "Anim75%.jpg", "Anim80%.jpg", "Anim85%.jpg", "Anim90%.jpg", "Anim95%.jpg", "AnimFull.jpg"};
    for(i=0; i<=19; i++){
        if(kbhit())
            return;
        //strcpy(title, titluri[i][0]);
        readimagefile(titluri[i], 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
        delay(40);
        }
    delay(2000);
    for(i=18; i>=0; i--){
        if(kbhit())
            return;
        //strcpy(title, titluri[i][0]);
        readimagefile(titluri[i], 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
        delay(40);
        }
    cleardevice();
    delay(1000);
}


#endif // ANIMATIEINCEPUT_H_INCLUDED
