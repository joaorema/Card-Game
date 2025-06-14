CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = Presidente
SRC = src/main.cpp   \
	  src/card.cpp   \
	  src/deck.cpp   \
	  src/player.cpp \
	  src/menu.cpp   \

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)
