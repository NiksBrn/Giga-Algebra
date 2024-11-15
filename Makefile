# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iheaders -I/usr/include/gtest -Igenerators

# Директории
SRC_DIR = sources
GEN_DIR = generators
INC_DIR = headers
OBJ_DIR = build
TEST_DIR = tests

# Имя основного исполняемого файла и тестового исполняемого файла
TARGET = main_program
TEST_TARGET = test_program

# Флаги для линковки с GTest
GTEST_LIBS = -lgtest -lgtest_main -pthread

# Список исходных и объектных файлов для основного исполняемого файла
SRC_FILES := $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(GEN_DIR)/*.cpp) main.cpp
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(patsubst $(GEN_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))))

# Список исходных и объектных файлов для тестового исполняемого файла
TEST_SRC_FILES := $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(GEN_DIR)/*.cpp) $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(patsubst $(GEN_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRC_FILES))))

# Правило по умолчанию — сборка основного исполняемого файла
all: $(TARGET) $(TEST_TARGET)

# Сборка основного исполняемого файла
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Сборка тестового исполняемого файла с использованием Google Test и gtest_main
$(TEST_TARGET): $(TEST_OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIBS)

# Компиляция .cpp файлов в .o файлы для основного исполняемого файла
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | create_build_dirs
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Компиляция .cpp файлов в .o файлы для main.cpp
$(OBJ_DIR)/%.o: %.cpp | create_build_dirs
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Компиляция .cpp файлов в .o файлы для generators
$(OBJ_DIR)/%.o: $(GEN_DIR)/%.cpp | create_build_dirs
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Компиляция .cpp файлов в .o файлы для тестов
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | create_build_dirs
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Создание папки build, если её нет
create_build_dirs:
	mkdir -p $(OBJ_DIR)

# Очистка объектных файлов и исполняемых файлов
clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(TEST_TARGET)

# Запуск тестов
test: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean test create_build_dirs
