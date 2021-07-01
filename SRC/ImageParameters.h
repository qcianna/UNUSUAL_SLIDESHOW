#pragma once

/**
* @brief klasa ImageParameters zawiera informacje dotycz¹ce po³o¿enia, rozmiaru, k¹ta obrotu i opisu zdjêcia
*/
class ImageParameters{

    public:
        /**
        * @brief konstruktor klasy 
        * @param x wspó³rzêdna x zdjêcia (w procentach wzglêdem rozmiaru okna programu 0-100)
        * @param y wspó³rzêdna y zdjêcia (w procentach wzglêdem rozmiaru okna programu 0-100)
        * @param width docelowa szerokoœæ zdjêcia w pikselach
        * @param height docelowa wysokoœæ zdjêcia w pikselach
        * @param angle wartoœæ k¹ta, o jaki ma byæ obrócone zdjêcie
        * @param name opis do³¹czony do zdjêcia
        */
        ImageParameters(float x, float y, int width, int height, double angle, std::string name = "");

        /**
        * @brief wartoœæ k¹ta obrotu zdjêcia
        */
        double _angle;
        /**
        * @brief procentowe po³o¿enie x wierzcho³ka zdjêcia wzglêdem okna
        */
        float _x;
        /**
        * @brief procentowe po³o¿enie y wierzcho³ka zdjêcia wzglêdem okna
        */
        float _y;
        /**
        * @brief docelowa szerokoœæ zdjêcia w pikselach
        */
        int _width;
        /**
        * @brief docelowa wysokoœæ zdjêcia w pikselach
        */
        int _height;
        /**
        * @brief opis dodany do zdjêcia
        */
        std::string _title;
};

inline ImageParameters::ImageParameters(float x, float y, int width, int height, double angle, std::string name) : _x(x), _y(y), _angle(angle), _width(width), _height(height), _title(name) {}
