#ifndef MENUBOX_H
#define MENUBOX_H

#include <gtkmm.h>
#include "../Model/GameLogic.h"
#include "../Controller/Controller.h"
#include <gdkmm.h>
#include "View.h"

class View;

class MenuBox : public Gtk::HBox {
        public:
            MenuBox(Controller * controller, GameLogic * gameLogic, View * window);
            virtual ~MenuBox();
            void updateProgressBar(double increment);
            void setController(Controller * controller);
        private:
            GameLogic * gameLogic_; //game logic is the model
            Controller * controller_; //controller

            View * mainWindow_; //handle to main window

            Gtk::Entry seedField_;
            Gtk::Label seedLabel_;
            Gtk::Button startButton_;
            Gtk::Button endButton_;

            Gtk::Label progressLabel_;
            Gtk::ProgressBar progressBar_;

            void onStartButtonClicked();
            void onEndButtonClicked();
        };

#endif