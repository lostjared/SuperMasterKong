CXX=em++
CXXFLAGS= -Wno-write-strings  -s USE_SDL=2 
LDFLAGS= -s USE_SDL=2
CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix ,$(notdir $(CPP_FILES:.cpp=.o)))
PRELOAD= --preload-file assets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
  
all: $(OBJ_FILES) 
	$(CXX) $(PRELOAD) $(OBJ_FILES)  -o SuperMasterKong.html  $(LDFLAGS)

clean:
	rm -f *.o *.html *.wasm *.js *.data

