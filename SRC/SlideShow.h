#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <filesystem>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include "ImageParameters.h"

using namespace sf;
using namespace std;

#pragma warning(disable : 4996)

/**
* @brief klasa SlideShow zawiera wszystkie parametry i funkcje potrzebne do prawid�owego dzia�ania programu
*/
class SlideShow {

    public:
        /**
        * @brief konstruktor bezparametrowy wywo�uj�cy funkcje odpowiedzialne za wczytanie danych konfiguracyjnych
        */
        SlideShow();
        /**
        * @brief funkcja zwi�kszaj�ca warto�� zmiennej it okre�laj�cej ilo�� wy�wietlonych na ekranie zdj��
        * funkcja odpowiada r�wnie� za op�nienie pomi�dzy kolejnymi zdj�ciami
        */
        void AddPicture();
        /**
        * @brief funkcja odpowiada za dodanie ramki do zdj�cia okre�lonego i-tym zestawem parametr�w z pliku config.txt
        * @param window okno programu, na kt�rym wy�wietlany jest pokaz slajd�w
        * @param i numer zestawu parametr�w z wektora config
        */
        void AddFrame(RenderWindow& window, int i);
        /**
        * @brief funkcja odczytuje �cie�ki wszystkich zdj�� w katalogu i zapisuje w wektorze pathlist
        */
        void UpdatePathlist();
        /**
        * @brief funkcja odczytuje dane z pliku config.txt i zapisuje parametry zdj�� w wektorze config
        */
        void UpdateConfig();
        /**
        * @brief funkcja ustawia parametry t�a do pokazu slajd�w
        */
        void LoadBackground();

        /**
        * @brief ilo�� zdj�� w katalogu
        */
        int number_of_images;
        /**
        * @brief liczba aktualnie wy�wietlonych zdj�� na ekranie
        */
        int it = 0;
        /**
        * @brief domy�lna warto�� op�nienia w sekundach
        */
        double delay = 2;
        /**
        * @brief kolor ramki
        */
        Color frame_color;
        /**
        * @brief tryb wy�wietlania ramki
        */
        int frame_mode = 0;
        /**
        * @brief tekstura ramki wczytana z pliku
        */
        Texture frame_texture;
        /**
        * @brief duszek ramki ;)
        */
        Sprite frame_image;
        /**
        * @brief tekstura t�a wczytana z pliku
        */
        Texture background_texture;
        /**
        * @brief sprite t�a
        */
        Sprite background_image;
        /**
        * @brief domy�lny kolor t�a
        */
        Color background_color = Color::Black;
        /**
        * @brief tryb wy�wietlania t�a
        */
        int background_mode = 0;
        /**
        * @brief tryb losowo�ci,
        * domy�nie - wy��czony
        */
        bool random = false;
        /**
        * @brief zmienna odpowiadaj�ca za tryb wy�wietlania napis�w
        */
        bool text_added = false;
        /**
        * @brief flaga informuj�ca program o zako�czeniu pokazu slajd�w
        */
        bool flag_finished = false;
        /**
        * @brief wektor przechowuj�cy �cie�ki zdj�� w katalogu
        */
        vector <string> pathlist;
        /**
        * @brief wektor przechowuj�cy zestawy parametr�w zdj��
        */
        vector <ImageParameters> config;
        /**
        * @brief szeroko�� okna
        */
        int window_width;
        /**
        * @brief wysoko�� okna
        */
        int window_height;
};