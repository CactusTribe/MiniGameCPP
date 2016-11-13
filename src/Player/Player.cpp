#include <iostream>
#include "Player.h"

Player::Player(std::string name, PlayerType type) : m_name(name), m_type(type){

}

Player::~Player(){

}

std::string Player::getName(){
  return m_name;
}

PlayerType Player::getType(){
  return m_type;
}

std::ostream& operator<<(std::ostream& out, const Player& j){

  out << "# " << j.m_name << " - ";

  switch(j.m_type){
    case PlayerType::HUMAN:
      out << "HUMAN";
    break;
    case PlayerType::COMPUTER:
      out << "COMPUTER";
    break;
  }

  return out;
}
