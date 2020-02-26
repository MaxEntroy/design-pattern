CXX= g++ -std=c++11
CXXFLAGS= -g -Wall -Wextra $(MYCXXFLAGS)
LDFLAGS= $(MYLDFLAGS)
LIBS= $(MYLIBS)

MYCXXFLAGS=
MYLDFLAGS=
MYLIBS=

RM= rm -f

MAIN_T= main
MAIN_O= main.o

# Targets start here

t: $(MAIN_T)

$(MAIN_T): $(MAIN_O)
	$(CXX) -o $@ $(LDFLAGS) $(MAIN_O) $(LIBS)

echo:
	@echo "CXX= $(CXX)"
	@echo "CXXFLAGS= $(CFLAGS)"
	@echo "LDFLAGS= $(LDFLAGS)"
	@echo "LIBS= $(LIBS)"
	@echo "RM= $(RM)"

clean:
	$(RM) $(MAIN_T) $(MAIN_O)


.PHONY: main clean

main.o: main.cc
