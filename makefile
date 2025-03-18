CXX = g++
CXXFLAGS = `pkg-config --cflags gtk+-3.0` -Wall -g
LDFLAGS = `pkg-config --libs gtk+-3.0`
TARGET = output

all: $(TARGET)

$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o $(LDFLAGS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(TARGET) *.o