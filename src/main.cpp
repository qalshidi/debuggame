/*
The MIT License (MIT)

Copyright (c) 2015 Qusai Al Shidi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <string>
#include "NessEngine/NessEngine.h"

#include "Game.h"
#include "Entity/Entity.h"
#include "Entity/Character.h"
#include "States/LocalMap.h"

using namespace std;

int main(int argc, char** argv)
{
    //Graphics engine init
    Ness::init();
    //Game init
    Engine::Game::instance().init();
    
    auto localmap = make_shared<Engine::LocalMapState>();
    localmap->on_start();
    Engine::Game::instance().push_state(localmap);

    Ness::Utils::EventsPoller EventsPoller;
    Ness::Utils::ApplicationEvents app;
    EventsPoller.add_handler(app);

    while( !app.got_quit() )
    {
        EventsPoller.poll_events();
        Engine::Game::instance().update();
    }

    return 0;
}
