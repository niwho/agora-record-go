.PHONY: clean

SRC =$(wildcard *.cpp)
OBJ=$(addsuffix .o, $(basename $(SRC)))

TARGET=agora_record_go

$(TARGET): libmyagora.a

libmyagora.a: $(OBJ)
	ar r $@ $^

%.o: %.cpp
	g++ -O2 -o $@ -c $^

clean:
	rm -f *.o *.so *.a $(TARGET)
