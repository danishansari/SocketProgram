CXX = -g -Wall
SRCDIR = src
OBJDIR = obj
BINDIR = bin

SRCS = Socket.cpp ServerSocket.cpp ClientSocket.cpp
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

INCFLAGS = -Iinclude

BIN_TRGTS = $(BINDIR)/server $(BINDIR)/client

LDFLAGS = $(LIBFLAGS) $(LIBDIRFLAGS)
CXXFLAGS = $(INCFLAGS)

all: $(BIN_TRGTS)

server: $(OBJS)
	@mkdir -p $(@D)
	g++ $(CXX) test/testServer.cpp  $^ -o $(BINDIR)/$@ $(CXXFLAGS) $(LDFLAGS)


client: $(OBJS)
	@mkdir -p $(@D)
	g++ $(CXX) test/testClient.cpp  $^ -o $(BINDIR)/$@ $(CXXFLAGS) $(LDFLAGS)

$(BINDIR)/server: $(OBJS)
	@mkdir -p $(@D)
	g++ $(CXX) test/testServer.cpp  $^ -o $@ $(CXXFLAGS) $(LDFLAGS)

$(BINDIR)/client: $(OBJS)
	@mkdir -p $(@D)
	g++ $(CXX) test/testClient.cpp  $^ -o $@ $(CXXFLAGS) $(LDFLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	g++ $(CXX) -c -Iinclude $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(OBJDIR)/*.o $(BIN_TRGTS)
