# Compilation variables
CXX = g++
CXXFLAGS = -Wall -Wextra -fdiagnostics-color=always -g -std=c++20 -Iinclude -mconsole -static-libgcc -static-libstdc++
DLLFLAGS = -shared -Wl,--out-implib,$(OUT_LIB)

# Directories
OUT_DIR = build

all: $(OUT_DIR) $(OUT_DLL) $(TEST_PUSHBACK) $(TEST_UNIT)

# Main building ( + Unit Tests)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(OUT_DLL): src/Vector.cpp | $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $(DLLFLAGS) -DBUILDING_VECTOR -o $(OUT_DLL) src/Vector.cpp

$(TEST_UNIT): tests/vector_tests.cpp tests/catch_amalgamated.cpp $(OUT_DLL) | $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $(TEST_UNIT) tests/vector_tests.cpp tests/catch_amalgamated.cpp -L$(OUT_DIR) -lVector

$(TEST_PUSHBACK): $(OOP3_DIR)/pushback_test.cpp $(OOP3_DIR)/lib/*.cpp $(OUT_DLL) | $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $(TEST_PUSHBACK) $(OOP3_DIR)/pushback_test.cpp $(OOP3_DIR)/lib/*.cpp -L$(OUT_DIR) -lVector

# Clean all build results

clean:
	rm -rf $(OUT_DIR)