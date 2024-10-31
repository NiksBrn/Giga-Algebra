# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iheaders

# Директории
SRC_DIR = sources
INC_DIR = headers
OBJ_DIR = build

# Имя исполняемого файла
TARGET = main_program

# Список всех исходных и объектных файлов (кроме tests)
SRC_FILES := $(wildcard $(SRC_DIR)/**/*.cpp) main.cpp
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES)))

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Компиляция .cpp файлов в .o файлы
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | create_build_dirs
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp | create_build_dirs
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Создание папки build, если её нет
create_build_dirs:
	mkdir -p $(OBJ_DIR)

# Очистка объектных файлов и исполняемого файла
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean create_build_dirs
