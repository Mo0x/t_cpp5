NAME = ./late_stage_capitalism
CXX = c++
SRCS =	./main.cpp \
		./Bureaucrat.cpp

OBJS = $(patsubst %.cpp, %.o, $(SRCS))
INCDIRS = ./includes
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98 -I$(INCDIRS) -pedantic
all : $(NAME)


$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all 

.PHONY : all clean fclean re