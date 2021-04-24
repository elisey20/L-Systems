#include <algorithm>
#include <chrono>
#include <thread>

#include "SFML/Graphics.hpp"
#include "Turtle.h"

using namespace sf;
using namespace std;

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(1500, 1000), "SFML", Style::Default, settings);
    window.clear(Color::White);
    window.setFramerateLimit(120);

    Turtle turtle(750, 700, window);

    string axiom = "F+F+F+F";
    const string rule1[2] = {"F", "F+f-FF+F+FF+Ff+FF-f+FF-F-FF-Ff-FFF"};
    const string rule2[2] = {"f", "ffffff"};

    string str = "";

    for(int i = 0; i < 2; i++)
    {
        for (int j = 0; j < axiom.length(); j++)
        {
            switch (axiom[j]) {
                case 'F':
                    str += rule1[1];
                    break;
                case 'f':
                    str += rule2[1];
                    break;
                default:
                    str += axiom[j];
                    break;
            }
        }
        axiom = str;
        str = "";
    }

    bool flag = true;

    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event{};
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }

        turtle.addRotate(90);

        if (flag)
        for(int i = 0; i < axiom.length(); i++)
        {
            switch (axiom[i])
            {
                case 'F':
                    turtle.drawLine();
                    break;
                case '+':
                    turtle.turnRight();
                    break;
                case '-':
                    turtle.turnLeft();
                    break;
                case '[':
                    turtle.addPos();
                    break;
                case ']':
                    turtle.returnPos();
                    break;
                case 'f':
                    turtle.goForward();
                    break;
            }
        }
        flag = false;

        window.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        window.clear(Color::White);
    }

    return 0;
}
