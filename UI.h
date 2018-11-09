//
// Created by devassassin on 6/19/18.
//

#ifndef OOP_PROJECT_UI_H
#define OOP_PROJECT_UI_H

#include <TGUI/TGUI.hpp>


class UI
{
public :
    UI();
    static tgui::Widget::Ptr InstructionsMenu();
    void GameUI();
    void Lose(std::string text);
    tgui::TextBox::Ptr p1text;
    tgui::TextBox::Ptr p2text;
private:
static tgui::Theme::Ptr theme;

};


#endif //OOP_PROJECT_UI_H
