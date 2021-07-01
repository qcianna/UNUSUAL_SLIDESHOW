#pragma once

/**
* @brief klasa ImageParameters zawiera informacje dotycz�ce po�o�enia, rozmiaru, k�ta obrotu i opisu zdj�cia
*/
class ImageParameters{

    public:
        /**
        * @brief konstruktor klasy 
        * @param x wsp�rz�dna x zdj�cia (w procentach wzgl�dem rozmiaru okna programu 0-100)
        * @param y wsp�rz�dna y zdj�cia (w procentach wzgl�dem rozmiaru okna programu 0-100)
        * @param width docelowa szeroko�� zdj�cia w pikselach
        * @param height docelowa wysoko�� zdj�cia w pikselach
        * @param angle warto�� k�ta, o jaki ma by� obr�cone zdj�cie
        * @param name opis do��czony do zdj�cia
        */
        ImageParameters(float x, float y, int width, int height, double angle, std::string name = "");

        /**
        * @brief warto�� k�ta obrotu zdj�cia
        */
        double _angle;
        /**
        * @brief procentowe po�o�enie x wierzcho�ka zdj�cia wzgl�dem okna
        */
        float _x;
        /**
        * @brief procentowe po�o�enie y wierzcho�ka zdj�cia wzgl�dem okna
        */
        float _y;
        /**
        * @brief docelowa szeroko�� zdj�cia w pikselach
        */
        int _width;
        /**
        * @brief docelowa wysoko�� zdj�cia w pikselach
        */
        int _height;
        /**
        * @brief opis dodany do zdj�cia
        */
        std::string _title;
};

inline ImageParameters::ImageParameters(float x, float y, int width, int height, double angle, std::string name) : _x(x), _y(y), _angle(angle), _width(width), _height(height), _title(name) {}
