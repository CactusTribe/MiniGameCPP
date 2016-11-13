#ifndef IHM_H
#define IHM_H

#include <SFML/Graphics.hpp>
#include <string>

class IHM {

public:

  IHM(int window_size, const std::string& title);
  virtual ~IHM();
  sf::RenderWindow* app();
  int window_size();

private:

  int _window_size = 0;
  sf::RenderWindow* _app;

};

#endif
