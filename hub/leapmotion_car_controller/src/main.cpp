//
// Created by simon on 17/11/2019.
//

#include "MyListener.hpp"
#include "Sfml.hpp"

int main(int ac, const char **av) {

    // Create a sample listener and controller
    //Leap::MyListener listener;
    //Leap::Controller controller;


    // Have the sample listener receive events from the controller
    //controller.addListener(listener);

    // Keep this process running until Enter is pressed
    //std::cout << "Press Enter to quit..." << std::endl;
    //std::cin.get();

    // Remove the sample listener when done
    //controller.removeListener(listener);
    try {
        Sfml window;
        window.run();
    } catch (...) {
        return 84;
    }
    return (0);
}