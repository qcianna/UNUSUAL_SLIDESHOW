#include "NewImage.h"

NewImage::NewImage(int i, SlideShow object)
{
    _image.loadFromFile(object.pathlist[i]);
    _bitmap.setTexture(_image);

    if (i >= object.config.size())
    {
        i = i % object.config.size();
    }

    _bitmap.setPosition(object.window_width * object.config[i]._x / 100.f, object.window_height * object.config[i]._y / 100.f);
    _bitmap.setScale(static_cast <float> (object.config[i]._width) / _image.getSize().x, static_cast <float> (object.config[i]._height) / _image.getSize().y);
    _bitmap.setRotation(static_cast <float> (object.config[i]._angle));
}