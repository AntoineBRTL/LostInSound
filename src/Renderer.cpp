#include "precompile.hpp"

Renderer::Renderer(sf::RenderWindow *renderWindow):renderWindow(renderWindow){
    font.loadFromFile(".\\font\\font.ttf");
}

void Renderer::render(){

    renderWindow->clear(sf::Color::Black);

    for(Object *object : objects)
        object->render(renderWindow, font);

    renderWindow->display();
}

void Renderer::putObjects(std::vector<Object*> objects){
    this->objects = objects;
}