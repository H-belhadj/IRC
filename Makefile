CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

EXEC = IRC

all: $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

clean:
	rm -fr $(OBJS) $(EXEC) 

fclean: clean
	rm -fr $(EXEC)

re: fclean all