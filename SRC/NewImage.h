#pragma once
#include "SlideShow.h"

using namespace sf;
using namespace std;

class SlideShow;

/**
* @brief klasa NewImage odpowiada za wczytywanie zdjêæ i dopasowywanie ich parametrów zgodnie z plikiem konfiguracyjnym
*/
class NewImage
{
public:
    /**
    * @brief konstruktor przyjmuj¹cy numer zdjêcia i odpowiadaj¹cej mu konfiguracji oraz obiekt klasy SlideShow, przekszta³caj¹cy parametry obrazu
    * @param i numer zdjêcia
    * @param object objekt klasy SlideShow przechowuj¹cy parametry programu
    */
    NewImage(int i, SlideShow object);

    /**
    * @brief tekstura zdjêcia wczytanego z folderu
    */
    Texture _image;
    /**
    * @brief sprite zdjêcia
    */
    Sprite _bitmap;
};