//@orga=GoTronic
//@author=Sylvain G.

#include <OneSheeld.h>
#define CUSTOM_SETTINGS
#define INCLUDE_MUSIC_PLAYER_SHIELD
#define INCLUDE_KEYPAD_SHIELD
#define INCLUDE_NOTIFICATION_SHIELD

#define ECHO 7
#define TRIG 8
#define Led 12

int detection = 20; //100
int codeChiffre = 0;
byte actif = 0;
long distance;
long duree;
boolean notif = false;

void setup() {

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(Led, OUTPUT);

  OneSheeld.begin();
}

void loop() {
  activation();
  if (actif == 1) {
    condition();
    delay(100);
  } else {}
}

void condition() {

  //Mesure du capteur
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duree = pulseIn(ECHO, HIGH);

  distance = duree / 58; //norme constructeur

  if (distance < detection) {
    MusicPlayer.play(); //on enclenche l'alarme
    delay(15000);
    MusicPlayer.stop();
  }

}

void activation() {
  //vérification du code : 08110
  if (codeChiffre == 0 && toucheZero()) codeChiffre++;
  else if (codeChiffre == 1 && toucheHuit()) codeChiffre++;
  else if (codeChiffre == 2 && toucheUn()) codeChiffre++;
  else if (codeChiffre == 3 && toucheUn()) codeChiffre++;
  else if (codeChiffre == 4 && toucheZero()) {
    codeChiffre++;
    actif = !actif;
    if (actif == 1) {
      Notification.notifyPhone("Système Activé"); //envoie une notification au téléphone
      delay(100);
      digitalWrite(Led, HIGH); //on allume la LED
      delay(100);
    } else {
      Notification.notifyPhone("Système Désactivé"); //envoie une notification au téléphone
      delay(100);
      digitalWrite(Led, LOW); //on allume la LED
      delay(100);
      MusicPlayer.stop();
      delay(100);
    }
  }
  else if ((Keypad.isAnyRowPressed() || Keypad.isAnyColumnPressed()) && !toucheZero() && !toucheUn() && !toucheHuit()) {
    codeChiffre = 0;
  }
  if (codeChiffre == 5) codeChiffre = 0;
}

//fonctions pour l'utilisation des touches du clavier
boolean toucheZero() {
  return Keypad.isRowPressed(3) && Keypad.isColumnPressed(1); //touche 0
}
boolean toucheUn() {
  return Keypad.isRowPressed(0) && Keypad.isColumnPressed(0); //touche 1
}
boolean toucheHuit() {
  return Keypad.isRowPressed(2) && Keypad.isColumnPressed(1); //touche 8
}

/*
  boolean toucheDeux(){return Keypad.isRowPressed(0) && Keypad.isColumnPressed(1);} //touche 2
  boolean toucheTrois(){return Keypad.isRowPressed(0) && Keypad.isColumnPressed(2);} //touche 3
  boolean toucheQuatre(){return Keypad.isRowPressed(1) && Keypad.isColumnPressed(0);} //touche 4
  boolean toucheCinq(){return Keypad.isRowPressed(1) && Keypad.isColumnPressed(1);} //touche 5
  boolean toucheSix(){return Keypad.isRowPressed(1) && Keypad.isColumnPressed(2);} //touche 6
  boolean toucheSept(){return Keypad.isRowPressed(2) && Keypad.isColumnPressed(0);} //touche 7
  boolean toucheNeuf(){return Keypad.isRowPressed(2) && Keypad.isColumnPressed(2);} //touche 9
  boolean toucheA(){return Keypad.isRowPressed(0) && Keypad.isColumnPressed(3);} //touche A
  boolean toucheB(){return Keypad.isRowPressed(1) && Keypad.isColumnPressed(3);} //touche B
  boolean toucheC(){return Keypad.isRowPressed(2) && Keypad.isColumnPressed(3);} //touche C
  boolean toucheD(){return Keypad.isRowPressed(3) && Keypad.isColumnPressed(3);} //touche D
  boolean toucheEtoile(){return Keypad.isRowPressed(3) && Keypad.isColumnPressed(0);} //touche *
  boolean toucheDiese(){return Keypad.isRowPressed(3) && Keypad.isColumnPressed(2);} //touche #
*/
