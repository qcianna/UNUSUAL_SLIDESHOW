#pragma once
#include "SlideShow.h"

using namespace sf;
using namespace std;

class SlideShow;

/**
* @brief klasa NewImage odpowiada za wczytywanie zdj�� i dopasowywanie ich parametr�w zgodnie z plikiem konfiguracyjnym
*/
class NewImage
{
public:
    /**
    * @brief konstruktor przyjmuj�cy numer zdj�cia i odpowiadaj�cej mu konfiguracji oraz obiekt klasy SlideShow, przekszta�caj�cy parametry obrazu
    * @param i numer zdj�cia
    * @param object objekt klasy SlideShow przechowuj�cy parametry programu
    */
    NewImage(int i, SlideShow object);

    /**
    * @brief tekstura zdj�cia wczytanego z folderu
    */
    Texture _image;
    /**
    * @brief sprite zdj�cia
    */
    Sprite _bitmap;
};