src = $(wildcard ./src/*.cpp)
obj = $(patsubst %.cpp,%.o,$(src))
mysql_flags = `mysql_config --cflags --libs`
cflags = -I ./include
target = MyDB
$(target):$(obj)
	g++ $(obj) $(mysql_flags) $(cflags) -o $(target)
%.o:%.cpp
	g++ -c $< $(cflags) -o $@

.PHONY:clean
clean:
	rm -f $(obj) $(target)
