//
// Created by elisey on 20.04.2021.
//

#ifndef SFML_TEST_TURTLE_H
#define SFML_TEST_TURTLE_H

#include "SFML/Graphics.hpp"
#include <cmath>
#include <vector>

using namespace sf;

struct position
{
    Vector2f coords;
    float rotate;
    position(Vector2f coords, float rotate) : coords(coords), rotate(rotate) {}
};

class Turtle
{
private:
    Vector2f coords;
    float rotate = -90;
    float turn = 90;
    float lengthLine = 5;
    float widthLine = 1;
    Color color = Color::Black;
    RenderWindow * window = nullptr;
    std::vector<position> pos;

public:
    Turtle() : Turtle(0,0) {}
    Turtle(float x, float y)
    {
        coords = Vector2f(x, y);
    }
    Turtle(float x, float y, RenderWindow & window) : Turtle(x, y)
    {
        this->window = &window;
    }

    float getRotate()
    {
        return rotate;
    }
    Vector2f getCoords()
    {
        return coords;
    }

    void addPos()
    {
        pos.push_back(position(coords, rotate));
    }

    void returnPos()
    {
        position poss = pos.back();
        pos.pop_back();
        coords = poss.coords;
        rotate = poss.rotate;
    }

    void drawLine()
    {
        RectangleShape rect(Vector2f(lengthLine, widthLine));
        rect.setPosition(coords);
        rect.setRotation(rotate);
        rect.setFillColor(color);
        window->draw(rect);
        float x = (float)std::cos(rotate * M_PI / 180) * lengthLine;
        float y = (float)std::sin(rotate * M_PI / 180) * lengthLine;
        coords.x += x;
        coords.y += y;
    };

    void goForward()
    {
        float x = (float)std::cos(rotate * M_PI / 180) * lengthLine;
        float y = (float)std::sin(rotate * M_PI / 180) * lengthLine;
        coords.x += x;
        coords.y += y;
    }

    void turnRight()
    {
        rotate += turn;
    };
    void turnLeft()
    {
        rotate -= turn;
    };

    void addRotate(float rotate)
    {
        this->rotate += rotate;
    }
    void move(Vector2f add)
    {
        coords.x += add.x;
        coords.y += add.y;
    }
    void setLengthLine(float lengthLine)
    {
        this->lengthLine = lengthLine;
    }
    void setWidthLine(float widthLine)
    {
        this->widthLine = widthLine;
    }
    void setColor(Color color)
    {
        this->color = color;
    }
    void setWindow(RenderWindow & window)
    {
        this->window = &window;
    }
};


#endif //SFML_TEST_TURTLE_H
