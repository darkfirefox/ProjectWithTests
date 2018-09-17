#!/bin/bash

# Script for running tests. That's for specifying just one argument in QtCreator's configuration
/usr/bin/tst-translateMVC--sailfish -input /usr/share/tst-translateMVC-sailfish

# When you'll get some QML components in the main app, you'll need to import them to the test run
# /usr/bin/tst-translateMVC--sailfish -input /usr/share/tst-harbour-helloworld-pro-sailfish -import /usr/share/translateMVC-sailfish/qml/components
