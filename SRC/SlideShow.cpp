#include "SlideShow.h"

SlideShow::SlideShow() {
    UpdatePathlist();
    UpdateConfig();
}

void SlideShow::AddPicture() {

    if (it < number_of_images) {
        if (it > 0) {
            if (it == 1) {
                Clock timer;
                while (timer.getElapsedTime().asSeconds() < delay)
                {
                }
            }
            else {
                Clock timer;
                while (timer.getElapsedTime().asSeconds() < delay)
                {
                }
            }
        }
        it++;
    }
    else if (it == number_of_images && flag_finished == false) {
        Clock timer;
        while (timer.getElapsedTime().asSeconds() < delay)
        {
        }
        flag_finished = true;
    }
}

void SlideShow::AddFrame(RenderWindow& window, int i) {

    float dvec = 10;
    float r = dvec * sqrt(2.f);
    float dy = static_cast <float> (sin((45 + config[i]._angle) * 3.14 / 180) * r);
    float dx = static_cast <float> (cos((45 + config[i]._angle) * 3.14 / 180) * r);

    if (frame_mode == 1 || random == true) {
        RectangleShape recktangle;
        recktangle.setSize(Vector2f(config[i]._width + 20.f, config[i]._height + 60.f));
        recktangle.setRotation(static_cast <float> (config[i]._angle));
        recktangle.setPosition(Vector2f(window.getSize().x * config[i]._x / 100.f - dx, window.getSize().y * config[i]._y / 100.f - dy));

        if (!random) recktangle.setFillColor(frame_color);
        else recktangle.setFillColor(Color((config[i]._width + 20 * i) % 255, (config[i]._height + 15 * i) % 255, (static_cast <int> (config[i]._angle) + 3 * i + 50) % 255));
        window.draw(recktangle);

    }
    else {
        frame_image.setScale((config[i]._width + 20.f) / frame_texture.getSize().x, (config[i]._height + 60.f) / frame_texture.getSize().y);
        frame_image.setRotation(static_cast <float> (config[i]._angle));
        frame_image.setPosition(Vector2f(window.getSize().x * config[i]._x / 100 - dx, window.getSize().y * config[i]._y / 100 - dy));
        window.draw(frame_image);
    }

    if (text_added) {
        Text text;
        Font font;

        float r = 10.f + config[i]._height;
        font.loadFromFile("font.ttf");
        text.setCharacterSize(20);
        text.setString(config[i]._title);
        text.setFont(font);

        FloatRect text_size = text.getLocalBounds();
        float dr = (config[i]._width - text_size.width) / 2.f;

        text.setRotation(static_cast <float> (config[i]._angle));
        text.setFillColor(Color::White);
        text.setPosition(Vector2f(window_width * config[i]._x / 100.f + dr * static_cast <float> (cos(config[i]._angle * 3.14 / 180)) - r * static_cast <float> (sin(config[i]._angle * 3.14 / 180)), window_height * config[i]._y / 100.f + dr * static_cast <float> (sin(config[i]._angle * 3.14 / 180)) + r * static_cast <float> (cos(config[i]._angle * 3.14 / 180))));
        window.draw(text);

    }
}


void SlideShow::UpdateConfig() {

    FILE* fp;
    int ctr = 0;
    char a;
    char str[100];

    float x, y;
    int r, g, b;
    int w, h;
    double k;

    string s;

    fopen_s(&fp, "config.txt", "r");

    string linia;
    int counter = 0;
    fstream plik;
    plik.open("config.txt", ios::in);
    while (getline(plik, linia))
    {
        counter++;
    }
    plik.close();
    if (fp) {
        while (ctr < 2) {
            a = getc(fp);
            if (a == '\n')
                ctr++;
        }
        fscanf_s(fp, "%d %d", &frame_mode, &ctr);
        if (frame_mode == 1) {
            fscanf_s(fp, "%d %d %d", &r, &g, &b);
            frame_color.r = r;
            frame_color.g = g;
            frame_color.b = b;
        }
        else if (frame_mode == 0) {
            int ctr = 0;
            char a;
            while (ctr < 2) {
                a = getc(fp);
                if (a == '\n')
                    ctr++;
            }
        }
        else if (frame_mode == 2) {
            fscanf_s(fp, "%s", str, 100);
            str[99] = '\0';
            frame_texture.loadFromFile(str);
            frame_image.setTexture(frame_texture);
        }
        if (ctr == 1)
            text_added = true;

        fscanf_s(fp, "%d", &ctr);
        if (ctr == 1)
            random = true;

        fscanf_s(fp, "%lf", &delay);

        if (random) {
            fclose(fp);

            background_mode = 1;
            background_color = Color::Black;
            srand(static_cast <unsigned int> (time(NULL)));

            for (int i = 0; i < number_of_images; i++) {
                int size = rand() % 200 + 400;
                config.push_back(ImageParameters(rand() % 80 + 10.f, rand() % 80 + 10.f, size, size, static_cast <float> (rand() % 360)));
            }
        }

        else if (text_added) {
            for (int i = 0; i < (counter - 6) / 2; i++) {
                fscanf_s(fp, "%f %f %d %d %lf", &x, &y, &w, &h, &k);
                if ((a = getc(fp)) == '\n')
                    fgets(str, 100, fp);
                else while (a != '\n')
                    a = getc(fp);
                s = str;
                config.push_back(ImageParameters(x, y, w, h, k, s));
            }
        }
        else {
            for (int i = 0; i < (counter - 6); i++) {
                fscanf_s(fp, "%f %f %d %d %lf", &x, &y, &w, &h, &k);
                config.push_back(ImageParameters(x, y, w, h, k));
            }
        }
        fclose(fp);
    }
}

void SlideShow::UpdatePathlist() {

    std::string path = "./zdjecia";
    for (const auto& entry : std::filesystem::directory_iterator(path))
        pathlist.push_back(entry.path().string());

    number_of_images = static_cast <int> (pathlist.size());
}

void SlideShow::LoadBackground() {

    if (!random) {
        FILE* fp;

        char str[100];
        int r, g, b;

        fopen_s(&fp, "config.txt", "r");

        if (fp) {
            fscanf_s(fp, "%d", &background_mode);


            if (background_mode == 2)
            {
                fscanf_s(fp, "%s", str, 100);
                str[99] = '\0';
                background_texture.loadFromFile(str);
                background_image.setTexture(background_texture);
                float x_0 = static_cast <float> (background_texture.getSize().x);
                float y_0 = static_cast <float> (background_texture.getSize().y);
                background_image.setScale(window_width / x_0, window_height / y_0);
            }
            else if (background_mode == 1)
            {
                fscanf_s(fp, "%d %d %d", &r, &g, &b);
                background_color.r = r;
                background_color.g = g;
                background_color.b = b;
            }
            else {
                int ctr = 0;
                char a;
                while (ctr < 2) {
                    a = getc(fp);
                    if (a == '\n')
                        ctr++;
                }
            }
            fclose(fp);
        }
    }
}