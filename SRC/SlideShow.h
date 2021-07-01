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
* @brief klasa SlideShow zawiera wszystkie parametry i funkcje potrzebne do prawid³owego dzia³ania programu
*/
class SlideShow {

    public:
        /**
        * @brief konstruktor bezparametrowy wywo³uj¹cy funkcje odpowiedzialne za wczytanie danych konfiguracyjnych
        */
        SlideShow();
        /**
        * @brief funkcja zwiêkszaj¹ca wartoœæ zmiennej it okreœlaj¹cej iloœæ wyœwietlonych na ekranie zdjêæ
        * funkcja odpowiada równie¿ za opóŸnienie pomiêdzy kolejnymi zdjêciami
        */
        void AddPicture();
        /**
        * @brief funkcja odpowiada za dodanie ramki do zdjêcia okreœlonego i-tym zestawem parametrów z pliku config.txt
        * @param window okno programu, na którym wyœwietlany jest pokaz slajdów
        * @param i numer zestawu parametrów z wektora config
        */
        void AddFrame(RenderWindow& window, int i);
        /**
        * @brief funkcja odczytuje œcie¿ki wszystkich zdjêæ w katalogu i zapisuje w wektorze pathlist
        */
        void UpdatePathlist();
        /**
        * @brief funkcja odczytuje dane z pliku config.txt i zapisuje parametry zdjêæ w wektorze config
        */
        void UpdateConfig();
        /**
        * @brief funkcja ustawia parametry t³a do pokazu slajdów
        */
        void LoadBackground();

        /**
        * @brief iloœæ zdjêæ w katalogu
        */
        int number_of_images;
        /**
        * @brief liczba aktualnie wyœwietlonych zdjêæ na ekranie
        */
        int it = 0;
        /**
        * @brief domyœlna wartoœæ opóŸnienia w sekundach
        */
        double delay = 2;
        /**
        * @brief kolor ramki
        */
        Color frame_color;
        /**
        * @brief tryb wyœwietlania ramki
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
        * @brief tekstura t³a wczytana z pliku
        */
        Texture background_texture;
        /**
        * @brief sprite t³a
        */
        Sprite background_image;
        /**
        * @brief domyœlny kolor t³a
        */
        Color background_color = Color::Black;
        /**
        * @brief tryb wyœwietlania t³a
        */
        int background_mode = 0;
        /**
        * @brief tryb losowoœci,
        * domyœnie - wy³¹czony
        */
        bool random = false;
        /**
        * @brief zmienna odpowiadaj¹ca za tryb wyœwietlania napisów
        */
        bool text_added = false;
        /**
        * @brief flaga informuj¹ca program o zakoñczeniu pokazu slajdów
        */
        bool flag_finished = false;
        /**
        * @brief wektor przechowuj¹cy œcie¿ki zdjêæ w katalogu
        */
        vector <string> pathlist;
        /**
        * @brief wektor przechowuj¹cy zestawy parametrów zdjêæ
        */
        vector <ImageParameters> config;
        /**
        * @brief szerokoœæ okna
        */
        int window_width;
        /**
        * @brief wysokoœæ okna
        */
        int window_height;
};