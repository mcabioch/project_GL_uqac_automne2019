DEBUG = no

#
#	Softwares
#
AR = ar
RM = rm
INFO = doxygen
ARCHIVE = tar
libCreate = $(TEMPDIR)/libCreate

CXXExtension =
CCExtension =

ifeq ($(TARGET),rpi1)
	CXXExtension = arm-linux-gnueabihf-
	CCExtension = arm-linux-gnueabihf-
else ifeq ($(TARGET),rpi2)
	CXXExtension = arm-linux-gnueabihf-
	CCExtension = arm-linux-gnueabihf-
else ifeq ($(TARGET),rpi3)
	CXXExtension = arm-linux-gnueabihf-
	CCExtension = arm-linux-gnueabihf-
else ifeq ($(TARGET),beaglebb)
	CXXExtension = arm-linux-gnueabihf-
	CCExtension = arm-linux-gnueabihf-
else ifeq ($(TARGET),win)
	CXXExtension = x86_64-w64-mingw32-
	CCExtension = x86_64-w64-mingw32-
endif

CXX = $(CXXExtension)g++
CC = $(CCExtension)gcc

#
#	OS
#
ifeq ($(OS),Windows_NT)
	DETECTED_OS = Windows
	TARGET = win
else
	DETECTED_OS = $(shell uname)
endif

#
#	Folders
#
BINDIR = bin
SRCDIR = src
INCDIR = inc
OBJDIR = obj
LIBDIR = lib
DOCDIR = doc
SQLDIR = sql
RESDIR = res
TEMPDIR = $(HOME)/Bureau/Mes_Documents/Programmation/Makefiles/Templates
MAINDOCDIR = $(HOME)/Bureau/Mes_Documents/Docs

#
#	Needed files
#
BIN := $(wildcard $(BINDIR)/*)
SRC := $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/*.c)
NAME := $(basename $(notdir $(SRC)))
CINC := $(wildcard $(INCDIR)/*.h)
CXXINC := $(wildcard $(INCDIR)/*.hpp)
OBJ := $(addprefix $(OBJDIR)/, $(addsuffix .o, $(NAME)))
DOC := $(wildcard doc/*.doxyfile)

ifneq ($(TARGET),)
	LIB := $(wildcard $(LIBDIR)/*-$(TARGET).a)
else
	LIB := $(filter-out $(wildcard $(LIBDIR)/*-*.a), $(wildcard $(LIBDIR)/*.a))
endif

LIBS := $(addprefix -l, $(subst lib, , $(subst .a, , $(LIB))))

ISSFML = $(basename $(notdir $(wildcard $(LIBDIR)/SFML.a)))


#
#	Output software name
#
EXE_TMP = $(shell basename $(CURDIR))

#
#	Flags
#
CCXXWARNINGS = -W -Wconversion
CCXXWARNINGS += -Wall -Wextra -pedantic

CXXWARNINGS = -Wcast-qual -Wcast-align -Wpointer-arith
CXXWARNINGS += -Woverloaded-virtual -Wctor-dtor-privacy -Wdelete-non-virtual-dtor
CXXWARNINGS += -Wshadow -Weffc++
CXXWARNINGS += -Wwrite-strings -Wredundant-decls -Wdouble-promotion -Winit-self -Wswitch-default -Wundef -Wlogical-op

CCXXFLAGS = -I$(INCDIR) $(CCXXWARNINGS)

ifeq ($(DEBUG), yes)
	CCXXFLAGS += -g -ggdb -Werror -Wfatal-errors -Og
else
	CCXXFLAGS += -O2 -s
endif

CXXFLAGS = $(CCXXFLAGS) -std=c++14  $(CXXWARNINGS) -Wold-style-cast
CFLAGS = $(CCXXFLAGS)
ARFLAGS = crf
RMFLAGS = -rf
ARCHFLAGS = cvf

ifeq ($(TARGET),rpi1)
	CXXFLAGS += -mcpu=arm1176jzf-s -mfloat-abi=hard -mfpu=vfp -mtune=arm1176jzf-s
else ifeq ($(TARGET),rpi2)
	CXXFLAGS += -mcpu=cortex-a7 -mfloat-abi=hard -mfpu=neon-vfpv4 -mtune=cortex-a7
else ifeq ($(TARGET),rpi3)
	CXXFLAGS += -mcpu=cortex-a53 -mfloat-abi=hard -mfpu=neon-fp-armv8 -mneon-for-64bits -mtune=cortex-a53
else ifeq ($(TARGET),beaglebb)
	CXXFLAGS += -mcpu=cortex-a8 -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8
else ifeq ($(TARGET),win)
	CXXFLAGS += -w
endif

#
#	Link flags
#
UNKNOWNLIBS = -Wl,--no-as-needed

ifeq ($(ISSFML),SFML)
	OPENGLLIBS =# -lGL -lGLU
	SFMLLIBS = -L/usr/local/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-network-s -lsfml-audio-s $(OPENGLLIBS)
endif

BDDLIBS =# -lmysqlcppconn-static
PTHREADLIBS = -pthread -lpthread

CXXLIBS = -lm $(PTHREADLIBS) -static
ifeq ($(TARGET),win)
	CXXLIBS += -static-libstdc++ $(wildcard $(LIBDIR)/libboost_*.a)
endif

QTLIBS = $(LIB) $(BDDLIBS) -lm $(PTHREADLIBS)

LDFLAGS = $(LIB) $(SFMLLIBS) $(BDDLIBS) $(CXXLIBS)# -lOpenCL

#
#	Targets
#
ifeq ($(TARGET),rpi1)
	EXTENSION = -rpi1
	NETTARGET = `cat config | grep -i "$(TARGET)" | cut --delimiter='|' -f 2`
else ifeq ($(TARGET),rpi2)
	EXTENSION = -rpi2
	NETTARGET = `cat config | grep -i "$(TARGET)" | cut --delimiter='|' -f 2`
else ifeq ($(TARGET),rpi3)
	EXTENSION = -rpi3
	NETTARGET = `cat config | grep -i "$(TARGET)" | cut --delimiter='|' -f 2`
else ifeq ($(TARGET),beaglebb)
	EXTENSION = -beaglebb
	NETTARGET = `cat config | grep -i "$(TARGET)" | cut --delimiter='|' -f 2`
else ifeq ($(TARGET),win)
	EXTENSION = -win
	CCXXFLAGS += -DMAKE_WINDOWS
endif

EXE = $(EXE_TMP)$(EXTENSION)

ifeq ($(TARGET),win)
	FIN_EXE = $(EXE).exe
else
	FIN_EXE = $(EXE)
endif

#
#	SymLinks
#
DOXYLN = $(MAINDOCDIR)/$(FIN_EXE).doxyfile
HTMLLN = $(MAINDOCDIR)/Web/$(FIN_EXE)-doc

#
#	Files
#
MAINFILE = main.cpp

FUNCTFILEC = functions.cpp
FUNCTFILEH = functions.hpp

OPENGLH = OpenGL.hpp
OPENGLC = OpenGL.cpp

CLASSFILEC = Class.cpp
CLASSFILEH = Class.hpp

DOXYFILE = Doxyfile

MAINWINDOWH = MainWindow.h
MAINWINDOWC = MainWindow.cpp

CMAINFILE = main.c

CFUNCTFILEC = functions.c
CFUNCTFILEH = functions.h

CONFIG = config

#
#	Others
#
CIN = ~/Bureau/Algo/CTests/C/inc/C
COUT = $(INCDIR)/C
CPPIN = ~/Bureau/Algo/C++Tests/C++/inc/C++
CPPOUT = $(INCDIR)/C++

BOOSTIN = ~/Bureau/Algo/Boost/boost_1_71_0/bin/inc/boost
BOOSTOUT = $(INCDIR)/boost

SFMLIN = ~/Bureau/Algo/SFMLWidgetsTests/SFML/inc/SFML
SFMLOUT = $(INCDIR)/SFML
SFMLRESIN = ~/Bureau/Algo/SFMLWidgetsTests/SFML/res/*
SFMLRESOUT = $(RESDIR)/

QTIN = ~/Bureau/Algo/QTTests/Widgets
QTOUT = ./inc/Widgets

PROJECTFILE = $(wildcard *.pro)
ifeq ($(PROJECTFILE),)
	PROJECTFILE = $(EXE).pro
endif

LIBCIN = $(wildcard ~/Bureau/Algo/CTests/C/lib/*.a)
LIBCOUT = $(addprefix $(LIBDIR)/, $(notdir $(LIBCIN)))

LIBCPPIN = $(wildcard ~/Bureau/Algo/C++Tests/C++/lib/*.a)
LIBCPPOUT = $(addprefix $(LIBDIR)/, $(notdir $(LIBCPPIN)))

LIBBOOSTIN = $(wildcard ~/Bureau/Algo/Boost/boost_1_71_0/bin/lib/*.a)
LIBBOOSTOUT = $(addprefix $(LIBDIR)/, $(notdir $(LIBBOOSTIN)))

LIBSFMLIN = $(wildcard ~/Bureau/Algo/SFMLWidgetsTests/SFML/lib/*.a)
LIBSFMLOUT = $(addprefix $(LIBDIR)/, $(notdir $(LIBSFMLIN)))

ARCHNAME = $(FIN_EXE)

QTMAKEFILE = Makefile QMAKE=qmake

#
#	Rules
#
all:
	qmake -project
	if [ ! -f $(PROJECTFILE) ]; then qmake -project; fi
	echo "\nQT += gui core widgets" >> $(PROJECTFILE)
#
	qmake
	echo "\nCXXFLAGS +=  -std=c++14 -Iinc" >> Makefile
#
	$(MAKE) -f $(QTMAKEFILE) all SUBLIBS="$(QTLIBS)"

$(BINDIR)/$(FIN_EXE): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(BINDIR)/$(FIN_EXE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(CINC)
	$(CC) -c $< -o $@ $(CFLAGS) $(OTHERFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(CXXINC)
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(OTHERFLAGS)

#
#	Implicit rules
#
PHONY =

PHONY += createDirs create createBoost createC createSFML createSFMLOPENGL

createDirs:
	mkdir -p $(BINDIR)
	mkdir -p $(DOCDIR)
	mkdir -p $(INCDIR)
	mkdir -p $(LIBDIR)
	mkdir -p $(OBJDIR)
	mkdir -p $(SQLDIR)
	mkdir -p $(SRCDIR)
#
	mkdir -p $(RESDIR)
	mkdir -p $(RESDIR)/imgs
#
	make doxyfile

PHONY += cleanConfigure clean mrproper remove

cleanConfigure:
	$(RM) $(RMFLAGS) autoscan.log
	$(RM) $(RMFLAGS) config.h.in
	$(RM) $(RMFLAGS) configure.ac
	$(RM) $(RMFLAGS) autom4te.cache

clean: cleanConfigure
	$(RM) $(RMFLAGS) $(OBJDIR)/*
#
	$(RM) $(RMFLAGS) configure

mrproper: clean
	$(RM) $(RMFLAGS) ./$(BINDIR)/*
	$(RM) $(RMFLAGS) $(ARCHNAME).tar

remove: clean
	$(RM) $(RMFLAGS) $(BINDIR)
	$(RM) $(RMFLAGS) $(DOCDIR)
	$(RM) $(RMFLAGS) $(INCDIR)
	$(RM) $(RMFLAGS) $(LIBDIR)
	$(RM) $(RMFLAGS) $(OBJDIR)
	$(RM) $(RMFLAGS) $(SQLDIR)
	$(RM) $(RMFLAGS) $(SRCDIR)
	$(RM) $(RMFLAGS) $(RESDIR)
#
	$(RM) $(RMFLAGS) $(DOXYLN)
	$(RM) $(RMFLAGS) $(HTMLLN)

PHONY += install remake lib libs

install: clean
	make all

remake: mrproper install

PHONY += qtRun qtClean qt qtInstall qtRemove createQt libqt qtRemake install_dependencies

createQt: createDirs
	cp "$(TEMPDIR)/QT$(MAINFILE)" "$(SRCDIR)/$(MAINFILE)"
	cp "$(TEMPDIR)/QT$(MAINWINDOWC)" "$(SRCDIR)/$(MAINWINDOWC)"
	cp "$(TEMPDIR)/QT$(MAINWINDOWH)" "$(INCDIR)/$(MAINWINDOWH)"
#
	make libqt

libqt: libcpp
	rm -rf $(BINDIR)
	rm -rf $(OBJDIR)
#
	ln -sfn $(QTIN) $(QTOUT)

qt:
	qmake -project
	echo "\nQT += gui core widgets" >> $(PROJECTFILE)
#
	qmake
	echo "\nCXXFLAGS +=  -std=c++14 -Iinc" >> Makefile
#
	$(MAKE) -f $(QTMAKEFILE) all SUBLIBS="$(QTLIBS)"

qtRemake: mrproper
	rm -rf *.pro
	rm -rf Makefile
	rm -rf moc_*
	rm -rf *.o
	rm -rf $(FIN_EXE)
#
	make qt

qtClean: clean
	make -f $(QTMAKEFILE) clean

qtInstall: qt qtClean

qtRemove: remove
	rm -rf Widgets
	rm -rf *.pro
	rm -rf Makefile
	rm -rf moc_*
	rm -rf *.o
	rm -rf $(FIN_EXE)

qtRun:
	@./$(FIN_EXE)

PHONY += doxyfile doc

doxyfile:
	"$(TEMPDIR)/addDoxyfile" "$(TEMPDIR)" "$(CURDIR)" "$(DOCDIR)" "$(DOXYFILE)" "$(DOXYLN)" "$(HTMLLN)"

doc:
ifneq (,$(wildcard $(DOCDIR)/$(DOXYFILE)))
	doxygen $(DOCDIR)/$(DOXYFILE)
endif

PHONY += dist configure export

dist: remake
	make configure
	$(ARCHIVE) $(ARCHFLAGS) $(FIN_EXE).tar $(BINDIR)/$(FIN_EXE) $(RESDIR)/ sql/ doc/

configure:
	autoscan
	mv configure.scan configure.ac
	aclocal
	autoheader
#	mv config.h.in config.in
	autoconf

export: remake mrproper doc configure
	$(RM) $(RMFLAGS) $(ARCHNAME)
#
	mkdir -p $(ARCHNAME)
#
	echo "#!/bin/sh\n\nrm -rf conf19262.dir\nrm -rf conf19262\nrm -rf conf19262.file\nrm -rf config.h\nrm -rf config.h.in\nrm -rf config.log\nrm -rf config.status\nrm -rf makefile.in\n\nmake install\nmake run\n\nexit 0" > $(ARCHNAME)/install.sh
	chmod a+x $(ARCHNAME)/install.sh
#
	rsync -avrL --exclude="$(ARCHNAME)" --exclude="$(OBJDIR)/*" ./ $(ARCHNAME)
#
	mv $(ARCHNAME)/makefile $(ARCHNAME)/makefile.in
#
	$(ARCHIVE) $(ARCHFLAGS) $(ARCHNAME).tar $(ARCHNAME)
#
	$(RM) $(RMFLAGS) $(ARCHNAME)
	make clean

PHONY += info move edit

info: doc
	$(INFO) $(INFOFLAGS) $(DOC)

move: createDirs
	find ./* -maxdepth 0 -perm -u+x -type f -print0 | xargs -0 -r -I FILE mv FILE $(BINDIR)/
	find ./*.o -maxdepth 0 -print0 | xargs -0 -r -I FILE mv FILE $(OBJDIR)/
	find ./*.hpp -maxdepth 0 -print0 | xargs -0 -r -I FILE mv FILE $(INCDIR)/
	find ./*.cpp -maxdepth 0 -print0 | xargs -0 -r -I FILE mv FILE $(SRCDIR)/
	find ./*.a -maxdepth 0 -print0 | xargs -0 -r -I FILE mv FILE $(LIBDIR)/
	find ./*.so -maxdepth 0 -print0 | xargs -0 -r -I FILE mv FILE $(LIBDIR)/
	find ./*.sql -maxdepth 0 -print0 | xargs -0 -r -I FILE mv FILE $(SQLDIR)/
	find ./* -maxdepth 0 -not -name makefile -type f -print0 | xargs -0 -r -I FILE mv FILE $(RESDIR)/

edit:
	if [ -f "$(SRCDIR)/$(MAINFILE)" ]; then gedit "$(SRCDIR)/$(MAINFILE)" &; fi
	if [ -f "$(INCDIR)/$(FUNCTFILEH)" ]; then gedit "$(INCDIR)/$(FUNCTFILEH)" &; fi
	if [ -f "$(SRCDIR)/$(FUNCTFILEC)" ]; then gedit "$(SRCDIR)/$(FUNCTFILEC)" &; fi

PHONY += addClassCpp addPathfindingCpp addExceptionCpp addClassSfml addWindowSfml addWindowOpenGL addClassC

addClassCpp:
	"$(TEMPDIR)/addCPPClass" "$(TEMPDIR)"

addPathfindingCpp:
	"$(TEMPDIR)/addCPPPathfinding" "$(TEMPDIR)"

addExceptionCpp:
	"$(TEMPDIR)/addCPPException" "$(TEMPDIR)"

addClassSfml:
	"$(TEMPDIR)/addSFMLClass" "$(TEMPDIR)"

addWindowSfml:
	"$(TEMPDIR)/addSFMLWindow" "$(TEMPDIR)" "$(NAME_NEW_FILE)"

addWindowOpenGL:
	"$(TEMPDIR)/addOPENGLWindow" "$(TEMPDIR)" "$(NAME_NEW_FILE)"

addClassC:
	"$(TEMPDIR)/addCClass" "$(TEMPDIR)"

PHONY += libcpp libboost libc libsfml

libcpp:
	ln -sfn $(CPPIN) $(CPPOUT)
	$(libCreate) "$(LIBCPPIN)" "$(LIBCPPOUT)"

libboost:
	ln -sfn $(BOOSTIN) $(BOOSTOUT)
	$(libCreate) "$(LIBBOOSTIN)" "$(LIBBOOSTOUT)"

libc:
	ln -sfn $(CIN) $(COUT)
	$(libCreate) "$(LIBCIN)" "$(LIBCOUT)"

libsfml: libcpp
	ln -sfn $(SFMLIN) $(SFMLOUT)
	$(libCreate) "$(LIBSFMLIN)" "$(LIBSFMLOUT)"
	cp -r $(SFMLRESIN) $(SFMLRESOUT)


PHONY += send

send: remake
ifdef NETTARGET
	scp $(BINDIR)/$(FIN_EXE) $(NETTARGET)
endif

.PHONY: $(PHONY) see

