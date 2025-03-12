//
// Created by andyl on 2025/3/8.
//

#ifndef BACKGROUNDIMAGE_HPP
#define BACKGROUNDIMAGE_HPP

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"


class BackgroundImage : public Util::GameObject {
private:
    inline std::string ImagePath(const int phase) {
        return RESOURCE_DIR"/Image/Background/phase" + std::to_string(phase) + ".png";
    }
public:
    BackgroundImage() : GameObject(std::make_unique<Util::Image>(RESOURCE_DIR"/Image/Background/phase1.png"),-10){}

    void NextPhase(const int phase) {
        auto temp = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
        temp->SetImage(ImagePath(phase));
    }
};



#endif //BACKGROUNDIMAGE_HPP
