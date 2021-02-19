#include <chrono>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#include "Snek.hpp"

MODULE_EXPORTER(Snek)

Snek::Snek() noexcept {
    srand(static_cast<unsigned int>(time(nullptr) ^ (std::size_t)this));
    if (_wk)
        _parallelSnegDimension = Thread<>{&Snek::doASnaggyRoll, this};
}

bool Snek::handle(Connection &connection) {
    doTheBlelp();
    return true;
}

Snek::~Snek() noexcept {
    _ragnaSneg.store(true);
    if (_wk)
        _parallelSnegDimension.join();
}

void Snek::setLogger(api::module::ALogger *logger) {
    updateLogger(logger);
}

void Snek::setConfig(const api::JsonObject &config) {
    _config = config;
    try {
        _winX = _config.at(L"resolution").as<api::JsonArray>()[0].as<api::JsonNumber>();
        _winY = _config.at(L"resolution").as<api::JsonArray>()[1].as<api::JsonNumber>();
        _appleFrequency = _config.at(L"apple frequency").as<api::JsonNumber>();
        _speed = _config.at(L"snake speed").as<api::JsonNumber>();
    } catch (...) {}
}

Snek::KbdPass::KbdPass() noexcept {
    _vntDep.store(true);
}

void Snek::KbdPass::magicalCompass(Snek &s) noexcept {
    if (s._vnt.type == sf::Event::KeyPressed) {switch (s._vnt.key.code) {case sf::Keyboard::Z: {if (_sneggPass.load() == Compass::PampaCompass::_ || !(_sneggPass.load() % 2)) {_sneggPass.store(Compass::PampaCompass::N);}break;}case sf::Keyboard::Up: {if (_sneggPass.load() == Compass::PampaCompass::_ || !(_sneggPass.load() % 2)) {_sneggPass.store(Compass::PampaCompass::N);}break;}case sf::Keyboard::S: {if (_sneggPass.load() == Compass::PampaCompass::_ || !(_sneggPass.load() % 2)) {_sneggPass.store(Compass::PampaCompass::S);}break;}case sf::Keyboard::Down: {if (_sneggPass.load() == Compass::PampaCompass::_ || !(_sneggPass.load() % 2)) {_sneggPass.store(Compass::PampaCompass::S);}break;}case sf::Keyboard::Q: {if (_sneggPass.load() == Compass::PampaCompass::_ || _sneggPass.load() % 2) {_sneggPass.store(Compass::PampaCompass::W);}break;}case sf::Keyboard::Left: {if (_sneggPass.load() == Compass::PampaCompass::_ || _sneggPass.load() % 2) {_sneggPass.store(Compass::PampaCompass::W);}break;}case sf::Keyboard::D: {if (_sneggPass.load() == Compass::PampaCompass::_ || _sneggPass.load() % 2) {_sneggPass.store(Compass::PampaCompass::E);}break;}case sf::Keyboard::Right: {if (_sneggPass.load() == Compass::PampaCompass::_ || _sneggPass.load() % 2) {_sneggPass.store(Compass::PampaCompass::E);}break;}default:return;}}
}

void Snek::RnPass::magicalCompass(Snek &s) noexcept {
    if (_sneggPass.load() == Compass::PampaCompass::_ || !(rand() % 40)) {
        Compass::PampaCompass n = (Compass::PampaCompass)(rand() % 4 + 1);
        if (_sneggPass.load() == Compass::PampaCompass::_ || n % 2 != _sneggPass.load() % 2)
            _sneggPass.store(n);
    }
}

void Snek::rewind() noexcept {
    _pampa._snegs.clear();
    _pampa._blolps.clear();
    _pampa._snegs.emplace_back(new KbdPass{}, rand() % (int)(_winX - 10), rand() % (int)(_winY - 10), *this);
    _pampa._snegs.front().gros(3);
}

void Snek::doTheBlelp() {
    if (_ragnaSneg.load())
        return;
    _pampa._snegs.emplace_back(new RnPass{}, rand() % (int)(_winX - 10), rand() % (int)(_winY - 10), *this);
    _pampa._snegs.back().gros(rand() % 10);
}

Snek::SnekAble::SnekAble(float const &x, float const &y) noexcept : _x{std::move(x)}, _y{std::move(y)} {
                                                                                      }

Snek::Blolp::Blolp(float const &x, float const &y, Snek &s, unsigned char const blooo) noexcept : SnekAble{std::move(x), std::move(y)}, _blooo{std::move(blooo)}, _s{s} {
    _sprt.setTexture(_s._blolpT);
    _sprt.setColor(blooo < 3 ? sf::Color{255, 255, 0} : blooo < 5 ? sf::Color{255, 102, 0} : sf::Color{255, 0, 0});
                                                                                                                                                                  }

Snek::Sneker::Sneker(Compass *ctrl, float const &x, float const &y, Snek &s) noexcept : _sneggWay{std::move(ctrl)}, _s{s} {
    _sneggWay->_sneggPass = (Compass::PampaCompass)(rand() % 4 + 1);
    switch (rand() % 7) {case 0:_sneggSkin = sf::Color{(sf::Uint8)(rand() % 155 + 100), (sf::Uint8)(rand() % 100), (sf::Uint8)(rand() % 100)};break;case 1:_sneggSkin = sf::Color{(sf::Uint8)(rand() % 100), (sf::Uint8)(rand() % 155 + 100), (sf::Uint8)(rand() % 100)};break;case 2:_sneggSkin = sf::Color{(sf::Uint8)(rand() % 100), (sf::Uint8)(rand() % 100), (sf::Uint8)(rand() % 155 + 100)};break;case 3:_sneggSkin = sf::Color{(sf::Uint8)(rand() % 100), (sf::Uint8)(rand() % 155 + 100), (sf::Uint8)(rand() % 155 + 100)};break;case 4:_sneggSkin = sf::Color{(sf::Uint8)(rand() % 155 + 100), (sf::Uint8)(rand() % 155 + 100), (sf::Uint8)(rand() % 100)};break;case 5:_sneggSkin = sf::Color{(sf::Uint8)(rand() % 155 + 100), (sf::Uint8)(rand() % 100), (sf::Uint8)(rand() % 155 + 100)};break;case 6:_sneggSkin = sf::Color{(sf::Uint8)(rand() % 155 + 100), (sf::Uint8)(rand() % 155 + 100), (sf::Uint8)(rand() % 155 + 100)};break;default:0[(char*)0]=0;break;}
    _zeSneg.emplace_back(x, y, *this, true);
    _sneggy = s._speed;
                                                                                                                    }

Snek::SnegMent::SnegMent(float const &x, float const &y, Sneker &s, bool const head) noexcept : Snek::SnekAble{std::move(x), std::move(y)}, _s{s}, _mv{head}, _head{head} {
    if (head)
        _sprt.setTexture(_s._s._snegHeadT);
    else
        _sprt.setTexture(_s._s._snegMentT);
    _sprt.setColor(_s._sneggSkin);
                                                                                                                                                              }

void Snek::wait(std::size_t const t) const noexcept {
    std::this_thread::sleep_for(std::chrono::milliseconds(t));
}

void Snek::Sneker::snegArround(float const &x, float const &y) noexcept {
    SnekAble actionFault{0, 0}, swap{0, 0};
    bool h{false};
    std::for_each(_zeSneg.begin(), _zeSneg.end(), [&](SnegMent &s){swap = *dynamic_cast<SnekAble *>(&s);if (s._head) {s._x += x;s._y += y;h = true;}if (s._mv) {if (!s._head) {*dynamic_cast<SnekAble *>(&s) = actionFault;if (h) {h = false;s._imprecisionX = rand() % 4 - 2;s._imprecisionY = rand() % 4 - 2;}}if (s._x <= -10)s._x = s._s._s._winX - 10;else if (s._y <= -10)s._y = s._s._s._winY - 10;else if (s._y >= s._s._s._winY)s._y = 0;else if (s._x >= s._s._s._winX)s._x = 0;} else {s._way.first += x;s._way.second += y;if (s._way.first >= s._s._sneggy || s._way.second >= s._s._sneggy || s._way.second <= s._s._sneggy || s._way.first <= s._s._sneggy) {s._mv = true;}}actionFault = swap;});
}

void Snek::my_runner_2017() noexcept {
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    float elapsed = 0, fac = 1;
    while (!_ragnaSneg.load()) {
        if (_nWn.load()) {
            wait(10);
            continue;
        }
        start = std::chrono::steady_clock::now();
        {
            Locker wrldLckr{_pampa._wrldMtx};
            std::for_each(_pampa._snegs.begin(), _pampa._snegs.end(), [&](Sneker &s){if (s._ded)return;if (s._dy) {if (s._dyer < 50) s._ded = true; else s._dyer -= 5;} if (!s._dy) {switch (s._sneggWay->_sneggPass) {case Compass::PampaCompass::N: {s.snegArround(0, -s._sneggy * fac);break;}case Compass::PampaCompass::S: {s.snegArround(0, s._sneggy * fac);break;}case Compass::PampaCompass::E: {s.snegArround(s._sneggy * fac, 0);break;}case Compass::PampaCompass::W: {s.snegArround(-s._sneggy * fac, 0);break;}default:break;}}});
            if (_appleFrequency > rand() % 100)_pampa._blolps.emplace_back(rand() % (int)(_winX - 10), rand() % (int)(_winY - 10), *this, rand() % 6 + 1);
            std::for_each(_pampa._snegs.begin(), _pampa._snegs.end(), [&](Sneker &s){if (s._ded)return;SnegMent &collide = s._zeSneg.front();std::for_each(_pampa._snegs.begin(), _pampa._snegs.end(), [&](Sneker &ss){if (ss._ded)return;std::for_each(ss._zeSneg.begin() + 1, ss._zeSneg.end(), [&](SnegMent &sn){if ((sn._mv || &s != &ss) && 8 > std::sqrt((sn._x - collide._x) * (sn._x - collide._x) + (sn._y - collide._y) * (sn._y - collide._y)))s._dy = true;});});std::for_each(_pampa._blolps.begin(), _pampa._blolps.end(), [&](Blolp &b){if (b._ded)return;if (10 > std::sqrt((b._x - collide._x) * (b._x - collide._x) + (b._y - collide._y) * (b._y - collide._y))) {s.gros(b._blooo);b._ded = true;}});});
        }
        end = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        if (elapsed < 30)
            wait(30 - elapsed);
        end = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        fac = elapsed / 30;
    }
}

void Snek::doASnaggyRoll() noexcept {
    if (!_snegMentT.loadFromFile("resources/snek/snegMent.png") || !_snegHeadT.loadFromFile("resources/snek/snegHead.png") || !_blolpT.loadFromFile("resources/snek/blolp.png") || !_starsT.loadFromFile("resources/snek/stars.png"))
        _ragnaSneg.store(true);
    _snekWasher = Thread<>{&Snek::guardThis, this};
    _snekRunn = Thread<>{&Snek::my_runner_2017, this};
    wait(100);
    if (_nWn.load() && _wk && !_ragnaSneg.load()) {
        _wn = std::make_unique<sf::RenderWindow>(sf::VideoMode(_winX, _winY), "SNEG", sf::Style::Close);
        _back.setTexture(_starsT);
        _wn->setFramerateLimit(30);
        _wn->setActive(true);
        rewind();
        _nWn.store(false);
    }
    while (!_ragnaSneg.load()) {
        {
            Locker wnLckr{_wnMtx};
            if (_wn) {
                _wn->clear();
                _wn->draw(_back);
                std::for_each(_pampa._snegs.begin(), _pampa._snegs.end(), [&](Sneker &s){if (s._ded)return;std::for_each(s._zeSneg.begin(), s._zeSneg.end(), [&](SnegMent &sn){sn._sprt.setPosition(sn._x + sn._imprecisionX, sn._y + sn._imprecisionY); sn._sprt.setColor(sf::Color{sn._s._sneggSkin.r, sn._s._sneggSkin.g, sn._s._sneggSkin.b, sn._s._dyer}); _wn->draw(sn._sprt); });});std::for_each(_pampa._blolps.begin(), _pampa._blolps.end(), [&](Blolp &b){if (b._ded)return;b._sprt.setPosition(b._x + b._imprecisionX, b._y + b._imprecisionY);_wn->draw(b._sprt);});
                _wn->display();
            }
        }
    }
    _snekWasher.join();
    _snekRunn.join();
}

void Snek::Sneker::gros(std::size_t n) noexcept {
    while (n--)
        _zeSneg.emplace_back(_zeSneg.back()._x, _zeSneg.back()._y, *this, false);
}

void Snek::guardThis() noexcept {
    while (!_ragnaSneg.load()) {
        if (_nWn.load()) {
            wait(10);
            continue;
        }
        {
            Locker wnLckr{_wnMtx};
            while (_wn->pollEvent(_vnt)){
                if (_vnt.type == sf::Event::Closed) {
                    _wn->close();
                    _wn = nullptr;
                    _ragnaSneg.store(true);
                    return;
                } else if (sf::Event::KeyPressed ==_vnt.type) {
                    if (sf::Keyboard::Space == _vnt.key.code) {
                        Locker wrldLckr{_pampa._wrldMtx};
                        rewind();
                    } else if (sf::Keyboard::Escape == _vnt.key.code) {
                        _wn->close();
                        _wn = nullptr;
                        _ragnaSneg.store(true);
                        return;
                    } else {
                        Locker wrldLckr{_pampa._wrldMtx};
                        std::for_each(_pampa._snegs.begin(), _pampa._snegs.end(), [&](Sneker &s){if (s._dy)return;if (s._sneggWay->_vntDep.load()) s._sneggWay->magicalCompass(*this);});
                    }
                }
            }
        }
        {
            Locker wrldLckr{_pampa._wrldMtx};
            std::for_each(_pampa._snegs.begin(), _pampa._snegs.end(), [&](Sneker &s){if (s._dy)return;if (!s._sneggWay->_vntDep.load()) s._sneggWay->magicalCompass(*this);});
        }
        wait(30);
    }
}
