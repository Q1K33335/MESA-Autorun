CC 	= gcc

write_inlist : write_inlist.cpp
	$(CC) write_inlist.cpp -o write_inlist -lstdc++

.PHONY	: clean
clean	:
	rm -f write_inlist
