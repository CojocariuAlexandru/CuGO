#ifndef INITIALIZARIVARIABILE_H_INCLUDED
#define INITIALIZARIVARIABILE_H_INCLUDED

#define FONT DEFAULT_FONT
#define MAX 10
#define INF 999999999

using namespace std;

//Ecran si I/O
double lungimeEcran = getmaxwidth();
double latimeEcran = getmaxheight();
double ratieEcran = lungimeEcran/latimeEcran;
int inaltimeEcranJoc = latimeEcran - 200;
int lungimeEcranJoc = inaltimeEcranJoc * ratieEcran;
int spatiulDintreButoane = inaltimeEcranJoc / 12;
int inaltimeCaracter = inaltimeEcranJoc / 36;
int latimeCaracter = inaltimeEcranJoc / 26;
int inaltimeCaracterMic = inaltimeEcranJoc / 40;
int latimeCaracterMic = inaltimeEcranJoc / 30;
int MouseX, MouseY, MouseLeftClickX, MouseLeftClickY, MouseRightClickX, MouseRightClickY, MouseLeftUpX, MouseLeftUpY;
int stanga, sus, lungimeTablaJoc, latimeTablaJoc, lungimeLatura, patrateLatura=8;
int TablaDeJoc[MAX][MAX], Vizitat[MAX][MAX], pieseAlbe, pieseNegre, adancimeMaxima=3, mutareFin;
vector<int> pozitiePieseAlbe[3];
vector<int> pozitiePieseNegre[3];

int coordonatePiese[8][2];
int Dificultate = 1; //0 = easy; 1 = medium; 2 = hard;
int Limba = 0; //0 = romana; 1 = engleza
char textDificultate[7]="NORMAL";
char textLimba[7]="ROMANA";
int darkMode=0;
char DarkMode[10]="DARK MODE";
char textDarkMode[4]="OFF";

char CASTIGATOR[22];
char MENIU[6]="MENIU";

const char* title;
char JUCATOR1[]="JUCATOR 1";
char JUCATOR2[]="JUCATOR 2";
char tutorial1[]="Tutorial1.jpg";
char tutorial1En[]="Tutorial1En.jpg";
char tutorial2[]="Tutorial2.jpg";
char tutorial2En[]="Tutorial2En.jpg";
char tutorial3[]="Tutorial3.jpg";
char tutorial3En[]="Tutorial3En.jpg";
char tutorial4[]="Tutorial4.jpg";
char tutorial4En[]="Tutorial4En.jpg";
char SINGLEPLAYER[]="SINGLEPLAYER";
char MULTIPLAYER[]="MULTIPLAYER";
char OPTIONS[]="OPTIUNI";
char IESIRE[]="IESIRE";
char CULORIPIESE[]="CULORI";
char DIFICULTATE[]="DIFICULTATE";
char INAPOI[7]="INAPOI";


int FUNDAL = WHITE;
int DESENE = BLACK;
char LIMBA[9]="LIMBA";

char BackgroundMeniu[13]="poza1.png";
char BackgroundJoc[11]="Joc.jpg";

int gradPericol[10][10], pozFinI, pozFinJ, pieseCalculator[8][2];

int contorCulori=0;
int culoriJucator1[]={ LIGHTCYAN, YELLOW, LIGHTMAGENTA, LIGHTGREEN , LIGHTBLUE, LIGHTRED };
int culoriJucator2[]={ LIGHTRED, LIGHTBLUE, LIGHTGREEN, LIGHTMAGENTA, YELLOW, LIGHTCYAN };
int culoareJucator1 = culoriJucator1[contorCulori];
int culoareJucator2 = culoriJucator2[contorCulori];

void afisareCastigator(int jucator);
void butonRestart(int mod);
void initializareTablaJoc();




//Margini butoane
int topSingleplayer, bottomSingleplayer, leftSingleplayer, rightSingleplayer;
int topMultiplayer, bottomMultiplayer, leftMultiplayer, rightMultiplayer;
int topOPTIUNI, bottomOPTIUNI, leftOPTIUNI, rightOPTIUNI;
int topExit, bottomExit, leftExit, rightExit;

int topDarkMode, bottomDarkMode, leftDarkMode, rightDarkMode;
int topCuloriPiese, bottomCuloriPiese, leftCuloriPiese, rightCuloriPiese;
int topDificultate, bottomDificultate, leftDificultate, rightDificultate;
int topLimba, bottomLimba, leftLimba, rightLimba;
int topBack, bottomBack, leftBack, rightBack;

int topRestart, bottomRestart, leftRestart, rightRestart;
int topMeniu, bottomMeniu, leftMeniu, rightMeniu;

int topTutorial, bottomTutorial, leftTutorial, rightTutorial;
int topInapoi, bottomInapoi, leftInapoi, rightInapoi;
int topUrmatorul, bottomUrmatorul, leftUrmatorul, rightUrmatorul;
int topSunet, bottomSunet, leftSunet, rightSunet;

int undeCursor, varAux;
int dimensiuneCerc;
int soundOn=1;


//Auxiliare
int undeSunt = 1, ok;
char caracter;
int dl[] = {-1,0,1,0}; //DEPLASARE LINIE
int dc[] = {0,1,0,-1}; //DEPLASARE COLOANA

//Functii
void Meniu();
void OPTIUNI();
void CuGOsingleplayer();
void CuGOmultiplayer();
void DarkModeOnOff(int&darkMode);
void conditieIesire();
void joc();
void initializareEcran();
void preluareInput();
void afisareBackgroundMeniu();
void cursorPesteSingleplayer();
void cursorPesteMultiplayer();
void cursorPesteOptiuni();
void cursorPesteExit();
void cursorPesteNimic();
bool clickExit();
bool clickOPTIUNI();
bool clickSingleplayer();
bool clickMultiplayer();
bool clickTutorial();
bool clickInapoi();
bool clickUrmatorul();
bool clickSunet();
void precalculari();
void cursor();
void desen();
void afisareSunet();

void citire();
void mutarePiesaCalculatorHARD();
void urmatoareaMutareHARD();
void afisare();
int FazaI(int adancimeInArbore);
int FazaII(int adancimeInArbore);
double scorTabla();
double scorTabla2();

void punerePiesaJucator(int & numarPiese, int jucator, int culoare);
void mutarePiesaJucator(int jucator, int culoare);
void afisareRundaJucator1();
void afisareRundaJucator2();
int detectTrapped();
int isTrapped(int, int);
void mutareRandom();
void animatieInceput();
void Tutorial();
void Tutorial2();
void Tutorial3();
void Tutorial4();

#endif
