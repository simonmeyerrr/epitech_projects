The project is developed in C++ and is using Conan for the dependencies management

To compile the program, execute the `build.sh`.


**How to start the server**

To start server use the command below.

./zia load resources/config.json start -n

This config.json is used with ssl. You can open
a page on https://localhost:port.c (By default port:8080) 

The config2.json is used without ssl. You can open
a page on http://localhost:port.

**On the web site**

There are three pages:

One for testing POST request.

Another one for testing GET resquest with query.

The last one is set to visualize the header's page set with PhpCgi.