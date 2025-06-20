#############################
# RUN `make build` TO BUILD #
#############################

CC = g++
SRC = ./src/main.cpp
TARGET = planes

.PHONY: clean

$(SRC) :

build : $(SRC)
	$(CC) -g -o $(TARGET) $^

clean :
	unlink ./samples/$(TARGET)
	rm $(TARGET)
