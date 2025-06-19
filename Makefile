#######################
# RUN `make` TO BUILD #
#######################

CC = g++
SRC = ./src/main.cpp
TARGET = planes

.PHONY: clean

$(SRC) :

$(TARGET) : $(SRC)
	$(CC) -o $(TARGET) $^

clean :
	unlink ./samples/$(TARGET)
	rm $(TARGET)
