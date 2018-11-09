//
// Created by devassassin on 6/19/18.
//

#include "UI.h"
#include "Game_Manager.h"

UI::UI()
{

}

tgui::Widget::Ptr UI::InstructionsMenu()
{

tgui::MessageBox::Ptr inst=theme->load("MessageBox");
inst->setSize(800,600);
inst->setPosition(Game_Manager::windowWidth-490,Game_Manager::windowHeight-170);
inst->setText("For Player 1 : \n Use |W,S,A,D| for moving and |Space| for shooting"
              "\n For Player 2 : \n Use NumPad |8,4,6,2| for moving and |RCtrl| for shooting \n");
inst->getCloseButton()->connect("pressed",[&](){ Game_Manager::gui.remove(inst); });
inst->setTitle("Instructions ");
inst->setResizable(false);
Game_Manager::gui.add(inst);
return inst;
}

void UI::GameUI()
{

   //set Gamebackground

    tgui::Picture::Ptr G_background=tgui::Picture::create("art/gamebackground.jpg");
    G_background->setSize
            (tgui::bindMax(Game_Manager::windowWidth,Game_Manager::windowWidth),
             tgui::bindMax(Game_Manager::windowHeight,Game_Manager::windowHeight));

    Game_Manager::gui.add(G_background);

    //add instructions button
    tgui::Button::Ptr instruction= theme->load("Button");
    instruction->setSize(Game_Manager::windowWidth/6,Game_Manager::windowHeight/6);
    instruction->setPosition
            (Game_Manager::windowWidth-instruction->getSize().x,Game_Manager::windowHeight-instruction->getSize().y);
    instruction->setText("Instructions");
    instruction->connect("pressed",InstructionsMenu);
    Game_Manager::gui.add(instruction);


    //add Player1 Text
p1text=theme->load("TextBox");

p1text->setSize(100,70);
    p1text->setPosition(0,0);
p1text->setText("Health");
Game_Manager::gui.add(p1text);


// add player2 Text
    p2text=theme->load("TextBox");

    p2text->setSize(100,70);
    p2text->setPosition(0,Game_Manager::windowHeight-p2text->getSize().y);
    p2text->setText("Health ");
    Game_Manager::gui.add(p2text);



}

void UI::Lose(std::string text)
{
    Game_Manager::gui.removeAllWidgets();
    tgui::TextBox::Ptr txt=theme->load("TextBox");
    txt->setPosition(Game_Manager::windowWidth/4,Game_Manager::windowHeight/4);
    txt->setSize(200,200);
    txt->setText("Game Over\n"+text);
    Game_Manager::gui.add(txt);
}


tgui::Theme::Ptr UI::theme = tgui::Theme::create("widgets/BabyBlue.txt");

