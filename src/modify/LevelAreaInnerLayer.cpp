#include "../SwelvyBG.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/LevelAreaInnerLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelAreaInnerLayer, LevelAreaInnerLayer) {
	bool init(bool p0) {
		if (!LevelAreaInnerLayer::init(p0)) {
			return false;
		}
		if (Mod::get()->getSettingValue<bool>("show-inner-tower")){
			auto swelvyBG = SwelvyBG::create();
			swelvyBG->setZOrder(-2);
			swelvyBG->setID("swelvy-background");

			this->addChild(swelvyBG);
		}
		return true;
	}
};