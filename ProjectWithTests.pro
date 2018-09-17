TEMPLATE = subdirs

SUBDIRS =translateMVC test

OTHER_FILES += $$files(rpm/*)
CONFIG+=ordered
