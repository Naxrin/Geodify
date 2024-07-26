#include "../SwelvyBG.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelBrowserLayer, LevelBrowserLayer) {
	bool init(GJSearchObject* p0) {
		if (!LevelBrowserLayer::init(p0)) {
			return false;
		}
		if (Mod::get()->getSettingValue<bool>("show-vault-of-secrets")){
			if (auto bg = this->getChildByID("background")) {
				bg->setVisible(false);
				auto swelvyBG = SwelvyBG::create();
				swelvyBG->setZOrder(-2);
				swelvyBG->setID("swelvy-background");
	
				this->addChild(swelvyBG);				
			}
		}
		return true;
	}
};