target=hello
src=$(wildcard ./*.c)
obj=$(patsubst %.c,%.o,$(src))
CC=gcc
CXX=g++
$(target):$(obj)
	$(CC) $(obj) -o $(target)
%.o:%.cpp
	$(CC) -c %< -o %@

.PHONY:clean
clean:
	rm -f $(obj) $(target)