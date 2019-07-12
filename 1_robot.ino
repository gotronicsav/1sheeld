#include <OneSheeld.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_SHIELD
#define INCLUDE_KEYPAD_SHIELD

#include <Servo.h>

Servo base;
Servo epaule;
Servo coude;
Servo poignet;
Servo rotapince;
Servo ouvrepince;

int base_val = 90;
int epaule_val = 90;
int coude_val = 90;
int poignet_val = 90;
int rotapince_val = 90;
int ouvrepince_val = 130;

int vitesse = 1;


void setup() {

  base.attach(6);
  epaule.attach(3);
  coude.attach(9);
  poignet.attach(5);
  rotapince.attach(11);
  ouvrepince.attach(10);

  OneSheeld.begin();
  //Serial.begin(9600);

  base.write(base_val);
  epaule.write(epaule_val);
  coude.write(coude_val);
  poignet.write(poignet_val);
  rotapince.write(rotapince_val);
  ouvrepince.write(ouvrepince_val);

}

void loop() {

  if (Keypad.isRowPressed(0) && Keypad.isColumnPressed(0)) {
    vitesse = 1;
    else if (Keypad.isRowPressed(0) && Keypad.isColumnPressed(2)) {
      vitesse = 3;
      else if (Keypad.isRowPressed(1) && Keypad.isColumnPressed(1)) {
        vitesse = 5;
        else vitesse = vitesse;

        if (GamePad.isLeftPressed()) {
          base_val += vitesse;
          if (base_val >= 170) base_val = 170;
          base.write(base_val);
        }

        if (GamePad.isRightPressed()) {
          base_val -= vitesse;
          if (base_val <= 10) base_val = 10;
          base.write(base_val);
        }



        if (GamePad.isUpPressed()) {
          epaule_val -= vitesse;
          if (epaule_val <= 10) epaule_val = 10;
          epaule.write(epaule_val);
        }

        if (GamePad.isDownPressed()) {
          epaule_val += vitesse;
          if (epaule_val >= 170) epaule_val = 170;
          epaule.write(epaule_val);
        }



        if (GamePad.isOrangePressed()) {
          coude_val -= vitesse;
          if (coude_val <= 10) coude_val = 10;
          coude.write(coude_val);
        }

        if (GamePad.isGreenPressed()) {
          coude_val += vitesse;
          if (coude_val >= 170) coude_val = 170;
          coude.write(coude_val);
        }



        if (GamePad.isBluePressed()) {
          poignet_val += vitesse;
          if (poignet_val >= 170) poignet_val = 170;
          poignet.write(poignet_val);
        }

        if (GamePad.isRedPressed()) {
          poignet_val -= vitesse;
          if (poignet_val <= 10) poignet_val = 10;
          poignet.write(poignet_val);
        }



        if (Keypad.isRowPressed(3) && Keypad.isColumnPressed(0)) { //touche *
          rotapince_val += vitesse;
          if (rotapince_val >= 170) rotapince_val = 170;
          rotapince.write(rotapince_val);
        }

        if (Keypad.isRowPressed(3) && Keypad.isColumnPressed(2)) { //touche #
          rotapince_val -= vitesse;
          if (rotapince_val <= 10) rotapince_val = 10;
          rotapince.write(rotapince_val);
        }



        if (Keypad.isRowPressed(0) && Keypad.isColumnPressed(3)) { //touche A
          ouvrepince_val += vitesse;
          if (ouvrepince_val >= 170) ouvrepince_val = 170;
          ouvrepince.write(ouvrepince_val);
        }

        if (Keypad.isRowPressed(1) && Keypad.isColumnPressed(3)) { //touche B
          ouvrepince_val -= vitesse;
          if (ouvrepince_val <= 100) ouvrepince_val = 100;
          ouvrepince.write(ouvrepince_val);
        }


        delay(15);
      }

