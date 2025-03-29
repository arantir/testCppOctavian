CXX = g++
CXXFLAGS = `pkg-config --cflags gtk+-3.0` -Wall -g
LDFLAGS = `pkg-config --libs gtk+-3.0`
TARGET = output
# Используем wildcard для получения всех .cpp файлов в директории
SRC_FILES = $(wildcard *.cpp)  # Список исходных файлов
OBJ_FILES = $(SRC_FILES:.cpp=.o)  # Преобразуем список .cpp в .o

# Правило по умолчанию
all: $(TARGET)

# Линковка объектных файлов в исполняемый файл
$(TARGET): $(OBJ_FILES)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Компиляция исходных файлов в объектные файлы
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка сгенерированных файлов
clean:
	rm -f $(TARGET) $(OBJ_FILES)

.PHONY: all clean  # Указываем, что all и clean не являются файлами
