#ifndef VIEW_H
#define VIEW_H

#include <gtkmm.h>
#include <gdkmm.h>
#include <list>
#include "DeckGUI.h"
#include "../Model/GameLogic.h"
#include "../Controller/Controller.h"
#include "Observer.h"
#include "../Card.h"
#include "PlayerBox.h"

class View : public Gtk::Window, public Observer {
public:
        View(Controller * controller, GameLogic * gameLogic); // where gameLogic is the common interface using facade pattern
        virtual ~View();
        virtual void update();

private:
        class PopupMessage : public Gtk::Dialog { //popup window/dialog for invalid moves or round finishes messages
        public:
                PopupMessage(Gtk::Window &main, std::string title, std::string message);
                
        private:
                Gtk::Label msg;
        };

        GameLogic * gameLogic_; //game logic is the model
        Controller * controller_; //controller

        Gtk::Table table; //top level container

        DeckGUI deck_;

        Gtk::HBox menuBox_;
        Gtk::Entry seedField_;
        Gtk::Label seedLabel_;
        Gtk::Button startButton_;
        Gtk::Button endButton_;

        Gtk::Frame cardFrame_; //table
        Gtk::Table cardTableView_;
        Gtk::Image *clubs_[13];
        Gtk::Image *diamonds_[13];
        Gtk::Image *hearts_[13];
        Gtk::Image *spades_[13];

        PlayerBox playerBox_[4]; //player stats and view
        Gtk::HBox playerHBox_; //container for player boxes

        Gtk::HBox handBox_; //container for current hand
        Gtk::Frame handBoxFrame_;
        Gtk::Button handButton_[13];
        Gtk::Image *hand_[13];

        Gtk::Label progressLabel_;
        Gtk::ProgressBar progressBar_;
        const double progressMax_ = 52;
        double progress_ = 0;

        void restart();
        void onStartButtonClicked();
        void onCardClicked(int index);
        void onEndButtonClicked();
        void onRageButtonClicked();
};

#endif