# Fonctional documentation

- General 
- Server
- Client 

## General

The program is developped in C++ and is using Conan for the depedencies management

To compile the program, execute the build.sh script


##  Server 

Usage : r-type_server [PORT]

PORT : Launch the program with the defined port. By default the program is launched on port 8080. 

Once the program is launched the ip address is displayed



##  Client

Usage : r-type_client

When the game is launched, you need to fill some fields : 
- your username 
- the ip address of the server 
- the port the server is listening on

After clicking the login button, you can either create a room or join a room.
You can see the different rooms already created by the other players.
You can't join game that are already in progress. 
The number of player per room is limited to 4 players maximum.
Only the creator of the room can launch the game.

Once the game is launched, play solo or with your friends and try to survive.

Command: 

Z move up
S move down
q move left
d move right

WARNING: If the host of the game exits the lobby, all of the players are disconnected of the game session.
