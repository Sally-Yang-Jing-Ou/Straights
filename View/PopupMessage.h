#ifndef POPUPMESSAGE_H
#define POPUPMESSAGE_H

#include <gtkmm.h>
#include <string>
#include "View.h"

class View;

class PopupMessage : public Gtk::Dialog { //popup window/dialog for invalid moves or round finishes messages
public:
    PopupMessage(Gtk::Window &main, std::string title, std::string message); //constructor
        
private:
    Gtk::Label msg; //message to display
};

#endif