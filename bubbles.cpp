#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

using std:: cout;
using std:: endl;
using std:: ifstream;

using namespace std;


int main(int argc, char *argv[])
{
    //bubble 1
    sf::RenderWindow Window(sf::VideoMode(1024, 768), "Bubbles");
    sf::CircleShape bubble1(50.f);
    bubble1.setFillColor(sf::Color::Yellow);
    bubble1.getGlobalBounds();
    
    //bubble2
    sf::CircleShape bubble2(100.f);
    bubble2.setFillColor(sf::Color::Blue);
    bubble2.getGlobalBounds();
    
    
    //bubble2 variables
    int pos_y2 { };
    int pos_x2 { };
    bubble2.setPosition(pos_x2, pos_y2);
    int delta_y2 = 45;
    int delta_x2 = -15;
    
    //bubble 1 variables
    int pos_y { 500 };
    int pos_x { 500 };
    bubble1.setPosition(pos_x, pos_y);
    int delta_y = -10;
    int delta_x = 68;
    //bubble distances
    
    
    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        
            if(event.type == sf::Event::Closed)
            {
            Window.close();
            }
            //making the bubble 1 to bounce down
        if (pos_y < 0) {
            delta_y *= -1;
            }
        // makes the ball bounce back up
        if (pos_y > 650) {
            delta_y *= -1;
        }
        // make the ball go left
        if (pos_x < 0) {
               delta_x *= -1;
               }
        //make the ball go right
        if (pos_x > 906) {
               delta_x *= -1;
               }
        
        //bubble 2 directions
        
        //making the bubble 2 to bounce down
    if (pos_y2 < 0) {
        delta_y2 *= -1;
        }
    // makes the bubble2 bounce back up
    if (pos_y2 > 550) {
        delta_y2 *= -1;
    }
    // make the bubble2 go left
    if (pos_x2 < 0) {
           delta_x2 *= -1;
           }
    //make the bubble2 go right
    if (pos_x2 > 806) {
           delta_x2 *= -1;
           }
        
        // if bubbles collide
       if  (bubble2.getGlobalBounds().intersects(bubble1.getGlobalBounds())) {
           delta_x *= -1;
           delta_x2 *= -1;
           delta_y *= -1;
           delta_y2 *= -1;
       }
        
        //bubble 1
        pos_y += delta_y;
        pos_x += delta_x;
        
        //bubble 2
        pos_y2 += delta_y2;
        pos_x2 += delta_x2;
        
        
        //sets the position of the bubbles 1 and 2
        bubble1.setPosition(pos_x, pos_y);
        bubble2.setPosition(pos_x2, pos_y2);
        Window.clear();
        //draws bubbles
        Window.draw(bubble1);
        Window.draw(bubble2);
        Window.display();
        sf::sleep(sf::seconds(0.1));
    }
    return 0;
    }
