#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(HelloMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto winSize = CCDirector::get()->getWinSize();

        // The button itself
        auto sprite = ButtonSprite::create("Hello");
        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(HelloMenuLayer::onHelloButton)
        );

        // Put the button in its own menu, top-left corner of the screen
        auto menu = CCMenu::create();
        menu->setID("hello-menu"_spr);
        menu->addChild(button);
        menu->setPosition({60.f, winSize.height - 30.f});
        this->addChild(menu);

        return true;
    }

    void onHelloButton(CCObject*) {
        // Remove the old text first so clicking again doesn't stack labels
        if (auto old = this->getChildByID("hello-label"_spr)) {
            old->removeFromParent();
        }

        auto winSize = CCDirector::get()->getWinSize();

        auto label = CCLabelBMFont::create("Hello!", "bigFont.fnt");
        label->setID("hello-label"_spr);
        label->setPosition({winSize.width / 2.f, winSize.height / 2.f});
        this->addChild(label, 100);
    }
};
