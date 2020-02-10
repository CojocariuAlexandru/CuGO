#ifndef TUTORIAL_H_INCLUDED
#define TUTORIAL_H_INCLUDED

void Tutorial() {
    if(Limba == 0)
        title = tutorial1;
        else
        title = tutorial1En;
    readimagefile(title, 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
    while (1) {
        preluareInput();
        if (clickInapoi()) {
            if(soundOn == 1)
                PlaySound(TEXT("Button.wav"), NULL, SND_SYNC);
            undeSunt = 1;
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            break;
        }
        if (clickUrmatorul()) {
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            Tutorial2();
            if(Limba == 0)
                title = tutorial1;
                else
                title = tutorial1En;
            readimagefile(title, 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
        }
    }
}

void Tutorial2() {
    if(Limba == 0)
        title = tutorial2;
        else
        title = tutorial2En;
    readimagefile(title, 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
    while (1) {
        preluareInput();
        if (clickInapoi()) {
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            break;
        }
        if (clickUrmatorul()) {
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            Tutorial3();
            if(Limba == 0)
                title = tutorial2;
                else
                title = tutorial2En;
            readimagefile(title, 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
        }
    }
}

void Tutorial3() {
    if(Limba == 0)
        title = tutorial3;
        else
        title = tutorial3En;
    readimagefile(title, 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
    while (1) {
        preluareInput();
        if (clickInapoi()) {
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            break;
        }
        if (clickUrmatorul()) {
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            Tutorial4();
            if(Limba == 0)
                title = tutorial3;
                else
                title = tutorial3En;
            readimagefile(title, 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
        }
    }
}

void Tutorial4() {
    if(Limba == 0)
        title = tutorial4;
        else
        title = tutorial4En;
    readimagefile(title, 0, 0, lungimeEcranJoc, inaltimeEcranJoc);
    while (1) {
        preluareInput();
        if (clickInapoi()) {
            if(soundOn == 1)
                PlaySound(TEXT("Click.wav"), NULL, SND_SYNC);
            MouseLeftClickX = 0;
            MouseLeftClickY = 0;
            break;
        }
    }
}

bool clickInapoi(){
    if(MouseLeftClickX >= leftInapoi && MouseLeftClickX <= rightInapoi && MouseLeftClickY>=topInapoi && MouseLeftClickY<=bottomInapoi)
        return 1;
    return 0;
}

bool clickUrmatorul(){
    if(MouseLeftClickX >= leftUrmatorul && MouseLeftClickX <= rightUrmatorul && MouseLeftClickY>=topUrmatorul && MouseLeftClickY<=bottomUrmatorul)
        return 1;
    return 0;
}
#endif // TUTORIAL_H_INCLUDED
