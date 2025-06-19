#############################
# RUN `make build` TO BUILD #
#############################

CC = g++
SRC = ./src/main.cpp
TARGET = planes

.PHONY: build, clean

$(SRC) :

build : $(SRC)
	$(CC) -o $(TARGET) $^
	ln -s ./$(TRAGET) ./samples/$(TARGET)

clean :
	unlink ./samples/$(TARGET)
	rm $(TARGET)
