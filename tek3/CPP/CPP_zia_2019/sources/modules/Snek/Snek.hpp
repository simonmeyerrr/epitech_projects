#ifndef SNEK_HPP_
#define SNEK_HPP_

#include <memory>
#include <deque>

#include <SFML/Graphics.hpp>

#include <ModuleLoggable.hpp>

#include "AHttp.hpp"
#include "Thread.hpp"
#include "Atomic.hpp"

#define ABS(X)(X<0?-X:X)
#define MIN(X,Y)(X<Y?X:Y)
#define MAX(X,Y)(X<Y?Y:X)

class Snek : public api::module::AHttp, public ModuleLoggable {
public:
    ~Snek() noexcept override;
    Snek() noexcept;

    api::String getName() const override {return "Snek";}

    bool handle(Connection &connection) override;

    void setLogger(api::module::ALogger *logger) override;
    void setConfig(const api::JsonObject &config) override;

private:
    void wait(std::size_t const) const noexcept;
    void doASnaggyRoll() noexcept; //when the snaggy goes WOOOSH
    void doTheBlelp();

    struct Sneker;
    sf::Texture _snegMentT, _blolpT, _snegHeadT, _starsT;
    sf::Sprite _back;
    struct SnekAble { //able to sneg the snekable as a snektor
        SnekAble(float const &, float const &) noexcept;
        virtual ~SnekAble() noexcept = default;
        SnekAble &operator=(SnekAble const &) = default;
        float _x, _y, _imprecisionX{0}, _imprecisionY{0}; //snektor like definition
    };

    struct Blolp final : public SnekAble { //for the snake to mlolp
        Blolp(float const &, float const &, Snek &, unsigned char const blooo = 1) noexcept;
        virtual ~Blolp() noexcept override final = default;
        unsigned char _blooo; //the blooo-ness of the blolp defines how much the sneg is sneggy after mlolping the instanciated blolp
        bool _ded{false};
        sf::Sprite _sprt;
        Snek &_s;
    };

    struct SnegMent final : public SnekAble { //snegmentation of the snaggy-thing
        SnegMent(float const &, float const &, Sneker &, bool const head = false) noexcept;
        sf::Sprite _sprt;
        Sneker &_s;
        bool _mv{true}, _head;
        std::pair<float, float> _way{0, 0};
    };

    struct Compass {
        virtual ~Compass() noexcept = default;
        enum PampaCompass {
            _,N,E,S,W
        };
        Atomic<bool> _vntDep{false};
        Atomic<PampaCompass> _sneggPass{_};
        virtual void magicalCompass(Snek &) noexcept = 0;
    };

    struct KbdPass final : Compass {
        KbdPass() noexcept;
        virtual void magicalCompass(Snek &) noexcept override final;
    };

    struct RnPass final : Compass {
        virtual void magicalCompass(Snek &) noexcept override final;
    };

    struct Sneker { //it is used to sneg the snekky (belonging to the pampa, like the snegs or blolps (then in this case, mlolping happens))
        Sneker(Compass *, float const &, float const &, Snek &) noexcept;
        virtual ~Sneker() noexcept = default;
        void gros(std::size_t n = 1) noexcept;
        void snegArround(float const &, float const &) noexcept; //way to sneg in the sneg dimension
        bool _ded{false}, _dy{false};
        unsigned char _dyer = 255;
        sf::Color _sneggSkin;
        std::unique_ptr<Compass> _sneggWay;
        int _sneggy{12};
        std::deque<SnegMent> _zeSneg; //the actual famous SNEG
        Snek &_s;
    };
    void rewind() noexcept;
    struct SnegWorld { //the snegworld for all the snegginess lying arround
        std::deque<Sneker> _snegs; //a collection mimicking the pampa snegborhood
        std::deque<Blolp> _blolps; //growing happenz when the mlolp occurs
        Mutex _wrldMtx;
    } _pampa; //(pampa)

    std::size_t _speed = 12;
    void guardThis() noexcept;
    void my_runner_2017() noexcept;
    Thread<> _parallelSnegDimension; //the sneggy spooky dimension where all the mlolps on blolps occurs by the sneg's devotion
    Atomic<bool> _ragnaSneg{false};
    Mutex _wnMtx;
    int _appleFrequency{1};
    api::JsonObject _config;
    std::unique_ptr<sf::RenderWindow> _wn = nullptr;
    Atomic<bool> _nWn{true};
    sf::Event _vnt;
    Thread<> _snekWasher, _snekRunn;
    unsigned int _winX{800}, _winY{600};
    bool _wk{true};
};

#endif
