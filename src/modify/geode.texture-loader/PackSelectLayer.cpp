#include <Geode/Geode.hpp>
#include "../../SwelvyBG.hpp"
#include "../../Hooks/Hooker.hpp"

using namespace geode::prelude;

Viper_Hookclass(PackSelectLayer) {
        if (auto bg = this->getChildByID("background")) {
            bg->setVisible(false);
        }

        SwelvyBG* swelvyBG = SwelvyBG::create();
        swelvyBG->setZOrder(-1);
        swelvyBG->setID("swelvy-background");
        this->addChild(swelvyBG);
}

#include <Geode/Geode.hpp>
#include "../../SwelvyBG.hpp"
#include "../../Hooks/Hooker.hpp"


class PackSelectLayer : public Betterhook::HookBetter {
public:
    void init(CCNode* _This) override {
        //_This->setTag(100);
        if (auto bg = _This->getChildByID("background")) {
            bg->setVisible(false);
        }

        SwelvyBG* swelvyBG = SwelvyBG::create();
        swelvyBG->setZOrder(-1);
        swelvyBG->setID("swelvy-background");
        _This->addChild(swelvyBG);
    }

    const char* PutLayer() const override {
        return "PackSelectLayer";
    }
};

REGISTER_HookBetter(PackSelectLayer);

#include <Geode/modify/CCSprite.hpp>
class $modify(CCSprite) {
    void draw() {
        CCSprite::draw();
        auto scene = CCDirector::sharedDirector()->getRunningScene();
        if (auto pkl = scene->getChildByID("PackSelectLayer")) {
            if (auto bg = pkl->getChildByID("background"))
                bg->setVisible(false);
            
            if (pkl->getChildByID("swelvy-background"))
                return;

            SwelvyBG* swelvyBG = SwelvyBG::create();
            swelvyBG->setZOrder(-1);
            swelvyBG->setID("swelvy-background");
            pkl->addChild(swelvyBG);
        }
    }
};
