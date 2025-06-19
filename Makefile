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
	cd samples
	ln -s ../$(TARGET) $(TARGET)
	cd -

clean :
	unlink ./samples/$(TARGET)
	rm $(TARGET)
