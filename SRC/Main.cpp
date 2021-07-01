#include "SlideShow.h"
#include "NewImage.h"
#include "ImageParameters.h"

int main()
{
    SlideShow menu;

    RenderWindow window(VideoMode::getDesktopMode(), "Projekt do Hall of Fame", Style::Fullscreen | Style::Titlebar, ContextSettings(24));
    Event event;

    menu.window_width = window.getSize().x;
    menu.window_height = window.getSize().y;

    menu.LoadBackground();

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        window.clear(menu.background_color);
        if (menu.background_mode == 2)
            window.draw(menu.background_image);


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        for (int i = 0; i < menu.it; i++) {
            if (menu.frame_mode) menu.AddFrame(window, i % menu.config.size());
            window.draw(NewImage(i, menu)._bitmap);
        }

        menu.AddPicture();

        window.display();

        if (menu.flag_finished) {

            Clock timer;
            while (timer.getElapsedTime().asSeconds() < menu.delay)
            {
            }
            window.close();
        }

    }
    return 0;
}



