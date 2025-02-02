#ifndef CPP_RTYPE_2019_CONFIG_HPP
#define CPP_RTYPE_2019_CONFIG_HPP

#define STRINGIFY(x) XSTRINGIFY(x)
#define XSTRINGIFY(x) #x

#ifndef ASSETS_PATH
    #define ASSETS_PATH ./assets/
#endif /* ASSETS_PATH */

#define ASSETS_PATH_STR STRINGIFY(ASSETS_PATH)

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

#endif //CPP_RTYPE_2019_CONFIG_HPP
